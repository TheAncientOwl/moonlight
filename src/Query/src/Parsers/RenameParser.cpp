#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

/**
 * @brief bring query to format: "content"
 *
 * @param query string representation of query in format: "rename { content }"
 */
void cleanup(std::string_view& query)
{
    query.remove_prefix("rename"sv.length());
    ltrim(query);

    if (query.front() != '{')
    {
        throw std::runtime_error("Missing '{' symbol");
    }
    query.remove_prefix(1);

    if (query.back() != '}')
    {
        throw std::runtime_error("Missing '}' symbol");
    }
    query.remove_suffix(1);

    trim(query);
}

Primitives::EStructureRenameType extractRenameType(std::string_view& query)
{
    const auto type = extractValue(query, "type");

    return Primitives::StructureRenameType::to_literal(std::string(type));
}

/**
 * @brief checks if the old & new names are valid (Identifiers & . matching when Field type specified)
 *
 * @param obj object representation of a Rename query
 */
void validateRenameObject(const QueryData::Rename& obj)
{
    switch (obj.type)
    {
    case Primitives::EStructureRenameType::Structure:
    case Primitives::EStructureRenameType::Database:
    {
        if (!isValidIdentifier(obj.old_name))
        {
            throw std::runtime_error("Invalid name identifiers specified for old_name");
        }

        if (!isValidIdentifier(obj.new_name))
        {
            throw std::runtime_error("Invalid name identifiers specified for new_name");
        }
        break;
    }
    case Primitives::EStructureRenameType::Field:
    {
        const auto extract_structure_name_and_validate = [](std::string_view name) -> std::string_view {
            const auto dot_pos = name.find_first_of('.');

            if (dot_pos == std::string_view::npos)
            {
                throw std::runtime_error("Missing '.' symbol @ '"s + std::string(name) + "'"s);
            }

            if (dot_pos != name.find_last_of('.'))
            {
                throw std::runtime_error("Name cannot contain more than one '.' symbol @ '"s + std::string(name) + "'"s);
            }

            if (dot_pos == name.length() - 1)
            {
                throw std::runtime_error("Missing field name @ '"s + std::string(name) + "'"s);
            }

            const auto structure_name = name.substr(0, dot_pos);
            const auto field_name = name.substr(dot_pos + 1);

            if (!isValidIdentifier(structure_name))
            {
                throw std::runtime_error("Invalid structure name @ '"s + std::string(structure_name) + "'"s);
            }

            if (!isValidIdentifier(field_name))
            {
                throw std::runtime_error("Invalid structure name @ '"s + std::string(field_name) + "'"s);
            }

            return structure_name;
            };

        const auto old_structure_name = extract_structure_name_and_validate(obj.old_name);
        const auto new_structure_name = extract_structure_name_and_validate(obj.new_name);
        if (old_structure_name != new_structure_name)
        {
            throw std::runtime_error(
                "Structure names must match in rename ("s
                + std::string(old_structure_name)
                + " != "s
                + std::string(new_structure_name)
                + ")"s
            );
        }
        break;
    }
    default:
        throw std::runtime_error("Invalid rename type");
    }
}

} // Anonymous namespace

QUERY_COULD_MATCH(Rename)
{
    return startsWithIgnoreCase(query, "rename");
};

QUERY_PARSER(Rename)
{
    QUERY_OBJECT(obj, Rename);

    cleanup(query);

    obj.type = extractRenameType(query);
    obj.old_name = extractValue(query, "old_name");
    obj.new_name = extractValue(query, "new_name");

    validateRenameObject(obj);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation

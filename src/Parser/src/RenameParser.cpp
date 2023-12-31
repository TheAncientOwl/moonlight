#include "common/QueryParsers.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::Parser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "rename" };

Primitives::EStructureRenameType extractRenameType(std::string_view& query)
{
    const auto type_seq{ extractValue(query, "type") };

    return Primitives::StructureRenameType::to_literal(std::string(type_seq));
}

/**
 * @brief checks if the old & new names are valid (Identifiers & . matching when Field type specified)
 *
 * @param obj object representation of a Rename query
 */
void validateRenameObject(const Objects::Rename& obj)
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
            const auto dot_pos{ name.find_first_of('.') };

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

            const auto structure_name{ name.substr(0, dot_pos) };
            const auto field_name{ name.substr(dot_pos + 1) };

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

        const auto old_structure_name{ extract_structure_name_and_validate(obj.old_name) };
        const auto new_structure_name{ extract_structure_name_and_validate(obj.new_name) };
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

QUERY_PARSER_CLASS_IMPL(Rename, c_query_prefix)
{
    QUERY_OBJECT(obj, Rename);

    cleanupQuery(query, c_query_prefix);

    obj.type = extractRenameType(query);
    obj.old_name = extractValue(query, "old_name");
    obj.new_name = extractValue(query, "new_name");

    validateRenameObject(obj);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::Parser::Implementation

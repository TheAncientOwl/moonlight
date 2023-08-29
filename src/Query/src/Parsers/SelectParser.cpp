#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

#include <regex>
#include <functional>

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "select" };

QueryData::Alias parseStructureAlias(std::string seq)
{
    static const std::regex s_regex(R"((\w+)\s+as\s+(\w+))", std::regex_constants::icase);

    QueryData::Alias out{};

    std::smatch match{};
    if (std::regex_match(seq, match, s_regex))
    {
        out.original = match.str(1);
        out.alias = match.str(2);
    }
    else if (isValidIdentifier(seq))
    {
        out.original = std::move(seq);
        out.alias = out.original;
    }
    else
    {
        throw std::runtime_error("Invalid structure alias @ '"s + seq + "'"s);
    }

    return out;
}

QueryData::Alias parseFieldAlias(std::string seq)
{
    static const std::regex s_regex(R"((\w+\.\w+)\s+as\s+(\w+))", std::regex_constants::icase);
    static const std::regex s_field_regex(R"(\w+\.\w+)", std::regex_constants::icase);

    QueryData::Alias out{};

    std::smatch match{};
    if (std::regex_match(seq, match, s_regex))
    {
        out.original = match.str(1);
        out.alias = match.str(2);
    }
    else if (std::regex_match(seq, s_field_regex))
    {
        out.original = std::move(seq);
        out.alias = out.original;
    }
    else
    {
        throw std::runtime_error("Invalid field alias @ '"s + seq + "'"s);
    }

    return out;
}

std::vector<QueryData::Alias> extractAliases(std::string_view& query, std::string_view keyword, std::function<QueryData::Alias(std::string)> parse)
{
    const auto aliases = extractList(query, keyword);

    std::vector<QueryData::Alias> out{};
    out.reserve(aliases.size());

    for (const auto alias : aliases)
    {
        out.emplace_back(parse(std::string(alias)));
    }

    return out;
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Select, c_query_prefix)
{
    QUERY_OBJECT(obj, Select);

    cleanupQuery(query, c_query_prefix);

    obj.from = extractAliases(query, "from", parseStructureAlias);
    obj.fields = extractAliases(query, "fields", parseFieldAlias);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation

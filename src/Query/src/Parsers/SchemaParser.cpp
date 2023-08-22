#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

#include <regex>

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

std::vector<std::string> extractInherits(std::string_view& query)
{
    std::vector<std::string> out{};

    try
    {
        out = extractIdentifiersList(query, "inherits");
    }
    catch (const std::runtime_error& e)
    {
        if (!equalsIgnoreCase(e.what(), "Invalid query, missing 'inherits' keyword"))
        {
            throw e;
        }
    }

    return out;
}

QueryData::Field parseField(std::string str)
{
    const auto make_boolean = [](const std::smatch& match) -> QueryData::Field {
        QueryData::Field out{};

        out.name = match.str(1);
        out.data_type = Primitives::EDataType::Boolean;
        out.metadata = match.str(3);
        out.size = std::nullopt;
        out.nullable = match.str(2).front() == '?';
        return out;
        };
    const auto make_date_time = [](const std::smatch& match) -> QueryData::Field {
        QueryData::Field out{};

        return out;
        };
    const auto make_string = [](const std::smatch& match) -> QueryData::Field {
        QueryData::Field out{};

        return out;
        };
    const auto make_integer = [](const std::smatch& match) -> QueryData::Field {
        QueryData::Field out{};

        return out;
        };
    const auto make_decimal = [](const std::smatch& match) -> QueryData::Field {
        QueryData::Field out{};

        return out;
        };
    const auto make_reference = [](const std::smatch& match) -> QueryData::Field {
        QueryData::Field out{};

        return out;
        };

    using MakeFunction = std::function<QueryData::Field(const std::smatch& match)>;
    static const std::vector<std::pair<std::regex, MakeFunction>> s_matchers
    {
        std::make_pair(
            std::regex{ R"((\w+)\s*is\s*([?]{0,1}Boolean)\s*@default\((true|false|null)\))", std::regex_constants::icase },
            make_boolean
        ),
        std::make_pair(
            std::regex{ R"((\w+)\s*is\s([?]{0,1}DateTime)\s*@default\((now\(\)|null)\))", std::regex_constants::icase },
            make_date_time
        ),
        std::make_pair(
            std::regex{ R"((\w+)\s*is\s([?]{0,1}String)\s*\[\s*([1-9]\d*)\s*\]\s*@default\((".*"|null)\))", std::regex_constants::icase },
            make_string
        ),
        std::make_pair(
            std::regex{ R"((\w+)\s*is\s*([?]{0,1}Integer)\s*\[(8|16|32|64)\]\s*@default\((0|[1-9]\d*|null)\))", std::regex_constants::icase },
            make_integer
        ),
        std::make_pair(
            std::regex{ R"((\w+)\s*is\s*([?]{0,1}Decimal)\s*\[(8|16|32|64)\]\s*@default\((0|\d+\.\d+|null)\))", std::regex_constants::icase },
            make_decimal
        ),
        std::make_pair(
            std::regex{ R"((\w+)\s*is\s*([?]{0,1}Reference)\s*@of\((\w+)\))", std::regex_constants::icase },
            make_reference
        )
    };

    std::smatch match{};
    const auto matcher_it = std::find_if(s_matchers.begin(), s_matchers.end(),
        [str, &match](const auto& matcher) {
            return std::regex_match(str, match, matcher.first);
        });

    if (matcher_it == std::cend(s_matchers))
    {
        throw std::runtime_error("Invalid field @ '"s + std::string(str) + "'"s);
    }

    return matcher_it->second(match);
}

std::vector<QueryData::Field> extractFields(std::string_view& query)
{
    std::vector<QueryData::Field> out{};

    auto fields_sequence = extractValue(query, "fields", EParserModifier::EscapeQuotes);

    if (fields_sequence.front() != '[')
    {
        throw std::runtime_error("Missing '[' symbol in fields sequence");
    }

    if (fields_sequence.back() != ']')
    {
        throw std::runtime_error("Missing ']' symbol in fields sequence");
    }

    fields_sequence.remove_prefix(1);
    fields_sequence.remove_suffix(1);

    const auto fields = splitAtComma(fields_sequence, EParserModifier::EscapeQuotes);
    if (fields.empty())
    {
        throw std::runtime_error("Fields list cannot be empty");
    }

    for (const auto field : fields)
    {
        out.emplace_back(parseField(std::string(field)));
    }

    return out;
}

} // Anonymous namespace

QUERY_COULD_MATCH(Schema)
{
    return startsWithIgnoreCase(query, "schema");
}

QUERY_PARSER(Schema)
{
    QUERY_OBJECT(obj, Schema);

    cleanupQuery(query, "schema");

    obj.name = extractIdentifier(query, "name");
    obj.inherits = extractInherits(query);
    obj.fields = extractFields(query);

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation

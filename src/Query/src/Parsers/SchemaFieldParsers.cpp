#include "SchemaFieldParsers.hpp"

namespace Moonlight::QueryParser::Implementation::FieldParsers {

using namespace std::literals;

namespace {

std::uint32_t parseSize(const std::string& str)
{
    std::uint32_t value{ 0 };
    try
    {
        value = std::stoul(str);
    }
    catch (const std::invalid_argument& e)
    {
        throw std::runtime_error("Cannot convert string size to a valid 32 bits number");
    }
    catch (const std::out_of_range& e)
    {
        throw std::runtime_error("String size out of the range of representable values by a 32 bit integer");
    }
    return value;
}

bool isNullable(std::string_view type)
{
    return type.front() == '?';
}

std::optional<std::string> getMetadata(std::string str, bool nullable)
{
    static const std::string s_null{ "null" };

    std::optional<std::string> out{ std::nullopt };

    if (str != s_null)
    {
        out = std::move(str);
    }
    else
    {
        if (!nullable)
        {
            throw std::runtime_error("Non nullable type cannot have 'null' as default value");
        }
    }

    return out;
}

} // Anonymous namespace

FIELD_PARSER_MATCH(Boolean, R"((\w+)\s*is\s*([?]{0,1}Boolean)\s*@default\s*\(\s*(true|false|null)\s*\))");
FIELD_PARSER_LOGICS(Boolean)
{
    QueryData::Field out{};

    out.name = m_smatch.str(1);
    out.data_type = Primitives::EDataType::Boolean;
    out.size = std::nullopt;
    out.nullable = isNullable(m_smatch.str(2));
    out.metadata = getMetadata(m_smatch.str(3), out.nullable);

    return out;
}


FIELD_PARSER_MATCH(String, R"((\w+)\s*is\s([?]{0,1}String)\s*\[\s*([1-9]\d*)\s*\]\s*@default\s*\(\s*(".+"|null)\s*\))");
FIELD_PARSER_LOGICS(String)
{
    QueryData::Field out{};

    out.name = m_smatch.str(1);
    out.data_type = Primitives::EDataType::String;
    out.size = parseSize(m_smatch.str(3));
    out.nullable = isNullable(m_smatch.str(2));
    out.metadata = getMetadata(m_smatch.str(4), out.nullable);

    return out;
}

FIELD_PARSER_MATCH(Integer, R"((\w+)\s*is\s*([?]{0,1}Integer)\s*\[\s*(8|16|32|64)\s*\]\s*@default\s*\(\s*(0|[-]{0,1}[1-9]\d*|null)\s*\))");
FIELD_PARSER_LOGICS(Integer)
{
    QueryData::Field out{};

    out.name = m_smatch.str(1);
    out.data_type = Primitives::EDataType::Integer;
    out.size = parseSize(m_smatch.str(3));
    out.nullable = isNullable(m_smatch.str(2));
    out.metadata = getMetadata(m_smatch.str(4), out.nullable);

    // TODO: check if default fits specified type...

    return out;
}


FIELD_PARSER_MATCH(Decimal, R"((\w+)\s*is\s*([?]{0,1}Decimal)\s*\[\s*(8|16|32|64)\s*\]\s*@default\s*\(\s*(0|[-]{0,1}\d+\.\d+|null)\s*\))");
FIELD_PARSER_LOGICS(Decimal)
{
    QueryData::Field out{};

    out.name = m_smatch.str(1);
    out.data_type = Primitives::EDataType::Decimal;
    out.size = parseSize(m_smatch.str(3));
    out.nullable = isNullable(m_smatch.str(2));
    out.metadata = getMetadata(m_smatch.str(4), out.nullable);

    // TODO: check if default fits specified type...

    return out;
}


FIELD_PARSER_MATCH(Reference, R"((\w+)\s*is\s*([?]{0,1}Reference)\s*@of\s*\(\s*(\w+)\s*\))");
FIELD_PARSER_LOGICS(Reference)
{
    QueryData::Field out{};

    out.name = m_smatch.str(1);
    out.data_type = Primitives::EDataType::Reference;
    out.size = std::nullopt;
    out.nullable = isNullable(m_smatch.str(2));
    out.metadata = m_smatch.str(3);

    return out;
}


FIELD_PARSER_MATCH(DateTime, R"((\w+)\s*is\s*([?]{0,1}DateTime)\s*@default\s*\(\s*(null|now|\d\d(?:\/|.|-)\d\d(?:\/|.|-)\d\d\d\d)\s*\))");
FIELD_PARSER_LOGICS(DateTime)
{
    QueryData::Field out{};

    out.name = m_smatch.str(1);
    out.data_type = Primitives::EDataType::DateTime;
    out.size = std::nullopt;
    out.nullable = isNullable(m_smatch.str(2));
    out.metadata = getMetadata(m_smatch.str(3), out.nullable);

    // TODO: check if date is valid...

    return out;
}

} // namespace Moonlight::QueryParser::Implementation::FieldParsers

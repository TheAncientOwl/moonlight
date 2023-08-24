#pragma once

#include "../QueryData.hpp"

#include <regex>
#include <string>

#define FIELD_PARSER_CLASS_DEFINITION(Type) \
    class Type ## FieldParser : public IFieldParser \
    { \
    public: \
        bool match(std::string field_str) override; \
        QueryData::Field parse() const override; \
    }

#define FIELD_PARSER_CLASS_IMPL(Type, rgx) \
    bool Type ## FieldParser::match(std::string field_str) \
    { \
        static const std::regex regex{ rgx, std::regex_constants::icase }; \
        m_field = std::move(field_str); \
        return std::regex_match(m_field, m_smatch, regex); \
    } \
    QueryData::Field Type ## FieldParser::parse() const

namespace Moonlight::QueryParser::Implementation::FieldParsers {

class IFieldParser
{
public: // methods
    virtual bool match(std::string field_str) = 0;
    virtual QueryData::Field parse() const = 0;
    void clear();

public: // lifecycle
    IFieldParser(const IFieldParser&) = delete;
    IFieldParser& operator=(const IFieldParser&) = delete;

    IFieldParser(IFieldParser&&) noexcept = delete;
    IFieldParser& operator=(IFieldParser&&) noexcept = delete;

    IFieldParser() = default;
    virtual ~IFieldParser() {}

protected: // fields
    std::smatch m_smatch;
    std::string m_field;
};

FIELD_PARSER_CLASS_DEFINITION(String);
FIELD_PARSER_CLASS_DEFINITION(DateTime);
FIELD_PARSER_CLASS_DEFINITION(Boolean);
FIELD_PARSER_CLASS_DEFINITION(Integer);
FIELD_PARSER_CLASS_DEFINITION(Decimal);
FIELD_PARSER_CLASS_DEFINITION(Reference);

#define FIELD_PARSERS \
    StringFieldParser, \
    DateTimeFieldParser, \
    BooleanFieldParser, \
    IntegerFieldParser, \
    DecimalFieldParser, \
    ReferenceFieldParser

} // namespace Moonlight::QueryParser::Implementation::FieldParsers

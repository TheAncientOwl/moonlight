#pragma once

#include "./api/QueryObject.hpp"

#include <stdexcept>

#define QUERY_PARSER_CLASS_DEFINITION(Specialization) \
    class Specialization ## Parser : public IQueryParser { \
    public: \
        const char* queryPrefix() const override; \
        QueryObject parse(std::string_view query) const override; \
    }

#define QUERY_PARSER_CLASS_IMPL(Specialization, QueryPrefix) \
    const char* Specialization ## Parser::queryPrefix() const { return QueryPrefix; }; \
    QueryObject Specialization ## Parser::parse(std::string_view query) const


#define PLAIN_QUERY_OBJECT QueryObject query_obj{}
#define QUERY_OBJECT(name, type) \
    QueryObject query_obj = QueryObject::make<Objects::type>(); \
    auto& name = query_obj.get<Objects::type>();
#define RETURN_QUERY_OBJECT return query_obj


namespace Moonlight::Parser::Implementation {

using QueryObject = Objects::QueryObject;

class IQueryParser
{
public: // methods
    virtual const char* queryPrefix() const = 0;
    virtual QueryObject parse(std::string_view query) const = 0;

public: // constructors
    IQueryParser() = default;

    IQueryParser(const IQueryParser&) = delete;
    IQueryParser& operator=(const IQueryParser&) = delete;

    IQueryParser(IQueryParser&&) noexcept = delete;
    IQueryParser& operator=(IQueryParser&&) noexcept = delete;

    virtual ~IQueryParser();
};

QUERY_PARSER_CLASS_DEFINITION(Drop);
QUERY_PARSER_CLASS_DEFINITION(Create);
QUERY_PARSER_CLASS_DEFINITION(Rename);
QUERY_PARSER_CLASS_DEFINITION(Database);
QUERY_PARSER_CLASS_DEFINITION(Index);
QUERY_PARSER_CLASS_DEFINITION(Migrate);
QUERY_PARSER_CLASS_DEFINITION(Schema);
QUERY_PARSER_CLASS_DEFINITION(Delete);
QUERY_PARSER_CLASS_DEFINITION(Update);
QUERY_PARSER_CLASS_DEFINITION(Select);
QUERY_PARSER_CLASS_DEFINITION(View);
QUERY_PARSER_CLASS_DEFINITION(Insert);

#define QUERY_PARSERS \
    DropParser, \
    CreateParser, \
    RenameParser, \
    DatabaseParser, \
    IndexParser, \
    MigrateParser, \
    SchemaParser, \
    DeleteParser, \
    UpdateParser, \
    SelectParser, \
    ViewParser, \
    InsertParser

} // namespace Moonlight::Parser::Implementation

#pragma once

#include "QueryObject.hpp"

#define PARSER_CLASS(Specialization) \
class Specialization ## Parser : public IQueryParser { \
public: \
    bool match(std::string_view query) const override; \
    QueryObject parse(std::string_view query) const override; \
};

#define PARSER_MATCHER(Specialization) \
bool Specialization ## Parser::match(std::string_view query) const

#define PARSER_LOGICS(Specialization) \
QueryObject Specialization ## Parser::parse(std::string_view query) const

#define PLAIN_QUERY_OBJECT QueryObject query_obj{}

#define QUERY_OBJECT(name, type) \
    QueryObject query_obj = QueryObject::make<QueryData::type>(); \
    auto& name = query_obj.get<QueryData::type>();

#define RETURN_QUERY_OBJECT return query_obj

namespace Moonlight::QueryParser {

using QueryObject = QueryData::QueryObject;
QueryObject parseQuery(std::string_view query);

namespace Implementation {

class IQueryParser
{
public: // methods
    virtual bool match(std::string_view query) const = 0;
    virtual QueryObject parse(std::string_view query) const = 0;

public: // constructors
    IQueryParser() = default;

    IQueryParser(const IQueryParser&) = delete;
    IQueryParser& operator=(const IQueryParser&) = delete;

    IQueryParser(IQueryParser&&) noexcept = delete;
    IQueryParser& operator=(IQueryParser&&) noexcept = delete;

    virtual ~IQueryParser();
};

PARSER_CLASS(Drop)
PARSER_CLASS(Create)
PARSER_CLASS(Rename)
PARSER_CLASS(Database)
PARSER_CLASS(Index)
PARSER_CLASS(Migrate)
PARSER_CLASS(Schema)
PARSER_CLASS(Delete)
PARSER_CLASS(Update)
PARSER_CLASS(Select)
PARSER_CLASS(View)

} // namespace Implementation

} // namespace Moonlight::QueryParser

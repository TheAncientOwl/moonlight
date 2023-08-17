#pragma once

#include "QueryObject.hpp"

#define QUERY_PARSER_CLASS(Specialization) \
    class Specialization ## Parser : public IQueryParser { \
    public: \
        bool couldMatch(std::string_view query) const override; \
        QueryObject parse(std::string_view query) const override; \
    };

#define QUERY_COULD_MATCH(Specialization) bool Specialization ## Parser::couldMatch(std::string_view query) const
#define QUERY_PARSER(Specialization) QueryObject Specialization ## Parser::parse(std::string_view query) const

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
    /**
     * @brief check if query string starts with a specific keyword (like drop | create | etc...)
     *
     * @param query -> string representation of query
     * @return true -> if query starts with specific query string
     */
    virtual bool couldMatch(std::string_view query) const = 0;

    /**
     * @brief
     *
     * @param query -> string representation of query
     * @return QueryObject -> object representations of parsed query
     */
    virtual QueryObject parse(std::string_view query) const = 0;

public: // constructors
    IQueryParser() = default;

    IQueryParser(const IQueryParser&) = delete;
    IQueryParser& operator=(const IQueryParser&) = delete;

    IQueryParser(IQueryParser&&) noexcept = delete;
    IQueryParser& operator=(IQueryParser&&) noexcept = delete;

    virtual ~IQueryParser();
};

QUERY_PARSER_CLASS(Drop)
QUERY_PARSER_CLASS(Create)
QUERY_PARSER_CLASS(Rename)
QUERY_PARSER_CLASS(Database)
QUERY_PARSER_CLASS(Index)
QUERY_PARSER_CLASS(Migrate)
QUERY_PARSER_CLASS(Schema)
QUERY_PARSER_CLASS(Delete)
QUERY_PARSER_CLASS(Update)
QUERY_PARSER_CLASS(Select)
QUERY_PARSER_CLASS(View)

} // namespace Implementation

} // namespace Moonlight::QueryParser

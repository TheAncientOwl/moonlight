#include "common/ParsedQueries.hpp"

namespace Moonlight::ParsedQuery::Helpers {

// TODO: update when WhereClause implemented...
WhereClause parseWhereClause(std::string_view seq)
{
    WhereClause out{};

    out.content = seq;

    return out;
}

} // namespace Moonlight::ParsedQuery::Helpers

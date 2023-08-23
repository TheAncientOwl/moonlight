#include "QueryData.hpp"

namespace Moonlight::QueryData::Helpers {

// TODO: update when WhereClause implemented...
WhereClause parseWhereClause(std::string_view seq)
{
    WhereClause out{};

    out.content = seq;

    return out;
}

} // namespace Moonlight::QueryData::Helpers

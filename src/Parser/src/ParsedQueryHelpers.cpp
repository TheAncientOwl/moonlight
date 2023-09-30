#include "common/api/Objects.hpp"

namespace Moonlight::Parser::Objects::Helpers {

// TODO: update when WhereClause implemented...
WhereClause parseWhereClause(std::string_view seq)
{
    WhereClause out{};

    out.content = seq;

    return out;
}

} // namespace Moonlight::Parser::Objects::Helpers

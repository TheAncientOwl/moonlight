#include "common/QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

constexpr auto c_query_prefix{ "database" };

Primitives::EDatabaseOperationType extractOperationType(std::string_view& query)
{
    const auto operation_seq{ extractValue(query, "operation") };

    return Primitives::DatabaseOperationType::to_literal(std::string(operation_seq));
}

} // Anonymous namespace

QUERY_PARSER_CLASS_IMPL(Database, c_query_prefix)
{
    QUERY_OBJECT(obj, Database);

    cleanupQuery(query, c_query_prefix);

    obj.type = extractOperationType(query);
    obj.name = extractIdentifier(query, "name");

    if (obj.type == Primitives::EDatabaseOperationType::Backup)
    {
        ParsedQuery::DatabaseBackupMetadata metadata{};

        metadata.disk_path = extractValue(query, "to_disk");
        metadata.with_differential = extractBoolean(query, "with_differential");

        obj.backup_metadata = metadata;
    }

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation

#include "../QueryParser.hpp"

#include "Utils/src/Utils.hpp"

namespace Moonlight::QueryParser::Implementation {

using namespace Utils;
using namespace std::literals;

namespace {

Primitives::EDatabaseOperationType extractOperationType(std::string_view& query)
{
    const auto type = extractValue(query, "operation");

    return Primitives::DatabaseOperationType::to_literal(std::string(type));
}

} // Anonymous namespace

QUERY_COULD_MATCH(Database)
{
    return startsWithIgnoreCase(query, "database");
}

QUERY_PARSER(Database)
{
    QUERY_OBJECT(obj, Database);

    cleanupQuery(query, "database");

    obj.type = extractOperationType(query);
    obj.name = extractIdentifier(query, "name");

    if (obj.type == Primitives::EDatabaseOperationType::Backup)
    {
        QueryData::DatabaseBackupMetadata metadata{};

        metadata.disk_path = extractValue(query, "to_disk");
        metadata.with_differential = extractBoolean(query, "with_differential");

        obj.backup_metadata = metadata;
    }

    RETURN_QUERY_OBJECT;
}

} // namespace Moonlight::QueryParser::Implementation

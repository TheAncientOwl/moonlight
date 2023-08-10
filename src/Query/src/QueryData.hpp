#pragma once

#include "../../Primitives/src/Primitives.hpp"

#include <string>
#include <optional>
#include <vector>

namespace Moonlight::QueryData {

struct StructureDrop
{
    std::string name;
    bool cascade{ false };
};

struct StructureCreate
{
    Primitives::EStructureType type;
    std::string name{ "" };
    std::string schema{ "" };
    bool is_volatile{ false };
};

struct StructureRename
{
    Primitives::EStructureRenameType type;
    std::string old_name;
    std::string new_name;
};

struct DatabaseBackupMetadata
{
    std::string disk_path;
    bool with_differential{ false };
};

struct Database
{
    Primitives::EDatabaseOperationType type;
    std::string name;

    std::optional<DatabaseBackupMetadata> backup_metadata;
};

struct Index
{
    std::string on_structure;
    std::string name;
    std::vector<std::string> on_fields;
    bool unique{ false };
};

struct StructureMigrate
{
    std::string structure_name;
    std::string new_schema;
    std::vector<std::pair<std::string, std::string>> migrate_dictionary;
};

struct SchemaField
{
    std::string name;
    Primitives::EDataType data_type;
};

struct Schema
{
    std::string name;
    std::vector<std::string> inherits;
    std::vector<std::string> checks;
    std::vector<std::string> unique;
    std::vector<std::string> not_null;
};

struct WhereClause
{
    // TODO: implement
};

struct StructureDelete
{
    std::string name;
    WhereClause where;
};

struct SetClause
{
    // TODO: implement
};

struct StructureUpdate
{
    std::string name;
    SetClause set;
    WhereClause where;
};

struct Alias
{
    std::string original;
    std::string alias;
};

struct Join
{
    std::string father;
    std::string child;
    std::string reference_field;
};

struct OrderBy
{
    std::string field;
    Primitives::ESelectSortType type;
};

struct StructureSelect
{
    std::vector<Alias> fields;
    std::vector<Alias> from;
    std::vector<Join> join;
    WhereClause where;
    std::vector<OrderBy> order_by;
};

struct View : public StructureSelect
{
    bool replace{ false };
};

} // namespace Moonlight::QueryData

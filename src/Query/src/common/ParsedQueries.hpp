#pragma once

#include "Primitives/src/Primitives.hpp"

#include <string>
#include <optional>
#include <vector>

namespace Moonlight::ParsedQuery {

struct Drop
{
    std::string name;
    bool cascade{ false };
};

struct Create
{
    Primitives::EStructureType type;
    std::string name{ "" };
    std::string schema{ "" };
    bool is_volatile{ false };
};

struct Rename
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

struct Migrate
{
    std::string structure_name;
    std::string new_schema;
    std::vector<std::pair<std::string, std::string>> mappings;
};

struct Field
{
    std::string name;
    Primitives::EDataType data_type;
    std::optional<std::string> metadata;
    std::optional<std::uint32_t> size;
    bool nullable{ false };
    bool array{ false };
};

struct Schema
{
    std::string name;
    std::vector<std::string> inherits;
    std::vector<Field> fields;
    std::vector<std::string> restrictions;
};

struct WhereClause
{
    // TODO: implement
    std::string content;
};
namespace Helpers {

WhereClause parseWhereClause(std::string_view seq);

} // namespace Helpers

struct Delete
{
    std::string from;
    WhereClause where;
};

struct SetClauseItem
{
    std::string field;
    std::string expression;
};

struct Update
{
    std::string name;
    std::vector<SetClauseItem> set;
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

struct Select
{
    std::vector<Alias> fields;
    std::vector<Alias> from;
    std::vector<Join> join;
    WhereClause where;
    std::vector<OrderBy> order_by;
};

struct View : public Select
{
    bool replace{ false };
};

struct Insert
{
    std::string structure;
    std::vector<std::string> fields;
    std::vector<std::string> values;
};

} // namespace Moonlight::ParsedQuery

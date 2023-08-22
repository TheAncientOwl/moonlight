#pragma once

#include "../src/QueryData.hpp"

namespace Moonlight::QueryData::Init {

struct DropInit : public Drop
{
    using base_t = QueryData::Drop;
    DropInit();

    DropInit& name(const std::string& v);
    DropInit& cascade(const bool& v);
};

struct CreateInit : public Create
{
    using base_t = Create;
    CreateInit();

    CreateInit& type(const Primitives::EStructureType& v);
    CreateInit& name(const std::string& v);
    CreateInit& schema(const std::string& v);
    CreateInit& is_volatile(const bool& v);
};

struct RenameInit : public Rename
{
    using base_t = Rename;
    RenameInit();

    RenameInit& type(const Primitives::EStructureRenameType& v);
    RenameInit& old_name(const std::string& v);
    RenameInit& new_name(const std::string& v);
};

struct DatabaseBackupMetadataInit : public DatabaseBackupMetadata
{
    using base_t = DatabaseBackupMetadata;
    DatabaseBackupMetadataInit();

    DatabaseBackupMetadataInit& disk_path(const std::string& v);
    DatabaseBackupMetadataInit& with_differential(const bool& v);
};

struct DatabaseInit : public Database
{
    using base_t = Database;
    DatabaseInit();

    DatabaseInit& type(const Primitives::EDatabaseOperationType& v);
    DatabaseInit& name(const std::string& v);
    DatabaseInit& backup_metadata(const std::optional<DatabaseBackupMetadata>& v);
};

struct IndexInit : public Index
{
    using base_t = Index;
    IndexInit();

    IndexInit& on_structure(const std::string& v);
    IndexInit& name(const std::string& v);
    IndexInit& on_fields(const std::vector<std::string>& v);
    IndexInit& unique(const bool& v);
};

struct MigrateInit : public Migrate
{
    using base_t = Migrate;
    MigrateInit();

    MigrateInit& structure_name(const std::string& v);
    MigrateInit& new_schema(const std::string& v);
    MigrateInit& mappings(const std::vector<std::pair<std::string, std::string>>& v);
};

struct SchemaFieldInit : public Field
{
    using base_t = Field;
    SchemaFieldInit();

    SchemaFieldInit& name(const std::string& v);
    SchemaFieldInit& data_type(const Primitives::EDataType& v);
};

struct SchemaInit : public Schema
{
    using base_t = Schema;
    SchemaInit();

    SchemaInit& name(const std::string& v);
    SchemaInit& inherits(const std::vector<std::string>& v);
    SchemaInit& fields(std::vector<Field>& v);
    SchemaInit& checks(const std::vector<std::string>& v);
    SchemaInit& unique(const std::vector<std::string>& v);
    SchemaInit& not_null(const std::vector<std::string>& v);
};

struct WhereClauseInit : public WhereClause
{
    using base_t = WhereClause;
    WhereClauseInit();

    // TODO: implement
};

struct DeleteInit : public Delete
{
    using base_t = Delete;
    DeleteInit();

    DeleteInit& name(const std::string& v);
    DeleteInit& where(const WhereClause& v);
};

struct SetClauseInit : public SetClause
{
    using base_t = SetClause;
    SetClauseInit();

    // TODO: implement
};

struct UpdateInit : public Update
{
    using base_t = Update;
    UpdateInit();

    UpdateInit& name(const std::string& v);
    UpdateInit& set(const SetClause& v);
    UpdateInit& where(const WhereClause& v);
};

struct AliasInit : public Alias
{
    using base_t = Alias;
    AliasInit();

    AliasInit& original(const std::string& v);
    AliasInit& alias(const std::string& v);
};

struct JoinInit : public Join
{
    using base_t = Join;
    JoinInit();

    JoinInit& father(const std::string& v);
    JoinInit& child(const std::string& v);
    JoinInit& reference_field(const std::string& v);
};

struct OrderByInit : public OrderBy
{
    using base_t = OrderBy;
    OrderByInit();

    OrderByInit& field(const std::string& v);
    OrderByInit& type(const Primitives::ESelectSortType& v);
};

struct SelectInit : public Select
{
    using base_t = Select;
    SelectInit();

    SelectInit& fields(const std::vector<Alias>& v);
    SelectInit& from(const std::vector<Alias>& v);
    SelectInit& join(const std::vector<Join>& v);
    SelectInit& where(const WhereClause& v);
    SelectInit& order_by(const std::vector<OrderBy>& v);
};

struct ViewInit : public View
{
    using base_t = View;
    ViewInit();

    // TODO: implement
};

} // namespace Moonlight::QueryData::Init

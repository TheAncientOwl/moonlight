#include "QueryDataInit.hpp"

namespace Moonlight::QueryData::Init {

DropInit::DropInit() : base_t{} {}
DropInit& DropInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
DropInit& DropInit::cascade(const bool& v)
{
    return base_t::cascade = v, *this;
}


CreateInit::CreateInit() : base_t{} {}
CreateInit& CreateInit::type(const Primitives::EStructureType& v)
{
    return base_t::type = v, *this;
}
CreateInit& CreateInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
CreateInit& CreateInit::schema(const std::string& v)
{
    return base_t::schema = v, *this;
}
CreateInit& CreateInit::is_volatile(const bool& v)
{
    return base_t::is_volatile = v, *this;
}


RenameInit::RenameInit() : base_t{} {}
RenameInit& RenameInit::type(const Primitives::EStructureRenameType& v)
{
    return base_t::type = v, *this;
}
RenameInit& RenameInit::old_name(const std::string& v)
{
    return base_t::old_name = v, *this;
}
RenameInit& RenameInit::new_name(const std::string& v)
{
    return base_t::new_name = v, *this;
}


DatabaseBackupMetadataInit::DatabaseBackupMetadataInit() : base_t{} {}
DatabaseBackupMetadataInit& DatabaseBackupMetadataInit::disk_path(const std::string& v)
{
    return base_t::disk_path = v, *this;
}
DatabaseBackupMetadataInit& DatabaseBackupMetadataInit::with_differential(const bool& v)
{
    return base_t::with_differential = v, *this;
}


DatabaseInit::DatabaseInit() : base_t{} {}
DatabaseInit& DatabaseInit::type(const Primitives::EDatabaseOperationType& v)
{
    return base_t::type = v, *this;
}
DatabaseInit& DatabaseInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
DatabaseInit& DatabaseInit::backup_metadata(const std::optional<DatabaseBackupMetadata>& v)
{
    return base_t::backup_metadata = v, *this;
}


IndexInit::IndexInit() : base_t{} {}
IndexInit& IndexInit::on_structure(const std::string& v)
{
    return base_t::on_structure = v, *this;
}
IndexInit& IndexInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
IndexInit& IndexInit::on_fields(const std::vector<std::string>& v)
{
    return base_t::on_fields = v, *this;
}
IndexInit& IndexInit::unique(const bool& v)
{
    return base_t::unique = v, *this;
}


MigrateInit::MigrateInit() : base_t{} {}
MigrateInit& MigrateInit::structure_name(const std::string& v)
{
    return base_t::structure_name = v, *this;
}
MigrateInit& MigrateInit::new_schema(const std::string& v)
{
    return base_t::new_schema = v, *this;
}
MigrateInit& MigrateInit::migrate_dictionary(const std::vector<std::pair<std::string, std::string>>& v)
{
    return base_t::migrate_dictionary = v, *this;
}


SchemaFieldInit::SchemaFieldInit() : base_t{} {}
SchemaFieldInit& SchemaFieldInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
SchemaFieldInit& SchemaFieldInit::data_type(const Primitives::EDataType& v)
{
    return base_t::data_type = v, *this;
}

SchemaInit::SchemaInit() : base_t{} {}
SchemaInit& SchemaInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
SchemaInit& SchemaInit::inherits(const std::vector<std::string>& v)
{
    return base_t::inherits = v, *this;
}
SchemaInit& SchemaInit::checks(const std::vector<std::string>& v)
{
    return base_t::checks = v, *this;
}
SchemaInit& SchemaInit::unique(const std::vector<std::string>& v)
{
    return base_t::unique = v, *this;
}
SchemaInit& SchemaInit::not_null(const std::vector<std::string>& v)
{
    return base_t::not_null = v, *this;
}


WhereClauseInit::WhereClauseInit() : base_t{} {}


DeleteInit::DeleteInit() : base_t{} {}
DeleteInit& DeleteInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
DeleteInit& DeleteInit::where(const WhereClause& v)
{
    return base_t::where = v, *this;
}


SetClauseInit::SetClauseInit() : base_t{} {}


UpdateInit::UpdateInit() : base_t{} {}
UpdateInit& UpdateInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
UpdateInit& UpdateInit::set(const SetClause& v)
{
    return base_t::set = v, *this;
}
UpdateInit& UpdateInit::where(const WhereClause& v)
{
    return base_t::where = v, *this;
}


AliasInit::AliasInit() : base_t{} {}
AliasInit& AliasInit::original(const std::string& v)
{
    return base_t::original = v, *this;
}
AliasInit& AliasInit::alias(const std::string& v)
{
    return base_t::alias = v, *this;
}


JoinInit::JoinInit() : base_t{} {}
JoinInit& JoinInit::father(const std::string& v)
{
    return base_t::father = v, *this;
}
JoinInit& JoinInit::child(const std::string& v)
{
    return base_t::child = v, *this;
}
JoinInit& JoinInit::reference_field(const std::string& v)
{
    return base_t::reference_field = v, *this;
}


OrderByInit::OrderByInit() : base_t{} {}
OrderByInit& OrderByInit::field(const std::string& v)
{
    return base_t::field = v, *this;
}
OrderByInit& OrderByInit::type(const Primitives::ESelectSortType& v)
{
    return base_t::type = v, *this;
}

SelectInit::SelectInit() : base_t{} {}

SelectInit& SelectInit::fields(const std::vector<Alias>& v)
{
    return base_t::fields = v, *this;
}
SelectInit& SelectInit::from(const std::vector<Alias>& v)
{
    return base_t::from = v, *this;
}
SelectInit& SelectInit::join(const std::vector<Join>& v)
{
    return base_t::join = v, *this;
}
SelectInit& SelectInit::where(const WhereClause& v)
{
    return base_t::where = v, *this;
}
SelectInit& SelectInit::order_by(const std::vector<OrderBy>& v)
{
    return base_t::order_by = v, *this;
}


ViewInit::ViewInit() : base_t{} {}

} // namespace Moonlight::QueryData::Init

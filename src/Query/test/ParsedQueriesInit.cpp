#include "helpers/ParsedQueriesInit.hpp"

namespace Moonlight::ParsedQuery::Init {

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
MigrateInit& MigrateInit::mappings(const std::vector<std::pair<std::string, std::string>>& v)
{
    return base_t::mappings = v, *this;
}


FieldInit::FieldInit() : base_t{} {}
FieldInit& FieldInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
FieldInit& FieldInit::data_type(const Primitives::EDataType& v)
{
    return base_t::data_type = v, *this;
}
FieldInit& FieldInit::metadata(const std::optional<std::string>& v)
{
    return base_t::metadata = v, *this;
}
FieldInit& FieldInit::size(const std::optional<std::uint32_t>& v)
{
    return base_t::size = v, *this;
}
FieldInit& FieldInit::nullable(const bool& v)
{
    return base_t::nullable = v, *this;
}
FieldInit& FieldInit::array(const bool& v)
{
    return base_t::array = v, *this;
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
SchemaInit& SchemaInit::fields(const std::vector<Field>& v)
{
    return base_t::fields = v, *this;
}
SchemaInit& SchemaInit::restrictions(const std::vector<std::string>& v)
{
    return base_t::restrictions = v, *this;
}


WhereClauseInit::WhereClauseInit() : base_t{} {}
WhereClauseInit& WhereClauseInit::content(const std::string& v)
{
    return base_t::content = v, *this;
}

DeleteInit::DeleteInit() : base_t{} {}
DeleteInit& DeleteInit::from(const std::string& v)
{
    return base_t::from = v, *this;
}
DeleteInit& DeleteInit::where(const WhereClause& v)
{
    return base_t::where = v, *this;
}


SetClauseItemInit::SetClauseItemInit() : base_t{} {}
SetClauseItemInit& SetClauseItemInit::field(const std::string& v)
{
    return base_t::field = v, *this;
}
SetClauseItemInit& SetClauseItemInit::expression(const std::string& v)
{
    return base_t::expression = v, *this;
}

UpdateInit::UpdateInit() : base_t{} {}
UpdateInit& UpdateInit::name(const std::string& v)
{
    return base_t::name = v, *this;
}
UpdateInit& UpdateInit::set(const std::vector<SetClauseItem>& v)
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

} // namespace Moonlight::ParsedQuery::Init

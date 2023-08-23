#pragma once

#include "../src/QueryData.hpp"

#define EXPECT_DROP_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.name, obj2.name);\
    EXPECT_EQ(obj1.cascade, obj2.cascade)

#define EXPECT_CREATE_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.type, obj2.type); \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_EQ(obj1.schema, obj2.schema); \
    EXPECT_EQ(obj1.is_volatile, obj2.is_volatile)

#define EXPECT_RENAME_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.type, obj2.type); \
    EXPECT_EQ(obj1.old_name, obj2.old_name); \
    EXPECT_EQ(obj1.new_name, obj2.new_name)

#define EXPECT_DATABASE_BACKUP_METADATA_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.disk_path, obj2.disk_path); \
    EXPECT_EQ(obj1.with_differential, obj2.with_differential)

#define EXPECT_DATABASE_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.type, obj2.type); \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_EQ(obj1.backup_metadata.has_value(), obj2.backup_metadata.has_value()); \
    if (obj1.backup_metadata.has_value()) \
    { \
        const auto& metadata1 = obj1.backup_metadata.value(); \
        const auto& metadata2 = obj2.backup_metadata.value(); \
        EXPECT_DATABASE_BACKUP_METADATA_EQ(metadata1, metadata2); \
    }

#define EXPECT_INDEX_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.on_structure, obj2.on_structure); \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_EQ(obj1.on_fields, obj2.on_fields); \
    EXPECT_EQ(obj1.unique, obj2.unique)

#define EXPECT_MIGRATE_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.structure_name, obj2.structure_name); \
    EXPECT_EQ(obj1.new_schema, obj2.new_schema); \
    EXPECT_EQ(obj1.mappings, obj2.mappings)

#define EXPECT_SCHEMA_FIELD_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_EQ(obj1.data_type, obj2.data_type); \
    EXPECT_EQ(obj1.metadata.has_value(), obj2.metadata.has_value()); \
    if (obj1.metadata.has_value() && obj2.metadata.has_value()) { EXPECT_EQ(obj1.metadata.value(), obj2.metadata.value()); } \
    EXPECT_EQ(obj1.size.has_value(), obj2.size.has_value()); \
    if (obj1.size.has_value() && obj2.size.has_value()) { EXPECT_EQ(obj1.size.value(), obj2.size.value()); } \
    EXPECT_EQ(obj1.nullable, obj2.nullable)

#define EXPECT_ARRAYS_EQ(arr1, arr2, expect) \
    for (std::size_t i = 0u, end = std::min(arr1.size(), arr2.size()); i < end; i++) \
    { \
        const auto& val1 = arr1[i]; \
        const auto& val2 = arr2[i]; \
        expect(val1, val2); \
    } \
    EXPECT_EQ(arr1.size(), arr2.size())

#define EXPECT_SCHEMA_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_EQ(obj1.inherits, obj2.inherits); \
    EXPECT_ARRAYS_EQ(obj1.fields, obj2.fields, EXPECT_SCHEMA_FIELD_EQ); \
    EXPECT_EQ(obj1.checks, obj2.checks); \
    EXPECT_EQ(obj1.unique, obj2.unique)

#define EXPECT_WHERE_CLAUSE_EQ(obj1, obj2) \
    static_assert(false, "NOT IMPLEMENTED YET")

#define EXPECT_DELETE_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_WHERE_CLAUSE_EQ(obj1.where, obj2.where)

#define EXPECT_SET_CLAUSE_EQ(obj1, obj2) \
    static_assert(false, "NOT IMPLEMENTED YET")

#define EXPECT_UPDATE_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.name, obj2.name); \
    EXPECT_SET_CLAUSE_EQ(obj1.set, obj2.set); \
    EXPECT_WHERE_CLAUSE_EQ(obj1.where, obj2.where)

#define EXPECT_ALIAS_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.original, obj2.original); \
    EXPECT_EQ(obj1.alias, obj2.alias)

#define EXPECT_JOIN_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.father, obj2.father); \
    EXPECT_EQ(obj1.child, obj2.child); \
    EXPECT_EQ(obj1.reference_field, obj2.reference_field)

#define EXPECT_ORDER_BY_EQ(obj1, obj2) \
    EXPECT_EQ(obj1.field, obj2.field); \
    EXPECT_EQ(obj1.type, obj2.type)

#define EXPECT_SELECT_EQ(obj1, obj2) \
    EXPECT_ARRAYS_EQ(obj1.fields, obj2.fields, EXPECT_ALIAS_EQ); \
    EXPECT_ARRAYS_EQ(obj1.from, obj2.from, EXPECT_ALIAS_EQ); \
    EXPECT_ARRAYS_EQ(obj1.join, obj2.join, EXPECT_JOIN_EQ); \
    EXPECT_WHERE_CLAUSE_EQ(obj1.where, obj2.where); \
    EXPECT_ORDER_BY_EQ(obj1.order_by, obj2.order_by)

#define EXPECT_VIEW_EQ(obj1, obj2) \
    static_assert(false, "NOT IMPLEMENTED YET")

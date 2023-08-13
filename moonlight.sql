-- 1. DROP
Structure
    .drop(StructureName)
    .cascade(true | false);

-- 2. CREATE
Structure
    .create(table | document)
    .based_on(SchemaName1, SchemaName2)
    .named(StructureName)
    .volatile(true | false); // -- optional - default false

-- 3. RENAME
Structure
    .rename(structure)
    .old_name(StructureNameOld)
    .new_name(StructureNameNew);

Structure
    .rename(field)
    .old_name(StructureName.old_field)
    .new_name(StructureName.new_field);

-- 4. DATABASE
Database.create(SomeDatabase);
Database.drop(SomeDatabase);
Database.backup(SomeDatabase)
        .to_disk("/home/user/lunardb")
        .with_differential(true | false); // -- optional - default false

-- 5. INDEX
Index.create_on(SomeStructure)
     .named(Field1Field2Index)
     .on_fields(field1, field2)
     .unique(true | false);          // -- optional - default false

-- 6. MIGRATE
Structure
    .migrate(StructureName)
    .to(NewSchemaName)
    .migrate_dictionary(            // optional
        old_field1 => new_field1,
        old_field2 => new_field2
    );

-- 7. SCHEMA
Schema
    .create(SchemaName)
    .inherits(SchemaName1, SchemaName2) // -- optional
    .fields(
        string_field => String[30] default "SomeName",
        date_field => DateTime default SysDate,

        unsigned_decimal_field => Decimal[32] default 46,
        decimal_field => Decimal[32] default -46,

        unsigned_integer_field => Integer[32] default 21,
        integer_field => Integer[32] default -21
    )
    .checks(           // -- optional
        email like "*@*.*",
        length(cnp) = 13,
    )
    .unique(cnp, somefield)    // -- optional
    .not_null(cnp, somefield); // -- optional

-- 8. DELETE
Structure
    .delete_from(StructureName)
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);

-- 9. UPDATE
Structure
    .update(StructureName)
    .set(
        field1 => field1 * 1.5 + 2,
        field2 => 3
    )
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);
    
-- 10. SELECT
Structure
    .select(
        s1.field as alias_field1,
        s2.field as alias_field2,
        s3.field as alias_field3
    )
    .from(
        structure1 as s1,
        structure2 as s2,
        structure3 as s3
    )
    .join(
        s1 => s2 on reference_field12,
        s2 => s3 on reference_field23,
        s3 => s1 on reference_field31
    )
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);
    .order_by(
        s1.some_field asc,
        s2.some_field desc
    );

-- 11. VIEW
View
    .create(replace: true | false) // -- default false
    .as()
    .select()...

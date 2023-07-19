-- 1. DROP
Structure
    .drop(StructureName)
    .cascade();

-- 2. CREATE
Structure
    .create(table | document)
    .based_on(SchemaName)
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
Database
    .create(DatabaseName);

Database
    .drop(DatabaseName);

Database
    .backup(DatabaseName)
    .to_disk("/home/user/lunardb")
    .with_differential(true | false); // -- optional - default false

Database
    .rename()
    .old_name(DatabaseNameOld)
    .new_name(DatabaseNameNew)

-- 5. INDEX
Index
    .create(IndexName)
    .on(SomeStructure)
    .fields(field1, field2)
    .unique(true | false);     // -- optional - default false

-- 6. MIGRATE
Structure
    .migrate(StructureName)
    .to(NewSchemaName)
    .mappings(            /        // -- optional
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

        unsigned_decimal_field => Decimal[32b, unsigned] default 46,
        decimal_field => Decimal[32b] default -46,

        unsigned_integer_field => Integer[32b, unsigned] default 21,
        integer_field => Integer[32b] default -21
    )
    .check(           // -- optional
        email like "*@*.*",
        length(cnp) = 13,
        cnp unique,
        cnp not null
    );

-- 8. DELETE
Structure
    .delete()
    .from(StructureName)
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);

-- 9. UPDATE
Structure
    .update(StructureName)
    .set(
        field1 => field1 * 1.5 + 2,
        field2 => 3
    )
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);
    
-- 10. INSERT
Structure
    .insert()
    .into(StructureName)
    .fields(
        field1,
        field2,
        field3,
        new_field => String[25] default "some-value"
    )
    .values(
        ["value11", "value12", "value13", "value14"],
        ["value21, "value22", "value23"]
    );

-- 11. SELECT
Structure
    .select(
        s1.field => alias_field1,
        s2.field => alias_field2,
        s3.field => alias_field3
    )
    .from(
        structure1 => s1,
        structure2 => s2,
        structure3 => s3
    )
    .join(
        s1 => s2 on reference_field12,
        s2 => s3 on reference_field23,
        s3 => s1 on reference_field31
    )
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);
    .sort(
        s1.some_field asc,
        s2.some_field desc
    );

-- 12. VIEW
View
    .create(replace: true | false) // -- default false
    .as()
    .select()...

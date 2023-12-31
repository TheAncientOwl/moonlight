-- 1. DROP
drop {
    structure: StructureName;
    cascade: boolean;
};

-- 2. CREATE
create structure {
    name: StructureName;
    type: table|document;
    based_on: SchemaName;
    volatile: boolean;
};

-- 3. RENAME
rename {
    type: structure|field|database;
    
    old_name: StructureNameOld;
    new_name: StructureNameNew;
    OR
    old_name: StructureName.old_field;
    new_name: StructureName.new_field;
};

-- 4. DATABASE
database {
    operation: create|drop|backup
    name: DatabaseName;
    to_disk: "/home/user/lunardb-backup";
    with_differential: boolean;
};

-- 5. INDEX
index {
    on: SomeStructure;
    name: Field1Field2Index;
    fields: [ field1, field2 ];
    unique: boolean;
};

-- 6. MIGRATE
migrate {
    structure: StructureName;
    to: NewSchemaName;
    mappings: [
        old_field1 => new_field1,
        old_field2 => new_field2
    ];
};

-- 7. SCHEMA
schema {
    name: SchemaName;
    inherits: [ SchemaName1, SchemaName2 ];   -- optional

    fields: [
        field_11 is Boolean               @default(false),
        field_12 is DateTime              @default(now()),
        field_13 is String[15]            @default("empty"),
        field_14 is Integer[8|16|32|64]   @default(14),
        field_15 is Decimal[8|16|32|64]   @default(3.14),
        field_16 is Reference             @of(OtherSchemaName),

        field_21 is Boolean?              @default(false),
        field_22 is DateTime?             @default(now()),
        field_23 is String?[15]           @default("empty"),
        field_24 is Integer?[8|16|32|64]  @default(14),
        field_25 is Decimal?[8|16|32|64]  @default(3.14),
        field_26 is Reference?            @of(OtherSchemaName),

        field_31 is Boolean?              @default(null),
        field_32 is DateTime?             @default(null),
        field_33 is String?[15]           @default(null),
        field_34 is Integer?[8|16|32|64]  @default(null),
        field_35 is Decimal?[8|16|32|64]  @default(null),
        field_36 is Reference?            @of(OtherSchemaName)

        field_11 is ArrayOf<Boolean>               @default(false),
        field_12 is ArrayOf<DateTime>              @default(now()),
        field_13 is ArrayOf<String[15]>            @default("empty"),
        field_14 is ArrayOf<Integer[8|16|32|64]>   @default(14),
        field_15 is ArrayOf<Decimal[8|16|32|64]>   @default(3.14),
        field_16 is ArrayOf<Reference>             @of(OtherSchemaName),
    ];

    restrictions: [          -- optional
        field3 like "*@*.*",
        length(field3) = 13,
        field1 unique
    ];
};

-- 8. DELETE
delete {
    from: StructureName;
    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9  or rid = 120;
};

-- 9. UPDATE
update {
    structure: StructureName;
    set: [
        field1 => field1 * 1.5 + 2,
        field2 => 3
    ];
    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9  or rid = 120;
};
    
-- 10. SELECT
select {
    from: [
        structure1 as s1,
        structure2 as s2,
        structure3 as s3
    ];

    fields: [
        s1.field as alias_field1,
        s2.field as alias_field2,
        s3.field as alias_field3
    ];

    join: [
        s1 => s2 on reference_field12,
        s2 => s3 on reference_field23,
        s3 => s1 on reference_field31
    ];

    where: rid = 11 or (rid >= 2 and 5 <= rid or some_field < 5000) or rid = 9  or rid = 120;

    order_by: [
        s1.some_field asc,
        s2.some_field desc
    ];
};

-- 11. VIEW
-- TODO: implement
view {
    replace: boolean;
    ...select
};

-- 12. INSERT
insert into {
    structure: StructureName;
    fields: [ field1, field2, field3 ]; -- Optional, if missing all fields are inserted
    values: [ value1, value2, value3 ];
};

insert into {
    structure: StructureName;
    fields: [ field1, field2, field3, new_field is String[15] @default("empty") ]; -- Only for documents
    values: [ value1, value2, value3, "value,4" ]
};

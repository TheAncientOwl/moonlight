-- 1. DROP
SomeStructure.drop(cascade: true);

-- 2. CREATE
SomeSchema
    .create(table | document)
    .named(SomeStructure)
    .volatile(true | false); // -- optional - default false

-- 3. RENAME
SomeDatabaseOld.rename(SomeDatabaseNew);
SomeStructureOld.rename(SomeStructureNew);
SomeSchemaOld.rename(SomeSchemaNew);
SomeSchema.some_field_old.rename(some_field_new);

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
     .unique(true | false); // -- optional - default false

-- 6. MIGRATE
SomeStructure.migrate_to(SomeSchema)
    .migrate_dictionary ({
        old_field1: new_field1,
        old_field2: new_field2
    }); // -- optional

-- 7. INSERT
SomeStructure
    .insert()
    .fields(field1, field2, field3, other_field is String default "some-value")
    .values([
        ("value11", "value12", "value13", "value14");
        ("value21", "value22", "value23"); // -- here value24 is some-value
    ]);
// -- long syntax other_field is String default "some-value" available only for documents

-- 8. SCHEMA
Schema
    .create()
    .named(SomeSchema)
    .inherits(SomeOtherSchema)
    .fields({               // -- optional if inherits specified and inherited schema not empty
        string_field: {
            type: String[30],
            default: "SomeName"
        },
        date_field: {
            type: DateTime
        },
        decimal_field: {
            type: Decimal[32, false]
            default: 46
        },
        integer_field: {
            type: Integer(32, false)
            default: 21
        },
        reference_field: {
            type: Reference[SomeSchema]
        },
        list_field: {
            type: List[SomeSchema]
        }
    })             
    .checks([
        email like "*@*.*",
        length(cnp) = 13,
    ])                      // -- optional
    .unique([ cnp ])        // -- optional
    .not_null([ cnp ]);     // -- optional

-- 9. DELETE
SomeStructure
    .delete()
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);

-- 10. UPDATE
SomeStructure
    .update()
    .set({
        field1: field1 * 1.5 + 2,
        field2: 3
    })
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);

-- 11. SELECT
SomeStructure
    .select({
        s1.field: Field1,
        s2.field: Field2,
        s3.field 
    })
    .from({
        Structure1: s1,
        Structure2: s2,
        Structure3: s3
    })
    .join({
        s1 -> s2: reference_field12,
        s2 -> s3: reference_field23,
        s3 -> s1: reference_field31
    })
    .where(rid = 11 or (rid >= 2 and 5 <= rid or salary < 5000) or rid = 9 or rid = 120);
    .order_by([
        s1.some_field asc, 
        s2.some_field desc
    ]);

-- 12. VIEW
View
    .create(replace: true | false) // -- default false
    .as()
    .select()...

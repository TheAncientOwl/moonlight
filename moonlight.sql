-- 1. DROP --------------------------------------------------------------------
drop SomeStructure;
drop SomeStructure cascade references;

-- 2. CREATE ------------------------------------------------------------------
create table SomeTable based on SomeSchema;
create volatile table SomeVolatileTable based on SomeSchema;
create document SomeDocument based on SomeSchema;
create volatile document SomeVolatileDocument based on SomeSchema;

-- 3. RENAME ------------------------------------------------------------------
rename database SomeDatabaseOld to SomeDatabaseNew;
rename structure SomeStructureOld to SomeStructureNew;
rename field SomeSchema.some_field_old to SomeSchema.some_field_new;
rename schema SomeSchemaOld to SomeSchemaNew;

-- 4. DATABASE ----------------------------------------------------------------
database create SomeDatabase;
database drop SomeDatabase;
database backup SomeDatabase to disk "/home/user/lunardb";
database backup SomeDatabase to disk "/home/user/lunardb" with differential;

-- 5. INDEX -------------------------------------------------------------------
unique index Field1Field2Index on SomeStructure (field1, field2);

-- 6. MIGRATE -----------------------------------------------------------------
migrate table SomeTable to SomeSchema {
    from old_field1 to new_field1;
    from old_field2 to new_field2;
};

migrate document SomeDocument to SomeSchema {
    from old_field1 to new_field1;
    from old_field2 to new_field2;
};

-- 7. INSERT ------------------------------------------------------------------
insert into table SomeTable
fields {
    field1, field2, field3
}
values {
    ("value11", "value12", "value13");
    ("value21", "value22", "value23");
};

-- --------------------------------------------------
insert into document SomeDocument
fields {
    field1, field2, field3, other_field(String[25])
}
values {
    ("value11", "value12", "value13", "value14");
    ("value21", "value22", "value23", "value24");
};

-- 8. SCHEMA --------------------------------------------------------------    
schema SomeSchema inherits SomeOtherSchema {
    String[30] string_field ("SomeName");
    DateTime date_field;
    Decimal[32, false] decimal_field(46);
    Integer[32, false] integer_field(46);
    Reference[StructureName] reference_field;

    Check email like "*@*.*";
    Check length(cnp) = 13;

    Unique cnp;

    Not null cnp;
};

-- 9. DELETE ------------------------------------------------------------------
delete from SomeStructure 
where {
    (rid >= 2 and 5 >= rid or salary < 5000) or rid = 9 or rid = 120
};

-- 10. UPDATE ------------------------------------------------------------------
update SomeStructure
set {
    field1 to field1 * 1.5 + 2;
    field2 to 3;
}
where {
    (rid >= 2 and 5 >= rid or salary < 5000) or rid = 9 or rid = 120
};

-- 11. SELECT -----------------------------------------------------------------
select {
    s1.field1 as Field1,
    s2.field2 as Field2,
    s3.field3
}
from {
    Structure1 s1,
    Structure2 s2,
    Structure3 s3
}
join {
    s1 -> s2 on reference_field,
    s2 -> s3 on reference_field,
    s3 -> s1 on reference_field,
}
where {
    (rid >= 2 and 5 >= rid or salary < 5000) or rid = 9 or rid = 120
}
order by {
    s1.some_field asc,
    s2.some_field desc,
};

-- 12. VIEW -------------------------------------------------------------------
create or replace view SomeView as
select ...;

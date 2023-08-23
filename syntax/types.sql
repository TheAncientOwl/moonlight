-- 1. Boolean
field_11 is Boolean               @default(false)
field_21 is ?Boolean              @default(false)
field_31 is ?Boolean              @default(null)

-- 2. DateTime
some_field is DateTime    @default(now)
some_field is DateTime    @default(22/29/2023)
some_field is DateTime    @default(22.29.2023)
some_field is DateTime    @default(22-29-2023)
some_field is ?DateTime   @default(now)
some_field is ?DateTime   @default(null)

-- 3. String
field_13 is String[15]            @default("empty")
field_23 is ?String[15]           @default("empty")
field_33 is ?String[15]           @default(null)

-- 4. Integer
field_14 is Integer[8]   @default(14)
field_24 is ?Integer[8]  @default(14)
field_34 is ?Integer[8]  @default(null)

field_14 is Integer[16]   @default(14)
field_24 is ?Integer[16]  @default(14)
field_34 is ?Integer[16]  @default(null)

field_14 is Integer[32]   @default(14)
field_24 is ?Integer[32]  @default(14)
field_34 is ?Integer[32]  @default(null)

field_14 is Integer[64]   @default(14)
field_24 is ?Integer[64]  @default(14)
field_34 is ?Integer[64]  @default(null)

-- 5. Decimal
field_15 is Decimal[8]   @default(3.14)
field_25 is ?Decimal[8]  @default(3.14)
field_35 is ?Decimal[8]  @default(null)

field_15 is Decimal[16]   @default(3.14)
field_25 is ?Decimal[16]  @default(3.14)
field_35 is ?Decimal[16]  @default(null)

field_15 is Decimal[32]   @default(3.14)
field_25 is ?Decimal[32]  @default(3.14)
field_35 is ?Decimal[32]  @default(null)

field_15 is Decimal[64]   @default(3.14)
field_25 is ?Decimal[64]  @default(3.14)
field_35 is ?Decimal[64]  @default(null)

-- 6. Reference
field_16 is Reference     @of(OtherSchemaName)
field_26 is ?Reference    @of(OtherSchemaName)
field_36 is ?Reference    @of(OtherSchemaName)

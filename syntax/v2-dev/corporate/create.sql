create table Clients based on Client;
create table Regions based on Region;
create table Departments based on Department;
create table Functions based on Function;
create table Products based on Product;

create table Countries based on Country with [
    region from Regions,
];

create table Locations based on Location with [
    country from Countries;
];

create table Employees based on Employee with [
    function from Functions,
    department from Departments,
    manager from Employees
];
update reference Departments.manager to Employees;

create table Orders based on Order with [
    client from Clients,
    employee from Employees,
    products.product from OrderedProduct
];

create table FunctionsHistory based on FunctionsHistory [
    employee from Employees,
    function from Functions,
    department from Departments
];

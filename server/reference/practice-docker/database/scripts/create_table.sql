CREATE TABLE visits (
visitor_name varchar(25) not null,
visit_datetime datetime default NOW() not null
);
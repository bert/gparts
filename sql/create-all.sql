-- A simple script to speed up development
--
-- * Destroys existing database
-- * Creates replacement
-- * Loads developer test data
--
-- All the temporary files must be created as shown in the INSTALL document.
--
-- Be in the project root directory and when in MySQL:
--
--   mysql> source sql/create-all.sql
--

drop database GParts;
create database GParts;
use GParts;

source sql/mysql/create-basic.sql;

--source sql/mysql/create-crystals.sql;
source sql/mysql/create-discretes.sql;
source sql/mysql/create-passives.sql;
source sql/mysql/create-categories.sql;

source data/packages.sql;

source tmp/symbols.sql
source tmp/parts-bourns.sql;
source tmp/parts-vishay-sprague.sql;

source data/onsemi-switching-diodes.sql;
source data/onsemi-transistors.sql;


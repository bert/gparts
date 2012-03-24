-- ---------------------------------------------------------------------------
--
-- gEDA - GPL Electronic Design Automation
-- gparts - gEDA Parts Manager
-- Copyright (C) 2010 Edward C. Hennessy
-- Copyright (C) 2010 gEDA Contributors (see ChangeLog for details)
--
-- This program is free software; you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation; either version 2 of the License, or
-- (at your option) any later version.
--
-- This program is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with this program; if not, write to the Free Software
-- Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111 USA
--
-- ---------------------------------------------------------------------------
--
-- SQL commands to initially setup the GParts database for SQLite.
--

BEGIN TRANSACTION;

CREATE TABLE Category (
    CategoryID    INTEGER PRIMARY KEY,
    CategoryName  TEXT,
    ViewName      TEXT,
    CreateForm    TEXT,
    EditForm      TEXT,
    ParentID      INTEGER,

    UNIQUE( CategoryName )
    );


-- Create a table to store companies.
--
-- Currently, companies only include manufacturers.  In the future, companies
-- could be expanded to include vendors.
--
CREATE TABLE Company (

    CompanyID    INTEGER  PRIMARY KEY,
    CompanyName  TEXT     NOT NULL,
    Website      TEXT,

    UNIQUE ( CompanyName )
    );


-- Create a table to store devices.
--
CREATE TABLE Device (

    DeviceID    INTEGER  PRIMARY KEY,
    DeviceName  TEXT     NOT NULL,

    UNIQUE ( DeviceName )
    );


-- Create a table to store documents.
--
-- The GParts database stores documentation for parts, allowing the user
-- quick access to specific information on parts in the database.
--
-- The category field stores a short description of the document type for the
-- user.  Categories include datasheet, errata, user manual, etc...  The
-- database does not use the category field except for presenting it to the
-- user.  Likewise, the title field contains a more detailed description of
-- the document.
--
-- The source URL field specifies where to obtain a copy of the document.  This
-- field contains NULL for resources created locally.  If the URL becomes
-- invalid, this field can be set to NULL.  In this case, if the location field
-- does not contain NULL, the record can persist with a local copy of the
-- document.
--
-- The file location field specifies a local path to the document relative to
-- the gEDA top level directory.  This document could either be created locally
-- or be a downloaded copy from the source URL.
--
-- Entities with both source URL and file location containing NULL no longer
-- refer to anything, and can be deleted.
--
CREATE TABLE Document (

    DocumentID    INTEGER  PRIMARY KEY,
    Category      TEXT,
    Title         TEXT,
    SourceURL     TEXT     DEFAULT NULL,
    FileLocation  TEXT     DEFAULT NULL,

    UNIQUE ( SourceURL ),
    UNIQUE ( FileLocation )
    );


-- Create a junction table for parts and documents.
--
-- Parts and documents have a many-to-many relationhip.  For example, an entire
-- series of simple parts may share a single datasheet, such as resistors.
-- Complex parts may require multiple documents, such as datasheets, user
-- manuals, and errata.
--
CREATE TABLE DocumentPartJ (

    DocumentID  INTEGER NOT NULL,
    PartID      INTEGER NOT NULL,

    FOREIGN KEY ( DocumentID ) REFERENCES Document,
    FOREIGN KEY ( PartID ) REFERENCES Part
    );


-- Create a table for PCB footprints.
--
-- A footprint represents a series of footprints for a particular electronic
-- component's package.  The FootprintName gets placed into a heavy symbol as
-- the 'footprint' attribute.
--
CREATE TABLE Footprint (

    FootprintID    INTEGER  PRIMARY KEY,
    FootprintName  TEXT     NOT NULL,

    UNIQUE ( FootprintName )
    );



-- Create a table for parts.
--
CREATE TABLE Part (

    PartID      INTEGER  PRIMARY KEY,
    CompanyID   INTEGER  NOT NULL,
    PartNumber  TEXT     NOT NULL,
    DeviceID    INTEGER  DEFAULT NULL,

    FOREIGN KEY ( CompanyID ) REFERENCES Company,
    FOREIGN KEY ( DeviceID ) REFERENCES Device,
    UNIQUE ( CompanyID, PartNumber )
    );


-- Create a table for packages.
--
-- A package represents the physical form-factor of an electronic device.
--
-- PackageID    Surrogate key.
-- PackageName  A unique name for the package.
-- SMT          TRUE indicates the package uses surface mount technology.
--
CREATE TABLE Package (

    PackageID    INTEGER  PRIMARY KEY,
    PackageName  TEXT     NOT NULL,
    Technology   TEXT,

    UNIQUE ( PackageName )
    );


-- Create a table for schematic symbols.
--
-- The SymbolName field stores the symbol's basename.
--
CREATE TABLE Symbol (

    SymbolID    INTEGER  PRIMARY KEY,
    SymbolName  TEXT     NOT NULL,
    DeviceID    INTEGER  NOT NULL,

    UNIQUE ( SymbolName ),
    FOREIGN KEY ( DeviceID ) REFERENCES Device
    );


-- Create a table for symbol details (comments).
--
-- Each symbol may have many comments.
--
--CREATE TABLE SymbolDetail (

--    SymbolID  INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
--    Detail    VARCHAR(500)      NOT NULL,

--    FOREIGN KEY ( SymbolID ) REFERENCES Symbol,
--    UNIQUE ( SymbolID, Detail )
--    );


-- Create a view for categories
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW CategoryV AS
    SELECT
        CategoryID,
        CategoryName,
        ViewName,
        ParentID
    FROM Category
    ORDER BY CategoryName;


-- Create a view for companies
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW CompanyV AS
    SELECT
        CompanyID,
        CompanyName,
        Website
    FROM Company
    ORDER BY CompanyName;


-- Create a view for devices
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW DeviceV AS
    SELECT
        DeviceID,
        DeviceName
    FROM Device
    ORDER BY DeviceName;


-- Create a view for documents
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW DocumentV AS
    SELECT
        DocumentID,
        Category,
        SourceURL
    FROM Document
    ORDER BY Category, Title;


-- Create a view for PCB footprints
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW FootprintV AS
    SELECT
        FootprintID,
        FootprintName
    FROM Footprint
    ORDER BY FootprintName;


-- Create a view for component packages
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW PackageV AS
    SELECT
        PackageID,
        PackageName,
        Technology AS 'Tech'
    FROM Package
    ORDER BY PackageName;


-- Create a view for symbols
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW SymbolV AS
    SELECT
        SymbolID,
        SymbolName,
        DeviceID,
        DeviceName
    FROM Symbol
        JOIN Device USING ( DeviceID )
    ORDER BY SymbolName;

COMMIT;


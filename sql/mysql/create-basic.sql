-- ---------------------------------------------------------------------------
--
-- gEDA - GPL Electronic Design Automation
-- gparts - gEDA Parts Manager
-- Copyright (C) 2009 Edward C. Hennessy
-- Copyright (C) 2009 gEDA Contributors (see ChangeLog for details)
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
-- SQL commands to initially setup the GParts database.
--

CREATE TABLE Category (

    CategoryID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    CategoryName  VARCHAR(500)      NOT NULL,
    ViewName      VARCHAR(500),
    ParentID      INTEGER UNSIGNED,

    PRIMARY KEY ( CategoryID ),
    UNIQUE( CategoryName )
    );


-- Create a table for application specific column metadata
--
CREATE TABLE ColumnMeta (

    ViewName    VARCHAR(500) NOT NULL,
    ColumnName  VARCHAR(500) NOT NULL,
    Units       VARCHAR(500),

    UNIQUE ( ViewName, ColumnName )
    );


-- Create a table to store companies.
--
-- Currently, companies only include manufacturers.  In the future, companies
-- could be expanded to include vendors.
--
CREATE TABLE Company (

    CompanyID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    CompanyName  VARCHAR(500)      NOT NULL,

    PRIMARY KEY ( CompanyID ),
    UNIQUE ( CompanyName )
    );


-- Create a table to store devices.
--
-- GParts uses the device attribute from the symbol file to group symbols.
-- Currently, the device attribute offers the only mechanism to group symbols.
--
CREATE TABLE Device (

    DeviceID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    DeviceName  VARCHAR(500)      NOT NULL,

    PRIMARY KEY ( DeviceID ),
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

    DocumentID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    Category      VARCHAR(500)      NOT NULL,
    Title         VARCHAR(500)      NOT NULL,
    SourceURL     VARCHAR(500)      DEFAULT NULL,
    FileLocation  VARCHAR(500)      DEFAULT NULL,

    PRIMARY KEY ( DocumentID ),
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

    DocumentID  INTEGER UNSIGNED  NOT NULL,
    PartID      INTEGER UNSIGNED  NOT NULL,

    PRIMARY KEY ( DocumentID, PartID ),
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

    FootprintID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    FootprintName  VARCHAR(500)      NOT NULL,

    PRIMARY KEY ( FootprintID ),
    UNIQUE ( FootprintName )
    );



-- Create a table for parts.
--
CREATE TABLE Part (

    PartID      INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    CompanyID   INTEGER UNSIGNED  NOT NULL,
    PartNumber  VARCHAR( 500 )    NOT NULL,
    DeviceID    INTEGER UNSIGNED  DEFAULT NULL,

    PRIMARY KEY ( PartID ),
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

    PackageID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    PackageName  VARCHAR(500)      NOT NULL,
    Technology   VARCHAR(500)      NOT NULL,

    PRIMARY KEY ( PackageID ),
    UNIQUE ( PackageName )
    );


-- Create a table for schematic symbols.
--
-- The xpath field stores the location of the symbol file relataive to the
-- gEDA top level directory.
--
CREATE TABLE Symbol (

    SymbolID    INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    SymbolPath  VARCHAR(500)      NOT NULL,
    DeviceID    INTEGER UNSIGNED  NOT NULL,

    PRIMARY KEY ( SymbolID ),
    FOREIGN KEY ( DeviceID ) REFERENCES Device,
    UNIQUE ( SymbolPath )
    );


-- Create a table for symbol details (comments).
--
-- Each symbol may have many comments.
--
CREATE TABLE SymbolDetail (

    SymbolID  INTEGER UNSIGNED  NOT NULL AUTO_INCREMENT,
    Detail    VARCHAR(500)      NOT NULL,

    FOREIGN KEY ( SymbolID ) REFERENCES Symbol,
    UNIQUE ( SymbolID, Detail )
    );


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
        CompanyName
    FROM Company
    ORDER BY CompanyName;


-- Create a view for devices
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW DeviceV AS
    SELECT
        DeviceName
    FROM Device
    ORDER BY DeviceName;


-- Create a view for documents
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW DocumentV AS
    SELECT
        Category,
        Title,
        FileLocation
    FROM Document
    ORDER BY Category, Title;


-- Create a view for PCB footprints
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW FootprintV AS
    SELECT
        FootprintName
    FROM Footprint
    ORDER BY FootprintName;


-- Create a view for component packages
--
-- This view abstracts the application from the underlying tables.
--
CREATE VIEW PackageV AS
    SELECT
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
        SymbolPath,
        DeviceID,
        DeviceName
    FROM Symbol
        JOIN Device USING ( DeviceID )
    ORDER BY SymbolPath;

DELIMITER $$

-- Add a part category to the database
--
-- CategoryName - The name of the new category.
-- ViewName - The name of the view to query for this category
-- ParentName - The name of the parent category.  If at the root, NULL.
--
CREATE PROCEDURE AddCategory(
    IN CategoryName VARCHAR(500),
    IN ViewName     VARCHAR(500),
    IN ParentName   VARCHAR(500)
    )

BEGIN
    DECLARE ParentID INTEGER UNSIGNED;

    SELECT CategoryID INTO ParentID FROM Category WHERE ( Category.CategoryName = ParentName );

    INSERT INTO Category (
        CategoryName,
        ViewName,
        ParentID
        )
    VALUES (
        CategoryName,
        ViewName,
        ParentID
        );
END$$

-- Add a company to the database.
--
-- CompanyName - The name of the company to add to the database.
--
CREATE PROCEDURE AddCompany(
    IN CompanyName VARCHAR(500)
    )

BEGIN
    INSERT INTO Company(
        CompanyName
        )
    VALUES (
        CompanyName
        );
END$$

-- Add a new device to the database.
--
-- DeviceName - The name of the new device to add to the database.
--
CREATE PROCEDURE AddDevice(
    IN DeviceName VARCHAR(500)
    )

BEGIN
    INSERT INTO Device(
        DeviceName
        )
    VALUES (
        DeviceName
        );
END$$

-- Add a PCB footprint to the database.
--
-- FootprintName - The name of the new footprint to add to the database.
--
--
CREATE PROCEDURE AddFootprint(
    IN FootprintName VARCHAR(500)
    )

BEGIN
    INSERT INTO Footprint(
        FootprintName
        )
    VALUES (
        FootprintName
        );
END$$


-- Add a package to the database.
--
-- TODO Switch SMT/BOOLEAN to Technology/VARCHAR which could be values 'SMT' or 'TH'
--
CREATE PROCEDURE AddPackage(
    IN PackageName VARCHAR(500),
    IN Technology  VARCHAR(500)
    )

BEGIN
    INSERT INTO Package (
        PackageName,
        Technology
        )
    VALUES (
        PackageName,
        Technology
        );
END$$


-- Add a part to the database.
--
-- CompanyName - The name of the company that manufactures the part
-- PartNumber - The manufacturer's part number
-- DeviceName - The name of the device to associate the part with symbols.
--
CREATE PROCEDURE AddPart(
    IN CompanyName VARCHAR(500),
    IN PartNumber  VARCHAR(500),
    IN DeviceName  VARCHAR(500)
    )

BEGIN
    INSERT INTO Part (
        CompanyID,
        PartNumber,
        DeviceID
        )
    VALUES (
        ( SELECT CompanyID FROM Company WHERE Company.CompanyName = CompanyName ),
        PartNumber,
        ( SELECT DeviceID FROM Device WHERE Device.DeviceName = DeviceName )
        );
END$$

-- Add a symbol to the database.
--
-- DeviceName - The name of the device
-- SymbolPath - The filesystem path to the symbol.
--
-- The symbol path must uniquely identify the symbol
--
-- TODO Define the path: relative, absolute, URI?
--
CREATE PROCEDURE AddSymbol(
    IN DeviceName VARCHAR(500),
    IN SymbolPath VARCHAR(500)
    )

BEGIN
    INSERT INTO Symbol (
        DeviceID,
        SymbolPath
        )
    VALUES (
        ( SELECT DeviceID FROM Device WHERE Device.DeviceName = DeviceName ),
        SymbolPath
        );
END$$

-- Add a symbol detail (comment) to the database.
--
-- SymbolPath - The name of the symbol
-- Detail - The text of the detail (comment).
--
CREATE PROCEDURE AddSymbolDetail(
    IN SymbolPath VARCHAR(500),
    IN Detail     VARCHAR(500)
    )

BEGIN
    INSERT INTO SymbolDetail (
        SymbolID,
        Detail
        )
    VALUES (
        ( SELECT SymbolID FROM Symbol WHERE Symbol.SymbolPath = SymbolPath ),
        Detail
        );
END$$

DELIMITER ;


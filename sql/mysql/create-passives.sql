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
-- Create additional tables for storing passive devices.
--
-- These tables store additional information to allow quick selection of
-- passive electronic components.
--

-- Create a table for capacitors.
--
-- TODO The capacitor table requires more fields to be of any use.  For
-- example, the capacitor type: ceramic, aluminum electrolytic, tantalum,
-- etc...  Also, I seem to need ESR quite a bit.
--
CREATE TABLE Capacitor (

    PartID       INTEGER UNSIGNED  NOT NULL,
    PackageID    INTEGER UNSIGNED  NOT NULL,
    Capacitance  FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );

-- Create a table for inductors.
--
-- TODO Requires more columns to be useful.
--
CREATE TABLE Inductor (

    PartID      INTEGER UNSIGNED  NOT NULL,
    PackageID   INTEGER UNSIGNED  NOT NULL,
    Inductance  FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );

-- Create a table for resistors.
--
-- TODO Requires more columns to be useful.
--
CREATE TABLE Resistor (

    PartID      INTEGER UNSIGNED  NOT NULL,
    PackageID   INTEGER UNSIGNED  NOT NULL,
    Resistance  FLOAT             NOT NULL,
    Tolerance   FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );

-- Create a view for capacitors.
--
CREATE VIEW CapacitorV AS
    SELECT
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        Capacitor.Capacitance,
        Part.DeviceID
    FROM Capacitor
        JOIN Part USING ( PartID )
        JOIN Package USING ( PackageID )
        JOIN Company USING ( CompanyID );

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'CapacitorV', 'Capacitance', 'FARADS' );


-- Create a view for inductors.
--
CREATE VIEW InductorV AS
    SELECT
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        Inductor.Inductance,
        Part.DeviceID
    FROM Inductor
        JOIN Part USING ( PartID )
        Join Package USING ( PackageID )
        JOIN Company USING ( CompanyID );

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'InductorV', 'Inductace', 'HENRYS' );


-- Create a view for resistors.
--
-- For proper formatting, the Resistor.Resistance field must be immediately
-- followed by the Resistor.Tolerance field.
--

CREATE VIEW ResistorV AS
    SELECT
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        Resistor.Resistance,
        Resistor.Tolerance,
        Part.DeviceID
    FROM Resistor
        JOIN Part USING ( PartID )
        Join Package USING ( PackageID )
        JOIN Company USING ( CompanyID )
    ORDER BY Package.PackageName, Resistor.Resistance;

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'ResistorV', 'Resistnace', 'OHMS'    ),
    ( 'ResistorV', 'Tolerance',  'PERCENT' );


-- Add a capacitor to the GParts database
--
DELIMITER $$

CREATE PROCEDURE AddCapacitor(
    IN CompanyName  VARCHAR(500),
    IN PartNumber   VARCHAR(500),
    IN PackageName  VARCHAR(500),
    IN DeviceName   VARCHAR(500),
    IN Capacitance  FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO Capacitor ( PartID, PackageID, Capacitance ) VALUES (
        ( SELECT PartID
            FROM Part JOIN Company USING ( CompanyID )
            WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
            ),
        ( SELECT PackageID FROM Package WHERE PackageName = Package.PackageName ),
        Capacitance
        );
END$$

-- Add an inductor to the GParts database.
--
CREATE PROCEDURE AddInductor(
    IN CompanyName  VARCHAR(500),
    IN PartNumber   VARCHAR(500),
    IN PackageName  VARCHAR(500),
    IN DeviceName   VARCHAR(500),
    IN Inductance   FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO Inductor ( PartID, PackageID, Inductance ) VALUES (
        ( SELECT PartID
            FROM Part JOIN Company USING ( CompanyID )
            WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
            ),
        ( SELECT PackageID FROM Package WHERE PackageName = Package.PackageName ),
        Inductance
        );
END$$

-- Add a resistor to the GParts database.
--
CREATE PROCEDURE AddResistor(
    IN CompanyName  VARCHAR(500),
    IN PartNumber   VARCHAR(500),
    IN PackageName  VARCHAR(500),
    IN DeviceName   VARCHAR(500),
    IN Resistance   FLOAT,
    IN Tolerance    FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO Resistor ( PartID, Resistor.PackageID, Resistance, Tolerance ) VALUES (
        ( SELECT PartID
            FROM Part JOIN Company USING ( CompanyID )
            WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
            ),
        ( SELECT Package.PackageID FROM Package WHERE PackageName = Package.PackageName ),
        Resistance,
        Tolerance
        );
END$$

DELIMITER ;


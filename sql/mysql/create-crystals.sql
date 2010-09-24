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
-- Create additional tables for storing crystals.
--
-- These tables store additional information to allow quick selection of
-- passive electronic components.
--

-- Create a table for crystals.
--
CREATE TABLE Crystal (

    PartID       INTEGER UNSIGNED  NOT NULL,
    PackageID    INTEGER UNSIGNED  NOT NULL,
    Frequency    FLOAT             NOT NULL,
    Stability    FLOAT             NOT NULL,
    Tolerance    FLOAT             NOT NULL,
    Capacitance  FLOAT             NOT NULL,
    MinTemp      FLOAT             NOT NULL,
    MaxTemp      FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );


-- Create a view for crystals.
--
CREATE VIEW CrystalV AS
    SELECT
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        Crystal.Frequency,
        Crystal.Stability,
        Crystal.Tolerance,
        Crystal.Capacitance,
        Crystal.MinTemp,
        Crystal.MaxTemp,
        Part.DeviceID
    FROM Crystal
        JOIN Part USING ( PartID )
        JOIN Package USING ( PackageID )
        JOIN Company USING ( CompanyID );

-- Add a crystal to the GParts database
--
DELIMITER $$

CREATE PROCEDURE AddCrystal(
    IN CompanyName  VARCHAR(500),
    IN PartNumber   VARCHAR(500),
    IN PackageName  VARCHAR(500),
    IN DeviceName   VARCHAR(500),
    IN Frequency    FLOAT,
    IN Stability    FLOAT,
    IN Tolerance    FLOAT,
    IN Capacitance  FLOAT,
    IN MinTemp      FLOAT,
    IN MaxTemp      FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO Crystal ( PartID, PackageID, Frequency, Stability, Tolerance, Capacitance, MinTemp, MaxTemp ) VALUES (
        ( SELECT PartID
            FROM Part JOIN Company USING ( CompanyID )
            WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
            ),
        ( SELECT PackageID FROM Package WHERE PackageName = Package.PackageName ),
        Frequency,
        Stability,
        Tolerance,
        Capacitance,
        MinTemp,
        MaxTemp
        );
END$$

DELIMITER ;


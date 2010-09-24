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
-- Create additional tables for storing discrete semiconductors.
--
-- These tables store additional information to allow quick selection of
-- discrete semiconductor components.
--

-- Create a table for diodes.
--
-- This table can be used for most diodes, including small-signal, small-signal
-- Schottky, rectifiers and Schottky rectifiers.
--
-- TODO Should this table include additional fields to indicate the diode type?
-- (e.g. Small-signal, Rectifier, Schottky, etc...)
--
CREATE TABLE Diode (

    PartID             INTEGER UNSIGNED  NOT NULL,
    PackageID          INTEGER UNSIGNED  NOT NULL,
    MaxReverseVoltage  FLOAT,
    TypForwardVoltage  FLOAT,
    AveForwardCurrent  FLOAT,

    PRIMARY KEY ( PartID )
    );

-- Create a table for TVS diodes.
--
-- TODO What is the best way to indicate bidirectional or unidirectional?  The
-- type may be apparent from the symbol. Then, an additional field would not
-- be required.
--
CREATE TABLE TVSDiode (

    PartID            INTEGER UNSIGNED  NOT NULL,
    PackageID         INTEGER UNSIGNED  NOT NULL,
    WorkingVoltage    FLOAT             NOT NULL,
    BreakdownVoltage  FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );

-- Create a table for zener diodes.
--
CREATE TABLE ZenerDiode (

    PartID        INTEGER UNSIGNED  NOT NULL,
    PackageID     INTEGER UNSIGNED  NOT NULL,
    ZenerVoltage  FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );

-- Create a table for bipolar junction transistors.
--
CREATE TABLE BJT (

    PartID        INTEGER UNSIGNED  NOT NULL,
    PackageID     INTEGER UNSIGNED  NOT NULL,
    Polarity      VARCHAR(500)      NOT NULL,
    IC            FLOAT             NOT NULL,
    FT            FLOAT             NOT NULL,
    PD            FLOAT             NOT NULL,

    PRIMARY KEY ( PartID )
    );


-- Create a view for diodes.
--
CREATE VIEW DiodeV AS
    SELECT
        Part.PartID,
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        Diode.MaxReverseVoltage AS 'VR',
        Diode.TypForwardVoltage AS 'VF',
        Diode.AveForwardCurrent AS 'IF',
        Device.DeviceID
    FROM Diode
        JOIN Part USING ( PartID )
        JOIN Package USING ( PackageID )
        JOIN Company USING ( CompanyID )
        JOIN Device USING ( DeviceID );

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'DiodeV', 'VR', 'VOLTS' ),
    ( 'DiodeV', 'VF', 'VOLTS' ),
    ( 'DiodeV', 'IF', 'AMPS'  );

-- Create a view for TVS diodes.
--
CREATE VIEW TVSDiodeV AS
    SELECT
        Part.PartID,
        Company.CompanyName,
        Part.PartNumber,
        TVSDiode.WorkingVoltage AS 'VRWM',
        TVSDiode.BreakdownVoltage AS 'VBR'
    FROM TVSDiode
        JOIN Part USING ( PartID )
        JOIN Company USING ( CompanyID );

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'TVSDiodeV', 'VRWM', 'VOLTS' ),
    ( 'TVSDiodeV', 'VBR',  'VOLTS' );

-- Create a view for zener diodes.
--
CREATE VIEW ZenerDiodeV AS
    SELECT
        Part.PartID,
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        ZenerDiode.ZenerVoltage AS 'VZ',
        Device.DeviceID,
        Device.DeviceName
    FROM ZenerDiode
        JOIN Part USING ( PartID )
        JOIN Package USING ( PackageID )
        JOIN Company USING ( CompanyID )
        JOIN Device USING ( DeviceID );

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'ZenerDiodeV', 'VZ', 'VOLTS' );

-- Create a view for zener diodes.
--
CREATE VIEW BJTV AS
    SELECT
        Part.PartID,
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        BJT.Polarity,
        BJT.IC,
        BJT.FT,
        BJT.PD,
        Device.DeviceID,
        Device.DeviceName
    FROM BJT
        JOIN Part USING ( PartID )
        JOIN Package USING ( PackageID )
        JOIN Company USING ( CompanyID )
        JOIN Device USING ( DeviceID );

INSERT INTO ColumnMeta ( ViewName, ColumnName, Units ) VALUES
    ( 'BJTV', 'IC', 'AMPS'  ),
    ( 'BJTV', 'FT', 'HERTZ' ),
    ( 'BJTV', 'PD', 'WATTS' );


DELIMITER $$

-- Adds a diode to the GParts database.
--
CREATE PROCEDURE AddDiode(
    IN CompanyName        VARCHAR(500),
    IN PartNumber         VARCHAR(500),
    IN PackageName        VARCHAR(500),
    IN DeviceName         VARCHAR(500),
    IN MaxReverseVoltage  FLOAT,
    IN TypForwardVoltage  FLOAT,
    IN AveForwardCurrent  FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO Diode (
        PartID,
        Diode.PackageID,
        MaxReverseVoltage,
        TypForwardVoltage,
        AveForwardCurrent
        )
    VALUES (
        ( SELECT PartID
            FROM Part JOIN Company USING ( CompanyID )
            WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
            ),
        ( SELECT Package.PackageID FROM Package WHERE PackageName = Package.PackageName ),
        MaxReverseVoltage,
        TypForwardVoltage,
        AveForwardCurrent
        );
END$$

-- Adds a TVS diode to the GParts database.
--
CREATE PROCEDURE AddTVSDiode(
    IN CompanyName       VARCHAR(500),
    IN PartNumber        VARCHAR(500),
    IN PackageName       VARCHAR(500),
    IN DeviceName        VARCHAR(500),
    IN WorkingVoltage    FLOAT,
    IN BreakdownVoltage  FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO TVSDiode (
        PartID,
        TVSDoide.PackageID,
        WorkingVoltage,
        BreakdownVoltage
        )
    VALUES (
        ( SELECT PartID
            FROM Part JOIN Company USING ( CompanyID )
            WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
            ),
        ( SELECT Package.PackageID FROM Package WHERE PackageName = Package.PackageName ),
        WorkingVoltage,
        BreakdownVoltage
        );
END$$

-- Adds a zener diode to the GParts database.
--
CREATE PROCEDURE AddZenerDiode(
    IN CompanyName   VARCHAR(500),
    IN PartNumber    VARCHAR(500),
    IN PackageName   VARCHAR(500),
    IN DeviceName    VARCHAR(500),
    IN ZenerVoltage  FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO ZenerDiode ( PartID, ZenerDiode.PackageID, ZenerVoltage ) VALUES (
       ( SELECT PartID
           FROM Part JOIN Company USING ( CompanyID )
           WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
           ),
       ( SELECT Package.PackageID FROM Package WHERE PackageName = Package.PackageName ),
       ZenerVoltage
       );
END$$

-- Adds a BJT to the GParts database.
--
CREATE PROCEDURE AddBJT(
    IN CompanyName   VARCHAR(500),
    IN PartNumber    VARCHAR(500),
    IN PackageName   VARCHAR(500),
    IN DeviceName    VARCHAR(500),
    IN Polarity      VARCHAR(500),
    IN IC            FLOAT,
    IN FT            FLOAT,
    IN PD            FLOAT
    )

BEGIN
    CALL AddPart(
        CompanyName,
        PartNumber,
        DeviceName
        );

    INSERT INTO BJT ( PartID, BJT.PackageID, Polarity, IC, FT, PD ) VALUES (
       ( SELECT PartID
           FROM Part JOIN Company USING ( CompanyID )
           WHERE Company.CompanyName = CompanyName AND Part.PartNumber = PartNumber
           ),
       ( SELECT Package.PackageID FROM Package WHERE PackageName = Package.PackageName ),
       Polarity,
       IC,
       FT,
       PD
       );
END$$


DELIMITER ;


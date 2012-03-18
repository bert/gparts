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

-- ---------------------------------------------------------------------------
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

    PartID             INTEGER PRIMARY KEY,
    PackageID          INTEGER NOT NULL,
    MaxReverseVoltage  FLOAT,
    TypForwardVoltage  FLOAT,
    AveForwardCurrent  FLOAT

    );


-- ---------------------------------------------------------------------------
--
-- Create a table for diodes.
--

CREATE TABLE MOSFET (

    PartID                   INTEGER PRIMARY KEY,
    PackageID                INTEGER NOT NULL,
    Polarity                 TEXT,
    MaxDrainSourceVoltage    FLOAT,
    MaxDrainCurrent          FLOAT,
    TypGateThresholdVoltage  FLOAT,
    PowerDissipation         FLOAT

    );


-- ---------------------------------------------------------------------------
--
-- Create a table for TVS diodes.
--
-- TODO What is the best way to indicate bidirectional or unidirectional?  The
-- type may be apparent from the symbol. Then, an additional field would not
-- be required.
--

CREATE TABLE TVSDiode (

    PartID            INTEGER PRIMARY KEY, 
    PackageID         INTEGER NOT NULL,
    WorkingVoltage    FLOAT,
    BreakdownVoltage  FLOAT

    );


-- ---------------------------------------------------------------------------
--
-- Create a table for zener diodes.
--

CREATE TABLE ZenerDiode (

    PartID        INTEGER PRIMARY KEY,
    PackageID     INTEGER NOT NULL,
    ZenerVoltage  FLOAT

    );


-- ---------------------------------------------------------------------------
--
-- Create a table for bipolar junction transistors.
--

CREATE TABLE BJT (

    PartID        INTEGER PRIMARY KEY,
    PackageID     INTEGER NOT NULL,
    Polarity      TEXT,
    IC            FLOAT,
    FT            FLOAT,
    PD            FLOAT

    );


-- ---------------------------------------------------------------------------
--
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


-- ---------------------------------------------------------------------------
--
-- Create a view for MOSFETs
--

CREATE VIEW MOSFETV AS
    SELECT
        Part.PartID,
        Company.CompanyName,
        Part.PartNumber,
        Package.PackageName,
        MOSFET.Polarity,
        MOSFET.MaxDrainSourceVoltage   AS 'VDSS',
        MOSFET.MaxDrainCurrent         AS 'ID',       
        MOSFET.TypGateThresholdVoltage AS 'VGS',
        MOSFET.PowerDissipation        AS 'PD',
        Device.DeviceID,
        Device.DeviceName
    FROM MOSFET 
        JOIN Part USING ( PartID )
        JOIN Package USING ( PackageID )
        JOIN Company USING ( CompanyID )
        JOIN Device USING ( DeviceID );


-- ---------------------------------------------------------------------------
--
-- Create a view for rectifier diodes.
--
-- Rectifier diodes are stored in the diode table, but are selected for
-- a average forward current greater than or equal to 500 mA.
--
-- Diodes where the average forward current is null are selected also.
-- This way prevents parts from getting "lost" by not appearing in
-- either table.
--

CREATE VIEW RectifierDiodeV AS
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
        JOIN Device USING ( DeviceID )
    WHERE
        Diode.AveForwardCurrent IS NULL OR
        Diode.AveForwardCurrent >= 0.5;


-- ---------------------------------------------------------------------------
--
-- Create a view for Switching diodes.
--
-- Switching diodes are stored in the diode table, but are selected for
-- a average forward current less than 500 mA.
--
-- Diodes where the average forward current is null are selected also.
-- This way prevents parts from getting "lost" by not appearing in
-- either table.
--

CREATE VIEW SwitchingDiodeV AS
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
        JOIN Device USING ( DeviceID )
    WHERE
        Diode.AveForwardCurrent IS NULL OR
        Diode.AveForwardCurrent < 0.5;


-- ---------------------------------------------------------------------------
--
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


-- ---------------------------------------------------------------------------
--
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


-- ---------------------------------------------------------------------------
--
-- Create a view for BJTs.
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


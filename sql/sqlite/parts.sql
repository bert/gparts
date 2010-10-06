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
--  SQL to insert a part into the SQLite database
--
--  Since SQLite does not support stored procedures, this file requires a
--  considerable amount of code to insert a single part. This file serves as
--  a prototype for an operation that will eventually become part of another
--  program, likely a library for the part manager application itself.
--
-- ---------------------------------------------------------------------------

BEGIN TRANSACTION;

--  Ensure the company exists in the Company table. If not, insert it. It is
--  the responsibility of another query to update any other fields besides
--  the CompanyName.

INSERT INTO Company (CompanyName)
    SELECT ( "Fairchild Semiconductor" ) WHERE NOT EXISTS (
        SELECT * FROM Company WHERE CompanyName = "Fairchild Semiconductor"
        );

-- Ensure the device exists in the Device table.

INSERT INTO Device (DeviceName)
    SELECT ( "npn" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "npn"
        );

--  Ensure the package exists in the Package table. If not, insert it. It is
--  the responsibility of another query to update any other fields besides the
--  PackageName.

INSERT INTO Package (PackageName)
    SELECT ( "TO-92" ) WHERE NOT EXISTS (
        SELECT * FROM Package WHERE PackageName = "TO-92"
        );

-- Add the CompanyID and PartNumber to the Part table. If the CompanyID and
-- PartNumber already exist, do not insert a record.

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = "Fairchild Semiconductor"),
        "FJN3303",
        (SELECT DeviceID FROM Device WHERE DeviceName = "npn")
    WHERE NOT EXISTS
        (SELECT * FROM Part 
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = "Fairchild Semiconductor" AND PartNumber = "FJN3303"
             );

-- Add part specific data to the BJT table. Again, if the entry already exists
-- no operation is performed.

INSERT INTO BJT (PartID, PackageID, Polarity, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = "FJN3303"),
        (SELECT PackageID FROM Package WHERE PackageName = "TO-92"),
        "NPN",
        1.5,        
        4000000,
        1.1
    WHERE NOT EXISTS
        (SELECT * FROM BJT 
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = "Fairchild Semiconductor" AND PartNumber = "FJN3303"
             );

COMMIT;


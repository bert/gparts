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
-- ---------------------------------------------------------------------------

-- diodes 

INSERT INTO Company (CompanyName)
    SELECT ( "Fairchild Semiconductor" ) WHERE NOT EXISTS (
        SELECT * FROM Company WHERE CompanyName = "Fairchild Semiconductor"
        );

INSERT INTO Device (DeviceName)
    SELECT ( "npn" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "npn"
        );

INSERT INTO Package (PackageName)
    SELECT ( "TO-92" ) WHERE NOT EXISTS (
        SELECT * FROM Package WHERE PackageName = "TO-92"
        );

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = "Fairchild Semiconductor"),
        "FJN3303",
        (SELECT DeviceID FROM Device WHERE DeviceName = "npn")
    WHERE NOT EXISTS
        (SELECT * FROM Part WHERE PartNumber = "FJN3303");

INSERT INTO BJT (PartID, PackageID, Polarity, IC, FT, PD)
    VALUES (
        (SELECT PartID FROM Part WHERE PartNumber = "FJN3303"),
        (SELECT PackageID FROM Package WHERE PackageName = "TO-92"),
        "NPN",
        1.5,        
        4000000,
        1.1 );

--    WHERE NOT EXISTS
--        (SELECT * FROM Part WHERE PartNumber = "FJN3303");


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

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Batteries",
    "BatteryV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "UNKNOWN")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Crystals",
    "CrystalV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "UNKNOWN")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Discretes",
    NULL,
    (SELECT CategoryID FROM Category WHERE CategoryName = "UNKNOWN")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Diodes",
    NULL,
    (SELECT CategoryID FROM Category WHERE CategoryName = "Discretes")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Small-signal",
    "DiodeV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Diodes")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "TVS",
    "TVSDiodeV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Diodes")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Zeners",
    "ZenerDiodeV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Diodes")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Transistors",
    NULL,
    (SELECT CategoryID FROM Category WHERE CategoryName = "Discretes")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "BJTs",
    "BJTV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Transistors")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "MOSFETs",
    "MOSFETV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Transistors")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Passives",
    NULL,
    (SELECT CategoryID FROM Category WHERE CategoryName = "UNKNOWN")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Capacitors",
    "CapacitorV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Passives")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Inductors",
    "InductorV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Passives")
    );

INSERT INTO Category (CategoryName, ViewName, ParentID) VALUES(
    "Resistors",
    "ResistorV",
    (SELECT CategoryID FROM Category WHERE CategoryName = "Passives")
    );


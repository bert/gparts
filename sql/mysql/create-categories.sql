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

CALL AddCategory(
    "Batteries",
    "BatteryV",
    "UNKNOWN"
    );

CALL AddCategory(
    "Crystals",
    "CrystalV",
    "UNKNOWN"
    );

CALL AddCategory(
    "Discretes",
    NULL,
    "UNKNOWN"
    );

CALL AddCategory(
    "Diodes",
    NULL,
    "Discretes"
    );

CALL AddCategory(
    "Small-signal",
    "DiodeV",
    "Diodes"
    );

CALL AddCategory(
    "TVS",
    "TVSDiodeV",
    "Diodes"
    );

CALL AddCategory(
    "Zeners",
    "ZenerDiodeV",
    "Diodes"
    );

CALL AddCategory(
    "Transistors",
    NULL,
    "Discretes"
    );

CALL AddCategory(
    "BJT",
    "BJTV",
    "Transistors"
    );

CALL AddCategory(
    "Passives",
    NULL,
    "UNKNOWN"
    );

CALL AddCategory(
    "Capacitors",
    "CapacitorV",
    "Passives"
    );

CALL AddCategory(
    "Inductors",
    "InductorV",
    "Passives"
    );

CALL AddCategory(
    "Resistors",
    "ResistorV",
    "Passives"
    );


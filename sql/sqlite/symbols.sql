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
-- Populate an SQLite database with some data for testing.
--
-- A temporary source file until import functionality becomes operational
-- in the application.
--
-- This file does not use procedures for compatibilty with SQLite.
--
-- ---------------------------------------------------------------------------
--
-- capacitors
--
-- TODO Separate capaciors into polarized and non-polarized groups
--

INSERT INTO Device (DeviceName)
    SELECT ( "capacitor" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "capacitor"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-capacitor-non-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "capacitor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-capacitor-non-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-capacitor-non-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "capacitor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-capacitor-non-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-capacitor-pol-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "capacitor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-capacitor-pol-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-capacitor-pol-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "capacitor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-capacitor-pol-2.sym");

-- ---------------------------------------------------------------------------
--
-- diodes 
--

INSERT INTO Device (DeviceName)
    SELECT ( "diode" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "diode"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "diode-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "diode")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "diode-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "diode-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "diode")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "diode-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "diode-3.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "diode")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "diode-3.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-diode-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "diode")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-diode-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-diode-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "diode")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-diode-2.sym");

-- ---------------------------------------------------------------------------
--
-- diodes, schottky
--

INSERT INTO Device (DeviceName)
    SELECT ( "schottky" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "schottky"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-schottky-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "schottky")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-schottky-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-schottky-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "schottky")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-schottky-2.sym");

-- ---------------------------------------------------------------------------
--
-- diodes, tuning 
--

INSERT INTO Device (DeviceName)
    SELECT ( "tuning" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "tuning"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-tuning-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "tuning")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-tuning-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-tuning-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "tuning")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-tuning-2.sym");

-- ---------------------------------------------------------------------------
--
-- diodes, tunnel 
--

INSERT INTO Device (DeviceName)
    SELECT ( "tunnel" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "tunnel"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-tunnel-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "tunnel")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-tunnel-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-tunnel-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "tunnel")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-tunnel-2.sym");

-- ---------------------------------------------------------------------------
--
-- diodes, schottky
--

INSERT INTO Device (DeviceName)
    SELECT ( "tvs" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "tvs"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-tvs-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "tvs")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-tvs-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-tvs-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "tvs")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-tvs-2.sym");

-- ---------------------------------------------------------------------------
--
-- diodes, zener
--

INSERT INTO Device (DeviceName)
    SELECT ( "zener" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "zener"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "zener-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "zener")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "zener-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "zener-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "zener")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "zener-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "zener-3.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "zener")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "zener-3.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "zener-4.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "zener")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "zener-4.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-zener-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "zener")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-zener-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-zener-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "zener")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-zener-2.sym");

-- ---------------------------------------------------------------------------
--
-- n type mosfets
--

INSERT INTO Device (DeviceName)
    SELECT ( "nmos" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "nmos"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "nmos-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "nmos")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "nmos-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "nmos-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "nmos")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "nmos-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "nmos-3.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "nmos")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "nmos-3.sym");

-- ---------------------------------------------------------------------------
--
-- npn transistors
--

INSERT INTO Device (DeviceName)
    SELECT ( "npn" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "npn"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "npn-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "npn")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "npn-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "npn-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "npn")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "npn-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "npn-3.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "npn")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "npn-3.sym");

-- ---------------------------------------------------------------------------
--
-- p type mosfets
--

INSERT INTO Device (DeviceName)
    SELECT ( "pmos" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "pmos"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "pmos-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "pmos")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "pmos-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "pmos-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "pmos")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "pmos-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "pmos-3.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "pmos")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "pmos-3.sym");

-- ---------------------------------------------------------------------------
--
-- pnp transistors
--

INSERT INTO Device (DeviceName)
    SELECT ( "pnp" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "pnp"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "pnp-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "pnp")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "pnp-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "pnp-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "pnp")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "pnp-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "pnp-3.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "pnp")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "pnp-3.sym");

-- ---------------------------------------------------------------------------
--
-- resistors
--

INSERT INTO Device (DeviceName)
    SELECT ( "resistor" ) WHERE NOT EXISTS (
        SELECT * FROM Device WHERE DeviceName = "resistor"
        );

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "resistor-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "resistor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "resistor-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "resistor-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "resistor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "resistor-2.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-resistor-1.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "resistor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-resistor-1.sym");

INSERT INTO Symbol (SymbolName, DeviceID)
    SELECT 
        "gp-resistor-2.sym",
        (SELECT DeviceID FROM Device WHERE DeviceName = "resistor")
    WHERE NOT EXISTS
        (SELECT * FROM Symbol WHERE SymbolName = "gp-resistor-2.sym");


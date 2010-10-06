-- Adds packaging (case) data to the GParts database.
--
-- PACKAGE NAMES
-- Prefer uppercase in all package names.
--
-- CAPACITORS
-- EIA form factors include the maximum height: 'EIA-7343-43'.
--
-- CHIP COMPONENTS
-- Chip components include the metric designation in parenthesis to reduce
-- confusion. For example, an '0603' package is named '0603(1806)'.
--
-- DIODES
-- The DO-214 packages include the alternate name in parenthesis.  For example
-- 'DO-214AB(SMC)'.  This additional information gets presented to the user.
--

INSERT INTO Package (PackageName, Technology)
    SELECT
        "0201(0603)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "0201(0603)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "0402(1005)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "0402(1005)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "0603(1608)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "0603(1608)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "0805(2012)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "0805(2012)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "1005(2512)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "1005(2512)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "1206(3216)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "1206(3216)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "1806(4516)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "1806(4516)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "1812(4532)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "1812(4532)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "2010(5025)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "2010(5025)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "2512(6332)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "2512(6332)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "DO-214AA(SMB)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "DO-214AA(SMB)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "DO-214AB(SMC)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "DO-214AB(SMC)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "DO-214AC(SMA)",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "DO-214AC(SMA)");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "EIA-3216-18",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "EIA-3216-18");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "EIA-3528-21",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "EIA-3528-21");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "EIA-7343-20",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "EIA-7343-20");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "EIA-6032-28",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "EIA-6032-28");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "EIA-7343-31",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "EIA-7343-31");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "EIA-7343-43",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "EIA-7343-43");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "MA-505",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "MA-505");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SC-59",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SC-59");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SC-70",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SC-70");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SC-75",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SC-75");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SC-88A",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SC-88A");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOD-123",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOD-123");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOD-323",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOD-323");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOD-523",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOD-523");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOD-723",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOD-723");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOD-923",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOD-923");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOT-23",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOT-23");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOT-363",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOT-363");

INSERT INTO Package (PackageName, Technology)
    SELECT
       "SOT-563",
       'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOT-563");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "SOT-723",
        'SMT'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "SOT-723");

INSERT INTO Package (PackageName, Technology)
    SELECT
        "TO-92",
        'TH'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = "TO-92");


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

INSERT INTO Package (PackageName, Technology) VALUES (
    "0201(0603)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "0402(1005)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "0603(1608)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "0805(2012)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "1005(2512)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "1206(3216)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "1806(4516)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "1812(4532)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "2010(5025)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "2512(6332)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "DO-214AA(SMB)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "DO-214AB(SMC)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "DO-214AC(SMA)",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "EIA-3216-18",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "EIA-3528-21",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "EIA-7343-20",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "EIA-6032-28",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "EIA-7343-31",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "EIA-7343-43",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "MA-505",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SC-59",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SC-70",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SC-75",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SC-88A",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOD-123",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOD-323",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOD-523",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOD-723",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOD-923",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOT-23",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOT-363",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOT-563",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "SOT-723",
    'SMT'
    );

INSERT INTO Package (PackageName, Technology) VALUES (
    "TO-92",
    'TH'
    );


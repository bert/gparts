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

CALL AddPackage(
    "0201(0603)",
    'SMT'
    );

CALL AddPackage(
    "0402(1005)",
    'SMT'
    );

CALL AddPackage(
    "0603(1608)",
    'SMT'
    );

CALL AddPackage(
    "0805(2012)",
    'SMT'
    );

CALL AddPackage(
    "1005(2512)",
    'SMT'
    );

CALL AddPackage(
    "1206(3216)",
    'SMT'
    );

CALL AddPackage(
    "1806(4516)",
    'SMT'
    );

CALL AddPackage(
    "1812(4532)",
    'SMT'
    );

CALL AddPackage(
    "2010(5025)",
    'SMT'
    );

CALL AddPackage(
    "2512(6332)",
    'SMT'
    );

CALL AddPackage(
    "DO-214AA(SMB)",
    'SMT'
    );

CALL AddPackage(
    "DO-214AB(SMC)",
    'SMT'
    );

CALL AddPackage(
    "DO-214AC(SMA)",
    'SMT'
    );

CALL AddPackage(
    "EIA-3216-18",
    'SMT'
    );

CALL AddPackage(
    "EIA-3528-21",
    'SMT'
    );

CALL AddPackage(
    "EIA-7343-20",
    'SMT'
    );

CALL AddPackage(
    "EIA-6032-28",
    'SMT'
    );

CALL AddPackage(
    "EIA-7343-31",
    'SMT'
    );

CALL AddPackage(
    "EIA-7343-43",
    'SMT'
    );

CALL AddPackage(
    "SC-59",
    'SMT'
    );

CALL AddPackage(
    "SC-70",
    'SMT'
    );

CALL AddPackage(
    "SC-75",
    'SMT'
    );

CALL AddPackage(
    "SC-88A",
    'SMT'
    );

CALL AddPackage(
    "SOD-123",
    'SMT'
    );

CALL AddPackage(
    "SOD-323",
    'SMT'
    );

CALL AddPackage(
    "SOD-523",
    'SMT'
    );

CALL AddPackage(
    "SOD-723",
    'SMT'
    );

CALL AddPackage(
    "SOD-923",
    'SMT'
    );

CALL AddPackage(
    "SOT-23",
    'SMT'
    );

CALL AddPackage(
    "SOT-363",
    'SMT'
    );

CALL AddPackage(
    "SOT-563",
    'SMT'
    );

CALL AddPackage(
    "SOT-723",
    'SMT'
    );

CALL AddPackage(
    "TO-92",
    'TH'
    );


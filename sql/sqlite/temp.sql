INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3055AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3055AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3055AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        15,
        2500000.000000,
        115
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3055AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3055G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3055G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3055G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        15,
        2500000.000000,
        115
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3055G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3442G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3442G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3442G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        10,
        80000.000000,
        117
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3442G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3771G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3771G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3771G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        30,
        NULL,
        150
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3771G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3772G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3772G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3772G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        20,
        NULL,
        150
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3772G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3773G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3773G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3773G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        16,
        4000000.000000,
        150
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3773G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3904ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3904ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3904ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3906G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3906G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3906RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3906RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3906RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3906RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3906RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3906RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N3906RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N3906RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N3906RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4124G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4124G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4124G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4124G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4401G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4401G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4401RLRA',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401RLRA'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4401RLRA'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401RLRA'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4401RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4401RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4401RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4401RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4401RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4403G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4403G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4403RLRA',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403RLRA'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4403RLRA'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403RLRA'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4403RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4403RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4403RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4403RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4403RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4918G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4918G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4918G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4918G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4919G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4919G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4919G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4919G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4920G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4920G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4920G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4920G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4921G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4921G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4921G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4921G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4922G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4922G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4922G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4922G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N4923G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4923G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N4923G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N4923G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5038G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5038G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5038G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        20,
        60000000.000000,
        140
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5038G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5087G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5087G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5087G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        40000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5087G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5087RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5087RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5087RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        40000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5087RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5088G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5088G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5088G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5088G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5089G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5089G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5089G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5089G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5190G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5190G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5190G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        2000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5190G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5191G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5191G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5191G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        2000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5191G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5192G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5192G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5192G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        2000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5192G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5194G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5194G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5194G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        2000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5194G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5195G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5195G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5195G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        2000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5195G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5302G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5302G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5302G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        30,
        2000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5302G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5401G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5401G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5401G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5401G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5401RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5401RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5401RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5401RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5550G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5550G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5550G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5550G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5550RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5550RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5550RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5550RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5551G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5551G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5551RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5551RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5551RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5551RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5551RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5551RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5551ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5551ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5551ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5655G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5655G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5655G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1,
        10000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5655G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5657G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5657G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5657G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1,
        10000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5657G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5684G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5684G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5684G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        50,
        2000000.000000,
        300
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5684G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5686G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5686G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5686G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        50,
        2000000.000000,
        300
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5686G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5883G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5883G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5883G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        25,
        4000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5883G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5884G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5884G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5884G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        25,
        4000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5884G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5885G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5885G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5885G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        25,
        4000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5885G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N5886G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5886G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N5886G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        25,
        4000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N5886G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6107G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6107G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6107G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        7,
        4000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6107G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6109G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6109G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6109G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        7,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6109G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6111G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6111G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6111G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        7,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6111G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6288G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6288G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6288G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        7,
        4000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6288G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6292G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6292G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6292G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        7,
        4000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6292G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6338G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6338G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6338G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        25,
        40000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6338G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6341G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6341G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6341G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        25,
        40000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6341G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6487G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6487G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6487G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        5000000.000000,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6487G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6488G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6488G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6488G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        5000000.000000,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6488G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6490G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6490G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6490G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        5000000.000000,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6490G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6491G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6491G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6491G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        5000000.000000,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6491G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2N6520RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6520RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2N6520RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        40000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2N6520RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SA1020RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA1020RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SA1020RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA1020RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SA1774G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA1774G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SA1774G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        NULL,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA1774G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SA1774T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA1774T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SA1774T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        NULL,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA1774T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SA2029M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA2029M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SA2029M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.1,
        NULL,
        0.265
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SA2029M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SC4617G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SC4617G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SC4617G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        180000000.000000,
        0.125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SC4617G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SC4617T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SC4617T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SC4617T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        180000000.000000,
        0.125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SC4617T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        '2SC5658M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SC5658M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = '2SC5658M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.1,
        180000000.000000,
        0.26
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = '2SC5658M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC237BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC237BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC237BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.35
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC237BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC237BRL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC237BRL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC237BRL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.35
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC237BRL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC307BRL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC307BRL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC307BRL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.35
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC307BRL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC327-025G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-025G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC327-025G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-025G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC327-25RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-25RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC327-25RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-25RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC327-25ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-25ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC327-25ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-25ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC327-40ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-40ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC327-40ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC327-40ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337-025G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-025G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337-025G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-025G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337-040G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-040G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337-040G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-040G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337-25RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-25RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337-25RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-25RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337-25ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-25ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337-25ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-25ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337-40RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-40RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337-40RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-40RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337-40ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-40ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337-40ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337-40ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC337RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC337RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.8,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC337RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC369ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC369ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC369ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        65000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC369ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC490G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC490G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC490G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC490G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC546BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC546BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC546BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC546BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC546BRL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC546BRL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC546BRL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC546BRL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC546BZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC546BZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC546BZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC546BZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC547BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC547BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC547BRL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547BRL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC547BRL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547BRL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC547BZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547BZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC547BZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547BZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC547CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC547CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC547CZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547CZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC547CZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC547CZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC548BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC548BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC548BRL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548BRL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC548BRL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548BRL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC548BZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548BZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC548BZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548BZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC548CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC548CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC548CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC549CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC549CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC549CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC549CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC550CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC550CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC550CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC550CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC556BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC556BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC556BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC556BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC557BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC557BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC557BRL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557BRL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC557BRL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557BRL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC557BZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557BZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC557BZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557BZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC557CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC557CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC557CZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557CZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC557CZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC557CZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC558BRLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC558BRLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC558BRLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC558BRLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC560CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC560CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC560CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC560CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC637G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC637G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC637G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC637G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC639-16ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639-16ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC639-16ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639-16ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC639G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC639G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC639RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC639RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC639ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC639ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC639ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC640-016G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC640-016G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC640-016G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC640-016G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-16LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-16LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-16LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-16LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-16LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-16LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-16LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-16LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-16LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-16LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-16LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-16LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-25LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-25LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-25LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-25LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-25LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-25LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-25LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-25LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-25LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-25LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-25LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-25LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-40LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-40LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-40LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-40LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-40LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-40LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-40LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-40LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC807-40LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-40LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC807-40LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC807-40LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC808-25LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC808-25LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC808-25LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC808-25LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-16LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-16LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-16LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-16LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-16LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-16LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-16LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-16LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-25LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-25LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-25LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-25LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-25LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-25LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-25LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-25LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-25LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-25LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-25LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-25LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-40LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-40LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-40LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-40LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC817-40LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-40LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC817-40LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC817-40LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC818-40LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC818-40LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC818-40LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC818-40LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846ALT3',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846ALT3'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846ALT3'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846ALT3'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846ALT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846ALT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846ALT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846ALT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846BDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846BDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846BLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846BLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846BM3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BM3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846BM3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.1,
        100000000.000000,
        0.265
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BM3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC846BWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC846BWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC846BWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847AWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847AWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847AWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847AWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BDW1T3',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BDW1T3'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BDW1T3'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BDW1T3'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BDW1T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BDW1T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BDW1T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BDW1T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BLT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BLT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BLT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BLT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BM3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BM3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BM3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.1,
        100000000.000000,
        0.26
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BM3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BTT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BTT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BTT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        100000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BTT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847BWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847BWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847BWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847CDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847CDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847CDXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CDXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847CDXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        100000000.000000,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CDXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847CLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847CLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847CTT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CTT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847CTT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        100000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CTT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC847CWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC847CWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC847CWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848BLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848BLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848BLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848BLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848BWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848BWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848BWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848BWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848CDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848CDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848CDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848CDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC848CWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848CWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC848CWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC848CWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC849BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC849BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC849BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC849BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC849CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC849CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC849CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC849CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC850BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC850BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC850BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC850BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC850CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC850CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC850CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC850CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BDW1T3',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BDW1T3'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BDW1T3'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BDW1T3'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BDW1T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BDW1T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BDW1T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BDW1T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BM3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BM3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BM3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.1,
        100000000.000000,
        0.265
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BM3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC856BWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC856BWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC856BWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857BDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857BDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857BLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857BLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857BTT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BTT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857BTT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.1,
        100000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BTT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857BWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857BWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857BWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857CDW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CDW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857CDW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CDW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857CLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857CLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        -0.1,
        100000000.000000,
        0.3
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC857CWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC857CWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC857CWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858AWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858AWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858AWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858AWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858BLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858BLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858BLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858BLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858BLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858BLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858BLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858BLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858BWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858BWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858BWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858BWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858CDXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858CDXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858CDXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        100000000.000000,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858CDXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BC858CLT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858CLT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BC858CLT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BC858CLT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP53-10T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-10T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP53-10T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-10T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP53-10T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-10T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP53-10T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-10T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP53-16T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-16T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP53-16T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-16T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP53-16T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-16T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP53-16T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53-16T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP53T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP53T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP53T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP53T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP53T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56-10T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-10T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56-10T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-10T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56-10T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-10T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56-10T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-10T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56-16T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56-16T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56-16T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56-16T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56-16T3',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T3'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56-16T3'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T3'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56-16T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56-16T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56-16T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP56T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP56T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP56T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP68T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP68T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP68T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP68T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCP69T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP69T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCP69T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        1,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCP69T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW30LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW30LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW30LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW30LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW32LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW32LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW32LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW32LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW33LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW33LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW33LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW33LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW33LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW33LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW33LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW33LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW65ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW65ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW65ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.8,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW65ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW65CLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW65CLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW65CLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.8,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW65CLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW66GLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW66GLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW66GLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.8,
        100000000.000000,
        
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW66GLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW68GLT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW68GLT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW68GLT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.8,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW68GLT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW70LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW70LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW70LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW70LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCW72LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW72LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCW72LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCW72LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCX17LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCX17LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCX17LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCX17LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BCX19LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCX19LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BCX19LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BCX19LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD135G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD135G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD135G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        NULL,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD135G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD136G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD136G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD136G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        NULL,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD136G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD137G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD137G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD137G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        NULL,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD137G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD138G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD138G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD138G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        NULL,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD138G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD139G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD139G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD139G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        NULL,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD139G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD140G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD140G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD140G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        NULL,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD140G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD159G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD159G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD159G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        0.5,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD159G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD179G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD179G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD179G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD179G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD180G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD180G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD180G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD180G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD234G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD234G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD234G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        2,
        3000000.000000,
        25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD234G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD237G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD237G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD237G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        2,
        3000000.000000,
        25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD237G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD241CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD241CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD241CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD241CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD242BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD242BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD242BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD242BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD242CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD242CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD242CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD242CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD243CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD243CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD243CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD243CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD244BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD244BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD244BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD244BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD244CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD244CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD244CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD244CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD435G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD435G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD435G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD435G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD436TG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD436TG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD436TG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD436TG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD437G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD437G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD437G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD437G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD437TG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD437TG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD437TG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD437TG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD438G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD438G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD438G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD438G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD439G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD439G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD439G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD439G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD440G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD440G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD440G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD440G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD441G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD441G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD441G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD441G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD442G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD442G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD442G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        3000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD442G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD787G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD787G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD787G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        50000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD787G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD788G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD788G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD788G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        50000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD788G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD809G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD809G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD809G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        1500000.000000,
        90
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD809G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BD810G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD810G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BD810G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        1500000.000000,
        90
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BD810G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BF422G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF422G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BF422G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        60000000.000000,
        0.83
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF422G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BF423ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF423ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BF423ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        60000000.000000,
        0.83
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF423ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BF493SG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF493SG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BF493SG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF493SG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BF720T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF720T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BF720T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.1,
        60000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF720T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BF721T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF721T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BF721T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.1,
        60000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BF721T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BSP16T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSP16T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BSP16T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.1,
        15000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSP16T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BSP19AT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSP19AT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BSP19AT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.1,
        70000000.000000,
        0.8
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSP19AT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BSS63LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSS63LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BSS63LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSS63LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BSS64LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSS64LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BSS64LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        60000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BSS64LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BU406G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BU406G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BU406G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        7,
        10000000.000000,
        60
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BU406G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUD42D-1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUD42D-1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUD42D-1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        4,
        NULL,
        25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUD42D-1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUD42DT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUD42DT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUD42DT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        4,
        NULL,
        25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUD42DT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUH100G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUH100G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUH100G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        23000000.000000,
        100
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUH100G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUH150G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUH150G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUH150G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        23000000.000000,
        150
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUH150G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUH50G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUH50G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUH50G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        4,
        4000000.000000,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUH50G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUL45D2G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUL45D2G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUL45D2G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        5,
        NULL,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUL45D2G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUL45G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUL45G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUL45G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        5,
        NULL,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUL45G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUV21G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV21G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUV21G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        40,
        8000000.000000,
        250
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV21G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUV22G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV22G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUV22G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        40,
        8000000.000000,
        250
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV22G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUV26G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV26G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUV26G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        20,
        NULL,
        85
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV26G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUV27G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV27G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUV27G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        12,
        NULL,
        70
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUV27G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'BUX85G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUX85G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'BUX85G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        2,
        4000000.000000,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'BUX85G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D44C12G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44C12G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D44C12G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        4,
        NULL,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44C12G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D44H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D44H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D44H8G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44H8G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D44H8G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44H8G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D44VH10G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44VH10G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D44VH10G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        NULL,
        83
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D44VH10G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D45C12G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45C12G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D45C12G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        4,
        NULL,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45C12G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D45H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D45H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D45H8G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45H8G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D45H8G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45H8G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'D45VH10G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45VH10G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'D45VH10G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        15,
        NULL,
        83
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'D45VH10G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'EMT1DXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMT1DXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'EMT1DXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        NULL,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMT1DXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'EMT1DXV6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMT1DXV6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'EMT1DXV6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        NULL,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMT1DXV6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'EMX1DXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMX1DXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'EMX1DXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        NULL,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMX1DXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'EMX1DXV6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMX1DXV6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'EMX1DXV6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        NULL,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMX1DXV6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'EMX2DXV6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMX2DXV6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'EMX2DXV6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        NULL,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'EMX2DXV6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MBT2222ADW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT2222ADW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MBT2222ADW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.6,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT2222ADW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MBT3904DW1T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3904DW1T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MBT3904DW1T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.2,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3904DW1T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MBT3904DW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3904DW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MBT3904DW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.2,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3904DW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MBT3904DW1T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3904DW1T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MBT3904DW1T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.2,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3904DW1T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MBT3906DW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3906DW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MBT3906DW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.2,
        250000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT3906DW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MBT6429DW1T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT6429DW1T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MBT6429DW1T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.2,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MBT6429DW1T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJ14002G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ14002G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJ14002G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        60,
        NULL,
        300
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ14002G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJ2955G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ2955G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJ2955G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        15,
        2500000.000000,
        115
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ2955G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJ4502G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ4502G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJ4502G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        30,
        2000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ4502G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-204'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-204');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJ802G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ802G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJ802G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-204'),
        30,
        2000000.000000,
        200
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJ802G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB41CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB41CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB41CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB41CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB41CT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB41CT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB41CT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB41CT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB42CT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB42CT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB42CT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB42CT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB44H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB44H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB44H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        8,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB44H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB44H11T4',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB44H11T4'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB44H11T4'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        8,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB44H11T4'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB44H11T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB44H11T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB44H11T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        8,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB44H11T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB45H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB45H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB45H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        8,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB45H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB45H11T4',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB45H11T4'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB45H11T4'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        8,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB45H11T4'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'D2PAK'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'D2PAK');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJB45H11T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB45H11T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJB45H11T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'D2PAK'),
        8,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJB45H11T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD148T4',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD148T4'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD148T4'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        4,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD148T4'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD148T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD148T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD148T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        4,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD148T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD200G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD200G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD200G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        65000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD200G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD200RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD200RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD200RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        65000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD200RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD200T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD200T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD200T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        65000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD200T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD210G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD210G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        3000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD210RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD210RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        3000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD210T4',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210T4'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD210T4'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        3000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210T4'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD210T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD210T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        5,
        3000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD210T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD243G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD243G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD243G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        4,
        40000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD243G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD243T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD243T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD243T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        4,
        40000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD243T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD253-1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD253-1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD253-1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        4,
        40000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD253-1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD253T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD253T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD253T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        4,
        40000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD253T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD2955-1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD2955-1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD2955-1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        10,
        2000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD2955-1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD2955G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD2955G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD2955G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        10,
        2000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD2955G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD2955T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD2955T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD2955T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        10,
        2000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD2955T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD3055G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD3055G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD3055G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        10,
        2000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD3055G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD3055T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD3055T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD3055T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        10,
        2000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD3055T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD31C1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31C1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD31C1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31C1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD31CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD31CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD31CRLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31CRLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD31CRLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31CRLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD31CT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31CT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD31CT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31CT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD31T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD31T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD31T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD32CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD32CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD32CRLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CRLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD32CRLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CRLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD32CT4',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CT4'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD32CT4'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CT4'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD32CT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD32CT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32CT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD32RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD32RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD32T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD32T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        3,
        3000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD32T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD340G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD340G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD340G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        0.5,
        NULL,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD340G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD340RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD340RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD340RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        0.5,
        NULL,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD340RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD340T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD340T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD340T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        0.5,
        NULL,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD340T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD350G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD350G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD350G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        0.5,
        NULL,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD350G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD350T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD350T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD350T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        0.5,
        NULL,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD350T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD41CRLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD41CRLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD41CRLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        6,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD41CRLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD41CT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD41CT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD41CT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        6,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD41CT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD42C1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42C1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD42C1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        6,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42C1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD42CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD42CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        6,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD42CRLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42CRLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD42CRLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        6,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42CRLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD42CT4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42CT4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD42CT4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        6,
        3000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD42CT4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD44E3T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44E3T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD44E3T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        10,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44E3T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD44H11-1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11-1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD44H11-1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11-1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD44H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD44H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD44H11RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD44H11RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD44H11T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD44H11T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD44H11T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD44H11T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD44H11T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-3'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-3');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD45H11-1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11-1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD45H11-1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-3'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11-1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD45H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD45H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD45H11RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD45H11RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD45H11T4',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11T4'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD45H11T4'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11T4'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD45H11T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD45H11T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        8,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD45H11T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD47G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD47G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD47G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        1,
        10000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD47G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD47T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD47T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD47T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        1,
        10000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD47T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD50G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD50G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD50G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        1,
        10000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD50G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD50T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD50T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD50T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        1,
        10000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD50T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJD5731T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD5731T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJD5731T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        1,
        10000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJD5731T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE13003G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13003G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE13003G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        1.5,
        4000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13003G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE13005G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13005G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE13005G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        4,
        4000000.000000,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13005G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE13007G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13007G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE13007G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        4000000.000000,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13007G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE13009G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13009G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE13009G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        12,
        4000000.000000,
        100
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE13009G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE15033G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE15033G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE15033G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        30000000.000000,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE15033G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE170G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE170G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE170G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        50000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE170G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE171G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE171G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE171G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        50000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE171G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE172G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE172G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE172G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        50000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE172G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE18002G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18002G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE18002G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        2,
        NULL,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18002G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE18004G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18004G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE18004G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        5,
        NULL,
        75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18004G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE18006G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18006G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE18006G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        14000000.000000,
        100
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18006G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE18008G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18008G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE18008G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        13000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE18008G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE180G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE180G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE180G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        50000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE180G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE181G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE181G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE181G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        5000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE181G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE182G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE182G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE182G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        3,
        50000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE182G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE200G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE200G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE200G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        5,
        65000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE200G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE210G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE210G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE210G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        5,
        65000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE210G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE210TG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE210TG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE210TG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        5,
        65000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE210TG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE243G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE243G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE243G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        40000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE243G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE253G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE253G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE253G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        40000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE253G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE2955TG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE2955TG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE2955TG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        2000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE2955TG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE3055TG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE3055TG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE3055TG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        2000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE3055TG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE340G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE340G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE340G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        0.5,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE340G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE3439G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE3439G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE3439G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        0.3,
        15000000.000000,
        15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE3439G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE344G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE344G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE344G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        0.5,
        15000000.000000,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE344G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE350G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE350G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE350G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        0.5,
        NULL,
        20
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE350G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-225'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-225');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE371G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE371G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE371G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-225'),
        4,
        NULL,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE371G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE4343G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE4343G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE4343G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        16,
        1000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE4343G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE4353G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE4353G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE4353G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        16,
        1000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE4353G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE5730G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5730G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE5730G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5730G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE5731AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5731AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE5731AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5731AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE5731G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5731G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE5731G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5731G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE5850G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5850G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE5850G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        NULL,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5850G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE5851G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5851G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE5851G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        NULL,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5851G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJE5852G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5852G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJE5852G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        NULL,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJE5852G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF15030G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF15030G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF15030G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        30000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF15030G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF15031G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF15031G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF15031G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        30000000.000000,
        36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF15031G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF18004G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF18004G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF18004G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        5,
        NULL,
        35
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF18004G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF18008G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF18008G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF18008G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        8,
        NULL,
        45
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF18008G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF2955G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF2955G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF2955G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        2000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF2955G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF3055G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF3055G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF3055G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        2000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF3055G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF31CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF31CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF31CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF31CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF32CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF32CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF32CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF32CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF44H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF44H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF44H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF44H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF45H11G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF45H11G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF45H11G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        10,
        NULL,
        50
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF45H11G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJF47G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF47G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJF47G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        28
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJF47G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-247'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-247');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MJW18020G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJW18020G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MJW18020G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-247'),
        20,
        NULL,
        250
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MJW18020G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-74'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-74');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2131T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2131T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2131T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-74'),
        0.7,
        NULL,
        0.342
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2131T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222ALT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ALT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222ALT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ALT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222ALT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ALT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222ALT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ALT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222AM3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222AM3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222AM3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.6,
        300000000.000000,
        0.64
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222AM3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222ATT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ATT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222ATT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.6,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ATT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222ATT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ATT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222ATT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.6,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222ATT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222AWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222AWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222AWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.6,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222AWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2222LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2222LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2222LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2484LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2484LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2484LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2484LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2484LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2484LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2484LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2484LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2907ALT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907ALT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2907ALT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        200000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907ALT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2907ALT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907ALT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2907ALT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        200000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907ALT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2907ALT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907ALT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2907ALT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        200000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907ALT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2907AM3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907AM3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2907AM3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        -0.6,
        200000000.000000,
        0.64
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907AM3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT2907AWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907AWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT2907AWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.6,
        200000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT2907AWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3416LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3416LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3416LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3416LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3904LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3904LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3904LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3904LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3904LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3904LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3904TT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904TT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3904TT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.2,
        300000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904TT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3904WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3904WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.2,
        300000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3904WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3906LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3906LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3906LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3906LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3906LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3906LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-75'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-75');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3906TT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906TT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3906TT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-75'),
        0.2,
        250000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906TT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT3906WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT3906WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.2,
        250000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT3906WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4124LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4124LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4124LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        300000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4124LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4126LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4126LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4126LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4126LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4401LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4401LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4401LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4401LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4401LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4401LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        250000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4401M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4401M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.6,
        250000000.000000,
        0.64
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4401WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4401WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.6,
        250000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4401WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4403LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4403LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        200000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4403LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4403LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        200000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4403LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4403LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.6,
        200000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4403M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4403M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        -0.6,
        200000000.000000,
        0.64
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT4403WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT4403WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.6,
        200000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT4403WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT489LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT489LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT489LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        1,
        100000000.000000,
        0.31
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT489LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5087LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5087LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5087LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.05,
        40000000.000000,
        0.25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5087LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5087LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5087LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5087LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.05,
        40000000.000000,
        0.25
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5087LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5088LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5088LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5088LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.05,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5088LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5089LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5089LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5089LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.05,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5089LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5401LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5401LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5401LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5401LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5401LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5401LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5401LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5401LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5401LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5401LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5401LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5401LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5550LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5550LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5550LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.06,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5550LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5550LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5550LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5550LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.06,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5550LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5551LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5551LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.06,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5551LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5551LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.06,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5551LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5551LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.06,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT5551M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT5551M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.06,
        NULL,
        0.64
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT5551M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6428LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6428LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6428LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6428LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6429LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6429LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6429LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.2,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6429LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6517LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6517LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6517LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        40000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6517LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6517LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6517LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6517LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        40000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6517LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6517LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6517LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6517LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        40000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6517LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6520LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6520LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6520LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        40000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6520LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6520LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6520LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6520LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        40000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6520LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT6521LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6521LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT6521LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        NULL,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT6521LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBT8099LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT8099LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBT8099LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        150000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBT8099LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA05LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA05LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA05LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA05LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA05LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA05LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA05LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA05LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA06LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA06LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA06LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA06LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA06LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA06LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        100000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA06WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA06WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.5,
        100000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA06WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA42LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA42LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA42LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA42LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA42LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA42LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA42LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA42LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA42LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA42LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA42LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA42LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA55LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA55LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA55LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA55LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA56LT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56LT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA56LT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56LT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA56LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA56LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA56LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA56LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA56WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA56WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.5,
        50000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA56WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA70LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA70LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA70LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.1,
        125000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA70LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA92LT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA92LT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA92LT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA92LT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-23'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-23');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTA92LT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA92LT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTA92LT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-23'),
        0.5,
        50000000.000000,
        0.225
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTA92LT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMBTH10M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTH10M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMBTH10M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        ,
        650000000.000000,
        0.64
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMBTH10M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MMJT350T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMJT350T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MMJT350T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.5,
        NULL,
        2.75
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MMJT350T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222ARLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222ARLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222ARLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222ARLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222ARLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222ARLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222ARLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222ARLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222ARLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2222RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2222RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        250000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2222RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2907AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2907AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2907ARLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907ARLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2907ARLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907ARLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2907ARLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907ARLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2907ARLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907ARLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS2907ARLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907ARLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS2907ARLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS2907ARLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS4124RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS4124RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS4124RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        170000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS4124RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS4250G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS4250G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS4250G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        ,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS4250G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS5172RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS5172RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS5172RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS5172RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS650G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS650G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS650G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS650G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS650RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS650RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS650RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS650RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS650ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS650ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS650ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS650ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS651G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS651G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS651G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS651G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS651RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS651RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS651RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS651RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS651RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS651RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS651RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS651RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS6652G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS6652G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS6652G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS6652G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS6652RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS6652RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS6652RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS6652RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS6726G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS6726G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS6726G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        NULL,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS6726G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS750RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS750RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS750RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS750RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS751G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS751G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS751RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS751RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS751RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS751RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS751ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS751ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        2,
        75000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS751ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS8099G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS8099G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS8099G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS8099G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPS8099RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS8099RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPS8099RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPS8099RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA05G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA05G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA05G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA05G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA05RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA05RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA05RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA05RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA05RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA05RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA05RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA05RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA06G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA06G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA06RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA06RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA06RLG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA06RLG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA06RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA06RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA06RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA06RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA06RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA06RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA06RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA18RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA18RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA18RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA18RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA18RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA18RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA18RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.2,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA18RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA42G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA42G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA42RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA42RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA42RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA42RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA42RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA42RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA42RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA42RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA42ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA42ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.05,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA42ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA44G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA44G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA44G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.3,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA44G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA44RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA44RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA44RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.3,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA44RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA44RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA44RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA44RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.3,
        NULL,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA44RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA55G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA55G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA55G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA55G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA55RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA55RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA55RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.1,
        150000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA55RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA56G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA56G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA56RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA56RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA56RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA56RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA56RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA56RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA56ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA56ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        100000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA56ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA92G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA92G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA92RL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA92RL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA92RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA92RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA92RLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA92RLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA92RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA92RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSA92ZL1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92ZL1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSA92ZL1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSA92ZL1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW01AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW01AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        2.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW01ARLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01ARLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW01ARLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        2.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01ARLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW01ARLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01ARLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW01ARLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        2.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01ARLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW01G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW01G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        2.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW01G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW05G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW05G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW05G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW05G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW06G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW06G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW06G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW06G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW06RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW06RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW06RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW06RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW42G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW42G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW42G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW42G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW42RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW42RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW42RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW42RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW51AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW51AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW51ARLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51ARLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW51ARLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51ARLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW51ARLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51ARLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW51ARLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51ARLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW51G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW51G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        1,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW51G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW55G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW55G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW55G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW55G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW56RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW56RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW56RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW56RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW56RLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW56RLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW56RLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW56RLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MPSW92RLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW92RLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MPSW92RLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.5,
        50000000.000000,
        1
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MPSW92RLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSA1162GT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSA1162GT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSA1162GT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        80000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSA1162GT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSA1162GT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSA1162GT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSA1162GT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        80000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSA1162GT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSA1162YT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSA1162YT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSA1162YT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        80000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSA1162YT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSB1218A-RT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB1218A-RT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSB1218A-RT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        NULL,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB1218A-RT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSB709-RT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB709-RT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSB709-RT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        NULL,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB709-RT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSB92ASWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB92ASWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSB92ASWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.5,
        50000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB92ASWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSB92AWT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB92AWT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSB92AWT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.5,
        50000000.000000,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB92AWT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSB92WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB92WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSB92WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.5,
        NULL,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSB92WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSC2712GT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSC2712GT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSC2712GT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        50000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSC2712GT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSC2712GT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSC2712GT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSC2712GT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        50000000.000000,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSC2712GT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSD1328-RT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD1328-RT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSD1328-RT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.5,
        NULL,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD1328-RT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSD1819A-RT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD1819A-RT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSD1819A-RT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.1,
        NULL,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD1819A-RT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-70'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-70');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSD42WT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD42WT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSD42WT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-70'),
        0.15,
        NULL,
        0.15
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD42WT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSD601-RT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD601-RT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSD601-RT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.1,
        NULL,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD601-RT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-59'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-59');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'MSD602-RT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD602-RT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'MSD602-RT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-59'),
        0.5,
        NULL,
        0.2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'MSD602-RT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'DPAK-4'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'DPAK-4');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NJD2873T4G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NJD2873T4G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NJD2873T4G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'DPAK-4'),
        2,
        65000000.000000,
        12.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NJD2873T4G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NJT4030PT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NJT4030PT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NJT4030PT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        3,
        100000000.000000,
        2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NJT4030PT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NJT4030PT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NJT4030PT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NJT4030PT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        3,
        100000000.000000,
        2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NJT4030PT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-723'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-723');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NS2029M3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NS2029M3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NS2029M3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-723'),
        0.1,
        NULL,
        0.265
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NS2029M3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NSS40300MZ4T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS40300MZ4T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NSS40300MZ4T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        3,
        100000000.000000,
        2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS40300MZ4T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NSS40300MZ4T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS40300MZ4T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NSS40300MZ4T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        3,
        100000000.000000,
        2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS40300MZ4T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NSS60600MZ4T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS60600MZ4T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NSS60600MZ4T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        6,
        100000000.000000,
        2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS60600MZ4T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NSS60600MZ4T3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS60600MZ4T3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NSS60600MZ4T3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        6,
        100000000.000000,
        2
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NSS60600MZ4T3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST30010MXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST30010MXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST30010MXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.1,
        100000000.000000,
        0.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST30010MXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-963'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-963');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3904DP6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904DP6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3904DP6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-963'),
        0.2,
        200000000.000000,
        0.42
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904DP6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3904DXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904DXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3904DXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.2,
        300000000.000000,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904DXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3904DXV6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904DXV6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3904DXV6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.2,
        300000000.000000,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904DXV6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3904F3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904F3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3904F3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        0.2,
        200000000.000000,
        0.36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3904F3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-963'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-963');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3906DP6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3906DP6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3906DP6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-963'),
        0.2,
        250000000.000000,
        0.42
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3906DP6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-563'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-563');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3906DXV6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3906DXV6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3906DXV6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-563'),
        0.2,
        250000000.000000,
        0.357
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3906DXV6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST3906F3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3906F3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST3906F3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        0.2,
        250000000.000000,
        0.36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST3906F3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST45010MW6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST45010MW6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST45010MW6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        -0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST45010MW6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SC-88'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SC-88');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST45011MW6T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST45011MW6T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST45011MW6T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SC-88'),
        0.1,
        100000000.000000,
        0.38
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST45011MW6T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TSOP-6'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TSOP-6');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST489AMT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST489AMT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST489AMT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TSOP-6'),
        2,
        200000000.000000,
        0.535
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST489AMT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST846BF3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST846BF3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST846BF3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        0.1,
        100000000.000000,
        0.347
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST846BF3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-963'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-963');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST847BDP6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST847BDP6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST847BDP6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-963'),
        0.1,
        100000000.000000,
        0.42
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST847BDP6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST847BF3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST847BF3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST847BF3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        0.1,
        100000000.000000,
        0.36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST847BF3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST848BF3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST848BF3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST848BF3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        0.1,
        100000000.000000,
        0.347
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST848BF3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST856BF3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST856BF3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST856BF3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        -0.1,
        100000000.000000,
        0.347
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST856BF3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-963'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-963');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST857BDP6T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST857BDP6T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST857BDP6T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-963'),
        0.1,
        100000000.000000,
        420
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST857BDP6T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-1123'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-1123');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'NST857BF3T5G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST857BF3T5G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'NST857BF3T5G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-1123'),
        0.1,
        100000000.000000,
        0.36
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'NST857BF3T5G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'P2N2222AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'P2N2222AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'P2N2222AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'P2N2222AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PN2222AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PN2222AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PN2222ARLRAG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222ARLRAG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PN2222ARLRAG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222ARLRAG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PN2222ARLRMG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222ARLRMG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PN2222ARLRMG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222ARLRMG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-92'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-92');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PN2222ARLRPG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222ARLRPG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PN2222ARLRPG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-92'),
        0.6,
        300000000.000000,
        0.625
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PN2222ARLRPG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2222AT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2222AT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        300000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2222AT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2222AT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        300000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2222AT3',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT3'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2222AT3'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        300000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT3'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2222AT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2222AT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        300000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2222AT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2907AT1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2907AT1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2907AT1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2907AT1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2907AT1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2907AT1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2907AT1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2907AT1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT2907AT3G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2907AT3G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT2907AT3G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.6,
        200000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT2907AT3G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT3904T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT3904T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT3904T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.2,
        300000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT3904T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT3904T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT3904T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT3904T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.2,
        300000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT3904T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT651T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT651T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT651T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        2,
        75000000.000000,
        0.8
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT651T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT651T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT651T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT651T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        2,
        75000000.000000,
        0.8
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT651T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT751T1',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT751T1'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT751T1'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        2,
        75000000.000000,
        0.8
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT751T1'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZT751T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT751T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZT751T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        2,
        75000000.000000,
        0.8
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZT751T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZTA42T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZTA42T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZTA42T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.5,
        50000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZTA42T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZTA92T1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZTA92T1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZTA92T1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.5,
        50000000.000000,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZTA92T1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-223'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-223');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'PZTA96ST1G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZTA96ST1G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'PZTA96ST1G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-223'),
        0.5,
        NULL,
        1.5
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'PZTA96ST1G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP2955G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP2955G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP2955G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        15,
        2500000.000000,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP2955G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP29AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP29AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP29AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP29AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP29BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP29BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP29BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP29BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP29CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP29CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP29CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP29CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP3055G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP3055G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP3055G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        15,
        2500000.000000,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP3055G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP30CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP30CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP30CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        3000000.000000,
        30
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP30CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP31AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP31AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP31BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP31BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP31CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP31CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP31G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP31G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP31G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP32AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP32AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP32BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP32BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP32CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP32CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP32G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP32G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        3,
        3000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP32G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP33CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP33CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP33CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        10,
        3000000.000000,
        80
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP33CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP35AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP35AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP35AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        25,
        3000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP35AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP35CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP35CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP35CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        25,
        3000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP35CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP36AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP36AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP36AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        25,
        3000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP36AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'SOT-93'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'SOT-93');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP36CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP36CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP36CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'SOT-93'),
        25,
        3000000.000000,
        125
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP36CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP41AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP41AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP41AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP41AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP41BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP41BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP41BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP41BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP41CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP41CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP41CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP41CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP42AG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42AG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP42AG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42AG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP42BG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42BG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP42BG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42BG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP42CG',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42CG'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP42CG'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42CG'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'pnp'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'pnp');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP42G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'pnp')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP42G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        6,
        3000000.000000,
        65
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP42G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP47G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP47G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP47G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP47G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP48G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP48G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP48G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP48G'
             );

INSERT INTO Company ( CompanyName )
    SELECT
        'ON Semiconductor'
    WHERE NOT EXISTS
        (SELECT * FROM Company WHERE CompanyName = 'ON Semiconductor');

INSERT INTO Device ( DeviceName )
    SELECT
        'npn'
    WHERE NOT EXISTS
        (SELECT * FROM Device WHERE DeviceName = 'npn');

INSERT INTO Package ( PackageName )
    SELECT
        'TO-220'
    WHERE NOT EXISTS
        (SELECT * FROM Package WHERE PackageName = 'TO-220');

INSERT INTO Part (CompanyID, PartNumber, DeviceID)
    SELECT 
        (SELECT CompanyID FROM Company WHERE CompanyName = 'ON Semiconductor'),
        'TIP50G',
        (SELECT DeviceID FROM Device WHERE DeviceName = 'npn')
    WHERE NOT EXISTS
        (SELECT * FROM Part
            JOIN Company USING ( CompanyID )
        WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP50G'
        );

INSERT INTO BJT (PartID, PackageID, IC, FT, PD)
    SELECT
        (SELECT PartID FROM Part WHERE PartNumber = 'TIP50G'),
        (SELECT PackageID FROM Package WHERE PackageName = 'TO-220'),
        1,
        10000000.000000,
        40
    WHERE NOT EXISTS
        (SELECT * FROM BJT
             JOIN Part USING ( PartID )
             JOIN Company USING ( CompanyID )
             WHERE CompanyName = 'ON Semiconductor' AND PartNumber = 'TIP50G'
             );


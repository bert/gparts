#!/usr/bin/python
##
##
##
##

print "CALL AddCompany("
print "    'Vishay-Sprague'"
print "    );"
print

##############################################################################
##
##  593D Series Solid Tantalum Chip Capacitors
##
##############################################################################

capacitances = [
    ( "107", 0.0 ),
    ( "108", 0.0 ),
    ( "109", 0.0 ),
    ( "110", 0.0 )
    ]

packages = [
    ( "A", "EIA-3216-18" ),
    ( "B", "EIA-3528-21" ),
    ( "C", "EIA-6032-28" ),
    ( "D", "EIA-7343-31" ),
    ( "E", "EIA-7343-43" ),
    ( "V", "EIA-7343-20" )
    ]

voltages = [
    ( "004",  4.0 ),
    ( "6R3",  6.3 ),
    ( "010", 10.0 ),
    ( "016", 16.0 ),
    ( "020", 20.0 ),
    ( "025", 25.0 ),
    ( "035", 35.0 ),
    ( "050", 50.0 )
    ]

for capacitance in capacitances:
    for package in packages:
        for voltage in voltages:
            print "CALL AddCapacitor("
            print "    'Vishay-Sprague',"
            print "    '593D-%sX9%s%s'," % ( capacitance[0], voltage[0], package[0] )
            print "    '%s'," % package[1]
            print "    'CAPACITOR',"
            print "    %f" % capacitance[1]
            print "    );"
            print


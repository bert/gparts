#!/usr/bin/python
##############################################################################
##
##  Extracts data from the existing symbol library for GPart's database.
##
##  The command line parameter (required) specifies the top level gEDA
##  directory.
##
##############################################################################

import os
import re
import sys
import csv

company = "ON Semiconductor"

csv_file = "../tmp/onsemi-switching-diodes.csv"

print "CALL AddCompany("
print "    '%s'" % company
print "    );"
print

def process(input):

    for line in input:
        print "CALL AddDiode("
        print "    '%s'," % company
        print "    '%s'," % line[0]
        print "    '%s'," % line[9].partition(' ')[0]
        print "    '%s'," % 'DIODE'
        print "     %s,"  % line[4]
        print "     %s,"  % line[5]
        print "     %s"   % 'NULL'
        print "    );"
        print

if __name__ == "__main__":
    input = csv.reader(open(csv_file, "r"))
    process(input)

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

top = sys.argv[1]

pattern = re.compile( "^(.+?)=(.*)$", re.M )

## Parse symbol directories and return a list of the symbol files.  The symbol
## files include path relative to the top level gEDA directory.
##
## TODO Filter out non-symbol files.
##
def get_symbols():
    dirs = [ 'sym' ]
    symbols = list()
    for dir in dirs:
        files = os.listdir( os.path.join( top, dir ) )
        for file in files:
            path = os.path.join( dir, file )
            if os.path.isdir( os.path.join( top, path ) ):
                dirs.append( path )
            else:
                symbols.append( path )
    return symbols

## Output SQL commands to add details (comments) to the database.
##
## TODO Add code to escape any double quotes in the comment string.
##
def output_details( devices ):
    for ( symbol, attributes ) in devices.iteritems():
        if 'comment' in attributes:
            for comment in attributes['comment']:
                print "CALL AddSymbolDetail("
                print "    '%s'," % symbol
                print "    \"%s\"" % comment
                print "    );"
                print

## Output SQL commands to add devices to the database.
##
def output_devices( devices ):
    output = dict()
    for device in devices.itervalues():
        for name in device.get( 'device', list() ):
            if name not in output:
                print "CALL AddDevice("
                print "    '%s'" % name
                print "    );"
                print
                output[name] = 1

## Output SQL commands to add symbols to the database.
##
def output_symbols( devices ):
    for ( symbol, attributes ) in devices.iteritems():
        if 'device' in attributes:
            print "CALL AddSymbol("
            print "    '%s'," % attributes['device'][0]
            print "    '%s'" % os.path.basename(symbol)
            print "    );"
            print

##  Parses symbol files for attributes.  Returns a dictionary mapping symbol
##  filenames to another dictionary.  The next dictionary maps attribute names
##  to a list of attribute values.
##
def parse_symbols( symbols ):
    devices = dict()
    for symbol in symbols:
        attributes = devices.setdefault( symbol, dict() )
        file = os.path.join( top, symbol )
        data = open( file, 'r' ).read()
        for match in pattern.finditer( data ):
            name = match.group( 1 )
            value = match.group( 2 )
            attributes.setdefault( name, list() ).append( value )
    return devices


if __name__ == "__main__":
    symbols = get_symbols()
    devices = parse_symbols( symbols )
    output_devices( devices )
    output_symbols( devices )
    output_details( devices )


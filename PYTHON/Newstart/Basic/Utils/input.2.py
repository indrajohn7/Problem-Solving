#!/usr/bin/python

# Open a file
fo = open("data.txt", "r+")
str = fo.read(10);
print "Read String is : ", str

# Check current position
position = fo.tell();
print "Current file position : ", position

# Reposition pointer at the beginning once again
position = fo.seek(10, 1);
### file.seek(offset, from) --> offset is the number of byte from the second agrument file pointer location. from --> 0<beginning of file>/ 1<current position>/ 2<end of file>###
str = fo.read(10);
print "Again read String is : ", str
# Close opend file
fo.close()


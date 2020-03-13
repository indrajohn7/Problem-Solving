#!/usr/bin/python
import re

line = "Cats are smarter than dogs"

matchObj = re.match('(.*) are (.*?) (.*)', line, re.M|re.I)

if matchObj:
   print "matchObj.group() : ", matchObj.group()
   print "matchObj.group(1) : ", matchObj.group(1)
   print "matchObj.group(2) : ", matchObj.group(2)
   print "matchObj.group(3) : ", matchObj.group(3)
else:
   print "No match!!"


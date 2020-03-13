#!/usr/bin/python

import os

class Networkerror(RuntimeError):
   def __init__(self, arg):
      self.args = arg

###So once you defined above class, you can raise the exception as follows###

try:
   raise Networkerror("Bad hostname")
except Networkerror,e:
   print e.args


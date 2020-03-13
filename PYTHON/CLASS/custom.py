#!/usr/bin/python

import os

class custom(list):
	def __init__(self,a_name):
		list.__init__([])
		self.name=a_name;
	

c=custom("INDRA")
print(type(c))
print(dir(c))
c.extend(["NATASHA","DEEPAK"])
c.append('Aparna')
print(c)
print(c.name)

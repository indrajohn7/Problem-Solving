#!/usr/bin/python3

import os

def func1(str1):
	print(str1)
	return

def func2(age, name):
	print("age: %s, name:%s" % (age, name))
	return

def __init__():
	func1("Hi Indra!")
	func2(name = "Indra", age = 27) ### If you are calling an API through variable keyword name should be consistent with called API arg name ###
	func2("INDRA", 29)
	return

__init__()

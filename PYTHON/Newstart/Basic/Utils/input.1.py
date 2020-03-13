#!/usr/bin/python

import os

def __input__():

	str = input("Enter your input: "); # [x*5 for x in range(2,10,2)] <Paste this in the command line argument>
	print "Received input is : ", str
	return

def __raw_input__():
	str = raw_input("Enter your raw input: ");
	print "Recieved output is: ", str
	return

def insert_list(alist):
	blist = [1,2,3,4,5,6]
	clist = [11,22,33,44,55,66]
	alist.append(blist)
	alist.append(clist)
	alist.append(0)
	return

__input__()
__raw_input__()

def __main__():
	alist = []
	insert_list(alist)
	print(alist)
	return

__main__()

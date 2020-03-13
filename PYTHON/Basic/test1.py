#!/usr/bin/python

import os


def __init__():
	try:
		man=open("man_data.txt")
		data=[1,2,4]
		return data
	except IOError as err:
		print("EXCEPTION:"+str(err))




data=__init__()
print(data)

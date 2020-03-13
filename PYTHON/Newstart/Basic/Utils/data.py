#!/usr/bin/python

import os

data = open('data.txt', 'r')
for line in data:
	try:
		(role, line_spoken) = line.split(':', 1)
		print(role)
		print(' said: ')
		print(line_spoken)
	except:
		pass
data.close()

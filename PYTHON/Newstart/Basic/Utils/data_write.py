#!/usr/bin/python

import os

#data = open('data.txt', 'r')
out_data = open('out.txt', 'w')

with open('data.txt', 'r') as data:
	for line in data:
		try:
			(role, line_spoken) = line.split(':', 1)
			out_data.write(role)
			out_data.write(' said: ')
			out_data.write(line_spoken)
		except:
			pass
data.close()

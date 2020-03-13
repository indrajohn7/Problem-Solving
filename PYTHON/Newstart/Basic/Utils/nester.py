#!/usr/bin/python

import os

movie=['The Holy Grail', 1975, 'Terry Jones & Terry Gilliam', 
91, ['Graham Chapman', ['Michael Palin', 'John Cleese', 'Terry Gilliam', 'Eric Idle', 'Terry Jones'],
 ['HHH', 34, 'STEPH', 67]]];

def print_movies(movies,indent=True,level=0):
	for i in movies:
		if isinstance(i,list):
			print_movies(i,indent,level+1);
		else:
			if indent:
				for tab in range(level):
					print("\t")
					#print("\t",end='')
			print(i)

print_movies(movie)

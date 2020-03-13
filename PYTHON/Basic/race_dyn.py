#!/usr/bin/python

import os

cl_james=[]
cl_julie=[]
cl_sarah=[]
cl_mikey=[]

arr_cl=[cl_james,cl_julie,cl_sarah,cl_mikey]

files=['james.txt','julie.txt','sarah.txt','mickey.txt']

def sanitize(time_string):
	if '-' in time_string:
		splitter='-'
	elif ':' in time_string:
		splitter=':'
	else:
		return time_string
	
	(min,sec)=time_string.split(splitter)
	return (min+'.'+sec)


def __init__():
	#collect_data()
	idx=0
	for each in files:
		with open(each)as jaf:
			data=jaf.readline();
		james=data.strip().split(',')
		(name,dob)=james.pop(0),james.pop(0)
		for item in james:
			arr_cl[idx].append(sanitize(item))
		print(name+"'s best times are: "+str(sorted(set(arr_cl[idx]))[0:3]))
		idx=idx+1

__init__()

#!/usr/bin/python

import os

cl_james=[]
cl_julie=[]
cl_sarah=[]
cl_mikey=[]
'''
james=[]
julie=[]
sarah=[]
mikey=[]
'''

def sanitize(time_string):
	if '-' in time_string:
		splitter='-'
	elif ':' in time_string:
		splitter=':'
	else:
		return time_string
	
	(min,sec)=time_string.split(splitter)
	return (min+'.'+sec)
'''
def collect_data():
	with open('james.txt')as jaf:
		data=jaf.readline();
	james=data.strip().split(',')
	with open('julie.txt')as jul:
		data=jul.readline();
	julie=data.strip().split(',')
	with open('sarah.txt')as sar:
		data=sar.readline();
	sarah=data.strip().split(',')
	with open('mickey.txt')as mic:
		data=mic.readline();
	mikey=data.strip().split(',')
'''
def __init__():
	#collect_data()
	with open('james.txt')as jaf:
		data=jaf.readline();
	james=data.strip().split(',')
	with open('julie.txt')as jul:
		data=jul.readline();
	julie=data.strip().split(',')
	with open('sarah.txt')as sar:
		data=sar.readline();
	sarah=data.strip().split(',')
	with open('mickey.txt')as mic:
		data=mic.readline();
	mikey=data.strip().split(',')
	for each in james:
		cl_james.append(sanitize(each))
	for each in julie:
		cl_julie.append(sanitize(each))
	for each in sarah:
		cl_sarah.append(sanitize(each))
	for each in mikey:
		cl_mikey.append(sanitize(each))
	print('james: ',sorted(cl_james))
	print('julie: ',sorted(cl_julie))
	print('sarah: ',sorted(cl_sarah))
	print('mikey: ',sorted(cl_mikey))

__init__()

#!/usr/bin/python

import os


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

class Athlete:
	def __init__(self,a_name,a_dob,a_time):
		self.name=a_name;
		self.dob=a_dob;
		self.time=a_time;
	def top3(self):
		return(sorted(set(sanitize(time)for time in self.time))[0:3])

def get_data():
	#collect_data()
	for each in files:
		with open(each)as jaf:
			data=jaf.readline();
		james=data.strip().split(',')
		a=Athlete(james.pop(0),james.pop(0),james)
		#a.__init__(james.pop(0),james.pop(0),james)
		print(a.name+"'s best times are: "+str(a.top3()))

get_data()

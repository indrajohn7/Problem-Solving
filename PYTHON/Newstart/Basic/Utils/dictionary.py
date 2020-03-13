#!/usr/bin/python

import os

def __dicto__():
	type_brace={}
	type_dict=dict()
	type_brace['Name']='INDRA'
	type_brace['Occupation']=['player','Developer','builder']
	type_dict={'Name':'INDRAJIT','Occupation':['Actor','Singer','Dancer']}
	print('BRACE NAME:'+type_brace['Name']+'\tBRACE OCCUPATION:'+type_brace['Occupation'][1])
	print(type_dict)
	#type_brace['Occupation'][0]

__dicto__()

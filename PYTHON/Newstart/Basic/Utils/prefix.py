#!/usr/bin/python3

import os
import sys

def prefix(string1, string2, stream):
	is_string1_present = is_string2_present = 0
	if string1 in stream:
		is_string1_present =1
	if string2 in stream:
		is_string2_present = 1
	count = 0
	alist = list()
	if (not is_string1_present and not is_string2_present):
		return 0
	elif (not is_string1_present):
		return 0
	else:
		print(len(stream))
		for i in range(0, len(stream) + 1):
			res = stream[0:i]
			print(res)
			if (res.count(string1) > res.count(string2)):
				print("STRING:%s"%res)
				count += 1
	return count


res = prefix(sys.argv[2], sys.argv[3], sys.argv[1])
print("COUNT:%s\n"%res)

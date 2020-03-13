#!/usr/bin/python

import os
import pickle
import nester

with open('mydata.pickle','wb')as mysavedata:
	pickle.dump([1,2,[3,'three']],mysavedata)
with open('mydata.pickle','rb')as mydata:
	a_list=pickle.load(mydata)

nester.print_movies(a_list)

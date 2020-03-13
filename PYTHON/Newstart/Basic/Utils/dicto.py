#!/usr/bin/python3

import os
import sys


def __dicto__():
	type_dict=dict()
	type_dict={'Name':'INDRAJIT','Occupation':['Actor','Singer','Dancer']}
	print(type_dict)
	
	indra = {"B1" : "MATH", "B2" : "Physics", "B3" : "Chemistry"}
	subs = {"MATH" : ["calculas", "Algebra"], "Physics" : ["Mechanics", "optics"], "Chemistry" : "Organic"}
	dictionaries = {"en_de" : indra, "de_fr" : subs }
	print(dictionaries["de_fr"]["Physics"][1])
	print(dictionaries["en_de"]["B2"])

	w={"house":"Haus","cat":"Katze","red":"rot"}
	w1 = {"red":"rouge","blau":"bleu"}
	w.update(w1)
	print(w)
	w.items()
	w.keys()
	w.values()

	dishes = ["pizza", "sauerkraut", "paella", "Hamburger"]
	countries = ["Italy", "Germany", "Spain", "USA"]
	country_specialities = zip(countries, dishes)
	print(country_specialities)

	country_specialities_dict = dict(country_specialities)
	print(country_specialities_dict)

	iter = 0
	for keys in dictionaries:
		for each in dictionaries[keys]:
			print(str(iter)+":"+each+"::", end="")
			print(dictionaries[keys][each])
			#for i in keys[each]
			#	print(keys[each][i],)
			iter += 1
	print(sys.version)


__dicto__()

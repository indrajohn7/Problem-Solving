#!/usr/bin/python3

import os

# Python program to demonstrate working of zip
 
# Two separate lists
cars = ["Aston", "Audi", "McLaren"]
accessories = ["GPS", "Car Repair Kit", 
               "Dolby sound kit", "Beat Box"]
 
# Combining lists and printing
for c, a in zip(cars, accessories):
    print ("Car: %s, Accessory required: %s"\
          %(c, a))

car_zip = zip(cars, accesories)

for l1, l2 in zip(*(car_zip))
	print (l1)
	print (l2)

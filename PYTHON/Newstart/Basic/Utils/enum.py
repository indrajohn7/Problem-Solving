#!/usr/bin/python

import os

# Two separate lists
cars = ["Aston", "Audi", "McLaren"]
accessories = ["GPS kit", "Car repair-tool kit"]
 
# Single dictionary holds prices of cars and 
# its accessories.
# First two items store prices of cars and
# next three items store prices of accessories.
prices = {1:"570000$", 2:"68000$", 3:"450000$",
          4:"890000$", 5:"4500$"}
 
# Printing prices of cars
for index, c in enumerate(cars, start=1):
    print "Car: %s Price: %s"%(c, prices[index])
 
# Printing prices of accessories
for index, a in enumerate(accessories,start=1):
    print ("Accessory: %s Price: %s"%(a,prices[index+len(cars)]))


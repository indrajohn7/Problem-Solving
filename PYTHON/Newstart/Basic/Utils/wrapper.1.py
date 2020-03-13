#!/usr/bin/python

class JustCounter:
   __secretCount = 0 # This is a hidden member : __<attribute name>
  
   def count(self):
      self.__secretCount += 1
      print self.__secretCount

counter = JustCounter()
counter.count()  # Can be accessed through member function which returns its value
counter.count()
print counter._JustCounter__secretCount  # Only can access with this notation -->  <obj_name>._<class_name>__<attribute_name>
print counter.__secretCount  # Cant access the value directly with obj.


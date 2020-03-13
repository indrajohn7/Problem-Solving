#!/usr/bin/python

# Function definition is here
def changeme( mylist1 ):
   "This changes a passed list into this function"
   mylist1.append([1,2,3,4]);
   print "Values inside the function: ", mylist1
   return

def newme(mylist1):
	mylist1 = [1, 2, 3, 4] ### Redefinition of a data structure becomes local to the API, else any kind of update operation is allowed ###
	print("Value inside newme: ",mylist1)
	return

def delme(mylist1):
	del mylist1[1]
	if (mylist1 != None):
		print("Value inside delme: ",mylist1)
	else:
		print("List is deleted:")
	return

# Now you can call changeme function
mylist = [10,20,30];
changeme( mylist );
print "Values outside the function changeme: ", mylist
newme(mylist)
print "Values outside the function newmw : ", mylist
delme(mylist)
print "Values outside the function delme : ", mylist

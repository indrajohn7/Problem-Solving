#!/usr/bin/python
import os

man=[]
other=[]
junk=[]

try:
    data=open("data.txt")
    for line in data:
        try:
            if  not line.find(':')==-1:
                (role,spoken)=line.split(':',1)
           	    # print role
           	    # print spoken
                if role=='Man':
                    man.append(spoken);
                elif role=='Other Man':
                    other.append(spoken);
            else:
                junk.append(line);
        except ValueError as err:
            print('Value Error: '+str(err))
except IOError as err:
    print('IOERROR' +str(err))
try:
    man_file=open('man_data.txt','w')  ### To avoid finally block we can use <with>  Syntax::    with open("<File_name>",'<MODE>') ###
    other_file=open('other_file.txt','w')
    junk_file=open('junk_file.txt','w')
    for i in man:
        man_file.write(i)
        print(i)
    for i in other:
        other_file.write(i)
        print(i)
    for i in junk:
        junk_file.write(i)
except IOError as err:
    print('IOERROR'+str(err))
finally:
    if man_file in locals():
        man_fille.close()
    if other_file in locals():
        other_file.close()
    
                
    

man=[]
other=[]
try:
    data=open("data.txt")
    for line in data:
        try:
            (role,spoken)=line.split(':',1)
            if role=='man':
                man.append(spoken);
            elif role=='other man':
                other.append(spoken);
        except ValueError as err:
            print('Value Error: '+str(err))
except IOError as err:
    print('IOERROR' +str(err))
try:
    man_file=open('man_data.txt','w')  ### To avoid finally block we can use <with>  Syntax::    with open("<File_name>",'<MODE>') ###
    other_file=open('other_file.txt','w')
    for i in man:
        print(i,file=man_file)
    for i in other:
        print(i,file=other_file)
except IOError as err:
    print('IOERROR'+str(err))
finally:
    if man_file in locals:
        man_fille.close()
    if other_file in locals:
        other_file.close()
    
                
    

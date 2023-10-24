class Student:
    __d1={}
    __d2={}
    __d3={}
    __l1=[]
    __l2=[]
    __l3=[]
    def __init__(self,n,i,s,c):
        self.__detail=[n,i,s,c]
        if(s==1):
            Student.__l1.append(self.__detail)
        elif(s==2):
            Student.__l2.append(self.__detail)
        else:
            Student.__l3.append(self.__detail)  
    


    def display_results():
        Student.__l1.sort(reverse=True,key=Student.sortkey())
        for i,x in enumerate(Student.__l1):
            Student.__d1[i+1]=x
        Student.__l2.sort(reverse=True,key=Student.sortkey())
        for i,x in enumerate(Student.__l2):
            Student.__d2[i+1]=x   
        Student.__l3.sort(reverse=True)
        for i,x in enumerate(Student.__l3,key=Student.sortkey()):
            Student.__d3[i+1]=x     
        print('Sem 1-',Student.__d1)
        print('Sem 2-',Student.__d2)
        print('Sem 3-',Student.__d3)    
print('TAMANNA SHEIKH 0901AM221074')
while(True):
    
    c=int(input('Enter 1 to Register , 2 to Display'))
    if(c==1):
        s=Student(input('Name:'),input('ID:'),float(input('CGPA:')),int(input('Sem:')))  
        
    else:
        Student.display_results()
        break      



   





'''
  As python is dont support python overloadding or compile ime pholimorphisom...
  we use defauld argumemet , or kwargs
'''

class CompiletimePholimorphisom:
    
    def add(self,a,b):
        return a+b
    
    def add(self,a,b,c):
        "compile willl last function ,if we give two argument it will arise a eroor"
        return a+b+c

        
        
# obj = CompiletimePholimorphisom()
# print(obj.add(4,5))







#============================ first function never execute,it always overidding by lastst function in runtime===============

#================================== solution: using defaulf argumetn+========
class Solutin_defatuld_argumet_CompiletimePholimorphisom:
    
    def add(self,a,b):
        print("First Function")
        return a+b
    
    def add(self,a,b,c=5):
        print("Second function ")
        return a+b+c

        
        
obj =  Solutin_defatuld_argumet_CompiletimePholimorphisom()
print(obj.add(4,5))






#=================== also we can use argumetn /kewword arguments============

class Solutin_defatuld_argumet_CompiletimePholimorphisom:
    
    def add(self,a,b):
        print("fist funciton")
        return a+b
    
    def add(self,a,b,*args):
        print("Second Function")
        return a+b+sum(args)

        
        
obj =  Solutin_defatuld_argumet_CompiletimePholimorphisom()
print(obj.add(4,5,6,565,7))




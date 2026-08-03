class Student:
    
    #------- class attribute ------
    university = "xyz universiy"
    uni_location = "chitagong"
    
    def __init__(
        self,
        name:str,
        age:int,
        id=None,
        dept=None):
        self.name = name
        self.age = age
        self.id = id
        self.dept = dept
        
    
    def __str__(self):
        return f'''Univesity : {self.university}\n
                   Name : {self.name} \n
                   age: {self.age}'''
                   
                   
                   
                   
                   
                   
                   
mizan = Student("mizan",27)
print(mizan)
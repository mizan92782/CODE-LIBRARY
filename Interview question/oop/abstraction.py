
# ******** Abstraction use for implmentation hidding and structure reinforcement
# *********** use ABC form abs to abstract
# ****** @abstractmethod inforce to implementaion in sub class

from abc import ABC,abstractmethod

class Car(ABC):
    #! ******* abstract method
    
    @abstractmethod
    def color():
        pass
        
    @abstractmethod
    def sound():
        pass
        
        
    @abstractmethod
    def engine():
        pass
        
    @abstractmethod
    def owner():
        pass
        
    
        
    #! ******* Concrete Method
    def Usage(self):
        return "Car is a vehicle for travelling"
        
        
        
        
        
        
class Toyota(Car):
    
    def color(self):
        return "toyota sound"
    def engine(self):
        return "toyota engine"
    def owner(self):
        return "toyota owner"
    def sound(self):
        return "toyota sound"
        
    
    
class Tesla(Car):
    
    def color(self):
        return "Tesla sound"
    def engine(self):
        return "Tesla engine"
    def owner(self):
        return "Tesla owner"
    def sound(self):
        return "Tesla sound"
        
    
    
toyoto=Toyota()
print(f"{toyoto.color()}   {toyoto.owner()}    {toyoto.sound()}")
print(toyoto.Usage())

tesla=Tesla()
print(f"{tesla.color()}   {tesla.owner()}    {tesla.sound()}")
print(tesla.Usage())


#! ============================== Different Car has same method or property, and force them to implemtn ,but all are diffent ,
#! that why abstraction called implementation hidding
#!==============================


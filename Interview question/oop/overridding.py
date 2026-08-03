
class Animal:
    def sound(self):
        return "Animal sound"

class Dog(Animal):
    def sound(self):
        return "Gaw Gaw Gaw !!"
        
        
class Cow(Animal):
    def sound(self):
        #calling super class sound
        return super().sound()




obj = Cow()
print(obj.sound())
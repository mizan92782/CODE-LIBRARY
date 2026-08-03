class Father:

    def __init__(self, father_name):
        self.father_name = father_name
        
    def details(self):
        return f"{self.father_name} : Father"


class Student(Father):

    def __init__(self, name, father_name):
        super().__init__(father_name)
        self.name = name

    def details(self):
        return f"{self.name} Father is {self.father_name}"


miz = Student("Mizan", "Milon")

print(miz.details())


# call super class data of object........*****
print(Father.details(miz))
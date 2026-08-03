
class Father:

    def __init__(self,name,home,salary):
        self.name = name  #public
        self._home = home #protected
        self.__salary =salary  # private


    def fathe_info(self):
        return {
            "Name" : self.name,
            "Home": self._home,
            "Salary" : self.__salary
        }
        


class Son(Father):

    def __init__(self,sname,age,fname,home,salary):
        super().__init__(fname,home,salary)
        self.sname=sname
        self.__age =age

    def fathersalary(self):
        return self._Father__salary





son = Son("mizan",22,"milon","noakhali",4545434)

data =son.fathe_info()
print(data)



father = Father("milon","dhaka",949)
print(father._home)
print(son.fathersalary())
#include <iostream>
#include <string>

struct Student {
    std::string name;

    Student(std::string name) {
        this->name = name;
    }

    // Nested struct
    struct Parent {
        std::string father;
        std::string mother;

        Parent(std::string father, std::string mother) {
            this->father = father;
            this->mother = mother;
        }

        void fun(const Student& super) {
            std::cout << "Information: ";
            std::cout << super.name << "'s parents - Father: " << father << ", Mother: " << mother << std::endl;
        }
    };
};

int main() {
    // https://www.geeksforgeeks.org/nested-structure-in-c-with-examples/


    
    Student myStudent("John");

    // Create an instance of the nested struct
    Student::Parent myParent("John's Father", "John's Mother");

    // Call the fun() method passing the outer struct by reference
    myParent.fun(myStudent);

    return 0;
}

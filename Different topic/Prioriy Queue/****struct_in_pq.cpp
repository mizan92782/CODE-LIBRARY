#include <iostream>
#include <queue>

struct MyStruct {
    int priority;
    std::string data;

    // Define the comparison operator for the struct
    //! as priority queue contain element by ordr,so have to say 
    // !which is our order by operator fucntion
    bool operator<(const MyStruct& other) const {
        return priority < other.priority;
    }
};

int main() {
    // Declare a priority queue of MyStruct
    std::priority_queue<MyStruct> myPriorityQueue;

    // Create some instances of MyStruct
    MyStruct element1 = {3, "Priority 3"};
    MyStruct element2 = {1, "Priority 1"};
    MyStruct element3 = {5, "Priority 5"};

    // Push elements into the priority queue
    myPriorityQueue.push(element1);
    myPriorityQueue.push(element2);
    myPriorityQueue.push(element3);

    // Pop elements from the priority queue (they will be in descending order of priority)
    while (!myPriorityQueue.empty()) {
        MyStruct topElement = myPriorityQueue.top();
        myPriorityQueue.pop();

        std::cout << "Priority: " << topElement.priority << ", Data: " << topElement.data << std::endl;
    }

    return 0;
}

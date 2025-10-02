#include "stack.h"

int main(){
    /*Test Stack Class*/
    Stack<int> stack1;
    Stack<int> stack2;

    /*Test Push*/
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);

    /*See The stack*/
    stack1.print();

    /*Test Pop*/
    stack1.pop();

    /*See The updated stack*/
    stack1.print();

    /*Check to see the top element*/
    std::cout << "[" << stack1.top() << "]";
    std::cout << stack2.top();
    std::cout << std::endl;


    (stack1.isEmpty()) ? std::cout << "Empty\n" :  std::cout << "Not Empty\n";
    (stack2.isEmpty()) ? std::cout << "Empty\n" :  std::cout << "Not Empty\n";
    (stack1.search(2)) ? std::cout << "Found\n" :  std::cout << "Not Found\n"; 
    (stack2.search(4)) ? std::cout << "Found\n" :  std::cout << "Not Found\n"; 




    return 0;
}
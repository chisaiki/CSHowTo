/*Header guards to avoid multiple definition errors*/
/*See CS Q's for more details*/
/*Many developers actually implement template class methods inside the header file to avoid complexity*/
#ifndef STACK_H 
#define STACK_H

#include <iostream>

/*- Associated with the definition of a stack is a set of operations that we would like to perform on this List ADT.
    -print
    -empty
    -find
    -insert     
    -remove
*/
template <typename Type>
class Stack{
    private:
        /*Singly Linked List Node Definition*/
        struct Node {
            Type data;
            Node* next;
            
            Node(const Type& value, Node* next = nullptr) : data(value), next(next){}
        };

        Node* head_; //An instance of the Node struct
        size_t size_ = 0;


    public:
    /*Constructors*/
    Stack(){
        head_ = nullptr;
    }

    /*Destructor - prevents memory leaks*/
    ~Stack() {
        clear();  // Clean up all nodes when stack is destroyed
    }

    /*Stack Operations*/
    bool isEmpty(){
        return (size_ == 0 && head_ == nullptr);
    }

    /*Clear the stack*/
    /*What the Clear Function Should Do:
        Traverse through all nodes and delete them
        Set head_ to nullptr
        Reset size_ to 0
    */
    void clear(){
        while (head_ != nullptr){
            /*Holds the node to delete*/
            Node* temp = head_;
            /*Traverse through the list*/
            head_ = head_->next;
            /*Follow head_ along and delete the already visited nodes*/
            delete temp;            
        }

        /*After everything has been cleared, set size to 0*/
        size_ = 0;
    }

    /*Insert new data*/
     /*What the Insert Function Should Do:
        Create a new node, that points to the original head
        Set the head to equal the new node
        Increase size counter
        NOTE: Remember right hand side is evaluated first
    */
    void push(const Type& newData){
        /*new node points to old head_*/
        head_ = new Node(newData, head_);
        /*After the new node is pointing to the old head, the new node is pointed to by the head*/
        size_++;
    }

    /*Delete data and return top element's data*/
    Type pop(){
        if(head_ != nullptr){
            Type data = head_->data;  // Save the data before deleting
            Node* temp = head_;
            head_ = head_->next;
            delete temp;
            
            size_--;
            return data;  // Return the popped data
        }
        else{
            std::cout << "\nWarning: Cannot pop empty stack, returning default value" << std::endl;
            return Type{}; 
        }
    }

    /*Show the data at top of the stack*/
    /*If stack is empty, return the default value of whichever type it is*/
    Type top() const{
        if (head_ == nullptr) {
            std::cout << "\nWarning: Accessing top of empty stack, returning default value: ";
            return Type{};  
        }
        return head_->data;
    }

    /*View all elements data value*/
    void print() const{
        if(head_ != nullptr){
            Node* current = head_;
            while(current != nullptr){
                std::cout << "[" << current->data << "]" << std::endl;
                current = current->next;
            }
        std::cout << std::endl;
        }
        else{
             std::cout << "Stack is empty" << std::endl;
        }
        
    }

    /*Return the number of elements in the stack*/
    size_t getSize() const{
        return size_;
    }

    /*Add copy and assignment operator,  
    
    Search*/
    bool search(const Type& value) const{
        if(head_ != nullptr){
            Node* current = head_;

            while(current){
                if(current->data == value){
                    return true;
                }
                current = current->next;
            }
        }

        return false;
    }

};

#endif

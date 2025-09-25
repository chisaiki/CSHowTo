/*Header guards to avoid multiple definition errors*/
/*See CS Q's for more details*/
#ifndef STACK_H 
#define STACK_H

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

        Node* head_;
        size_t size_;


    public:
    /*Constructors*/
    Stack();

    /*Stack Operations*/
    bool isEmpty();

    /*Clear the stack*/
    /*What the Clear Function Should Do:
        Traverse through all nodes and delete them
        Set head_ and tail_ to nullptr
        Reset size_ to 0
    */
    void clear();

    /*Insert new data*/
    void push(const Type& newData);

    /*Delete data and return top element*/
    Type pop();

    /*Show the top of the stack*/
    Type top() const;

    /*View all elements*/
    void print() const; 

    /*Return the number of elements in the stack*/
    size_t getSize() const;

}

#endif

//Acelajado, John Vince D.
#ifndef STACK_LIST_H
#define STACK_LIST_H

//class node that contains data and the next
template <typename T>
class Node{
    public:
    T data;           //VALUE THAT WE NEED STORE
    Node* next;       //POINTER TO THE NEXT NODE
};

template <typename T>
Node<T> *head = nullptr;

//operations for the stock

//push
template <typename T>
void push(T newData){
    //create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data=newData;

    //new node points to current top, then becomes the new top
       newNode->next=head<T>;
       head<T> = newNode;
}
//pop
template<typename T>
T pop(){
    //check if the stack is empty:
    if(head<T> == nullptr){
        std::cout<< "Stack Overflow. " << std::endl;
    }

    //save the current top node
    Node<T>*  temp = head<T>;
   
    //store its data
    T temVAl = temp->data;

    //move the head to the next node
    head<T> = head<T>->next;

    //free the removed node
    delete temp;

    //return the removed value
    return temVAl;

}

//top
template<typename T>
void Top(){
    // error catching:
    if(head<T> == nullptr){
        std::cout<<"Stack underflow" << std::endl;
        return;
    }
    // display the Top node
    std::cout<< "top of stack: "<< head<T>->data << std::endl;
}

//isEmpty
template<typename T>
bool isEmpty(){
    return head <T> == nullptr;
}

//display 
template <typename T>
void displayALL(){
    if (head<T> == nullptr){
        std::cout << "Stack is empty" << std::endl;
        return;
    }

    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout << temp->data << "\n";
        temp = temp->next;
    }
    std::cout << "\n";

}



#endif




#ifndef DOUBLE_LL_H
#define DOUBLE_LL_H

template <typename T>
class doubleList{
    public:
        T data;
        doubleList<T>* next = nullptr;
        doubleList<T>* prev = nullptr;
};

//****************** 
//creating a node
//****************** 

template <typename T>
doubleList<T>* new_node(T newData){
    //dynamically allocate memory for a new node
    doubleList<T>* newNode = new doubleList<T>;

    //store data in the node:
    newNode->data = newData;

    //since its a new node, it will point to null
    newNode->next = nullptr;
    newNode->prev = nullptr;

    return newNode;

}

//****************** 
//traversal
//****************** 
template <typename T>
void dllTraverse(doubleList<T>* currentNode){
    doubleList<T>* tail = nullptr;

    //traversal to the end
    std::cout << "Forward traversal \n";
    while(currentNode != NULL){
        //prints the data
        std::cout << currentNode->data<<" ";
        //save the current node as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }

    std::cout<<std::endl;
    //reverse traversal
    std::cout << "Reverse traversal \n";
    while(tail != NULL){
        std::cout << tail->data<<" ";
        tail = tail->prev;
    }
}

//****************** 
//insertion at the head
//****************** 
template <typename T>
void dllInsertHead(T newData, doubleList<T>** currentHead){

    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //set the new node to point to the current head
    newNode->next = *currentHead;

    //current head will be pointed to the new node
    (*currentHead)->prev = newNode;

    *currentHead = newNode;
}

//****************** 
//general insertion
//****************** 
template <typename T>
void dllInsertAny(T newData, doubleList<T>* prevNode){
    //cannot insert after a null node (prevNode cannot be null -> return)
    if(prevNode == nullptr){
        std::cout << "Previous node cannot be null";
        return;
    }

    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //new node points to the node after the prevNode
    newNode->next = prevNode->next;

    //newNode previous must be pointed to the previous
    newNode->prev = prevNode;

    //if there is a node after the previous node, make it point back to the new node
    //make it point back to the new node
    if(prevNode->next != nullptr){
        prevNode->next->prev=newNode;
    }

    //prevNode will be pointed to the newNode;
    prevNode->next = newNode;


}


//****************** 
//insertion at the end
//****************** 
template <typename T>
void dllInsertEnd(T newData, doubleList<T>* currentHead){

    //create a new node
    doubleList<T>* newNode = new_node(newData);

    //traverse until reaching the last node
    while(currentHead->next != nullptr){
        currentHead = currentHead->next;
    }

    //connect the last node to the new node
    currentHead->next = newNode;

    //connect the prev node to the new node
    newNode->prev = currentHead;
}


//****************** 
//delete
//****************** 

template <typename T>
void dllDeleteNode(doubleList<T>** head, doubleList<T>* delNode){

    //If list is empty or node to delete is NULL, do nothing
    if (*head == nullptr || delNode ==nullptr) return;
    //if the node to delete is thead, move head to the next node
    if (*head == delNode)
        *head = delNode->next;
    //if there is a next node, update its prev pointer
    if (delNode->next != nullptr)
        delNode->next->prev = delNode->prev;
    //if there is a previous node, update its next pointer
    if (delNode->prev != nullptr)
        delNode->prev->next = delNode->next;
    //Delete the node
    delete delNode;
}

#endif
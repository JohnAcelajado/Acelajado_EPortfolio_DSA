#include <iostream>
#include "double_LL1.h"

int main(){

    //'C' 'P' 'E'
    // Creation of head node
    doubleList<char>* head = new_node('C');

    // Creation of other nodes
    doubleList<char>* second = new_node('P');
    doubleList<char>* third = new_node('E');

    // Link the nodes
    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    std::cout << "Initial Traversal" << std::endl;
    dllTraverse(head);
    std::cout << std::endl;

    std::cout << "Inserting at the head" << std::endl;
    dllInsertHead('G',&head);
    dllTraverse(head);
    std::cout << std::endl;

    std::cout<< "Inserting at the end" << std::endl;
    dllInsertEnd('1',head);
    dllTraverse(head);
    std::cout << std::endl;

    //insert 'x' after 'p'
    std::cout<< "Inserting at the any node" << std::endl;
    doubleList<char>* current = head;

    //simple searching algo
    while(current != nullptr && current->data != 'P'){
        current = current->next;
    }

    if(current != nullptr){
        dllInsertAny('X',current);
    }

    dllTraverse(head);
    std::cout << std::endl;
 
    std::cout << "Deletion" << std::endl;

    // Find 'X'
    doubleList<char>* toDelete = head;
    while(toDelete != nullptr && toDelete->data != 'X') {
        toDelete = toDelete->next;
    }

    // Delete 'X'
    if(toDelete != nullptr) {
        dllDeleteNode(&head, toDelete);
    }

    dllTraverse(head);

    return 0;
}
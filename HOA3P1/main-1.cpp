#include <iostream>
#include "singly_LL.h"

int main(){

    //'C' 'P' 'E'
    // Creation of head node
    SingleList<char>* head = nullptr;
    SingleList<char>* second = nullptr;
    SingleList<char>* third = nullptr;

    // Allocate memory for nodes
    head = new SingleList<char>;
    second = new SingleList<char>;
    third = new SingleList<char>;
    
    // Link the nodes
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = nullptr;

    // Traversal
    std::cout << "Linked list traversal: ";
    listTraversal(head);

    std::cout << "Newly inserted head of Linked List: ";
    sllinsertHead('P',&head);
    listTraversal(head);

    std::cout << "Insetion at any part: ";
    sllGeneralinsertion('Q',head->next->next);
    listTraversal(head);

    std::cout << "Insertion at the end: ";
    sllinsertEnd('R', &head);
    listTraversal(head);

    std::cout << "Deleting a node: ";
    sllDelete('S',&head);
    listTraversal(head);

    return 0;
}
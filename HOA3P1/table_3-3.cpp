#include <iostream>
#include "singly_ll.h"

int main(){

    // Create the linked list
    SingleList<char> *head = new SingleList<char>;
    SingleList<char> *second = new SingleList<char>;
    SingleList<char> *third = new SingleList<char>;
    SingleList<char> *fourth = new SingleList<char>;
    SingleList<char> *fifth = new SingleList<char>;
    SingleList<char> *last = new SingleList<char>;

    // Store the data and link the nodes
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '1';
    fourth->next = fifth;

    fifth->data = '0';
    fifth->next = last;

    last->data = '1';
    last->next = nullptr;

    // Traverse the list
    std::cout << "a. Original Linked List: ";
    listTraversal(head);

    // Insert G at the head
    std::cout << "b. Insert G at the head: ";
    sllinsertHead('G', &head);
    listTraversal(head);

    // Insert E after P
    std::cout << "c. Insert E after P: ";
    sllGeneralinsertion('E', head->next->next);
    listTraversal(head);

    // Delete C
    std::cout << "d. Delete C: ";
    sllDelete('C', &head);
    listTraversal(head);

    // Delete P
    std::cout << "e. Delete P: ";
    sllDelete('P', &head);
    listTraversal(head);

    // Final linked list
    std::cout << "f. Final Linked List: ";
    listTraversal(head);

    // Delete the entire list
    sllDeletelist(&head);

    return 0;
}
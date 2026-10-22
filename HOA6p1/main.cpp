#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h>  //will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main(){
    //generate random values
    int dataset[max_size];
    srand(time(0));
    for (int i=0; i<max_size; i++){
        dataset[i] = rand();
    }
    for (int i=0; i < max_size; i++){
        std::cout << dataset[i] << " ";
    }
    
    std::cout << std::endl;
    //create a user input to ask what value to find:
    int toFind;
    std::cout << "what value you want to search? ";
    std::cin >> toFind;

    std::cout << "=====Linear Search Array=====" << std::endl;
    linearSearchArr(dataset, max_size, toFind);
    std::cout << std::endl;

    //linear search:

    //linked list: V I N C E
    Node<char>* name1 = new_node('V');
    Node<char>* name2 = new_node('I');
    Node<char>* name3 = new_node('N');
    Node<char>* name4 = new_node('C');
    Node<char>* name5 = new_node('E');

    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = NULL;


    std::cout << "=====Linear Search Linked List=====" << std::endl;
    std::cout << "Searching for D: ";
    linearSearchLL(name1, 'D');
    std::cout << "Searching for I: ";
    linearSearchLL(name1, 'I');
    std::cout << std::endl;

    //binary search:
    int sortedData[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    std::cout << "===== Binary Search Array =====" << std::endl;
    std::cout << "Searching for Data 10 and 70: ";
    binarySearchArr(sortedData, 10,70);
    std::cout << "Searching for Data 11 and 28: ";
    binarySearchArr(sortedData, 11,28);
    std::cout << std::endl;

    std::cout << "===== Binary Search Array =====" << std::endl;
    char choice = 'y';
    int count = 1;
    int newData;
    
    Node<int>* temp;
    Node<int>* head = nullptr;
    Node<int>* node;
    
    while(choice == 'y'){
        std::cout << "Enter data: ";
        std::cin >> newData;
        
        if(count == 1){
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        }
        else if(count == 2){
            node = new_node(newData);
            head->next = node;
            node->next = NULL;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }
        else{
            temp = head;
            while(true){
                if(temp->next == NULL)
                break;
                
            temp = temp->next;
        }

        node = new_node(newData);
        temp->next = node;

        std::cout << "Successfully added " << node->data << " to the list.\n";
        count++;
    }

    std::cout << "Continue? (y/n): ";
    std::cin >> choice;
}

std::cout << "=====Binary Search Linked List=====" << std::endl;

int findData;
std::cout << "Enter value to search: ";
std::cin >> findData;

binarySearchLL(head, findData);
}
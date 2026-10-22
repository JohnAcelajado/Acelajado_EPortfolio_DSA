#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

/*
N -> Boundary of the list
item -> Searching number
Data -> Linear array
Step 1: I := 0
Step 2: Repeat while I <= n
  if (item = data[i])
  Print "Searching is successful"
  Exit
Else
  Print "Searching is Unsuccessful"
Exit
*/

template <typename T>
void linearSearchArr(T data[], int arrSize, T dataFind){
    //Step 1: I :=0
    int i = 0;

    //Repeat while I <= n   
    while(i < arrSize){
        if(dataFind == data[i]){
            std::cout << "The search is success\n";
            return;
        }
        //increment i to move to the next element
        i++;
    }
    
    std::cout << "the element is not found\n";
    return;
}

//NODE -> starting node
//tem that we are searching

template <typename T>
void linearSearchLL(Node<T>* node, T dataFind){
    //repeat the lopp unting the current node is not null
    while(node != nullptr){

        //if item = current node's data then display searching is successful
        if(dataFind == node->data){
            std::cout << "the search was a sucess\n";
            return;
        }

        //if not, move to the next node
        node = node->next;
    }

    //the sea5rching reached nullptr, -> search is unccessful
    std::cout << "the search was unsuccessful\n";
}

/*
getMiddle, must take the first and last node as its parameters.
1. Traverse the singly linked list using two pointers
2. Move one pointer by one step ahead and the other pointer by two steps.
3. When the fast pointer reaches the end of the singly linked list, the slow pointer will
reach the middle of the singly linked list.
4. Return slow pointer address.
*/
template <typename T>
void binarySearchArr(T data[], int arrSize, T dataFind){
    int low = 0;
    int up = arrSize - 1;

    while(low <= up){

        int mid = (low + up) / 2;

        if(dataFind == data[mid]){
            std::cout << "The search was successful\n";
            return;
        }
        else if(dataFind < data[mid]){
            up = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    std::cout << "The search was unsuccessful\n";
} 


/*
1. Start node is set to head of the list and the last node is set to NULL.
2. Middle element is calculated using the two pointers approach discussed above.
3. If the middle element is same as the key to be search, we return it.
4. Else if middle element is greater than the key to be searched, we have to search is the 
right side of the singly linked list. So, we set start pointer to the next of middle 
element.
5. Else if middle element is less than the key to be searched, we have to search is the left
side of the singly linked list. So, we set last pointer to the middle element.
6. If the key is found or the entier linked list gets traversed, we break the loop.
*/

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    //use two pointers: 1. slow moves one node at a time, fast moves two at a time
    Node<T>* slow = start;
    Node<T>* fast = start;

    //get middle:
    while(fast != last && fast->next != last){
        //move slow (one step)
        slow = slow->next;
        //move sat (two steps)
        fast = fast->next->next;
    }

    //when fast reaches thend
    //slow points to the middle node
    return slow;
}

template <typename T> 
void binarySearchLL(Node<T> *start, T findData){ 
    Node<T>* last = nullptr;

    while(start != last){
        Node<T>* middle = getMiddle(start, last);

        if(middle->data == findData){
            std::cout << "the search was successful\n";
            return;
        }
        else if(middle->data < findData){
            start = middle->next;
        }
        else{
            last = middle;
        }
    }

    std::cout << "the search was unsuccessful\n";
}

#endif
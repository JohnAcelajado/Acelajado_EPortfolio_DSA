#ifndef SUPPLEMENT_LL_H
#define SUPPLEMENT_LL_H

#include <iostream>

template <typename T>
class supplementList{
public:
    T data;
    supplementList<T>* next = nullptr;
    supplementList<T>* prev = nullptr;
};

// Create a new node
template <typename T>
supplementList<T>* new_node(T newData){

    supplementList<T>* newNode = new supplementList<T>;

    newNode->data = newData;
    newNode->next = newNode;
    newNode->prev = newNode;

    return newNode;
}

// Play all songs
template <typename T>
void playSongs(supplementList<T>* head){

    if(head == nullptr){
        std::cout << "Playlist is empty." << std::endl;
        return;
    }

    supplementList<T>* current = head;

    do{
        std::cout << current->data;

        if(current->next != head){
            std::cout << " -> ";
        }

        current = current->next;

    }while(current != head);

    std::cout << std::endl;
}

// Next song
template <typename T>
void nextSong(supplementList<T>* current){

    if(current != nullptr){
        std::cout << "Next Song: " << current->next->data << std::endl;
    }
}

// Previous song
template <typename T>
void previousSong(supplementList<T>* current){

    if(current != nullptr){
        std::cout << "Previous Song: " << current->prev->data << std::endl;
    }
}

// Insert song
template <typename T>
void insertSong(T newData, supplementList<T>** head){

    supplementList<T>* newNode = new_node(newData);

    if(*head == nullptr){
        *head = newNode;
        return;
    }

    supplementList<T>* tail = (*head)->prev;

    tail->next = newNode;
    newNode->prev = tail;

    newNode->next = *head;
    (*head)->prev = newNode;
}

// Remove song
template <typename T>
void removeSong(T findData, supplementList<T>** head){

    if(*head == nullptr){
        return;
    }

    supplementList<T>* current = *head;

    do{

        if(current->data == findData){

            if(current->next == current){
                delete current;
                *head = nullptr;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if(current == *head){
                *head = current->next;
            }

            delete current;
            return;
        }

        current = current->next;

    }while(current != *head);
}

#endif
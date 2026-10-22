#include <iostream>
#include "binaryTree.h"

/*
                    A
                  /   \
                 B     C
                / \    / \
                D E   F   NULLPTR


*/

int main(){
    
    //create the root node
    BinaryTree<char>* root = new BinaryTree<char>('A');
    //              A

    //CREATE THE CHILDREN OF A
    root->insertLeft('B');
    root->insertRight('C');

    /*
                    A
                  /   \
                 B     C
    
    */

    //CREATE THE CHILDREN OF B
    root->getLeftChild()->insertLeft('D');
    root -> getLeftChild()->insertRight('E');

    /*
                    A
                  /   \
                 B     C
                / \    / \
                D E   F   NULLPTR
    
    */


    //CREATE THE CHILDREN OF C
    root-> getRightChild()->insertLeft('F');

    std::cout<<"Root: "<< root->getRootVal() << std::endl;
    std::cout<<"Left Child of A: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout<<"Right Child of A: " << root->getRightChild()->getRootVal()<< std::endl;
    std::cout << "Left Child of B: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "Right Child of B: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;
    std::cout << "Left Child of C: " << root->getRightChild()->getLeftChild()->getRootVal() << std::endl;

    return 0;
}
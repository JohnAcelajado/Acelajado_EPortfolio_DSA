#ifndef BINARYTREE_H
#define BINARYTREE_H

template<typename T>
class BinaryTree{

    private:
        //data
        T key;
        //left
        BinaryTree<T> *leftChild;
        //right
        BinaryTree<T> *rightChild;
    public:

    //Constructor:
    BinaryTree(T rootObj);

    //insert children
    void insertLeft(T newNode);
    void insertRight(T newNode);

    //accessing the child nodes:
    BinaryTree<T>* getLeftChild();
    BinaryTree<T>* getRightChild();

    //get and set node value
    void setRootVal(T obj);
    T getRootVal();

    //checker if the node is a leaf or not
    bool isLeaf();
};

//Constructor:
template<typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    //add a value to the key
    key = rootObj;
    //set your left and right child to nullptr
    leftChild = nullptr;
    rightChild = nullptr;
}

//Inserting left:
template<typename T>
void BinaryTree<T>::insertLeft(T newNode){

    if(leftChild == nullptr){
        //CREATE A NEW NODE
        leftChild = new BinaryTree<T>(newNode);
    } else{
        BinaryTree<T>* newChild = new BinaryTree<T>(newNode);

        //move the existing left and child below the new node
        newChild->leftChild = leftChild;

        //make the new node the left child;
        leftChild = newChild;
    }

}

//Inserting right:
template<typename T>
void BinaryTree<T>::insertRight(T newNode){

    if(rightChild == nullptr){
        //CREATE A NEW NODE
        rightChild = new BinaryTree<T>(newNode);
    } else{
        BinaryTree<T>* newChild = new BinaryTree<T>(newNode);

        //move the existing right and child below the new node
        newChild->rightChild = rightChild;

        //make the new node the right child;
        rightChild = newChild;
    }

}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getLeftChild(){
    return leftChild;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::getRightChild(){
    return rightChild;
}

//get and set node valie
template<typename T>
void BinaryTree<T>::setRootVal(T obj){
    key = obj;
}

template<typename T>
T BinaryTree<T>::getRootVal(){
    return key;
}

//if leaf
template<typename T>
bool BinaryTree<T>::isLeaf(){
    return leftChild == nullptr && rightChild == nullptr;
}

#endif
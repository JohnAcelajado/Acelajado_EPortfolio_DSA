
//Acelajado, John Vince D.
#include <iostream>

//static array, what do we need?
const size_t maxCap = 100;
int stack[maxCap];
int top = -1, i, newData;

void push();
void pop();
void Top();
bool isEmpty();
bool isFull();
void displayStack();

int main(){
    int choice;
    std::cout<< "Enter the number of max elements for the new stack:";
    std::cin>>i;
    
    while(true){
        std::cout<< "stack operations" << std::endl;
        std::cout<<" 1.PUSH \n 2.POP \n 3.TOP \n 4.isEMPTY \n 5.Display Stack\n" << std::endl;
        std::cin>>choice;
        switch (choice){

            case 1: push();
            break;
            case 2: pop();
            break;
            case 3: Top();
            break;
            case 4: std::cout << isEmpty()<<std::endl;
            break;
            case 5: displayStack();
            default: std::cout<<"Invalid choice" << std::endl;
        }
    }

    return 0;
}

bool isEmpty(){
    //create a condition to check whether the top element is equal to -1
    if (top == -1) return true;
    return false;
}

bool isFull(){
    //check if we reached the maximum capacity of an array:
    if(top > i-1) return true;
    return false;
}

void push(){
    //check if full -> if yes return an error
    if (top == i-1){
        std::cout<< "stack overflow" << std::endl;
        return;
    }

    std::cout<< "New Value to add into the stack" << std::endl;
    std::cin >> newData;
    // increment the top(indext by 1) then assign the new data;
    stack[++top] = newData;
}

void Top(){
    //check if the stack is empty
    if(isEmpty()){
        std::cout<<"Stack underflow."<<std::endl;
    }
    std::cout<<"The element on the top of the stack is" << stack[top]<<std::endl;
}

void pop(){
    //check if the stack is empty
    if(isEmpty()){
        std::cout<<"Stack underflow." << std::endl;
    }

    //display the top value
    std::cout<<"popping: " << stack[top];
    //decrement the top value from the stack
    top --;
}

void displayStack() {
    //condition to check if the stack is empty
    if (isEmpty()){
        std::cout<<"Cannot print an empty stack"<<std::endl;
    }
    //we have create a loop that iterated the top element;
    
    for (int i = top; i >= 0; i--) {
        //display

        std::cout << stack[i] << ',';
    }
    //add a new line
    std::cout<<std::endl;
}

#include <iostream>
#include <queue>

void display(std::queue<char> r);

int main(){

    std::queue<char> q;
    q.push('C');
    q.push('P');
    q.push('E');
    q.push('0');
    q.push('1');
    q.push('0');

    std::cout << "===== CHARACTERS QUEUES =====" << std::endl;
    
    //display
    display(q);

    //empty()
    std::cout << "Is the queue empty? " << " " << q.empty() << std::endl;

    //size()
    std::cout << "What is the size of the queue? " << " " << q.size() << std::endl;

    //front
    std::cout << "What is in the front of the queue?" << " " << q.front() << std::endl;

    //back
    std::cout << "What is in the back of the queue?" << " " << q.back() << std::endl;

    //pop
    std::cout << "Popping a character: " << q.front()<< std::endl;
    q.pop();
    display(q);

    //push another element
    q.push('S');
    std::cout << "After pushing of another element: " << std::endl;
    display(q);

}

void display(std::queue<char> r){
    //create a copy of the queue
    std::queue<char> c = r;

    while(!c.empty()){
        std::cout<<" "<<c.front();
        c.pop();
    }
    std::cout<<"\n";

}
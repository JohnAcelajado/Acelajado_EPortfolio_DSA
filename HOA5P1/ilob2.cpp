#include <iostream>
#include "queuell.h"
#include "queueArr.h"

int main(){

    //create an object:
    std::cout << "========CIRCULAR QUEUE========" << std::endl;
    queueArr<int> q(6);
    q.Enqueue(1);
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
    q.Enqueue(2);
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
    q.Enqueue(3);
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
    q.Enqueue(4);
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
    q.Enqueue(5);
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
    q.Enqueue(6);
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
    q.Dequeue();
    std::cout<<"q_front:" << q.Front() << " " << "q_back:" << q.Back() << " " << "q_size:" << q.Size() << std::endl;
   
    return 0;
}
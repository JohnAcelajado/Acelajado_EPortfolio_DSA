#ifndef QUEUEARR_H
#define QUEUEARR_H


//Array-Based Circular Queue
template <typename T>
class queueArr{
    private:
        //create a pointer array:
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;
        
    public:
        //prototype:
        queueArr(size_t capacity);
        bool Empty();
        bool Full();
        
        size_t Size();
        void Clear();
        

        T Front();
        T Back();

        void Enqueue(T newData);
        void Dequeue();

        ~queueArr();

        //task:
        queueArr(const queueArr& other);
        queueArr& operator = (const queueArr& other);

};

//constructor:
template <typename T>
queueArr<T>::queueArr(size_t capacity){

    //capacity of the array
    q_capacity = capacity;

    //current size of the queue
    q_size = 0;
    //initial front and back index
    q_front = 0;
    q_back = -1;
    //new allocoted array
    q_array = new T[q_capacity];
    std::cout << "constructor class was called\n";
}

template <typename T>
queueArr<T>::~queueArr(){

    delete[] q_array;
}

//empty()
template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}

//full()
template<typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;
}

template <typename T>
void queueArr<T>::Clear(){
    q_front = 0;
    q_back = -1;
    q_size = 0;
}

template <typename T>
T queueArr<T>::Front(){
    //check and display if the queue is empty
    if (Empty()){
        std::cout<<"The queue is empty\n";
        return T{};
    }

    //return the front item
    return q_array[q_front];

}

template <typename T>
T queueArr<T>::Back(){
    //check and display if the queue is empty
    if (Empty()){
        std::cout<<"The queue is empty\n";
        return T{};
    }

    //return the back item
    return q_array[q_back];

}

template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

template <typename T>
void queueArr<T>::Enqueue(T newData){
    //check if the queue if full
    if (Full()){
        std::cout << "Queue is full" << std::endl;
        return;
    }

    //compute for the q_back to move it circulary
    q_back = (q_back+1) % q_capacity;

    //assign the new value to the back of the queue array
    q_array[q_back] = newData;

    //increment the q_size
    q_size++;
}

template <typename T>
void queueArr<T>::Dequeue(){
    //check if its empty
    if (Empty()){
        std::cout<< "The queue is empty\n";
        return;
    }


    //compute for the q_front to move it circularly
    q_front = (q_front +1) % q_capacity;

    //decrement the q_size
    q_size--;
}

#endif
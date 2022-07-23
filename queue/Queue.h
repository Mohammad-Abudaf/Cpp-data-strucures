//
// Created by shark on 7/20/22.
//

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <exception>
#include <iostream>

template <class T>
struct StructNode{
    T item;
    StructNode* next;
};

template <class T>
class Queue{
private:
    unsigned int length;
    StructNode<T>* front;
    StructNode<T>* rear;
public:
    Queue();
    ~Queue();

    bool isEmpty() const;
    void enQueue(T value);
    void deQueue(T& value);

    unsigned int getLength() const;
};

template<class T>
Queue<T>::Queue() {
    length = 0;
    front = rear = nullptr;
}

template<class T>
Queue<T>::~Queue() {
    delete front;
    delete rear;
}

template<class T>
bool Queue<T>::isEmpty() const{
    return length == 0;
}

template<class T>
void Queue<T>::enQueue(T value) {
    if(isEmpty())
    {
        front = new StructNode<T>;
        front->item = value;
        rear = front;
        length++;
    } else {
        auto* newNode = new StructNode<T>;
        newNode->item = value;
        newNode->next = NULL;
        rear->next = newNode;
        rear = newNode;
        length++;
    }
}

template<class T>
void Queue<T>::deQueue(T& value) {
    if(isEmpty()){
        std::cout << "error in dequeue: no elements!" << std::endl;
        throw std::bad_alloc();
    }else if(front == rear){
        value = front->item;
        front = NULL;
        rear = NULL;
        length--;

    } else {
        value = static_cast<T>(front->item);
        StructNode<T>* tempNode = front;
        front = front->next;
        --length;
        delete tempNode;
    }
}

template<class T>
unsigned int Queue<T>::getLength() const {
    return length;
}

#endif //DATASTRUCTURES_QUEUE_H

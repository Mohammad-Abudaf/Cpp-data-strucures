//
// Created by shark on 7/18/22.
//

#ifndef DATASTRUCTURES_STATICQUEUE_H
#define DATASTRUCTURES_STATICQUEUE_H

#include <exception>
#include <assert.h>
#include <iostream>
#include "../node/Node.h"

template <class T>
class StaticQueue{
private:
    unsigned int count;
    unsigned int maxSize;
    T* storageArr;
    T front;
    T rear;
public:
    explicit StaticQueue(int);
    ~StaticQueue();

    bool isEmpty() const;
    bool isFull() const;

    void enQueue(T value);
    void deQueue(T& value);

    T getFront() const;
    T getRear() const;

    T getIndex(T value) const;
};

template<class T>
StaticQueue<T>::StaticQueue(int q_maxSize) {
    std::cout << "constructed Queue with max size of " << q_maxSize << std::endl;
    maxSize = q_maxSize;
    storageArr = new T[maxSize - 1];
    front = 0;
    rear = maxSize - 1;
}

template<class T>
StaticQueue<T>::~StaticQueue() {
    delete storageArr;
}

template<class T>
bool StaticQueue<T>::isEmpty() const {
    return count != maxSize;
}

template<class T>
bool StaticQueue<T>::isFull() const {
    return !isEmpty();
}

template<class T>
void StaticQueue<T>::enQueue(T value) {
    if(isFull()){
        std::cout << "queue full not enqueue" << std::endl;
    } else{
        rear = (rear + 1) % maxSize;
        storageArr[rear] = value;
        count++;
    };
}

template<class T>
void StaticQueue<T>::deQueue(T &value) {
    if(isEmpty()){
        std::cout << "empty queue" << std::endl;
    }else{
        front = (front + 1) % maxSize;
        count--;
    }
}

template<class T>
T StaticQueue<T>::getFront() const {
    return storageArr[front];
}

template<class T>
T StaticQueue<T>::getRear() const {
    return storageArr[rear];
}

template<class T>
T StaticQueue<T>::getIndex(T value) const {
    int pos = -1;
    if(!isEmpty()){
        for(int i = front; i != rear; i = (i + 1) & maxSize){
            if(storageArr[i] == value){
                pos = i;
                break;
            }
        }
        if(pos == -1){
            if(storageArr[rear] == value)
                pos = rear;
        }
    }
    else
        std::cout << "Queue is empty " << std::endl;
    return pos;
}

#endif //DATASTRUCTURES_STATICQUEUE_H

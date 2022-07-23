//
// Created by shark on 7/15/22.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <stdexcept>
#include "../node/Node.h"
#include "exception"
#include <iostream>

template <class T>
class Stack{
public:
    explicit Stack();
    ~Stack();
    bool isEmpty() const;
    void push(const T& value);
    void pop(T& value);
    void pop();
    void display() const;
    Node<T>* getTop();
    T getTopValue() const;

    int getLength() const;
private:
    Node<T>* top;
    int length;
};

template<class T>
Stack<T>::Stack() {
//    auto* initNode = new Node<T>;
//    initNode->setData(0);
//    top = initNode;
    top = nullptr;
    length = 0;
}

template<class T>
Stack<T>::~Stack() {
    delete top;
}

template<class T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template<class T>
Node<T> *Stack<T>::getTop() {
    return top;
}

template<class T>
T Stack<T>::getTopValue() const{
    return top->getData();
}

template<class T>
void Stack<T>::push(const T &value) {
    auto* newNode = new Node<T>;
    if(newNode == nullptr){
        throw std::bad_alloc();
    }else{
        newNode->setData(value);
        newNode->setNextPtr(top);
        top = newNode;
        length++;
    }
}

template<class T>
void Stack<T>::pop() {
    Node<T>* tempPrt = top;
    if(isEmpty()){
        throw std::out_of_range("out of range");
    }else{
        top = top->getNextPtr();
        tempPrt->setNextPtr(nullptr);
        length--;
        delete tempPrt;
    }
}

template <class T>
void Stack<T>::pop(T& value) {
    Node<T>* tempPrt = top;
    if(isEmpty()){
        throw std::out_of_range("out of range");
    }else{
        top = top->getNextPtr();
        value = tempPrt->getData();
        tempPrt->setNextPtr(nullptr);
        length--;
        delete tempPrt;
    }
}

template<class T>
int Stack<T>::getLength() const {
    return length;
}

template<class T>
void Stack<T>::display() const {
    if (!getLength()){
        throw std::out_of_range("stack is null");
    }
    else{
        Node<T>* current = top;
        std::cout << "[ ";
        while (current != nullptr){
            std::cout << current->getData() << ' ' ;
            current = current->getNextPtr();

        }
        std::cout << ']' << std::endl;
    }
}

#endif //DATASTRUCTURES_STACK_H

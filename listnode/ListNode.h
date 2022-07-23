//
// Created by shark on 7/17/22.
//

#ifndef DATASTRUCTURES_LISTNODE_H
#define DATASTRUCTURES_LISTNODE_H

#include <iostream>
#include "../node/Node.h"

template<class T>
class ListNode {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    ListNode(); // constuctor

    void insertAtFront(const Node<T> &);
    void attachAtBack(const Node<T> &);
    bool deleteFromFront(Node<T>*&);
    bool deleteFromBack(Node<T>*&);
    bool isEmpty() const;
    void display() const;

    Node<T>* getHeadNode();
    Node<T>* getTealNode();

    ~ListNode(); // deconstruct
};

template<class T>
ListNode<T>::ListNode() {
    head = tail = nullptr;
}

template<class T>
Node<T> *ListNode<T>::getHeadNode() {
    return head;
}

template<class T>
Node<T> *ListNode<T>::getTealNode() {
    return tail;
}

template<class T>
bool ListNode<T>::isEmpty() const {
    return head == nullptr;
}

template<class T>
void ListNode<T>::insertAtFront(const Node<T> &node) {
    auto* newNode = new Node<T>(node);
    if(isEmpty())
        head = tail = newNode;
    else{
        newNode->setNextPtr(head);
        head = newNode;
    }
}


template<class T>
void ListNode<T>::attachAtBack(const Node<T> &node) {
    auto* newNode = new Node<T>(node);
    if(isEmpty())
        head = tail = newNode;
    else{
        newNode->setNextPtr(tail);
        tail = newNode;
    }
}
template<class T>
ListNode<T>::~ListNode() {
    std::cout << "destroying listNode" << std::endl;
    if(isEmpty())
        return;
//    while (!isEmpty()){
//        // delete each object in listNode
//    }
}

template<class T>
bool ListNode<T>::deleteFromFront(Node<T>*& node) {
    if(isEmpty()) return true;
    else{
        Node<T>* tempNode = head;
        if(head == tail)
            head = tail = nullptr;
        else
            head = tempNode->getNextPtr();

        node = tempNode->getNextPtr();
        delete tempNode;
        return true;
    }
}

template<class T>
bool ListNode<T>::deleteFromBack(Node<T> *& node) {
    if(isEmpty()) return true;
    else{
        Node<T>* tempNode = tail;
        if(head == tail)
            head = tail = nullptr;
        else
            tail = tempNode->getNextPtr();

        node = tempNode->getNextPtr();
        delete tempNode;
        return true;
    }
}

template<class T>
void ListNode<T>::display() const {
    /* this methode display the total list from top to down */
    if(isEmpty()){
        std::cout << "list is empty" << std::endl;
        return;
    }
    Node<T>* top = head;
    Node<T>* bottom = tail;
    Node<T>* current = top;
    while (current != nullptr){
        std::cout << "node data is " << current->getData() << " in ptr "
            << current << std::endl;
        current = current -> getNextPtr();
    }
}


#endif //DATASTRUCTURES_LISTNODE_H

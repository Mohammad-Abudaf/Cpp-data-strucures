//
// Created by shark on 7/14/22.
//

#ifndef DATASTRUCTURES_NODE_H
#define DATASTRUCTURES_NODE_H

template <class T>
class Node{
private:
    T data;
    Node* nextNodePtr;
public:
    Node(){
        nextNodePtr = nullptr;
    };
    explicit Node(T value){
        this->data = value;
        nextNodePtr = nullptr;
    }
    void setData(const T& value){
        this->data = value;
    }
    void setNextPtr(Node<T>* node){
        nextNodePtr = node;
    }

    Node<T>* getNextPtr() {
        return nextNodePtr;
    }
    T getData() const{
        return data;
    }
    ~Node() = default;
};
#endif //DATASTRUCTURES_NODE_H

//
// Created by shark on 7/15/22.
//

#ifndef DATASTRUCTURES_FIXEDSTACK_H
#define DATASTRUCTURES_FIXEDSTACK_H

const int SIZE = 100;
template <class T>
class FixedStack {
private:
    int top;
    T stack[SIZE];
public:
    FixedStack();
    ~FixedStack();
    bool isEmpty() const;
    bool isFull() const;
    T getTop() const;
    void push(T);
    void pop(T&);
};

template <class T>
FixedStack<T>::FixedStack() : top(-1){}

template<class T>
bool FixedStack<T>::isEmpty() const {
    return top == -1;
}

template<class T>
bool FixedStack<T>::isFull() const {
    return top == 100 - 1;
}

template<class T>
T FixedStack<T>::getTop() const {
    if (isEmpty()){
        return -1;
    }
    return stack[top];
}

template<class T>
void FixedStack<T>::push(T value) {
    if(!isFull()){
        top++;
        stack[top] = value;
    }
    else
        return;
}

template<class T>
void FixedStack<T>::pop(T & value) {
    if(!isEmpty())
        value = stack[top--];
    else
        return;
}

template <class T>
FixedStack<T>::~FixedStack() = default;




#endif //DATASTRUCTURES_FIXEDSTACK_H

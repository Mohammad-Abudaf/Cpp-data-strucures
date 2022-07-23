//
// Created by shark on 7/20/22.
//

#ifndef DATASTRUCTURES_ARRAY_H
#define DATASTRUCTURES_ARRAY_H

#include <exception>
#include <stdexcept>

template <class T>
class Array{
private:
    unsigned int length;
    unsigned int maxSize;
    T* array;
public:
    explicit Array(unsigned int);
    ~Array();

    void insertAt(unsigned index, T value);
    void removeFrom(unsigned index);
    T getValue(int index) const;
    bool isEmpty() const;
    bool isFull() const;
    void updateValue(unsigned index, T value);
    void printArray();
    void clearArray();
};

template<class T>
Array<T>::Array(unsigned int size) : maxSize(size),
    length(0){
    array = new T[maxSize];
}

template<class T>
Array<T>::~Array() {
    delete[] array;
}

template<class T>
T Array<T>::getValue(int index) const {
    return array[index];
}

template<class T>
void Array<T>::insertAt(unsigned int index, T value) {
    if(isFull()){
        throw std::exception();
    }
    else if(index > 0 && index < maxSize){
        throw std::out_of_range("out of range");
    } else {
        for(int i = length; i > index; i++){
            array[i] = array[i - 1];
        }
        array[index] = value;
        length++;
    }
}

template<class T>
bool Array<T>::isEmpty() const {
    return length == 0;
}

template<class T>
void Array<T>::removeFrom(unsigned index) {
    if(isEmpty()){
        throw std::exception();
    }else if(index > 0 && index < maxSize){
        throw std::out_of_range("out of range");
    }else{
        for(unsigned int i = index; i < length; i++){
            array[i] = array[i + 1];
        }
        length--;
    }
}

#include <cassert>
template<class T>
void Array<T>::updateValue(unsigned int index, T value) {
    assert(isEmpty());
    array[index] = value;
}

template<class T>
bool Array<T>::isFull() const {
    return length == maxSize;
}

#endif //DATASTRUCTURES_ARRAY_H

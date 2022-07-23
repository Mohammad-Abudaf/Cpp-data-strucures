//
// Created by shark on 7/22/22.
//

#ifndef DATASTRUCTURES_TREE_H
#define DATASTRUCTURES_TREE_H

#include <exception>
#include <iostream>
#include "TreeNode.h"

#define LOG std::cout << 1 << std::endl;
using std::exception;
using std::cout;

template <class T>
class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(const T &value);
    void preOrderTraversal(TreeNode<T>* node) const;
    void inOrderTraversal(TreeNode<T>* node) const;
    void postOrderTraversal(TreeNode<T>* node) const;

    bool search(T key);
    T getMinValue();
    T getMaxValue();
    TreeNode<T>* getRootNode();

    TreeNode<T> *deleteNode(TreeNode<T> *parentNode, T key);

private:
    TreeNode<T>* root;
    // private methode members to for class creator
    TreeNode<T> *insertToTree(TreeNode<T>* parentNode, T data);
    TreeNode<T> *search(TreeNode<T> *parentNode, T key);
    TreeNode<T> *findMin(TreeNode<T> *parentNode);
    TreeNode<T> *findMax(TreeNode<T> *parentNode);
};

template<class T>
TreeNode<T> *BinaryTree<T>::insertToTree(TreeNode<T>* parentNode, T data) {
    if(parentNode == nullptr){ // check if the value of tree node is null
        /*** if null set the initial value to the root ***/
        auto* newNode = new TreeNode<T>(data);
        parentNode = newNode;
    } else if (data >= parentNode->getData()){
        parentNode->
            setRightPtr(insertToTree(parentNode->getRightPtr(), data));
    }else if(data < parentNode->getData()){
        parentNode->
            setLeftPtr(insertToTree(parentNode->getLeftPtr(), data));
    }
    return parentNode;
}

template<class T>
void BinaryTree<T>::insert(const T& value) {
    root = insertToTree(root, value);
}

template<class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    delete root;
}

template<class T>
void BinaryTree<T>::preOrderTraversal(TreeNode<T> *node) const{
    if(node == nullptr){
//        std::cout << "no values here" << std::endl;
        return;
    }
    std::cout << node->getData() << '\t';
    preOrderTraversal(node->getLeftPtr());
    preOrderTraversal(node->getRightPtr());
}

template<class T>
void BinaryTree<T>::inOrderTraversal(TreeNode<T> *node) const {
    if(node == nullptr){
        return;
    }
    preOrderTraversal(node->getLeftPtr());
    std::cout << node->getData() << '\t';
    preOrderTraversal(node->getRightPtr());
}

template<class T>
void BinaryTree<T>::postOrderTraversal(TreeNode<T> *node) const {
    if(node == nullptr){
//        std::cout << "no values here" << std::endl;
        return;
    }
    preOrderTraversal(node->getLeftPtr());
    preOrderTraversal(node->getRightPtr());
    std::cout << node->getData() << '\t';

}

template<class T>
TreeNode<T> *BinaryTree<T>::search(TreeNode<T> *parentNode, T key) {
    while (parentNode!= nullptr){
        if (parentNode->getData() == key){
            return parentNode;
        }else if(parentNode->getData() < key){
            parentNode = parentNode->getRightPtr();
        }else if(parentNode->getData() > key){
            parentNode = parentNode->getLeftPtr();
        }else {
            return nullptr;
        }
    }
}

template<class T>
TreeNode<T> *BinaryTree<T>::getRootNode() {
    return root;
}

template<class T>
bool BinaryTree<T>::search(T key) {
    TreeNode<T>* result = search(root, key);
    if(result == nullptr)
        return false;
    else
        return true;
}

template<class T>
TreeNode<T> *BinaryTree<T>::findMin(TreeNode<T> *parentNode) {
    if(parentNode->getLeftPtr() == nullptr){
        return parentNode;
    }
    else if(parentNode == nullptr){
        return nullptr;
    }
    else{
        findMin(parentNode->getLeftPtr());
    }
}

template<class T>
T BinaryTree<T>::getMinValue(){
    TreeNode<T>* minValue = findMin(root);
    return minValue->getData();
}

template<class T>
TreeNode<T> *BinaryTree<T>::findMax(TreeNode<T> *parentNode) {
    if(parentNode == nullptr){
        return nullptr;
    }else if(parentNode->getRightPtr() == nullptr){
        return parentNode;
    }
    return findMax(parentNode->getRightPtr());
}

template<class T>
T BinaryTree<T>::getMaxValue() {
    TreeNode<T>* maxValue = findMax(root);
    return maxValue->getData();
}

template<class T>
TreeNode<T> *BinaryTree<T>::deleteNode(TreeNode<T> *parentNode, T key) {
    if(parentNode == nullptr){
        return nullptr;
    }
    if(key < parentNode->getData()){
        parentNode->setLeftPtr(deleteNode(parentNode->getLeftPtr(), key));
    }else if(key > parentNode->getData()){
        parentNode->setRightPtr(deleteNode(parentNode->getRightPtr(), key));
    }else{
        if(parentNode->getRightPtr() == NULL && parentNode->getLeftPtr() == NULL){
            // this condition done of the node is leave node
            parentNode = nullptr;
        }else if(parentNode->getLeftPtr() != NULL && parentNode->getRightPtr() == NULL){
            // this condition done for the node has only one child
            parentNode->setData(parentNode->getLeftPtr()->getData());
            delete parentNode->getLeftPtr();
            parentNode->setLeftPtr(nullptr);
        }
        else if(parentNode->getLeftPtr() == NULL && parentNode->getRightPtr() != NULL){
            // this condition done for the node has only one child
            parentNode->setData(parentNode->getRightPtr()->getData());
            delete parentNode->getRightPtr();
            parentNode->setRightPtr(nullptr);
        }
        else{
            TreeNode<T>* pre = findMax(parentNode->getLeftPtr());
            parentNode->setData(pre->getData());
            deleteNode(parentNode->getLeftPtr(), pre->getData());
        }
    }
    return parentNode;
}


#endif //DATASTRUCTURES_TREE_H
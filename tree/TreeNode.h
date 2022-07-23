//
// Created by shark on 7/21/22.
//

#ifndef DATASTRUCTURES_TREENODE_H
#define DATASTRUCTURES_TREENODE_H
template <class T> class BinaryTree;

template <class T>
class TreeNode{
    TreeNode<T> *leftPtr;
    TreeNode<T> *rightPtr;
    T data;
public:
    explicit TreeNode(T value){
        leftPtr = nullptr;
        rightPtr = nullptr;
        data = value;
    }
    TreeNode* getLeftPtr() const{
        return leftPtr;
    }
    TreeNode* getRightPtr() const{
        return rightPtr;
    }
    T getData() const{
        return data;
    }
    T setData(T value) {
        data = value;
    }
    void setRightPtr(TreeNode<T>* node){
        rightPtr = node;
    }
    void setLeftPtr(TreeNode<T>* node){
        leftPtr = node;
    }
};
#endif //DATASTRUCTURES_TREENODE_H

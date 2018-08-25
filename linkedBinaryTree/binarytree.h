#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <iostream>
using std::endl;
using std::cout;
using std::cin;


/**
    * @projectName   linkedBinaryTree
    * @brief         二叉树ADT方法
    * @author        HF
    * @date          2018-08-17
    */

template <class T>
class binaryTree
{
public:
    virtual ~binaryTree(){}
    virtual bool empty() const=0;
    virtual int size() const=0;
    virtual void preorder(void (*) (T* ))=0;
    virtual void inOrder(void (*)(T*))=0;
    virtual void postOrder(void (*)(T*))=0;
    virtual void levelOrder(void (*)(T*))=0;
};
#endif // BINARYTREE_H_

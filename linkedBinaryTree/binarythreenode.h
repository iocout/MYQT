#ifndef BINARYTHREENODE_H_
#define BINARYTHREENODE_H_

#include <iostream>
#include <algorithm>
#include "arrayQueue.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

    /**
    * @projectName   binaryThreeNode
    * @brief         二叉树节点结构
    * @brief         三种初始化方式
    * @author        HF
    * @date          2018-08-16
    */
template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild,  //左子树
                      *rightChild; //右子树
    binaryTreeNode() {leftChild = rightChild = nullptr;}
    binaryTreeNode(const T& theElement)
    {
        element(theElement);
        leftChild=rightChild=NULL;
    }
    binaryTreeNode(const T & theElement,
                   binaryTreeNode * theleftChild,
                   binaryTreeNode * theRightChild)
    {
        element(theElement);
        leftChild = theleftChild;
        theRightChild = theRightChild;
    }
//protected:
//    void visit(binaryTreeNode<T> * t);
//public:
//    void preOrder(binaryTreeNode<T> * t );
//    void inOrder(binaryTreeNode<T> * t );
//    void postOrder(binaryTreeNode<T> * t);
};

//visit 函数
template <class T>
void visit(binaryTreeNode<T> * t)
{
    cout<<t->element<<' ';
}

//前项遍历
template  <class T>
void preOrder(binaryTreeNode<T> * t )
{
    //前序遍历二叉树 *t
    if(t != NULL)
    {
        visit(t);
        preOrder(t->leftChild);
        preOrder(t->rightChild);
    }
}

//中项遍历
template  <class T>
void inOrder(binaryTreeNode<T> * t )
{
    //中序遍历二叉树 *t
    if(t != NULL)
    {
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->rightChild);
    }
}

// 后序遍历
template  <class T>
void postOrder(binaryTreeNode<T> * t )
{
    //后序遍历二叉树 *t
    if(t != NULL)
    {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

//层序遍历(使用队列）
template <class T>
void  levelOrder(binaryTreeNode<T> *t )
{
    //层序遍历二叉树
    arrayQueue<binaryTreeNode<T>*> q;
    while (t!=nullptr) {
        visit(t);  //访问t

        //将t的根节点插入队列
        if(t->leftChild != nullptr)
            q.push(t->leftChild);
        if(t->rightChild!=nullptr)
            q.push(t->rightChild);

        //提取下一个节点访问
        try {
            t=q.front();
        } catch (queueEmpty) {
            return ;
        }
        q.pop();
    }
}

#endif // BINARYTHREENODE_H_

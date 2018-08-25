#include <iostream>
#include <cstring>
#include <QtPrintSupport/QtPrintSupport>
#include "booster.h"
#include "linkedbinarytree.h"

using std::cout;
using std::endl;
using std::string;

////设置全局变量,设置最大容忍值
const int tolerance =3;

void placeBoosters(binaryTreeNode<booster> *x)
{
    x->element.degradeToLeaf=0; //设置初始化衰减值为0
    //
    binaryTreeNode<booster> * y=x->leftChild;
    if(y!=nullptr)
    {
        int degradation=y->element.degradeFromParent+
                y->element.degradeToLeaf;
        if(degradation>tolerance)
        {
            //总值大于容忍值,放一个放大器
            y->element.boosterHere=true;
            x->element.degradeToLeaf=y->element.degradeFromParent;
        }
        else{
            //不需要放置放大器
            x->element.degradeToLeaf=degradation;
        }
    }

    //计算右值的衰减量
    y=x->rightChild;
    if(y!=nullptr){
        //x的右子树非空
        int degradation=y->element.degradeToLeaf +
                   y->element.degradeFromParent;
        if(degradation>tolerance){
            y->element.boosterHere=true;
            degradation=y->element.degradeFromParent;
        }
        if(x->element.degradeToLeaf<degradation)
            x->element.degradeToLeaf=degradation; //注意，degradeToLeaf的值取较大者
    }
}

// test linked binary tree class

using namespace std;

int main(void)
{
    booster a, b;
      a.degradeFromParent = 2;
      a.degradeToLeaf =0;
      a.boosterHere = 0;
      b.degradeFromParent=1;
      b.degradeToLeaf=0;
      b.boosterHere = 0;

      linkedBinaryTree <booster> t, u, v, w, x, y;
      u.makeTree(a,x,x);
      v.makeTree(b,u,x);
      u.makeTree(a,x,x);
      w.makeTree(a,u,x);

      b.degradeFromParent=3;
      u.makeTree(b,v,w);
      v.makeTree(a,x,x);

      b.degradeFromParent=3;
      w.makeTree(b,x,x);
      y.makeTree(a,v,w);
      w.makeTree(a,x,x);
      t.makeTree(b,y,w);

      b.degradeFromParent=0;
      v.makeTree(b,t,u);

      v.postOrder(placeBoosters);
      v.postOrderOutput();

      return 0;
}

#ifndef BOOSTER_H
#define BOOSTER_H
#include<iostream>
using std::ostream;
using std::cout;
using std::cin;
using std::endl;

struct  booster
{
    int degradeToLeaf,
        degradeFromParent;
    bool boosterHere;  //是否放置放大器

    void output(ostream& out) const
    {
        out<<boosterHere<<' '<<degradeToLeaf<<' '
           <<degradeFromParent<<' ';
    }
};

//overload
ostream & operator<<(ostream & out,booster x)
{
    x.output(out);
    return out;
}


#endif // BOOSTER_H

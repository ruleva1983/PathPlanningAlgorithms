#ifndef SEARCH_H_
#define SEARCH_H_

#include <vector>
#include <algorithm>

struct List_Element{
    
    List_Element(double x_, double y_, double xp_, double yp_ , double value_):
                 x(x_),
                 y(y_),
                 xp(xp_),
                 yp(yp_),
                 cost(value_){}
                 
    double x, y;
    double xp, yp;
    double cost;
};


class Astar{
public:
    Astar() : OpenList(), ClosedList (){}

    
private:
    std::vector<List_Element> OpenList;
    std::vector<List_Element> ClosedList;
};

#endif

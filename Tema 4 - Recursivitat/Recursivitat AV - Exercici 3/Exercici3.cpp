#include <list>
using namespace std;

int MaxElsRec(list<int> &l, list<int>::iterator it)
{
    if (it == l.end())
    {
        return l.front();
    }
    else
    {
        int max = MaxElsRec(l, ++it);
        if (*it > max)
        {
            return *it;
        }
        else
        {
            return max;
        }
    }
}

int MaxElementsLlista(list<int> &l)
{
    list<int>::iterator it = l.begin();
    return MaxElsRec(l, it);
}

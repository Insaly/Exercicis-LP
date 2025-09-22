#include <vector>
using namespace std;

void quicksort(vector<int>& v, int indexInici, int indexFinal)
{
    if (indexInici < indexFinal)
    {
        int indexPivot = indexInici, aux;
        for (int i = indexInici; i < indexFinal; i++)
        {
            if (v[i] < v[indexFinal])
            {
                aux = v[i];
                v[i] = v[indexPivot];
                v[indexPivot] = aux;
                indexPivot++;
            }
        }
        aux = v[indexFinal];
        v[indexFinal] = v[indexPivot];
        v[indexPivot] = aux;
        quicksort(v, indexInici, indexPivot - 1);
        quicksort(v, indexPivot + 1, indexFinal);
    }
}
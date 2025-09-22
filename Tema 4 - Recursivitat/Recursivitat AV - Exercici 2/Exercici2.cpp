#include <vector>
using namespace std;

void ordenaArray(vector<int>& v, int indexInici, int indexFinal)
{
  if (indexInici < indexFinal)
  {
    int i = indexInici - 1;
    for (int j = indexInici; j < indexFinal; j++)
    {
      if (v[j] < v[indexFinal])
      {
        i++;
        int aux = v[i]; 
        v[i] = v[j];
        v[j] = aux;
      }
    }
    int aux = v[i + 1];
    v[i + 1] = v[indexFinal];
    v[indexFinal] = aux;
    ordenaArray(v, indexInici, i);
    ordenaArray(v, i + 2, indexFinal);
  }
}

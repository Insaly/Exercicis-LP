#ifndef GrafPonderat_h
#define GrafPonderat_h

#include <vector>
#include <string>
#include <cstdio>
#include "Graf.h"

class GrafPonderat : public Graf
{
public:
    GrafPonderat();
    GrafPonderat(const std::vector<std::string>& nodes, const std::vector<std::vector<int>>& parelles_nodes,
                 const std::vector<int>& pesos);
    ~GrafPonderat();


private:
    void crearMatriu(const std::vector<std::vector<int>>& parelles, const std::vector<int>& pesos);


};

#endif /* GrafPonderat_h */

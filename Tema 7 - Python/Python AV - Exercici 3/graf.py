# -*- coding: utf-8 -*-


import copy as cp
import numpy as np
class Graf:
    __slots__ = {'__nodes', '__arestes'}
        
    def __init__(self, nodes, arestes, pesos):
        self.__nodes = cp.deepcopy(nodes)
        self.__arestes = np.zeros([len(nodes), len(nodes)])
        for aresta, pes in zip(arestes, pesos):
            self.__arestes[aresta[0],aresta[1]] = pes
            self.__arestes[aresta[1],aresta[0]] = pes
            
    def __str__(self):
        s = "";
        for posNode, node in enumerate(self.__nodes):
            s = s + "Etiqueta: " + str(node) + "\n"
            s = s + "Arestes: " + str([[vei[0], pes] for vei, pes in np.ndenumerate(self.__arestes[posNode,:]) if pes != 0]) + "\n"
        return s
    
    def cicles(self):
       
        cicles = []
        n = len(self.__nodes)
        
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j + 1, n):
                    if self.__arestes[i, j] != 0 and self.__arestes[j, k] != 0 and self.__arestes[k, i] != 0:
                        cicles.append([self.__nodes[i], self.__nodes[j], self.__nodes[k]])
        return cicles
          
    def nodeMaxArestes(self):
        
        max_arestes = -1
        node_max = None
        
        for i, node in enumerate(self.__nodes):
            num_arestes = np.count_nonzero(self.__arestes[i, :])
            if num_arestes > max_arestes:
                max_arestes = num_arestes
                node_max = node
                
        return node_max
    
    def nodesAillats(self):

        aillats = []

        for i, node in enumerate(self.__nodes):
            if not any(self.__arestes[i, :]) and not any(self.__arestes[:, i]):
                aillats.append(node)

        return aillats
       
    def etiquetesAdjacents(self, node):

        if node not in self.__nodes:
            return []

        index = self.__nodes.index(node)
        adjacents = []

        for i, pes in enumerate(self.__arestes[index, :]):
            if pes != 0:
                adjacents.append(self.__nodes[i])

        return adjacents
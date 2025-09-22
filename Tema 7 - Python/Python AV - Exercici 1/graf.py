# -*- coding: utf-8 -*-

class Graf:
    __slots__ = {'__nodes'}
        
    def __init__(self, nodes, arestes, pesos):
        self.__nodes = [[node, []] for node in nodes]
        for aresta, pes in zip(arestes, pesos):
            self.__nodes[aresta[0]][1].append([aresta[1], pes])
            self.__nodes[aresta[1]][1].append([aresta[0], pes])
            
    def __str__(self):
        s = "";
        for node in self.__nodes:
            s = s + "Comment :=>> Etiqueta: " + str(node[0]) + "\n"
            s = s + "Comment :=>> Arestes: " + str(node[1]) + "\n"
        return s
    
    def cicles(self):
        cicles = []
        for i in range(len(self.__nodes)):
            et_i = self.__nodes[i][0]
            ad_i = self.__nodes[i][1]

            for adj1 in ad_i:
                j = adj1[0]
                et_j = self.__nodes[j][0]
                ad_j = self.__nodes[j][1]

                for adj2 in ad_j:
                    k = adj2[0]
                    et_k = self.__nodes[k][0]
                    ad_k = self.__nodes[k][1]

                    for adj3 in ad_k:
                        if adj3[0] == i:
                            cicle = [et_i, et_j, et_k]
                            cicle.sort()
                            if cicle not in cicles:
                                cicles.append(cicle)
        return cicles

    def nodeMaxArestes(self):
        max = 0
        node = 0
        for n in self.__nodes:
            if len(n[1]) > max:
                max = len(n[1])
                node = n[0]
        return node

    def nodesAillats(self):
        return [node[0] for node in self.__nodes if not node[1]]

    def etiquetesAdjacents(self, node):
        for n in self.__nodes:
            if n[0] == node:
                return [self.__nodes[adjacent[0]][0] for adjacent in n[1]]
        return []
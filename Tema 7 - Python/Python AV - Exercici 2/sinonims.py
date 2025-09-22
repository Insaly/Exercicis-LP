# -*- coding: utf-8 -*-
"""
Created on Wed Jan 24 10:43:25 2018

@author: ernest
"""
import random

def afegeixSinonim(diccionari, paraula, sinonim):

    if paraula not in diccionari:
        diccionari[paraula] = [sinonim]
    elif sinonim not in diccionari[paraula]:
        diccionari[paraula].append(sinonim)


def conversioSinonims(frase, diccionari):
    nova_frase = []
    for paraula in frase:
        if paraula in diccionari and diccionari[paraula]:
            index = random.randrange(0, len(diccionari[paraula]))
            nova_frase.append(diccionari[paraula][index])
        else:
            nova_frase.append(paraula)
    return nova_frase
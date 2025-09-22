# Lliurable I
def suma(llista):
    resultat = 0
    for i in llista:
        resultat += i
    return resultat

# Lliurable II
def minim(llista):
    minim = llista[0]
    index = 0
    for i in range(len(llista)):
        if llista[i] < minim:
            minim = llista[i]
            index = i
    return index, minim

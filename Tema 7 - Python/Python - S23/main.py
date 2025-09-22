from llista import *

grade = 0

l = [6,5,1,2,3,4]

ans = suma(l)
if ans == 21:
	grade += 4
	print(f"Comment ==> Funcio suma correcta")
	print ("Grade :=>>", grade)
else:
    print(f"Comment ==> Error a funcio suma")

indexMin,valorMin = minim(l)
ok = 0
if valorMin == 1:
	ok += 1
if indexMin == 2:
	ok += 1
if ok == 2:
	grade += 6
	print(f"Comment ==> Funcio minim correcta")
	print ("Grade :=>>", grade)
else:
    print(f"Comment ==> Error a funcio minim")

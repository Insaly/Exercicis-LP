from problemas import *



import numpy as np

grade = 0
mat_ex_1 = np.array([[1, 2, 3, 4], [1, 1, 4, 4]])
value = 1
ret = find_val(mat_ex_1, value)
sol = [(0, 0), (1, 0), (1, 1)]
if ret == sol:
    grade += 3.33   
    print(f"Comment ==> Funcion find_val correcta")
    print ("Grade :=>>", grade)
else:
    print(f"Comment ==> Errores en find_val")
    print(f"Comment ==> Esperado: {sol}")
    print(f"Comment ==> Recibido: {ret}")


mat_ex_2 = np.array( [[[3, 1],[3, 1],[3, 1]],[[2, 4],[2, 4],[2, 4]],[[1, 3],[2, 6],[3, 9]]])
meaned = approx_color_to_grayscale(mat_ex_2)
sol_meaned = np.array([[2., 2., 2.], [3., 3., 3.], [2., 4., 6.]])
if (meaned == sol_meaned).all():
    grade += 3.33
    print(f"Comment ==> Funcion approx_to_gray correcta (sin factor)")
    print ("Grade :=>>", grade)
else:
    print(f"Comment ==> Errores en approx_to_grayscale")
    print(f"Comment ==> Esperado: {sol_meaned}")
    print(f"Comment ==> Recibido: {meaned}")

factor = approx_color_to_grayscale(mat_ex_2, np.array([2, 0.5]))
sol_factor = np.array([[6.5, 6.5, 6.5], [6., 6., 6.], [3.5, 7., 10.5]])
if (factor == sol_factor).all():
    grade += 3.34
    print(f"Comment ==> Funcion approx_to_gray correcta (con factor)")
    print ("Grade :=>>", grade)
else:
    print(f"Comment ==> Errores en approx_to_grayscale")
    print(f"Comment ==> Esperado: {sol_factor}")
    print(f"Comment ==> Recibido: {factor}")
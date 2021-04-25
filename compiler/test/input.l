0: t0 = 3 * 5
1: t1 = 4 / 2
2: t2 = - t1
3: t3 = t2 + 1
4: t4 = t0 + t3
5: var_int = t4
6: t5 = 3.0 + var_int
7: var_real = t5
8: t6 = var_real <= var_int
9: var_bool = t6
10: if var_bool goto 12
11: goto 27
12: var_real = 100
13: b = false
14: t7 = ~ 2
15: i = 2
16: t8 = var_real >= var_int
17: if t8 goto 19
18: goto 30
19: t9 = var_real - 1
20: var_real = t9
21: t10 = b || true
22: b = t10
23: goto 16
24: t11 = var_real <= var_int
25: if t11 goto 27
26: goto 30
27: t12 = var_real + 1
28: var_real = t12
29: goto 24
30:

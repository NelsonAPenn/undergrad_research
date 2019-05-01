import numpy as np
import random

def empty(x, y):
    return x*0

n=3

b = np.fromfunction(empty, (n, n), dtype = int)

for i in range(0, n):
    for j in range(i, n):
        if i == j:
            b[i][j] = 0
        else:
            switch = random.random()
            random.seed()
            if switch > random.random():
                a = random.randrange(0, 2000)
                b[i][j] = a
                b[j][i] = a
            #else:
            #    b[i][j] = 0
            #    b[j][i] = 0
print("")
print("%d %d" % (n,n))

for i in range(0,n):
    for j in range(0,n):
        print(b[i][j])
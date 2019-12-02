import numpy as np

fuel = (np.loadtxt('input.txt')//3-2).sum()
print(fuel)

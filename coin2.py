import numpy as np

n, sum = tuple(map(int, input().split()))

choices = list(map(int, input().split()))
mod = 10**9 + 7
choices.sort()

a = np.zeros(sum + 1)

print(a)
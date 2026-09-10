import numpy as np

n, sum = tuple(map(int, input().split()))

choices = list(map(int, input().split()))
MOD = 10**9 + 7
choices.sort()

a = np.zeros(sum + 1)

a[0] = 1
for s in range(1, sum+1):
    if s % choices[0] == 0:
        a[s] = 1

for i in range(1, n):
    c = choices[i]
    for r in range(c):
        a[r::c] = np.cumsum(a[r::c]) % MOD

print(int(a[sum]))
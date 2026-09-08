toh

given sum, and choices

f(sum) = sum of all f(sum - choice) for all choices 

f(x) = 0 for x < 0

n, sum = tuple(map(int, input().split()))

choices = list(map(int, input().split()))

dp = [-1 for _ in range(sum+1)]

def f(sum):
    if sum = 0:
        return 0
    if dp[sum] != -1:
        return dp[sum]
    s = 0
    for c in choices:
        s += f(sum-c)
    dp[sum] = s
    return s

print(f(sum))



so this is taking every permutation

we need to something like 
index

sort choices
start from n

if choice[idx] < sum , take
if not idx--

if idx < 0  and sum != 0, couldnt find any return 0
if idx < 0  nd sum == 0 return 1





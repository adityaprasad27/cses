from collections import defaultdict, deque

n = int(input())
adj = defaultdict(set)

digits = [1, 2, 3, 4, 5, 6, 7, 8, 9]
vis = set()

def d_is_in_n(n, d):
    s = str(n)
    return str(d) in s

# main loop
def f(n):
    if n <= 0:
        return
    if n in vis:
        return 
    vis.add(n)
    for d in digits:
        if d_is_in_n(n, d):
            adj[n].add(n-d)
            f(n-d)

f(n)

def bfs(n):
    q = deque([n])
    v = set()
    res = 1
    while q:
        n = len(q)
        for _ in range(n):
            node = q.popleft()
            v.add(node)
            for nei in adj[node]:
                if nei not in v:
                    if nei == 0:
                        return res
                    q.append(nei)
        res += 1
    return res

print(bfs(n))

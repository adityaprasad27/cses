
Given a number n, you can take any digit in it, substract it so you get to n-d. whats the shortest path to 0

so imagine like 

for d in (1...9) is present in n:
	adj[n].append(n-d) if not already present
		maybe we should have set here

so graph of [number] -> set

then bfs from n to 0 to find shortest path


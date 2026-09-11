given a `n*n` grid with . for walkable paths, * for traps, find number of paths from `[0][0]` to `[n-1][n-1]` 

so a simple recrusion

`dfs(i, j) = dfs(i+1, j) + dfs(i, j+1)`

works, give 0 when out of bounds or encoutner trap and 1 when you reach `[n-1][n-1]` . 

works

but ofc this is not doable becuase recrusion is bad. need array

so n* n array. but then recrusion is top down, in a snese that you need to know i+1 to know i. 


# BOJ 2606 바이러스
백준 Baekjoon Online Judge  
Link: [https://www.acmicpc.net/problem/2606](https://www.acmicpc.net/problem/2606)  



```python
Input: n (컴퓨터의 수), G (그래프)

function dfs(G, i)
    if visited[i]
        return 0
    visited[i] <- True
    s <- 0
    for next_i in G[i]
        s <- s+dfs(G, next_i)
    return s

visited <- [False,...,False] (n개의 요소)
print(dfs(G, 1))
```
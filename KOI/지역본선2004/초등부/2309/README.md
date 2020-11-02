# BOJ 2309 일곱 난쟁이
백준 Baekjoon Online Judge  
Link: [https://www.acmicpc.net/problem/2309](https://www.acmicpc.net/problem/2309)  



```python

Input: a[1,...,9] (난쟁이들의 키)

function find(c, ai, ci)
    if ci == 8
        if sum(c) == 100
            return True
        else
            return False
    
    for i in ai+1,...,7
        c[ci] <- a[i]
        f <- find(c, i, ci+1)
        if f == True
            return True
    return False

c <- Array(7)
i <- 0
find(c, i, 1)
c <- sort(c)
print(c)
```
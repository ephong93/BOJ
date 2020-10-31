# BOJ 2605 줄 세우기
백준 Baekjoon Online Judge  
Link: [https://www.acmicpc.net/problem/2605](https://www.acmicpc.net/problem/2605)  



```python
Input: n (학생 수), a[1,...,n] (학생들이 뽑은 번호)

result <- Array(n)
for i in n,...,1
    count <- a[i]
    for j in n,...,1
        if result[j] is not empty
            continue
        else if count > 0
            count <- count-1
        else
            result[j] = i
            break
print result
```
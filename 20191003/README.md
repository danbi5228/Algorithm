# 2019-10-03 Algorithm Study

## Today

### 물통
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/2251)
* BFS
* Problem Number : 2251
* Result
    * memory : 2028 KB
    * time : 0 ms

### 수열
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/2491)
* 각 자리에서 증가/감소 변수 모두 고려.
* Problem Number : 2491
* Result
    * memory : 2256 KB
    * time : 16 ms

### N과 M (7)
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/15656)
* Recursive Function
* Problem Number : 15656
* Result
    * memory : 1988 KB
    * time : 668 ms 
---
## Today I Learned
* Recursive Function 만들 때에 가장 주의할 점 <br>
: 어떤 데이터를 변화가 없도록 맞춰 줄 것인지 이해하기.<br>
N과 M (7) 문제 - result 값 (vector) 의 변화가 없도록 push 이후 pop 한다.
```cpp
result.push_back(v[i]);
print_n(n, m);
result.pop_back();
```

---
## Assignment
### 평범한 배낭
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/12865)
* Problem Number : 12865

### 재귀호출 문제 2문제
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/tag/%EC%9E%AC%EA%B7%80%20%ED%98%B8%EC%B6%9C)
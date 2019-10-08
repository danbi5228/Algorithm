# 2019-10-08 Algorithm Study

## Today

### 알약
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/4811)
* Dynamic Programming
* Problem Number : 4811
* Result
    * memory : 1988 KB
    * time : 24 ms

### 유레카 이론
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/10448)
* Brute-Force
* Problem Number : 10448
* Result
    * memory : 1988 KB
    * time : 40 ms

### 퇴사
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/14501)
* Brute-Force
* Problem Number : 14501
* Result
    * Fail
---
## Today I Learned

* vector 처음 선언 시에 dump 값으로 초기화
1. 1차원 vector
```cpp
vector <long long> dp(31, -1);
```
2. 2차원 vector
```cpp
vector <vector <long long>> pill_dp(31, vector<long long> (31, -1)) 
```
---
## Assignment

### 퇴사
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/14501)
* Problem Number : 14501
* I need to obviously understand the source code in 14501_solution.cpp

### 평범한 배낭
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/12865)
* Problem Number : 12865

### 유레카 이론
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/10448)
* 1. 삼중 포문 말고 재귀로 구현
* 2. 삼각수를 1개 선택 했을 때-> 2개 선택 했을 때 -> 3개 선택 했을 때를 모두 구현 (중복 제거를 위해 set 이용)

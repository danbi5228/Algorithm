# 2019-11-22 Algorithm Study 

## Today

### 위장
* [Programmers](https://programmers.co.kr/learn/courses/30/lessons/42578)
* Hashing
* Result
    * Success
    * Previous My code, I want to calculate for all each case. 
    * Instead of that, About all count of key
    * [(value(input) + 1(No choice case)) * [value + 1] * ...] - 1(No choice even one thing)
    * is much easier than before  

### 문자열 폭발
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/9935)
* Dynamic Programming
* Problem Number : 9935
* Result
    * memory : 5968 KB
    * time : 80 ms
* In the file, there are 3 way to solve this problem.
* Only first code from the top succeed.

### 반도체 설계
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/2352)
* Dynamic Programming, Greedy Algorithm
* Problem Number : 2352
* Result
    * fail
    * time over
    * I need to think about the right way of dynamic programming

---
## Today I Learned

* vector 로 구현하는 stack
```cpp
input_string.push_back(input[i]);
input_string.pop_back();
```

* string STL
```cpp
    string input = "c343deE3";
    string bomb = "c3"
	string::size_type n;
	
	n = input.find(bomb);
	if (n == string::npos) {
        // if there is no bomb then n == string::npos
		break;
	}
	else {
        // if there is bomb then erase bomb from input[n:n+bomb.size()]
		input.erase(n, bomb.size());
	}
```
* map, key 중복 처리

```cpp
map <string, int>::iterator iter;
iter = closet.find(clothes[i][1]);
if ( iter == closet.end()){
    // if there is key then iter point closet.end()
    ...
}


// key pair를 이용하여 insert 하는 것이 정석
std::map<char,int> mymap;
std::pair<std::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( std::pair<char,int>('z',500) );
  if (ret.second==false) {
    std::cout << "element 'z' already existed";
    std::cout << " with a value of " << ret.first->second << '\n';
  }
```


---
## Assignment

### 반도체 설계
* [BAEKJOON ONLINE JUDGE](https://www.acmicpc.net/problem/2352)
* Dynamic Programming, Greedy Algorithm
* Problem Number : 2352
---

## Reference
* [cplusplus.com](http://www.cplusplus.com/reference/map/map/insert/)
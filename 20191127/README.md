# 2019-11-27 Algorithm Study

## Today

### 기능개발
* [Programmers](https://programmers.co.kr/learn/courses/30/lessons/42586)
* Stack / Queue
* Language
    * C++
* Result
    * Success
    
---
## Today I Learned
* Queue STL
```cpp
#include <queue>

int main(){
    queue <int> q;

    //push
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    //pop
    q.pop();

    // front 
    cout << "front element : " << q.front() << endl;

	// back
	cout << "back element : " << q.back() << endl;

	// size
	cout << "queue size : " << q.size() << endl;

	// is empty
	cout << "Is it empty? : " << (q.empty() ? "Yes" : "No") << endl;

	return 0;
}
```

* Header ```<cmath>```
```cpp

    // 반올림
    round(4.3); // 4.0
    round(4.7); // 5.0

    // 올림
    ceil(4.2); // 5.0

    // 내림
    floor(4.2) // 4.0

```
---
* Reference
    * https://twpower.github.io/76-how-to-use-queue-in-cpp



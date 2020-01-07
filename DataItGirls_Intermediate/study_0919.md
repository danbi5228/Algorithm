# ChekiO

## the most numbers

* 단비
```python
def checkio(*args):
   max = -1000
   min = 1000
   for arg in args:
       if arg < min:
           min = arg
       if arg > max:
           max = arg
   if max == -1000 or min == 1000:
       return 0
   return max - min
```
* 민주
```python
def checkio(*args):
    if args:
        answer = max(args) - min(args)
        if type(max(args)) == float:
            return round(answer, 3)
        return answer

    return 0
```

* 보경
```python
def checkio(*args):
    if len(args) > 0:
        max_num = max(args)
        min_num = min(args)
        return max_num - min_num
    else:
        return 0
```

* 예슬
```python
if len(args) > 0:
        return max(args) - min(args)
    else:
        return 0
```
* Parkito
```python
def checkio(*args):
    return max(args) - min(args) if args else 0
```


## even the last

* 보경
```python
def checkio(array):
    if len(array) > 0:
        count = 0
        last = array[len(array)-1]
        for i in range(0, len(array)):
            if i % 2 == 0:
                count += array[i]
        return last * count
    else:
        return 0
```

* 민주
```python
def checkio(args):
    answer = 0
    if args:
        for i in range(len(args)):
            if i % 2 == 0:
                answer += args[i]
        answer *= args[-1]
    return answer
```

* 단비
```python
def checkio(array):
    result = 0

    if(len(array) == 0):
        return 0
    for i in range(len(array)):
       if i%2 == 0:
           result += array[i]
    return result * array[-1]
```

* 예슬
```python
num = 0
    if array:
        for i in range(len(array)):
            if i%2==0:
                num += array[i]
        return num*array[-1]

    else:

        return 0
```

* Parkito
```python
# enumerate 함수 사용 권장
def checkio(array):
    if not array:
        return 0
    else:
        return sum(n for i, n in enumerate(array) if i % 2 == 0) * array[-1]

```

## secret message

* 민주
```python
def find_message(text):
    answer = []
    for word in text:
        if word.isupper(): answer.append(word)
    return ''.join(answer)
```
* 보경
```python
def find_message(text: str) -> str:
    message = ""
    for i in text:
        if i.isupper() == True:
            message += i
    return message
```
* 예슬
```python
answer =""
    for i in text:
        if i in text.upper():
            answer += i

    return answer
```
* 단비
```python
def find_message(text: str) -> str:
    answer = ""
    for letter in text:
        if letter.isalpha() and not letter.islower():
            answer += letter
    return answer
```
* Parkito
```python
def find_message(text: str) -> str:
    return ''.join(c for c in text if c.isupper())
```

## three words

* 민주
```python
def checkio(text):
    text_list = text.lower().split(' ')
    answer = []
    for i in range(len(text_list)):
        if ((text_list[i].isupper() == False) and (text_list[i].islower()) == False):
            answer.append(i)
    for i in answer:
        if i < 3:
            return False
    return True
```
* 보경
```python
def checkio(words: str) -> bool:
    split_words = words.split()
    count = 0
    for i in split_words:
        # i가 알파벳 문자일때
        if i.isalpha() == True:
            count += 1
        # 문자가 연속으로 나와야하니까 숫자가 나오면 count를 리셋
        else:
            count = 0
        # count에 대한 if문을 for문 안에 넣을 생각을 못 해서 오래 걸렸음..
        if count >= 3:
            return True
    return False
```
* 단비
```python
def checkio(words: str) -> bool:
    words = words.split(' ')
    cnt = 0
    for word in words:
        if cnt == 3:
            break
        if word.isalpha():
            cnt += 1
        else:
            cnt = 0
    return True if cnt == 3 else False
```
* 예슬
```python
def checkio(words: str) -> bool:
   count = 0
   words = words.split()
   for i in words:
       if i.isalpha():
           count+=1
       else:
           count = 0
       if count>=3:
           return True

   return False
```
* Parkito
```python
def checkio(words: str) -> bool:
    words = words.split()
    for i in range(len(words) - 2):
        if words[i].isalpha() and words[i+1].isalpha() and words[i+2].isalpha():
            return True
    return False
```
# index power

* 민주
```python
def power(array: list, n: int):
    if len(array) < n:
        return -1
    return array[n] ** n
```
* 보경
```python
def index_power(array: list, n: int) -> int:
    if len(array)-1 < n :
        return -1
    else:
        return pow(array[n], n)   # pow(n, m) : n의 m승
```
* 단비
```python
def index_power(array: list, n: int) -> int:
    if n >= len(array):
        return -1
    return array[n] ** n
```

* 예슬
```python
if len(array) > n:
       return array[n]**n
   else:
       return -1
```

* Parkito
```python
def index_power(array: list, n: int) -> int:
    return -1 if len(array) <= n else array[n] ** n
```

# Programmers 

## K 번째 수

* 민주
```python
def solution(array, commands):
    answer = [0] * len(commands)
    for i in range(len(commands)):
        answer[i] = sorted(array[commands[i][0] - 1 : commands[i][1]])[commands[i][2]-1]

    return answer
```
* 보경
```python
def solution(array, commands):
    answer = []
    for i in commands:
        start = i[0]
        finish = i[1]
        k = i[2]-1
        answer.append(sorted(array[start-1:finish])[k])
    return answer
```
* 단비
```python
def solution(array, commands):
    answer = []
    for i in range(len(commands)):
        tmp_array = []
        start_idx = commands[i][0] - 1
        end_idx = commands[i][1] - 1
        target_idx = commands[i][2] - 1

        while start_idx <= end_idx:
            print(array[start_idx])
            tmp_array.append(array[start_idx])
            start_idx += 1
        tmp_array.sort()
        answer.append(tmp_array[target_idx])
    return answer
```
* 예슬
```python
def solution(array, commands):
    answer = []
    num=[]
    for i in commands:
        if i[0] == i[1] :
            num = array[i[0]-1]
            answer.append(num)
        else:
            num = array[i[0]-1:i[1]+1]
            num.sort()
            num = num[i[2]-1]
            answer.append(num)
    return answer
```
* Parkito
```python
def solution(array, commands):
    ans = []
    for cmd in commands:
        start, end, k = cmd
        part = sorted(array[start - 1:end])
        ans.append(part[k - 1])

    return ans
'''
아래와 같은 설정이 가능하다.
l = (1, 2, 3)
a, b, c = l
'''
```
---

## Programmers - 체육복
자신의 앞 사람은 자신외의 빌려줄 수 있는 사람에 대한 가능성이 없다. 따라서 무조건 앞 사람에게 빌려주는 것을 먼저 전제로 확인을 한 뒤에 뒷사람에게 빌려줄 수 있는 지를 확인한다.


* 보경
```python
# 돌아가지 못하는 이유 : for 문 안에서 대상이 되는 리스트의 원소를 직접 삭제하기 때문 --> 예상치 못한 동작을 일으킬 수 있음
# 새로운 list를 만들어서 사용하는 것을 권장
def solution(n, lost, reserve):
    for i in lost:
        if i in reserve:
            reserve.remove(i)
            lost.remove(i)
        elif i-1 in reserve:
            reserve.remove(i-1)
            lost.remove(i)
        elif i+1 in reserve:
            reserve.remove(i+1)
            lost.remove(i)
    answer = n-len(lost)
    return answer
```

* 민주
```python
def solution(n, lost, reserve):

    # 순서대로
    lost.sort()
    reserve.sort()

    # 잃어버렸지만 여벌 있는 경우
    still_got_clothes = set(lost) & set(reserve)
    lost = list(set(lost) - still_got_clothes)
    reserve = list(set(reserve) - still_got_clothes)

    # # 앞 뒤 번호에 Reserve 가 있는지, 빌리면 Remove
    for number in reserve:

        if (number - 1) in lost:
            lost.remove(number - 1)

        elif (number + 1) in lost:
            lost.remove(number + 1)

    return n - len(lost)
```
* 단비
```python
from itertools import zip_longest
def solution(n, lost, reserve):
    answer1 = 0
    answer2 = 0

    lost.sort()
    reserve.sort()

    for l in lost:
        if lost in reserve:
            lost.remove(l)
            reserve.remove(l)

    for l_st, r_st in zip_longest(lost, reserve, fillvalue=-1):
        if l_st == -1:
            break
        if abs(l_st - r_st) != 1:
            answer1 += 1

    return n - answer1
```

* Parkito
```python
def solution(N, lost, reserve):
    lost, sorted_reserve = sorted(lost), sorted(reserve)
    reserve = []
    # 문제 그 어디에도 목록이 정렬되어 있을 것이라는 희망을 품게 하는 문장은 없습니다.

    for r in sorted_reserve:
        if r in lost:
            lost.pop(lost.index(r))
        else:
            reserve.append(r)

    for r in reserve:
        if (r - 1) in lost:
            lost.pop(lost.index(r - 1))
        elif (r + 1) in lost:
            lost.pop(lost.index(r + 1))

    return N - len(lost)
```

* 한슬
```python
def solution(n, lost, reserve):
    lost, reserve = [i for i in lost if i not in reserve], [i for i in reserve if i not in lost]

    answer = n - len(lost)

    lost.sort()
    reserve.sort()

    for i in lost:
        for j in reserve:
            if i - 1 == j or i + 1 == j:
                answer += 1
                reserve.remove(j)
                break

    return answer
```

---
# 필기

* ctrl + '[' / ']' : indent 정리 단축키

* list -> set : 위치정보가 없어진다!

* pass/continue/break 차이
pass -> 한 줄 채우는 용도. 그 다음 줄의 같은 인덴트의 내용이 실행됨
continue -> 그 다음 흐름으로 넘어간다. 다음 줄의 내용은 실행되지 않는다. 루프 안에서만 사용 가능하다.
break -> 아예 해당 루프를 빠져나온다. 루프 안에서만 사용 가능하다.

* sorted -> 원래 배열을 복사하여 정렬한다.

* 도움말 함수
dir(list) -> list 내의 method 확인이 가능.
help(list.count) -> count method 사용 설명. help 함수는 괄호 안의 함수에 대한 사용 설명이 나타난다.
'''
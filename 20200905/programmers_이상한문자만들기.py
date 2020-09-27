def solution(s):
    answer = ''
    
    s = s.lower()
    s_arr = s.split(' ')
    
    for word in s_arr:
        for i in range(len(word)):
            if i%2 == 0:
                answer += word[i].upper()
            else:
                answer += word[i]
        answer += ' '
    return answer[:-1]

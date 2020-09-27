def solution(x, n):
    answer = []
    
    interval = x
    while(len(answer) != n):
        answer.append(x)
        x += interval
    return answer

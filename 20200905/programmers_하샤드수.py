def solution(x):
    answer = True
    x_arr = []
    if x%10 == 0 or x<=10:
        return answer
    
    copy_x = x
    div_10 = 1000
    while (1):
        n = int(copy_x/div_10)
        x_arr.append(n)
        copy_x -= n*div_10
        div_10 /= 10
        if copy_x == 0:
            break
    
    if x%sum(x_arr) != 0:
        answer = False
    return answer

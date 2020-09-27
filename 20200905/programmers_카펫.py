def solution(brown, yellow):
    answer = []
    
    carpet = brown+yellow
    
    #가로
    width = 0
    #세로
    height = 0
    
    for i in range(carpet):
        if i<2:
            continue
        if carpet%i == 0:
            q = carpet/i
            if q>=i and q>2:
                if brown == (q*2) + (i*2) -4 :
                    width = q
                    height = i        
    answer.append(width)
    answer.append(height)
    return answer

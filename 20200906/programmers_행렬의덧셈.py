def solution(arr1, arr2):
    answer = []
    
    row = 0
    col = 0
    for i in arr2:
        tmp = []
        for elem in i:
            tmp.append(arr1[row][col]+elem)
            col += 1
        answer.append(tmp)
        row += 1
        col = 0
    return answer

# ing - just for the cases
def solution(numbers):
    answer = ''
    str_numbers = []
    numbers_arr = []
    
    for i in range(100001):
        numbers_arr.append(0)
    
    for i in numbers:
        numbers_arr[i] += 1
        str_numbers.append(str(i))
    
    while (sum(numbers_arr)!=0):
        max_number = '0'
        for i in str_numbers:
            if max_number < i :
                if i[len(max_number):len(max_number)+1] > max_number:
                    max_number = i
                    continue
                # '3' and '34' 일때 둘 다 동일하게  '3'
                if i[:len(max_number)] > max_number:
                    max_number = i
                
        numbers_arr[int(max_number)] -= 1
        str_numbers.remove(max_number)
        
        for i in range(numbers_arr[int(max_number)]):
            str_numbers.append(max_number)
            
        answer += max_number
    return answer



# ing
def solution(numbers):
    answer = ''
    str_numbers = []
    numbers_arr = []
    
    for i in range(100001):
        numbers_arr.append(0)
    
    for i in numbers:
        numbers_arr[i] += 1
        str_numbers.append(str(i))
    
    while (sum(numbers_arr)!=0):
        max_number = '0'
        for i in str_numbers:
            if max_number < i :
                # '3' and '34' 일때 둘 다 동일하게 '3'
                if max_number == i[:len(max_number)]:
                    if max_number < i[len(max_number)]
                
        numbers_arr[int(max_number)] -= 1
        str_numbers.remove(max_number)
        
        for i in range(numbers_arr[int(max_number)]):
            str_numbers.append(max_number)
            
        answer += max_number
    return answer



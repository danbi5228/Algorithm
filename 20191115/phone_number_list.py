def solution(phone_book):
    answer = True
    
    for standard_num in phone_book:
        standard = standard_num
        standard_size = len(standard);
        for phone_num in phone_book:
            if standard_num == phone_num:
                continue
            if standard in phone_num[:standard_size]:
                return False
    return True
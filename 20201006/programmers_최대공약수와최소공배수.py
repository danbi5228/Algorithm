# 유클리드 호제법
def gcd(n, m):
    if n%m == 0:
        return m
    return gcd(m,n%m)
def solution(n, m):
    answer = []
    answer.append(gcd(n,m))
    answer.append(n*m / answer[0])
    return answer

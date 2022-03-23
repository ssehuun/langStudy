"""
https://programmers.co.kr/learn/courses/30/lessons/86051
월간 코드 챌린지 시즌3 > 없는 숫자 더하기

- 제한사항
1 ≤ numbers의 길이 ≤ 9
0 ≤ numbers의 모든 원소 ≤ 9
numbers의 모든 원소는 서로 다릅니다.

- 입출력 예
numbers				result
[1,2,3,4,6,7,8,0]	14
[5,8,4,0,6,7,9]		6
"""

""" 성공 내풀이"""
def solution(numbers):
    li = [0,1,2,3,4,5,6,7,8,9]
    answer = 0
    for i in li:
        if i not in numbers:
            answer += i    
    return answer


""" 성공 다른풀이"""
def solution(numbers):
    return 45 - sum(numbers)

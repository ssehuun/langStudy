"""
https://programmers.co.kr/learn/courses/30/lessons/1845
찾아라 프로그래밍 마에스터 > 폰켓몬

- 제한사항
nums는 폰켓몬의 종류 번호가 담긴 1차원 배열입니다.
nums의 길이(N)는 1 이상 10,000 이하의 자연수이며, 항상 짝수로 주어집니다.
폰켓몬의 종류 번호는 1 이상 200,000 이하의 자연수로 나타냅니다.
가장 많은 종류의 폰켓몬을 선택하는 방법이 여러 가지인 경우에도, 선택할 수 있는 폰켓몬 종류 개수의 최댓값 하나만 return 하면 됩니다.

- 입출력예
nums			result
[3,1,2,3]		2
[3,3,3,2,2,4]	3
[3,3,3,2,2,2]	2
"""

""" 맞은 내풀이 """
def solution(nums):
    answer = 0
    s = set(nums)
    if len(s) > len(nums)//2:
        answer = len(nums)//2
    else:
        answer = len(s)
    return answer


""" 간단한 다른 사람 풀이 """
def solution(ls):
    return min(len(ls)/2, len(set(ls)))

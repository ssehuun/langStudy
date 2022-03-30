"""
https://programmers.co.kr/learn/courses/30/lessons/17681
2018 KAKAO BLIND RECRUITMENT > [1차] 비밀지도

- 입력형식
입력으로 지도의 한 변 크기 n 과 2개의 정수 배열 arr1, arr2가 들어온다.
1 <= n <= 16
arr1, arr2는 길이 n인 정수 배열로 주어진다.
정수 배열의 각 원소 x를 이진수로 변환했을 때의 길이는 n 이하이다. 즉, 0 <= x <= 2^n - 1을 만족한다.

- 출력형식
원래의 비밀지도를 해독하여 '#', 공백으로 구성된 문자열 배열로 출력하라

- 입출력예
매개변수	값
n			5
arr1		[9, 20, 28, 18, 11]
arr2		[30, 1, 21, 17, 28]
출력		["#####","# # #", "### #", "# ##", "#####"]
"""


""" 맞은 내풀이"""
def solution(n, arr1, arr2):
    bin_li = []
    answer = []
    tmp = []
    for i, j in zip(arr1, arr2):
        bin_li.append(bin(i | j)[2:])
    
    for y in bin_li:
        t = y.zfill(n)
        tmp.append(t)
        
    for k in tmp:
        s = ""
        for h in k:
            if h == "1":
                s += "#"
            else:
                s += " "
        answer.append(s)
    return answer


""" 맞은 다른사람풀이"""
def solution(n, arr1, arr2):
    answer = []
    for i,j in zip(arr1,arr2):
        a12 = str(bin(i|j)[2:])
        a12=a12.rjust(n,'0')
        a12=a12.replace('1','#')
        a12=a12.replace('0',' ')
        answer.append(a12)
    return answer

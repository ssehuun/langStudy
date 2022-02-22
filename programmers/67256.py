"""
https://programmers.co.kr/learn/courses/30/lessons/67256
2020 카카오 인턴십 > 키패드 누르기

제한사항
numbers 배열의 크기는 1 이상 1,000 이하
numbers 배열 원소의 값은 0 이상 9 이하인 정수
hand는 "left" 또는 "right"
왼손 엄지손가락을 사용한 경우는 L, 오른손 엄지손가락을 사용한 경우는 R을 순서대로 이어붙여 문자열 형태로 return

입출력예
numbers								hand		result
[1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5]	"right"		"LRLLLRLLRRL"
[7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2]	"left"		"LRLLRRLLLRR"
[1, 2, 3, 4, 5, 6, 7, 8, 9, 0]		"right"		"LLRLLRLLRL"
"""

""" 성공풀이"""
keypad = [[1,2,3], [4,5,6], [7,8,9], ["*", 0, "#"]]

def solution(numbers, hand):
    l_cur_y = 3
    l_cur_x = 0
    r_cur_y = 3
    r_cur_x = 2
    answer = ''
    for n in numbers: # numbers의 길이 1000이하        
        if n == 1:
            l_cur_y = 0
            l_cur_x = 0
            answer += "L"
        elif n == 4:
            l_cur_y = 1
            l_cur_x = 0
            answer += "L"
        elif n == 7:
            l_cur_y = 2
            l_cur_x = 0
            answer += "L"
        elif n == 3:
            r_cur_y = 0
            r_cur_x = 2
            answer += "R"
        elif n == 6:
            r_cur_y = 1
            r_cur_x = 2
            answer += "R"
        elif n == 9:
            r_cur_y = 2
            r_cur_x = 2
            answer += "R"
        else:
            for row in range(len(keypad)):
                for col in range(3):
                    if keypad[row][col] == n:
                        if (abs(col-l_cur_x)+abs(row-l_cur_y)) < (abs(col-r_cur_x)+abs(row-r_cur_y)):
                            l_cur_y = row
                            l_cur_x = col
                            answer += "L"
                        elif (abs(col-l_cur_x)+abs(row-l_cur_y)) > (abs(col-r_cur_x)+abs(row-r_cur_y)):
                            r_cur_y = row
                            r_cur_x = col
                            answer += "R"
                        elif (abs(col-l_cur_x)+abs(row-l_cur_y)) == (abs(col-r_cur_x)+abs(row-r_cur_y)):
                            if hand == "left":
                                l_cur_y = row
                                l_cur_x = col
                                answer += "L"
                            elif hand == "right":
                                r_cur_y = row
                                r_cur_x = col
                                answer += "R"
    return(answer)

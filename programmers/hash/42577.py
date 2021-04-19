/* 전화번호 목록
 * https://programmers.co.kr/learn/courses/30/lessons/42577?language=python3
 * case - 16/20
 * efficiency - 2/4
 */

def solution(phone_book):
    phone_book.sort(key=len)
    for i in range(len(phone_book)):
        j = phone_book[i]
        print("j: "+j)
        for k in phone_book[i+1:]:
            print("k: "+k)
            if j in k: 
                return False
    return True

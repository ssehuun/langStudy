/* 전화번호 목록
 * https://programmers.co.kr/learn/courses/30/lessons/42577?language=python3
 * case - 16/20
 * efficiency - 2/4
 */

def solution(phone_book):
    phone_book.sort(key=len)
    for i in range(len(phone_book)):
        j = phone_book[i]
        for k in phone_book[i+1:]:
            if j in k: 
                return False
    return True


/* 전화번호가 접두사에 있는것을 확인해야 하므로, 슬라이싱 필요
 * 정확성: 83.3
 * 효율성: 16.7
 * 합계: 100.0 / 100.0
 */
def solution(phone_book):
    answer = True
    phone_book.sort()
    for i in range(len(phone_book)-1):
        if phone_book[i] in phone_book[i+1][:len(phone_book[i])]:
            answer = False
    return answer

/*
https://www.acmicpc.net/problem/10610
런타임 에러난 접근법 - 문자열로 입력받아서 내림차순으로 순회를 할 때,
정수로 변환후 30으로 나눠 떨어지는지 확인한다.

정답 접근법 - 30의 배수는 3의 배수, 10의 배수이기도 하니 오름차순으로 정렬했을 때,
첫 원소가 0이고 자릿수를 모두 더한 값이 3의 배수이면 된다.
참고 블로그 - https://kyu9341.github.io/algorithm/2020/03/02/algorithm10610/
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
	int max_num = 0;
	int each_sum = 0;
	string N;
	cin >> N;

	sort(N.begin(), N.end());
	for (int i = 0; i < N.size(); i++) {
		each_sum += N[i] - '0'; // 문자 - '0' 은 숫자
	}
	if (N[0] == '0' && each_sum % 3 == 0) {
		reverse(N.begin(), N.end());
		cout << N;
	}
	else {
		cout << -1;
	}
	return 0;
}

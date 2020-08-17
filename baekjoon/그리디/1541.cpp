/*
https://www.acmicpc.net/problem/1541
접근법 - 괄호를 이용해 최소를 만들기 위해서는 처음 마이너스 기호가 나오고 다음 숫자부터 모두 괄호 처리로 빼주면 된다.
stoi(문자열을 정수로 바꿔주는 함수, string에 포함)는 C++11 버전에서만 컴파일 가능하다.
참고 블로그 - https://jaimemin.tistory.com/504
*/
#include <iostream>
#include <string>
using namespace std;

int main(void){
	string str;
	cin >> str;
	
	int result = 0;
	string temp = "";
	bool minus = false;

	for (int i = 0; i <= str.size(); i++)
	{
		//연산자일 경우
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
		{
			if (minus)
				result -= stoi(temp);
			else
				result += stoi(temp);

			temp = ""; //초기화
			//괄호를 뺄셈 이후에 치면 최소

			if (str[i] == '-')
				minus = true;
			continue;
		}
		//피연산자일 경우
		temp += str[i];
	}
	cout << result;

	return 0;
}

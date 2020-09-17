/*
짝지어 제거하기
https://programmers.co.kr/learn/courses/30/lessons/12973?language=cpp
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<int> st;
	for(int i = 0; i < s.size(); i++){
		if(!st.empty() && s[i] == st.top()){
			st.pop();
		}else{
			st.push(s[i]);
		}
	}
	if(!st.empty()) return answer;
	else answer = 1;
	return answer;
}

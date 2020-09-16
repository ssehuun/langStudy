/*
올바른 괄호
https://programmers.co.kr/learn/courses/30/lessons/12909
*/
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
	bool answer = false;
	stack<int> st;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '('){
			st.push(s[i]);
		}else{
			if(!st.empty() && st.top() == '('){ // stack의 pop을 할 때 empty() 조건을 넣지 않으면 segmentation fault 오류 발생
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
	}
	if(st.empty()) answer = true;
	return answer;
}

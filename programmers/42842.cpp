/*
카펫 - https://programmers.co.kr/learn/courses/30/lessons/42842
정확성 - 100
*/
#include <string>
#include <vector>
#include <cstdio>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

// 약수 구하는 함수
void divisors(int y){
	for(int i = 1; i*i <= y; i++){
		if(y % i == 0){
			m[y/i] = i;
		}
	}
}

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	divisors(yellow);
	for(auto i : m){
		if((i.first+2) * (i.second+2) == brown+yellow){
			answer.push_back(i.first+2);
			answer.push_back(i.second+2);
		}
	}
	return answer;
}

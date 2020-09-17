/*
두 개 뽑아서 더하기
https://programmers.co.kr/learn/courses/30/lessons/68644
sort, unique, erase 사용법
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
	vector<int> answer;
	int sum = 0;
	for(int i = 0; i < numbers.size(); i++){
		for(int j = i+1; j < numbers.size(); j++){
			sum = numbers[i]+numbers[j];
			answer.push_back(sum);
		}
	}
	sort(answer.begin(), answer.end());
	answer.erase(unique(answer.begin(), answer.end()), answer.end());

	return answer;
}

/*
https://www.acmicpc.net/problem/5585
*/
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int mony, change, min_num = 0;
	vector<int> vec;
	vec.push_back(500);
	vec.push_back(100);
	vec.push_back(50);
	vec.push_back(10);
	vec.push_back(5);
	vec.push_back(1);

	scanf("%d", &mony);
	change = 1000 - mony;

	for(int i=0; i<6; i++){
		if (change / vec[i] == 0) {
			continue;
		}else {
			min_num += change / vec[i];
			change = change % vec[i];
		}
	}
	printf("%d", min_num);
	return 0;
}

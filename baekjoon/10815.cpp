/*
2020.01.21
map에 key, value값을 넣은 뒤
찾고자 하는 key값은 이진탐색으로 찾기 때문에 O(logn) 시간 걸림
*/
#include <map>
#include <cstdio>

int main(){
	int N, num;
	std::map<int, int> m;
	scanf("%d", &N);
	while(N--){
		scanf("%d", &num);
		m[num] = num;
	}
	int M, num2;
	scanf("%d", &M);
	while(M--){
		scanf("%d", &num2);
		printf("%d ", m.count(num2));
	}	
	return 0;
}

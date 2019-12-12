// pair를 쓰기 위해 untility include
// pairt도 sort로 오름차순 정렬이 됨, x값, y값까지 같이 고려됨
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int main(){
	int N;
	vector<pair<int, int>> vec;
	scanf("%d", &N);
	int a,b;
	while(N--){
		scanf("%d %d", &a, &b);
		vec.push_back(pair<int, int>(a,b));
	}
	sort(vec.begin(), vec.end());
	N = vec.size();
	int i = 0;
	while(N--){ 
		printf("%d %d\n", vec[i].first, vec[i].second);
		i++;
	}
	return 0;
}

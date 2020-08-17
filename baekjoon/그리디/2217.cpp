//https://www.acmicpc.net/problem/2217

/*
접근법 - 로프를 다 사용한다면 오름차순 정렬된 벡터의 첫 원소에 로프개수를 곱하면 되겠지만
로프를 모두 사용할 필요는 없다. 때문에 첫 원소에 로프개수를 곱한 것을 기준으로
최소 길이의 기준을 올려가면서 비교하여 최대값을 구한다.
*/

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int i, rope, N, max_weight;
	vector<int> vec;

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &rope);
		vec.push_back(rope);
	}
	sort(vec.begin(), vec.end());
	max_weight = vec[0] * N;
	
	for (i = 1; i < N; i++) {
		if (max_weight < vec[i] * (N - i)) {
			max_weight = vec[i] * (N - i);
		}
	}
	printf("%d", max_weight);

	return 0;
}

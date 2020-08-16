#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
	return (a.second < b.second);
}
int main() {
	int N, i, p1, p2, min_num, cnt = 0;

	scanf("%d", &N);
	vector<pair<int, int> > vec;

	for (i = 0; i < N; i++) {
		scanf("%d %d", &p1, &p2);
		vec.push_back(make_pair(p1, p2));
	}
	sort(vec.begin(), vec.end()); // 끝난 시각 정렬전에 시작시간도 빠른 순서대로
	sort(vec.begin(), vec.end(), sortbysec);

	min_num = vec[0].second;
	cnt++;

	for (i = 1; i < N; i++) {
		if (vec[i].first >= min_num) {
			min_num = vec[i].second;
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}

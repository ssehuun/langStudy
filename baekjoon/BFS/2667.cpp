/*
단지번호붙이기 - https://www.acmicpc.net/problem/2667
접근법 - main함수에서 단지를 찾기 위해 bfs 함수를 호출하기 위한 조건(집이 없거나 방문한 곳은 탐색 통과)을 넣었다. 결과적으로 bfs함수를 3번 호출하면 단지가 3개 있는것이다.
집을 찾는것은 일반적인 bfs 알고리즘과 거의 같다.
큐에 넣으면서 집 개수를 증가시킨다. 
*/
#include <iostream>
#include <utility> // std::pair
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 26;
int mat[MAX][MAX];
int home_cnt; // 집 수
bool v[MAX][MAX]; //방문 체크
int y[4] = {0, 1, 0, -1};
int x[4] = {1, 0, -1, 0};
vector<int> complex_num; // 단지 체크가 끝나면 벡터에 넣음
int N;

int bfs(int n, int m){
	queue<pair<int, int> > q; // mat의 위치를 저장
	q.push(make_pair(n, m));
	v[n][m] = true;
	home_cnt = 0;

	while(!q.empty()){
		int curY = q.front().first;
		int curX = q.front().second;
		//cout << "pop curY: " << curY << " curX: " << curX << endl;
		home_cnt++;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			if(mat[curY+y[i]][curX+x[i]] == 0) continue;
			if(curY+y[i] <= 0 || curY+y[i] > N || curX+x[i] <= 0 || curX+x[i] > N) continue;
			if(v[curY+y[i]][curX+x[i]]) continue;
			q.push(make_pair(curY+y[i], curX+x[i]));
			v[curY+y[i]][curX+x[i]] = true;
		}
	}
	return home_cnt;
}

int main(void){
	cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%1d", &mat[i][j]);
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if(mat[i][j] == 0 || v[i][j]){
				continue;
			} else{
				//cout << "start Y: " << i  << " X: " << j << endl;
				//cout << bfs(i, j) << endl;
				complex_num.push_back(bfs(i, j));
			}
		}
	}
	sort(complex_num.begin(), complex_num.end());
	cout << complex_num.size() << endl;
	for(int i = 0; i < complex_num.size(); i++){
		cout << complex_num[i] << endl;
	}
	return 0;
}

/*
미로탐색 - https://www.acmicpc.net/problem/2178
접근법 - 매트릭스가 0인 곳을 못지나가고, 각 모서리 범위 지정하고, 이미 방문한곳은 가지 않는 조건들로 앞쪽에서 거른다.
이미 방문한 곳은 다시 가지 않기 위해 push 하면서 방문처리 해준다.
*/
#include <iostream>
#include <utility> // std::pair
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 101;
int mat[MAX][MAX]; // 미로 2차원 배열
bool v[MAX][MAX]; // 방문 체크
int cnt[MAX][MAX]; // 시작부터 각 위치까지 거리

int dy[4] = {0, 1, 0, -1}; // y축 오른쪽, 아래, 왼쪽, 위로 순서대로 탐색
int dx[4] = {1, 0, -1, 0}; // x축 오른쪽, 아래, 왼쪽, 위로 순서대로 탐색
int N, M;

int bfs(int n, int m){
	queue<pair<int, int> > q;
	q.push(make_pair(n, m));
	v[n][m] = true;
	cnt[n][m] = 1;

	while(!q.empty()){
		int curY = q.front().first;
		int curX = q.front().second;
		//cout << "curY: " << curY << ' ' << "curX: " << curX << endl;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			if(mat[curY+dy[i]][curX+dx[i]] == 0) continue;
			if(curX+dx[i] <= 0 || curX+dx[i] > M || curY+dy[i] <= 0 || curY+dy[i] > N) continue; // x가 열, y가 행이므로 m, n
			if(v[curY+dy[i]][curX+dx[i]]) continue; // dx, dy for문으로 4방향 탐색
			q.push(make_pair(curY+dy[i], curX+dx[i]));
			v[curY+dy[i]][curX+dx[i]] = true;
			cnt[curY+dy[i]][curX+dx[i]] = cnt[curY][curX]+1;
		}
	}
	return cnt[N][M];
}

int main(void){
	cin >> N >> M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scanf("%1d", &mat[i][j]);
		}
	}
	cout << bfs(1, 1);
	return 0;
}

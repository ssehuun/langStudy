/*
섬의 개수 - https://www.acmicpc.net/problem/4963
접근법 - 일반 BFS이지만 대각선도 동시에 탐색해야 한다.
대각선 또한 4방향으로 탐색하는 배열을 선언하여 bfs 함수안에 조건으로 넣어 해결하였다.
*/
#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 51;
int mat[MAX][MAX];
int v[MAX][MAX];
vector<int> vec;
int dx[4] = {1, 0, -1, 0}; // x축, 오/아/왼/위 순서
int dy[4] = {0, 1, 0, -1}; // y축
int ddx[4] = {1, 1, -1, -1}; // 오른쪽 위, 오른쪽 아래, 왼쪽 아래, 왼쪽 위
int ddy[4] = {-1, 1, 1, -1};
int w, h, island_num = 0; // 너비, 높이

void bfs(int sy, int sx){
	queue<pair<int, int> > q;
	v[sy][sx] = true;
	q.push(make_pair(sy, sx));
	while(!q.empty()){
		int cy = q.front().first;
		int cx = q.front().second;
		//cout << "cy: " << cy << " cx: " << cx << endl;
		q.pop();
		for(int i = 0; i < 4; i++){
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nny = cy + ddy[i];
			int nnx = cx + ddx[i];
			if(ny >= 1 && ny <= h && nx >= 1 && nx <= w && !v[ny][nx] && mat[ny][nx] == 1) {
				q.push(make_pair(ny, nx));
				v[ny][nx] = true;
			}
			if(nny >= 1 && nny <= h && nnx >= 1 && nnx <=w && !v[nny][nnx] && mat[nny][nnx] == 1){
				q.push(make_pair(nny, nnx));
				v[nny][nnx] = true;
			}
		}
	}
	island_num++;
}

int main(void){
	while(1){
		scanf("%d %d", &w, &h);
		if(w == 0 && h == 0) break;
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				scanf("%d", &mat[i][j]);
			}
		}
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				if(v[i][j] == false && mat[i][j] == 1)
					bfs(i, j);
			}
		}
		vec.push_back(island_num);
		island_num = 0;
		for(int i = 1; i <= h; i++){
			for(int j = 1; j <= w; j++){
				v[i][j] = false;
				mat[i][j] = 0;
			}
		}
	}
	for(int i = 0; i < vec.size(); i++)
		printf("%d\n", vec[i]);
	return 0;
}

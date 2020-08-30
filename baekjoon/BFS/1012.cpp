/*
유기농 배추 - https://www.acmicpc.net/problem/1012
접근법 - https://www.acmicpc.net/problem/2667 와 거의 같다.
if조건문 신경써서 하자, 여기서 시간낭비ㅠㅠ 
*/
#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 50;
int mat[MAX][MAX];
bool v[MAX][MAX]; //방문 체크
int worm;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};
int T, M, N, K, X, Y;

void bfs(int cury, int curx){
	queue<pair<int, int> > q;
	q.push(make_pair(cury, curx));
	v[cury][curx] = true;
	while(!q.empty()){
		int herey = q.front().first;
		int herex = q.front().second;
		//cout << endl << "start cury: " << cury << " curx: " << curx;	
		q.pop();
		for(int i = 0; i < 4; i++){
			int newx = herex+x[i];
			int newy = herey+y[i];
			if(newx >= 0 && newx < M && newy >= 0 && newy < N && !v[newy][newx] && mat[newy][newx]){
				v[newy][newx] = true;
				q.push(make_pair(newy, newx));		
			}
		}
	}
}

int main(void){
	cin >> T; // test case
	while(T--){
		cin >> M >> N >> K; // M:가로길이 N:세로길이 K:배추 위치의 개수
		// 배추 메트릭스 초기화
		worm = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				mat[i][j] = 0;
				v[i][j] = false;
			}
		}
		// 배추 심은곳 1로 초기화
		for(int i = 1; i <= K; i++){
			scanf("%d %d", &X, &Y);
			mat[Y][X] = 1;
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(!v[i][j] && mat[i][j] == 1){
					bfs(i, j);
					worm++;
				}
			}
		}
		printf("%d\n", worm);
	}
	return 0;
}

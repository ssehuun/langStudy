/*
연구소 - https://www.acmicpc.net/problem/14502
접근법 - 1. 바이러스의 위치는 한번 입력이 들어오면 변하지 않으므로 큐에 담아두고 BFS에선 큐에 복사하여 사용
2. 0 발견시 연구실 상태를 tmpmat에 복사하고 1을 할당하면서 첫번째 벽을 세운다. 0의 개수를 감소시키고, makeWall 호출. 완전탐색 시작
3. 재귀함수 호출을 통해 벽을 2개 더 세운다.
4. bfs함수에서 spreadLab은 3개의 벽으로 막은 후 바이러스가 퍼졌을 때의 연구소의 상황을 저장하는 곳.안전지역이 많다는 것은 0이 많다는 뜻.

참고 블로그 - https://kevinthegrey.tistory.com/157
*/
#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring> // memcpy
using namespace std;

const int MAX = 9; // C에서 MAX 변수가 배열에 못들어감
int mat[MAX][MAX], tmpmat[MAX][MAX];
int dx[4] = {1, 0, -1, 0}; // x축, 오/아/왼/위 순서
int dy[4] = {0, 1, 0, -1}; // y축
int N, M, zeroCnt, safeZone;
queue<pair<int, int> > q;

// 바이러스 퍼트리기(BFS)
void bfs(int& zero){ // zero가 최대한 조금 감소해야 안전범위(0)이 넓다는 뜻. 
	// 4. spreadLab은 3개의 벽으로 막은 후 바이러스가 퍼졌을 때의 연구소의 상황을 저장하는 곳.
	int spreadLab[MAX][MAX];
	memcpy(spreadLab, tmpmat, sizeof(tmpmat));
	int zc = zero;
	queue<pair<int, int> > innerQ = q;
	
	while(!innerQ.empty()){
		int y = innerQ.front().first;
		int x = innerQ.front().second;
		innerQ.pop();
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx >= 1 && nx <= M && ny >= 1 && ny <= N && spreadLab[ny][nx] == 0){
				spreadLab[ny][nx] = 2;
				--zc;
				innerQ.push(make_pair(ny, nx));		
			}
		}
	}
	//cout <<" safeZone: " << safeZone;
	safeZone = max(safeZone, zc);
}
//벽 세우기(재귀호출)
void makeWall(int cnt, int& zero){
	// 3개의 벽이 세워졌을 때 바이러스를 퍼트린다.	
	if(cnt == 3){
		bfs(zero);
		return;
	}
	// 3. 재귀함수 호출을 통해 벽을 2개 더 세운다.
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(tmpmat[i][j] == 0){
				tmpmat[i][j] = 1;
				--zero;
				makeWall(cnt+1, zero);
				// 모든 경우의 수를 넣어야 하므로 기존의 1을 0으로 바꾸어주는 역할
				tmpmat[i][j] = 0;
				++zero;
			}
		}
	}
}

int main(void){
	scanf("%d %d", &N, &M);
	zeroCnt = N * M;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scanf("%d", &mat[i][j]); // 0:빈칸 1:벽 2:바이러스
			if(mat[i][j] != 0){
				--zeroCnt;
				// 1. 바이러스의 위치는 한번 입력이 들어오면 변하지 않으므로 큐에 담아두고
				// BFS에선 큐에 복사하여 사용
				if(mat[i][j] == 2)
					q.push(make_pair(i, j));
					// q.push({i, j}); // C++11 부터 가능
			}
		}
	}
	// 연구소에서 0인 부분을 모두 벽을 세워야 하므로 다음과 같이 진행
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			// 2. 0 발견시 연구실 상태를 tmpmat에 복사하고 1을 할당하면서 첫번째 벽을 세운다. 0의 개수를 감소시키고, makeWall 호출. 완전탐색 시작
			if(mat[i][j] == 0){
				memcpy(tmpmat, mat, sizeof(mat));
				tmpmat[i][j] = 1;
				--zeroCnt;
				makeWall(1, zeroCnt);
				tmpmat[i][j] = 0;
				++zeroCnt;
			}
		}
	}
	printf("%d", safeZone);
	return 0;
}

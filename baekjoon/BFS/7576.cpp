/*
토마토 - https://www.acmicpc.net/problem/7576
접근법 - 토마토가 익기 시작한 부분이 한곳이 아닐 수 있기 때문에 처음 매트릭스 배열에 값을 넣을때 시작부분을 큐에 넣어준다.
하나의 seg 안(1개의 턴)에서 탐색이 끝나면 ans를 증가시킨다.
참고 블로그 - https://sihyungyou.github.io/baekjoon-7576/
https://jdselectron.tistory.com/55    - 이 블로그가 훨씬 더 간단함, 방문 배열을 쓰지 않고 품.
*/
#include <iostream>
#include <utility> // std::pair
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 1001;
int mat[MAX][MAX];
bool v[MAX][MAX] = {false,}; //방문 체크
int y[4] = {0, 1, 0, -1};
int x[4] = {1, 0, -1, 0};
int M, N, ans = 0, seg = 0, cnt = 0;
bool traverse; 
// seg 변수는 큐에 들어있는 좌표가 몇 개까지 탐색을 하나의 턴으로 봐야하는지 기록하는 변수, 예를들어 (1,1), (4,4) 에서 동시에 토마토가 익기 시작한다면 seg = 2
// cnt 변수는 한 seg 안에 들어있는 수를 세는 변수 

queue<pair<int, int> > q; // mat의 위치를 저장

void bfs(){
	while(!q.empty()){
		cnt = 0;
		traverse = false;
		for(int k = 0; k < seg; k++){
			int curY = q.front().first;
			int curX = q.front().second;
			//cout << "pop curY: " << curY << " curX: " << curX << endl;
			v[curY][curX] = true;
			q.pop();
			
			for(int i = 0; i < 4; i++){
				int newY = curY + y[i];
				int newX = curX + x[i];
				//if(mat[newY][newX] == 1) continue; // 익은 토마토는 스킵
				//if(newY <= 0 || newY > N || newX <= 0 || newX > M) continue;
				if(newY > 0 && newY <= N && newX > 0 && newX <= M && mat[newY][newX] == 0 && !v[newY][newX]){ // 위 두개의 if 문을 합쳐 다르게 표현한 조건
					traverse = true; // 인접 토마토를 익힘
					mat[newY][newX] = 1;
					q.push(make_pair(newY, newX));
					cnt++;
					//v[newY][newX] = true; // 여기에서 방문체크를 하면 안되는 이유?
				}
			}
		}
		seg = cnt; // 안익었던 토마토 수를 seg에 넣어 다음 탐색 턴으로 활용
		if(traverse) ++ans;
	}
}

int main(void){
	cin >> M >> N; // M:가로칸 N:세로칸
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			//scanf("%d", &mat[i][j]);
			cin >> mat[i][j];
			if(mat[i][j] == 1) {
				q.push(make_pair(i, j)); // 큐에 시작하기 위한 익은 토마토 위치를 push
				seg++; // 토마토가 익은 부분이 시작할 때 2개 이상이면 seg=2
			}
		}
	}
	bfs();
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(!v[i][j] && mat[i][j] == 0){
				cout << "-1";
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}

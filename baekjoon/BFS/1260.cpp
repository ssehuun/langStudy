/*
접근법 - 인접행렬  노드를 (N+1)*(N+1) 이차원 배열로 표현하였고, 연결된 노드는 간선수만큼
이차원 배열에 1로 초기화했다. dfs는 재귀함수를, bfs는 for문을 활용하여 구현하였다.
*/
#include <iostream>
#include <queue>
using namespace std;

int no[1001][1001] = {0,};
bool dfs_ch[1001] = {false,};
bool bfs_ch[1001] = {false,};
int N, M, V;

void dfs(int x){
	if(dfs_ch[x]) return;
	dfs_ch[x] = true;
	cout << x << ' ';
	for(int i = 1; i <= N; i++){
		if(dfs_ch[i] || no[x][i] == false || no[i][x] == false) continue;
		dfs(i);
	}
}
void bfs(int x){
	queue<int> q;
	q.push(x);
	bfs_ch[x] = true;
	while(!q.empty()){
		int p = q.front();
		cout << p << ' ';
		q.pop();
		for(int i = 1; i <= N; i++){
			if(bfs_ch[i] || no[p][i] == false || no[p][i] == false) continue;
			q.push(i);
			bfs_ch[i] = true;
		}
	}
}
int main(void){
	int n1, n2;
	
	cin >> N >> M >> V;
	for(int i = 0; i < M; i++){
		cin >> n1 >> n2;
		no[n1][n2] = no[n2][n1] = true;
	}
	dfs(V);
	cout << endl;
	bfs(V);
	return 0;
}

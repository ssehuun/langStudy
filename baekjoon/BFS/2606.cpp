/*
바이러스 - https://www.acmicpc.net/problem/2606
접근법 - https://www.acmicpc.net/problem/1260 문제와 비슷
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 101	;
int mat[MAX][MAX] = {0,};
bool v[MAX] = {false,}; //방문 체크
int virus = 0;
int com, net, n1, n2;

int bfs(int start){
	queue<int> q;
	q.push(start);
	v[start] = true;
	while(!q.empty()){
		int start = q.front();
		//cout << start << ' ';
		q.pop();
		for(int i = 1; i <= com; i++){
			if(start >= 1 && start <= com && mat[start][i] && !v[i]){
				v[i] = true;
				q.push(i);
				virus++;
			}
		}		
	}
	return virus;
}

int main(void){
	cin >> com >> net; // com: 노드수 net:간선수
	for(int i = 1; i <= net; i++){
		scanf("%d %d", &n1, &n2);
		mat[n1][n2] = mat[n2][n1] = 1;
	}
	printf("%d", bfs(1));
	return 0;
}

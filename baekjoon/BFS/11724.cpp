/*
연결 요소의 개수 - https://www.acmicpc.net/problem/11724
접근법 - 연결된 요소를 구하는 문제이다. 인접행렬을 이용해서 풀 수 있다.
1번 노드부터 탐색을 시작한다면 탐색이 끝나는 시점이 연결요소 1개가 된다.
이렇게 bfs 함수를 호출하는 횟수를 구하는 문제이다.
*/
#include <iostream>
#include <utility>
#include <cstdio>
#include <queue>
using namespace std;

const int MAX = 1001;
int mat[MAX][MAX] = {0,};
bool v[MAX] = {false,}; //방문 체크
int N, M, n1, n2, cc = 0;

void bfs(int start){
	queue<int> q;
	q.push(start);
	v[start] = true;
	while(!q.empty()){
		int s = q.front();
		//cout << "s :" << s << endl;
		q.pop();
		for(int i = 1; i <= N; i++){
			if(mat[s][i] == 1 && mat[i][s] == 1 && !v[i]){
				q.push(i);
				v[i] = true;
			}
		}
	}
}

int main(void){
	cin >> N >> M;
	for(int i = 1; i <= M; i++){
		cin >> n1 >> n2;
		mat[n1][n2] = mat[n2][n1] = 1;
	}
	for(int i = 1; i <= N; i++){
		if(!v[i]){
			bfs(i);
			cc++;
		}
	}
	printf("%d", cc);
	return 0;
}

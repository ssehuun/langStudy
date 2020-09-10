/*
트리의 부모 찾기 - https://www.acmicpc.net/problem/11725
접근법 - BFS나 DFS를 쓰지 않으면 틀리게 된다.
주어지는 노드가 순서있게 (부모, 자식) 입력되는게 아니라 랜덤으로 입력됨.
루트노드 1부터 탐색을 시작하여 자식 노드를 찾아가는게 해당 자식노드의 부모노드를 찾는거나 마찬가지.
반례 - 1과 연결된 노드가 먼저 올 필요가 없음.
시간초과 - print찍을때 "endl" 대신 "\n"을 써야함. 
BFS - https://ga0n.tistory.com/entry/%EB%B0%B1%EC%A4%80-11725%EB%B2%88-%ED%8A%B8%EB%A6%AC%EC%9D%98-%EB%B6%80%EB%AA%A8-%EC%B0%BE%EA%B8%B0
DFS - https://jaimemin.tistory.com/585
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector <int> > v;
int parent[100001];
bool visited[100001];

void bfs(){
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(auto nx : v[x]){
			if(!visited[nx]){
				parent[nx] = x;
				visited[nx] = true;
				q.push(nx);
			}
		}
	}
}
void getParent(){
	for(int i = 2; i <= N; i++){
		printf("%d\n", parent[i]);
	}
}
int main(void){
	int x, y;
	cin >> N;
	v.resize(N + 1);
	for(int i = 1; i <= N-1; i++){
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bfs();
	getParent();
}

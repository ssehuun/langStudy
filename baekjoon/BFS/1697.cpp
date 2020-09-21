/*
숨바꼭질 - https://www.acmicpc.net/problem/1697
접근법 - 가장 빠른 시간을 찾는 문제라 BFS로 선택.
하나의 배열 안에서 움직이기 때문에 visited 1차원 배열만 선언하고 
배열값엔 시작한 위치에서 이동한 시간이 들어감.
1. 시작하는 위치를 큐에 넣고 pop하면서 아래, 위, 2*시작 위치는 같은 시간이 걸렸기 때문에 처음 시작 값에 1을 증가시킴.
2. 큐를 pop하면서 그 위치에서 도착 위치에 도착할때까지 1번 반복.
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100000;
int visited[MAX_N*2]; // visited 배열 인덱스를 위치로 생각하고 배열값은 걸리는 시간으로 설정.

int bfs(int cur, int end){
    queue<int> q;
    q.push(cur);
    visited[cur] = 0;
    
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        
        if(here == end){
            return visited[here];
        }
        if(here-1 >= 0 && visited[here-1] == 0){ // 현재 위치에서 한칸 아래로 움직일 때 0이상이고 미방문 상태일 때
            visited[here-1] = visited[here]+1;
            q.push(here-1);
        }
        if(here+1 <= MAX_N*2 && visited[here+1] == 0){ // 현재 위치에서 한칸 위로 움직일 때 MAX_N*2 이하이고 미방문 상태일 때
            visited[here+1] = visited[here]+1;
            q.push(here+1);
        }
        if(here*2 <= MAX_N*2 && visited[here*2] == 0){ // 현재 위치에서 2배 위로 움직일 때 MAX_N*2 이하이고 미방문 상태일 때
            visited[here*2] = visited[here]+1;
            q.push(here*2);
        }
    }
    return -1;
}
int main(){
    int N, K;
    cin >> N >> K;
    cout << bfs(N, K);

    return 0;
}

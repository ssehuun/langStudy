/*
숨바꼭질2 - https://www.acmicpc.net/problem/12851
접근법 - 가장 빠른 시간을 찾는 문제라 BFS로 선택.
하나의 배열 안에서 움직이기 때문에 visited 1차원 배열만 선언하고, visited 체크를 큐에 푸쉬하고 하는게 아니라 pop하고 한다.
그 이유는 푸쉬를 하고 바로 visited 체크를 하게되면, 다른 경로에서 목적지까지 가는 경우를 확인 할 수 없기 때문.
참고 - https://jaimemin.tistory.com/582?category=988050
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 100000+1;
bool visited[MAX_N] = {false,}; // 방문했는지 체크
int cnt = 0;
int min_time = 0;

int bfs(int cur, int end){
    queue<pair<int, int> > q;
    q.push(make_pair(cur, 0));
    
    while (!q.empty()) {
		int curLoc = q.front().first;
		int curSec = q.front().second;
        q.pop();

		visited[curLoc] = true; // pop 할 때 현재 위치를 방문으로 처리, 다른 경로의 목적지를 보기 위해
		//cout << endl << "pop here: " << curLoc << ' ' << "times: " << curSec << endl;
		if(min_time && min_time == curSec && curLoc == end){ //이미 목적지에 도달한 경우
			cnt++;
		}
		if(min_time == 0 && curLoc == end){ // 처음 목적지에 도달한 경우
        	min_time = curSec;
			cnt++;
        }
		if(curLoc-1 >= 0 && !visited[curLoc-1]){ // 현재 위치에서 한칸 아래로 움직일 때 0이상이고 첫방문일 때
			q.push(make_pair(curLoc-1, curSec+1));
			//cout << "push: " << curLoc-1 << ' ' << curSec+1 << endl;
		}
		if(curLoc+1 < MAX_N && !visited[curLoc+1]){ // 현재 위치에서 한칸 위로 움직일 때 MAX_N 보다 작고 미방문 상태일 때
			q.push(make_pair(curLoc+1, curSec+1));
			//cout << "push: " << curLoc+1 << ' ' << curSec+1 << endl;
		}
		if(curLoc*2 < MAX_N && !visited[curLoc*2]){ // 현재 위치에서 2배 위로 움직일 때 MAX_N 보다 작고 미방문 상태일 때
			q.push(make_pair(curLoc*2, curSec+1));
			//cout << "push: " << curLoc*2 << ' ' << curSec+1 << endl;
		}
    }
	return min_time;
}
int main(){
    int N, K;
    cin >> N >> K;
	//if(N == K) cout << 0 << endl << 1;
	cout << bfs(N, K) << endl << cnt;

    return 0;
}

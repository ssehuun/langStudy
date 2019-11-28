//19.11.28 pass
#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int main(){
	int N;
	string cmd;
	queue<int> q;
	scanf("%d", &N);
	while(N--){
		cin >> cmd;
		if(cmd == "push"){
			int k;
			scanf("%d", &k);
			q.push(k);
		}else if(cmd == "pop"){
			if(q.size() == 0){
				 printf("-1\n");
			}else{
				printf("%d\n", q.front());
				q.pop();
			}
		}else if(cmd == "size"){
			printf("%d\n", q.size());
		}else if(cmd == "empty"){
			if(q.empty()){
				printf("1\n");
			}else{
				printf("0\n");
			}
		}else if(cmd == "front"){
			if(q.size() == 0){
				 printf("-1\n");
			}else{
				printf("%d\n", q.front());
			}
		}else if(cmd == "back"){
			if(q.size() == 0){
				 printf("-1\n");
			}else{
				printf("%d\n", q.back());
			}
		}	
	}
	return 0;
}

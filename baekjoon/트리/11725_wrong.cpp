#include <iostream>
#include <cstdio>
using namespace std;

typedef struct node{
	int parent;
	int left, right;
} node;

const int MAX = 100001;
node tree[MAX];
int N; // 노드 개수

void initTree(void){
	for(int i = 1; i <= N; i++){
		tree[i].parent = -1;
		tree[i].left = tree[i].right = -1;
	}
}
void addChild(int n, int m){
	int parent, child;
	if(n == 1) {
		parent = n; child = m;
	}else {
		parent = m; child = n;
	}
	//cout << "parent: " << parent << " child: " << child << endl;
	if(tree[parent].left == -1){ 
		tree[parent].left = child;
		tree[child].parent = parent;
	}else {
		tree[parent].right = child;
		tree[child].parent = parent;
	}
}
void addChild2(int a, int b){
	if(tree[a].parent != -1){ // a의 부모가 존재한다면 a가 부모노드, b가 자식노드
		if(tree[a].left == -1) tree[a].left = b;
		else tree[a].right = b;
		tree[b].parent = a;
		//cout << "parent: " << a << " child: " << b << endl;
	}else{ // a가 자식노드, b가 부모노드
		if(tree[b].left	== -1) tree[b].left = a;
		else tree[b].right = a;
		tree[a].parent = b;
		//cout << "parent: " << b << " child: " << a << endl;
	}
}
void getParent(){
	for(int i = 2; i <= N; i++){
		printf("%d\n", tree[i].parent);
	}
}
int main(void){
	int n1, n2;
	scanf("%d", &N);
	initTree();
	for(int i = 1; i <= N-1; i++){
		scanf("%d %d", &n1, &n2);
		if(n1 == 1 || n2 == 1) addChild(n1, n2);// 노드에 1이 있을 경우 해당 함후 호출
		else{
			addChild2(n1, n2);// 노드에 1이 없으면 해당 함수 호출
		}
	}
	getParent();
	return 0;
}

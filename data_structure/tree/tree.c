/*
트리 - 전위 순회
https://swexpertacademy.com/main/visualcode/main.do#/home/editor//

Input Data
3
13 12
1 2 1 3 2 4 3 5 3 6 4 7 7 12 5 9 5 8 6 11 6 10 11 13
10 9
1 2 1 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
50 49
31 7 2 17 27 32 14 30 1 21 45 26 44 27 39 11 26 3 48 6 3 44 2 49 42 13 48 8 23 33 11 10 8 42 41 31 17 4 8 22 25 23 21 41 28 25 13 16 46 2 31 35 42 19 32 18 27 50 45 15 28 20 46 28 44 40 40 5 15 48 9 34 1 46 17 29 35 36 21 45 14 37 23 14 6 39 11 9 19 24 26 47 16 38 40 12 47 43
*/
#include <stdio.h>

#define MAX_NODE_NUM 10000
#define MAX_CHILD_NUM 2

typedef struct{
	int parent;
	int child[MAX_CHILD_NUM];
} TreeNode;
TreeNode tree[MAX_NODE_NUM];

int nodeNum;
int edgeNum;
int root;

void initTree(void){
	printf("init Tree\n");
	for(int i = 1; i <= nodeNum; i++){
		tree[i].parent = -1;
		for(int j = 0; j < MAX_CHILD_NUM; j++){
			tree[i].child[j] = -1;
		}
	}
}

void addChild(int parent, int child){
	int i;
	for(i = 0; i < MAX_CHILD_NUM; i++){
		if(tree[parent].child[i] == -1) break;
	}
	tree[parent].child[i] = child;
	tree[child].parent = parent;
}

int getRoot(void){
	for(int i = 1; i <= nodeNum; i++){
		if(tree[i].parent == -1) return i;
	}
	return -1;
}

void preOrder(int root){
	int child;
	printf("%d ", root);
	for(int i = 0; i < MAX_CHILD_NUM; i++){
		child = tree[root].child[i];
		if(child != -1){
			preOrder(child);
		}
	}
}
int main(void){
	int i, T, parent, child, test_case;
	scanf("%d", &T);
	for(test_case = 1; test_case <= T; ++test_case){
		scanf("%d %d", &nodeNum, &edgeNum);
		initTree();

		for(i = 0; i < edgeNum; i++){
			scanf("%d %d", &parent, &child);
			addChild(parent, child);
		}
		root = getRoot();
		printf("#%d ", test_case);
		preOrder(root);
		printf("\n");
	}
	return 0;
}

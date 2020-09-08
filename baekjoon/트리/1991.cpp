/*
트리 순회 - https://www.acmicpc.net/problem/1991
접근법 - 1. node 구조체를 정의하고, 부모 노드를 입력할 때마다 node를 생성하는 함수 create를 동적으로 호출한다.
2. 왼쪽 자식, 오른쪽 자식은 배열 arr을 만들어 저장한다.
3. arr 배열에 저장된 값과 노드의 데이터(root->data)가 같을 때 그 노드를 왼쪽 자식 노드로 저장
4. arr 배열에 저장된 값과 노드의 데이터(root->data)가 같을 때 그 노드를 오른쪽 자식 노드로 저장
참고 블로그 - https://min5k-619.tistory.com/5
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX = 28;
//1. node 구조체를 정의하고, 부모 노드를 입력할 때마다 node를 생성하는 함수 create를 동적으로 호출한다.
typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
}node;

node* create(char c){
	node* newNode = (node*)malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = c;
	return newNode;
}
void preorder(node* t){
	if(t == NULL) return;
	printf("%c", t->data);
	preorder(t->left);
	preorder(t->right);
}
void inorder(node* t){
	if(t == NULL) return;
	inorder(t->left);
	printf("%c", t->data);
	inorder(t->right);
}
void postorder(node* t){
	if(t == NULL) return;
	postorder(t->left);
	postorder(t->right);
	printf("%c", t->data);
}

int main(void){
	node* root[MAX];
	int num;
	char parent, left, right, arr[81][2];
	scanf("%d", &num);

	for(int i = 1; i <= num; i++){
		// 아래 scanf으로 입력받을시 앞에 공백을 줘야 구분자로 간주하여 오류자 생기지 않는다.
		// 오류 이유는 for문을 돌면서 Enter값을 입력값으로 받아들여서 버퍼에 Enter값이 추가되기 때문. cin 을 쓰자 그냥.
		//scanf(" %c %c %c", &parent, &left, &right);
		cin >> parent >> left >> right;
		arr[i][0] = left;
		arr[i][1] = right;
		//2. 왼쪽 자식, 오른쪽 자식은 배열 arr을 만들어 저장한다.
		root[i] = create(parent);
	}
	for(int i = 1; i <= num; i++){
		for(int j = 1; j <= num; j++){
			//3. arr 배열에 저장된 값과 노드의 데이터(root->data)가 같을 때 그 노드를 왼쪽 자식 노드로 저장
			if(arr[i][0] == root[j]->data)
				root[i]->left = root[j];
			//4. arr 배열에 저장된 값과 노드의 데이터(root->data)가 같을 때 그 노드를 오른쪽 자식 노드로 저장
			if(arr[i][1] == root[j]->data)
				root[i]->right = root[j];
		}
	}
	preorder(root[1]);
	printf("\n");
	inorder(root[1]);
	printf("\n");
	postorder(root[1]);
	return 0;
}

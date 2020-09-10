/*
https://youtu.be/z_tzHoPfllA
편의상 완전 이진 트리를 구성하였지만, 포인터로 노드를 구성하였기 때문에
완전 이진 트리가 아니어도 아래 알고리즘은 작동한다.
*/
#include <iostream>
using namespace std;

int number = 15;

// 구조체 사용
typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;
/* 아래 구조체 방식도 가능
typedef struct node {
	int data;
	node* leftChild, rightChild;
}node;
*/
// 전위 순회 구현
void preorder(treePointer ptr){
	if(ptr){
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

// 중위 순회 구현
void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

// 후위 순회 구현
void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void){
	node nodes[number+1];
	for(int i = 1; i <= number; i++){
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	for(int i = 1; i <= number; i++){
		if(i % 2 == 0){
			nodes[i / 2].leftChild = &nodes[i];
		}else{
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	cout << "preorder: ";
	preorder(&nodes[1]);
	cout << endl <<  "inorder: ";
	inorder(&nodes[1]);
	cout << endl << "postorder: ";
	postorder(&nodes[1]);
	return 0;
}




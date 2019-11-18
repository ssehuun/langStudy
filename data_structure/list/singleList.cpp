#include <iostream>
using namespace std;

typedef struct Node{
	int data;
	Node* nextNode;
	Node(){data = 0; nextNode = nullptr;}
}Node;

typedef struct List{
	int size;
	Node* front;
	Node* back;
	List(){size = 0; front = nullptr; back = nullptr;}
}SingleList;

void push_front(SingleList &list, int num)
{
	Node* newNode = new Node[1];
	newNode->data = num;
	newNode->nextNode = nullptr;
	if(list.size == 0){
		list.front = newNode;
		list.back = newNode;
	}
	else{
		newNode->nextNode = list.front;
		list.front = newNode;
	}
	list.size++;
}

void push_back(SingleList &list, int num)
{
	Node* newNode = new Node[1];//not dynamic, static?
	newNode->data = num;
	newNode->nextNode = nullptr;
	if(list.size == 0){
		list.front = newNode;
		list.back = newNode;
	}
	else{
		list.back->nextNode = newNode;
		list.back = newNode;
	}
	list.size++;
}

void pop_front(SingleList &list)
{
	cout << "pop front element" << endl;
	list.front = list.front->nextNode;
}

void pop_back(SingleList &list)
{
	cout << "pop back element" << endl;
	for(Node* it = list.front; it != nullptr; it = it->nextNode){
		if(it->nextNode->nextNode == nullptr){
			list.back = it;
			it->nextNode = nullptr;
			break;
		}
	}
}
void insert(SingleList &list, 
void erase(SingleList &list);
void printList(SingleList list)
{
	cout << "print All elements: " << endl;
	for(Node* it = list.front; it != nullptr; it = it->nextNode){
		cout << it->data << " ";
	}
	cout << endl;
}
int main(){
	int size = 10;
	SingleList singleList;
	for(int i = 0; i < size; i++){
		push_back(singleList, i);
	}
	printList(singleList);

	pop_front(singleList);
	printList(singleList);

	pop_back(singleList);
	printList(singleList);
	pop_back(singleList);
	printList(singleList);

	return 0;
}

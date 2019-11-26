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
	cout << "push front!!!" << endl;
	Node* newNode = new Node[1];
	newNode->data = num;
	//newNode->nextNode = nullptr;
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
	//newNode->nextNode = nullptr;
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
	if(list.size == 1){
		free(list.front);
		list.front = nullptr;
		list.back = nullptr;
	}
	else{
		Node *tmp = list.front;
		list.front = list.front->nextNode;
		free(tmp);
	}
	list.size--;
}

void pop_back(SingleList &list)
{
	cout << "pop back element" << endl;
	if(list.size == 1){
		free(list.back);
		list.front = nullptr;
		list.back = nullptr;
	}else{
		for(Node* it = list.front; it != nullptr; it = it->nextNode){
			if(it->nextNode->nextNode == nullptr){
				list.back = it;
				it->nextNode = nullptr;
				break;
			}
		}
	}
	list.size--;
}
void erase(SingleList &list, Node* prevNode, Node* curNode)
{
	cout << "erase element!!!" << endl;
	if(prevNode == nullptr)
	{
		curNode = curNode->nextNode;
		free(list.front);
		list.front = curNode;
	}
	else
	{
		prevNode->nextNode = curNode->nextNode;
		free(curNode);
	}
}
void insert(SingleList &list, Node *curNode, int data)
{
	cout << "insert element!!!" << endl;
	Node *newNode = new Node[1];
	newNode->data = data;
	newNode->nextNode = curNode->nextNode;
	curNode->nextNode = newNode;
	list.size++;
}
void printList(SingleList list)
{
	cout << "print All elements: " << endl;
	for(Node* it = list.front; it != nullptr; it = it->nextNode){
		cout << it->data << " ";
	}
	cout << endl;
}
void clear(SingleList &list)
{
	while(list.size != 0){
		pop_front(list);
	}
}
int main(){
	int size = 10;
	SingleList singleList;
	for(int i = 0; i < size; i++){
		push_back(singleList, i);
	}
	printList(singleList);

	push_front(singleList, 100);
	printList(singleList);

	pop_front(singleList);
	printList(singleList);

	pop_back(singleList);
	printList(singleList);
	//erase element
	int deleteElement = 5;
	cout << "erase element: " << deleteElement << endl;
	Node *prevNode = nullptr;
	for(Node *it = singleList.front; it != nullptr; it = it->nextNode){
		if(it->data == deleteElement)
		{
			erase(singleList, prevNode, it);
			break;
		}
		prevNode = it;
	}
	printList(singleList);
	//insert element
	int data = 11;
	int insertElement = 6;
	cout << "insert " << data << " after " << insertElement << endl;
	for(Node *it = singleList.front; it != nullptr; it = it->nextNode){
		if(it->data == insertElement){
			insert(singleList, it, data);
		}
	}
	printList(singleList);
	return 0;
}

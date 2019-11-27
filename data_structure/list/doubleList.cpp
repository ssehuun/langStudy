#include <iostream>
using namespace std;

typedef struct Node{
	int data;
	Node *nextNode;
	Node *prevNode;
	Node(){data = 0; nextNode = nullptr; prevNode = nullptr;}
}Node;

typedef struct List{
	int size;
	Node *front;
	Node *back;
	List(){size = 0; front = nullptr; back = nullptr;}
}DoubleList;

void push_front(DoubleList &list, int num)
{
	cout << "push front!!!" << endl;
	Node* newNode = new Node[1];
	newNode->data = num;

	if(list.size == 0){
		list.front = newNode;
		list.back = newNode;
	}else{
		newNode->nextNode = list.front;
		list.front->prevNode = newNode;
		list.front = newNode;
	}
	list.size++;
}

void push_back(DoubleList &list, int num)
{
	Node* newNode = new Node[1];//not dynamic, static?
	newNode->data = num;

	if(list.size == 0){
		list.front = newNode;
		list.back = newNode;
	}else{
		list.back->nextNode = newNode;
		newNode->prevNode = list.back;
		list.back = newNode;
	}
	list.size++;
}

void pop_front(DoubleList &list)
{
	cout << "pop front element" << endl;
	if(list.size == 1){
		free(list.front);
		list.front = nullptr;
		list.back = nullptr;
	}else{
		Node *tmp = list.front;
		list.front = list.front->nextNode;
		free(tmp);
	}
	list.size--;
}

void pop_back(DoubleList &list)
{
	cout << "pop back element" << endl;
	if(list.size == 1){
		free(list.back);
		list.front = nullptr;
		list.back = nullptr;
	}else{
		Node *tmp = list.back;
		list.back = list.back->prevNode;
		list.back->nextNode = nullptr;
		free(tmp); 
	}
	list.size--;
}
void erase(DoubleList &list, Node* prevNode, Node* curNode)
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
void insert(DoubleList &list, Node *curNode, int data)
{
	cout << "insert element!!!" << endl;
	Node *newNode = new Node[1];
	newNode->data = data;
	newNode->nextNode = curNode->nextNode;
	curNode->nextNode = newNode;
	list.size++;
}
void printList(DoubleList list)
{
	cout << "print All elements: " << endl;
	for(Node *it = list.front; it != nullptr; it = it->nextNode){
		cout << it->data << " ";
	}
	cout << endl;
}
void clear(DoubleList &list)
{
	while(list.size != 0){
		pop_front(list);
	}
}
int main(){
	int size = 10;
	DoubleList doubleList;
	for(int i = 0; i < size; i++){
		push_back(doubleList, i);
	}
	printList(doubleList);

	push_front(doubleList, 100);
	printList(doubleList);

	pop_front(doubleList);
	printList(doubleList);

	pop_back(doubleList);
	printList(doubleList);
	//erase element
	int deleteElement = 5;
	cout << "erase element: " << deleteElement << endl;
	Node *prevNode = nullptr;
	for(Node *it = doubleList.front; it != nullptr; it = it->nextNode){
		if(it->data == deleteElement)
		{
			erase(doubleList, prevNode, it);
			break;
		}
		prevNode = it;
	}
	printList(doubleList);
	//insert element
	int data = 11;
	int insertElement = 6;
	cout << "insert " << data << " after " << insertElement << endl;
	for(Node *it = doubleList.front; it != nullptr; it = it->nextNode){
		if(it->data == insertElement){
			insert(doubleList, it, data);
		}
	}
	printList(doubleList);
	return 0;
}

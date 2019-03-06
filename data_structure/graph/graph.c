/* 
convert adjacent matrix into adjacent list with C
Sample Input
4
0 1 0 1
1 0 0 0
0 0 0 1
0 1 0 0

Sample Output
1: 2 4
2: 1
3: 4
4: 2
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 55

typedef struct node{
	struct node* next;
	int value;
}node;

void add(node** head, int value){
	node* new_node = (node*)malloc(sizeof(node));
	new_node->value = value;
	if(!(*head)){
		new_node->next = NULL;
		(*head) = new_node;
	}else{
		new_node->next = NULL;
		(*head) = new_node;
	}
	return;
}
int main(void) {
	int adj_matrix[MAX][MAX], n;
	node* head[MAX];
	scanf("%d", &n);
	
	for(int i=1; i<=n; i++){
		head[i] = NULL;
		for(int j=1; j<=n; j++){
			scanf("%d", &adj_matrix[i][j]);
			if(adj_matrix[i][j]) add(&head[i], j);
		}
	}
	for(int i=1; i<=n; i++){
		node* current_node = head[i];
		printf("%d: ", i);
		while(current_node){
			printf("%d", current_node->value);
			current_node = current_node->next;
		}
		printf("\n");
	}
	return 0;
}


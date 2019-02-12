/*
19.02.12
<Stack implemented with array>

input value
8
size
push 4
push 3
top
size
pop
top
size

output value
0
3
2
4
1
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct stack{
	int *data;
	int last;
	int maxsize;
};
void stack_init(struct stack *st, int sz){
	st->maxsize = sz;
	st->last = -1;
	st->data = (int*)malloc(st->maxsize * sizeof(int));
}
int stack_size(struct stack *st){
	return (st->last) + 1;
}
bool stack_empty(struct stack *st){
	return stack_size(st) == 0;
}
bool stack_full(struct stack *st){
	return stack_size(st) == st->maxsize;
}
void stack_push(struct stack *st, int val){
	assert(!stack_full(st));
	st->data[++(st->last)] = val;
}
void stack_pop(struct stack *st){
	assert(!stack_empty(st));
	(st->last)--;
}
int stack_top(struct stack *st){
	assert(!stack_empty(st));
	return st->data[st->last];
}
int N, val;
char cmd[16];
int main(){
	scanf("%d", &N);
	struct stack st;
	stack_init(&st, N);
	for(int i=0; i<N; i++){
		scanf("%s", cmd);
		if(cmd[0] == 's'){
			printf("%d\n", stack_size(&st));
		}else if(cmd[0] == 'p'){
			if(cmd[1] == 'u'){
				scanf("%d", &val);
				stack_push(&st, val);
			}else if(cmd[1] == 'o'){
				stack_pop(&st);
			}
		}else if(cmd[0] == 't'){
			printf("%d\n", stack_top(&st));
		}
	}
	return 0;
}

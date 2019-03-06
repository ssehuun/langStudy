#include <stdio.h>
#include <stdlib.h>

//1
struct simple{
	int data1;
	int data2;
};
void show(strunct simple s);

int main(){
	struct simple s1 = {1,2};
	struct simple s2 = swap(&s1);
	return 0;
}

void show(struct simple ts){
	printf("%d %d\n", &ts.data1, &ts.data2);
}
struct simple swap(struct simple* p){
	struct simple tmp;
	tmp.data1 = p->data2;
	tmp.data2 = p->data1;
	return tmp;
}

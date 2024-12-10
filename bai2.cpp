#include<stdio.h>
#include<stdlib.h>
#define MAX 100
typedef struct {
	int array[MAX];
	int top;
} Stack;
void initStack(Stack *s){
	s->top = -1;
}
int isEmpty(Stack *s){
	return s->top == -1;
}
int isFull(Stack *s){
	return s->top == MAX -1;
}
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("ngan xep da day.\n");
        return;
    }
    s->array[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("ngan xep rong.\n");
        return -1; 
    }
    return s->array[(s->top)--];
}

void printStack(Stack *s){
	if(isEmpty(s)){
		printf("ngan xep rong.\n");
		return;
	}
	printf("cac phan tu trong ngan xep:\n");
	for(int i = s->top; i >= 0; i--){
		printf("%d\n",s->array[i]);
	}
}
int main(){
	Stack stack;
    initStack(&stack);
    int n, value;

    printf("nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }
    printf("\nngan xep truoc khi xoa:\n");
    printStack(&stack);
    int removedValue = pop(&stack);
    if (removedValue != -1) {
        printf("phan tu bi xoa: %d\n", removedValue);
    }
    printf("ngan xep sau khi xoa:\n");
    printStack(&stack);
	
	return 0;
}


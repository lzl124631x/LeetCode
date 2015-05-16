#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// Implementation of a simple 3-in-1 stack.
// Assume the total size of stack is n,
// then the first stack (indexed by 0) corresponds to [0, n/3),
// the second stack (indexed by 1) corresponds to [n/3, 2n/3),
// the third stack (indexed by 2) corresponds to [2n/3, n).
typedef struct Stack{
	int *buf;
	int stackSize;	// the size of a single stack
	int top[3];
}Stack;

Stack* initStack(int stackSize){
	Stack *s = NULL;
	assert(stackSize > 0);
	s = malloc(sizeof *s);
	assert(s);
	s->buf = malloc(sizeof(int) * stackSize * 3);
	assert(s->buf);
	s->stackSize = stackSize;
	s->top[0] = s->top[1] = s->top[2] = -1;
	return s;
}

void push(Stack *s, int stackNum, int data){
	assert(s && stackNum >= 0 && stackNum < 3);
	assert(s->top[stackNum] + 1 < s->stackSize);  // prevent overflow
	s->top[stackNum]++;
	s->buf[s->stackSize * stackNum + s->top[stackNum]] = data;
}

void pop(Stack *s, int stackNum){
	assert(s && stackNum >= 0 && stackNum < 3);
	assert(s->top[stackNum] >= 0);	// prevent underflow
	s->top[stackNum]--;
}

int top(Stack *s, int stackNum){
	assert(s && stackNum >= 0 && stackNum < 3);
	return s->buf[s->stackSize * stackNum + s->top[stackNum]];
}

int isEmpty(Stack *s, int stackNum){
	assert(s && stackNum >= 0 && stackNum < 3);
	return s->top[stackNum] == -1;
}

int main(){
	Stack *s = initStack(100);
	int i = 0;
	printf("Stack #0 is %sempty.\n", isEmpty(s, 0) ? "" : "not ");
	while(i < 300){
		push(s, 0, i++);
		push(s, 1, i++);
		push(s, 2, i++);
	}
	printf("Top of Stack #1: %d\n", top(s, 1));
	printf("Stack #2 is %sempty.\n", isEmpty(s, 2) ? "" : "not ");
	printf("%d\n", s->)
	i = 0;
	while(i < 100){
		pop(s, 1);
	}
	printf("Stack #1 is %sempty.\n", isEmpty(s, 1) ? "" : "not ");	
	return 0;
}
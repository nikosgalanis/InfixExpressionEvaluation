#include <stdio.h>
#include <stdlib.h>

typedef char item;

typedef struct{
	int count;
	item Input[100];
} Stack;

void InitializeStack(Stack *S){
	S->count=0;
}

int Empty(Stack *S){
	return (S->count==0);
}
int Full(Stack* S){
	return(S->count==100);
}

void pop(Stack* S, char* X){
	if (Empty(S)) printf("Attempted to pop from an empty stack\n");
	else{
		(S->count)--;
		*X=S->Input[S->count];
	}
}

void push(Stack* S, char X){
	if (Full(S)) printf("Attempted to push into a full stack\n");
	else{
		S->Input[S->count]=X;
		(S->count)++;
	}
}

char get_top(Stack* S,int call){
	if (S->count)return S->Input[0];
	else {
		if (call==0) return 0;		//if we want an opperant
		else return '+';					//if we want an opperator
	}
}

//Manan Patel 2018A7PS0194H
//Adit Gandhi 2018A7PS0575H
//Dhiraaj Desai 2018A7PS0146H

#include "stack.h"
void push(node* stack[], int max, int *stackPointer, node* value){
	if( isFull(stack,max,*stackPointer) == 1 ){
		return;
	}
	++(*stackPointer);
	stack[*stackPointer] = value;
}

void pop(node* stack[], int max, int *stackPointer){
	if( isEmpty(stack,max,*stackPointer) == 1){
		return;
	}
	--(*stackPointer);
}

int isEmpty(node* stack[], int max, int stackPointer){
	if( stackPointer == -1 ){
		return 1;
	}
	return 0;
}

int isFull(node* stack[], int max, int stackPointer){
	if( stackPointer == (max-1) ){
		return 1;
	}
	return 0;
}

node* top(node* stack[], int max, int stackPointer){
	if( isEmpty(stack,max,stackPointer) == 1 ){
		return 0;
	}
	return stack[stackPointer];
}

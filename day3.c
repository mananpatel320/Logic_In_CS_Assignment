#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include "modifiedDay1.h"

void inorder(node *root){
        if(root != NULL)
	{
		if (isalpha(root->ch) && (root->ch) != 'V')
		{
			printf("%c", root->ch);
		}
		else
		{
			printf("(");
		  	inorder(root->left);
			printf("%c", root->ch);
		   		inorder(root->right);
			printf(")");
		}
	}
}

node* parseTree(char post_exp[]){
        int len = strlen(post_exp);
        node *stack[len];
        int i = 0, stackPointer = -1;
        while( i < len ){
                char a = post_exp[i];
                node *newNode = (node *)malloc(sizeof(node));
                newNode->ch = a;
                newNode->left = NULL;
                newNode->right = NULL;
                if( isalpha(a) && a != 'V'){
			push(stack,len,&stackPointer,newNode);
                        
			
                }
                else
		{
			if(a=='~')
			{
			 newNode->right = stack[stackPointer];
                        pop(stack,len,&stackPointer);
                        
                        push(stack,len,&stackPointer,newNode);
			}
			else
			{
                        newNode->right = stack[stackPointer];
                        pop(stack,len,&stackPointer);
                        newNode->left = stack[stackPointer];
                        pop(stack,len,&stackPointer);
                        push(stack,len,&stackPointer,newNode);
			}
		}
                ++i;
        }
        return stack[0];
}

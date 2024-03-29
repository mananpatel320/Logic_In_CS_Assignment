//Manan Patel 2018A7PS0194H
//Adit Gandhi 2018A7PS0575H
//Dhiraaj Desai 2018A7PS0146H

#include "stack.h"
#include<stdlib.h>
#include<stdio.h>

void traverseday2(node *currentnode,node *mainroot, node *prevnode){
	if( currentnode!= NULL ){
		if( currentnode->ch == '~' ){
			node *newNodeleft = (node *)malloc(sizeof(node));
			node *newNoderight = (node *)malloc(sizeof(node));
			newNodeleft->ch = '~';
			newNoderight->ch = '~';
			newNodeleft->left = NULL;
			newNoderight->left = NULL;
			newNodeleft->right = NULL;
			newNoderight->right = NULL;
			if( currentnode->right->ch == '^' ){
				 currentnode->ch = 'V'; 
				 newNodeleft->right = currentnode->right->left;
				 currentnode->left = newNodeleft;
				 newNoderight->right = currentnode->right->right;
				 currentnode->right = newNoderight;
			}
			else if( currentnode->right->ch == 'V' ){
				 currentnode->ch = '^'; 
				 newNodeleft->right = currentnode->right->left;
				 currentnode->left = newNodeleft;
				 newNoderight->right = currentnode->right->right;
				 currentnode->right = newNoderight;
			}
			else if( currentnode->right->ch == '~' ){
				if( prevnode->right == currentnode ){
					prevnode->right = currentnode->right->right;
					currentnode = prevnode;
				}
				else{
					prevnode->left = currentnode->right->right;
					currentnode = prevnode;
				}
			}
		}
		traverseday2(currentnode->left,mainroot,currentnode);
		traverseday2(currentnode->right,mainroot,currentnode);
	}
}

node *nnf(node *root){
	node *previous = (node *)malloc(sizeof(node));
	node *leftfake = (node *)malloc(sizeof(node));
	leftfake->right = NULL;
	leftfake->left = NULL;
	leftfake->ch = '1';
	previous->right = root;
	previous->left = leftfake;
	previous->ch = '0';
	traverseday2(previous,previous,previous);
	return previous->right;
}	

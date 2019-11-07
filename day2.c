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
	traverseday2(root,root,root);
	return root;
}	

//Manan Patel 2018A7PS0194H
//Adit Gandhi 2018A7PS0575H
//Dhiraaj Desai 2018A7PS0146H

#include "stack.h"
#include<stdlib.h>

void traverse(node *root){ 
	if( root!= NULL ){
		if( root->ch == '>' ){
			root->ch = 'V';
			node *newNode = (node*)malloc(sizeof(node));
			newNode->ch = '~';
			newNode->left = NULL;
			newNode->right = root->left;
			root->left = newNode;
		}
		traverse(root->left);
		traverse(root->right);
	} 
}

node *impl_free(node *root){
	traverse(root);
	return root;
}

//Manan Patel 2018A7PS0194H
//Adit Gandhi 2018A7PS0575H
//Dhiraaj Desai 2018A7PS0146H

#include "stack.h"
#include<stdlib.h>

node *distr(node *n1, node *n2){
	node *newNode = (node *)malloc(sizeof(node));
	if( n1->ch == '^' ){
		newNode->right = distr(n1->right,n2);
		newNode->left = distr(n1->left,n2);
		newNode->ch = '^';
	}
	else if ( n2->ch == '^'){
		newNode->left = distr(n1,n2->left);
		newNode->right = distr(n1,n2->right);
		newNode->ch = '^';
	}
	else{
		newNode->left = n1;
		newNode->right = n2;
		newNode->ch = 'V';
	}
	return newNode;
}
		
node *cnf(node *root){
	if( root != NULL && root->right!=NULL ){
		if( root->ch == 'V' ){
			root = distr(cnf(root->left),cnf(root->right));
		}
		else if( root->ch == '^' ){
			root->right = cnf(root->right);
			root->left = cnf(root->left);
		}
	}
	return root;
}

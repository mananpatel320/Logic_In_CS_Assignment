#include<ctype.h>
#include "modifiedDay1.h"
#include<stdio.h>
int x = 1;
int evalParseTree(node *root, char var[], int value[], int n){
          if( x == 1 ){
               printf("\n");
               x = 0;
          }
          if( isalpha(root->ch) && root->ch != 'V' ){
               for(int i=0;i<n;i++){
                    if(var[i] == root->ch)
                         return value[i];
               }
           }
           else if( root->ch == '~' ){
               int RightChildResult;
               RightChildResult = evalParseTree(root->right,var,value,n);
               return (!RightChildResult);
           }
           else{
               int RightChildResult,LeftChildResult;
               LeftChildResult = evalParseTree(root->left,var,value,n);
               RightChildResult = evalParseTree(root->right,var,value,n);
               switch(root->ch){
                    case '^' :return (LeftChildResult&RightChildResult);
                              break;
                    case 'V' :return (LeftChildResult|RightChildResult);
                              break;
                    case '>' :return ((!LeftChildResult)|RightChildResult);
                              break;
               }
            }
}
                             
                             
                             
                             
          

#include "day1.h"
#include<string.h>
#include<ctype.h>
// function to print postfix form of an infix string.
// author : Rashi Jain, 11/10/19

// prints the postfix expression.
// infix_exp : character array containing infix string. 
// return : void. 
void infixToPostfix(char infix_exp[]);

void infixToPostfix(char infix_exp[]){
    int len = strlen(infix_exp), i = 0, stackPointer = -1;
    char stack[len];
    while(i < len){
        char a = infix_exp[i];
        if(isalpha(a) != 0 && a!='V' ){
            printf("%c",a);
        }
        else{
            if( a == ')' ){
                while( stack[stackPointer] != '('){
                    printf("%c",stack[stackPointer]);
                    pop(stack,len,&stackPointer);
                }
                pop(stack,len,&stackPointer);
            }
            else
                push(stack,len,&stackPointer,a);
       }
       i++;
   }
   printf("\n");
}
         

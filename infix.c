#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
#include "STACKImplementation.h"

char operators[2][4]={{'+','-','*','/'},{'0','0','1','1'}};


int main(void){
  Stack operator_stack,operand_stack;
  char expresion[100],token,garbage,op,op1,op2,result,res;
  printf("Give an infix expresion, so we can evaluate it\n");
  scanf("%s",expresion);
  int length=strlen(expresion);
  InitializeStack(&operand_stack); InitializeStack(&operator_stack);
	for(int i=0;i<length;i++){
    token = expresion[i];
		if (token==' ') continue;
    if ((token >= '0') && (token <= '9')) push(&operand_stack,token);
    else if (token == '(' ) push(&operator_stack,token);
    else  if ((token == '+') || (token == '-') || (token == '*') || (token == '/') ){
      char top=get_top(&operator_stack,1);
      while(!Empty(&operator_stack) && has_precendence(token,top)){
				op1=0;op2=0;
        pop(&operator_stack,&op); pop(&operand_stack,&op1); pop(&operand_stack,&op2);
        res=calculate(op1,op,op2);
				push(&operand_stack,res);
				top=get_top(&operator_stack,1);
      }
			push(&operator_stack,token);
    }
    if(token==')'){
			char top=get_top(&operator_stack,1);
      while(top!='('){
        pop(&operator_stack,&op); pop(&operand_stack,&op1); pop(&operand_stack,&op2);
        res=calculate(op1,op,op2);
        push(&operand_stack,res);
				top=get_top(&operator_stack,1);
      }
      pop(&operator_stack,&garbage);
    }
  }
  while(!Empty(&operator_stack)){
    pop(&operator_stack,&op); pop(&operand_stack,&op1); pop(&operand_stack,&op2);
    res=calculate(op1,op,op2);
    push(&operand_stack,res);
  }
	char final;
	pop(&operand_stack,&final);
  printf("The result is %d\n",final);
	return 0;
}

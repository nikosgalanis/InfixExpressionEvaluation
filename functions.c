#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char calculate(char operand1, char op, char operand2){
	char op1=operand1-48, op2=operand2-48;
  if(op=='+') return (op1+op2);
  else if(op=='-') return (op1-op2);
  else if(op=='*') return (op1*op2);
  else{
    if (op2==0) {
    printf("Give normal numbers! -.-\n");
    return 0;}
    else return(op1/op2);
  }
}

int has_precendence(char op1, char op2){
	if (op2=='(' || op2==')') return 0;
	if ((op1=='*' || op1=='/') && (op2=='+' || op2=='-')) return 0;
	else return 1;
}

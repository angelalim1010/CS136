#include <iostream>
using namespace std;
/*
Author: Angela Lim
Assignment: Project Task D
This program will read a file, accept symbols,
formulas, and non-negative integers. This will be
able to return the sum of the integers.
*/
int main(){
  int number, sum=0; 
  //result
  char op; 
  //operator
  char op2='+';
  cin>>number; 
  //reads in the first number
  while (cin>>op){
  //reads in the operator
    if (op=='^'){ 
    //square numbers
      number = number*number;
      cin>>op;
      //reads in the next operator
    }
    if(op2 =='+'){
      sum += number; 
      //adds next number to sum
    }
    if(op2=='-'){
      sum -= number; 
      //subtracts number to sum
    }
    op2=op; 
    //resets the variable
    cin>>number; 
    //reads in the numbers
    if(op2==';'){
      cout<<sum<<endl; 
      //prints out sum
      sum=0; 
      //resets the sum 
      op2='+'; 
      //resets the variable
    }
  }
  return 0;
}
    
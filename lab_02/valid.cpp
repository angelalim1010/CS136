/*
Author: Angela Lim
Course: CSCI-133
Instructor: Mike Zamansky
Assignment: Lab2A

This program asks the user to input an integer within the range of 0-100. If the number is out of range, 
the program will ask the user th re-enter a value until it is valid.
The valid number will be squared
*/
//I couldn't figure out how to convert from string to and int
#include <iostream>

using namespace std;
bool istrue (int input_number)
{
    if ((input_number < 0)  or (input_number > 100)){
        return false;
    }
   else {
     
       return true;
   } 
}
int main(){
	int input_number;
	
	cout << "Please enter an integer: ";
	cin >> input_number;
	while (istrue(input_number) == false){
		if ((input_number < 0)  or (input_number > 100)){
		cout << "Please re-enter: ";
		cin >> input_number;
		}
	}
	
			    
			    int num;
	            num = input_number*input_number;
	            cout << "Number squared is " << num;
	            cout << endl;
	            
			
			   
		
		/*
	}
	(input_number >-1 or input_number < 101){
	    
	    
	    }	
	*/

			
	
	
	return 0;

}


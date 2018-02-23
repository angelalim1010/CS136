#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

using namespace std;

double east_storage(string valid_date){

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
    }
    string junk;
    getline(fin, junk);
    string date;
    double eastSt, eastEl, westSt, westEl, result;
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) { 
      if(valid_date == date){
	       return eastSt;
      }
    }
    fin.close();

  
  return 0.0;
}
int main(){

cout<< "East storage at 1/01/2016" << east_storage("01/10/2016")<<endl;
cout<<"East storage at 2/01/2016" << east_storage("02/01/2016")<<endl;
cout<<"East storage at 3/01/2016" << east_storage("3/01/2016")<<endl;
cout<<"East storage at 1/01/2017 is  "<<east_storage("1/01/2017")<<endl;

}
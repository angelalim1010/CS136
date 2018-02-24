#include <iostream>
#include "funcs.h"
#include <cstdlib>
#include <fstream>
using namespace std;

int main(){
	ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
    }
    string junk;
    getline(fin, junk);
    // a
    cout<< "East storage at 1/01/2016" << east_storage("01/10/2016")<<endl;
	cout<<"East storage at 2/01/2016" << east_storage("02/01/2016")<<endl;
	cout<<"East storage at 3/01/2016" << east_storage("3/01/2016")<<endl;
	cout<<"East storage at 1/01/2017 is  "<<east_storage("1/01/2017")<<endl;
	//b
	cout << "The miminum is" << mineast() << endl;
	cout << "The maximum is " << maxeast() << endl;
	//c 
	cout << "Compare \n" << compare("09/13/2016", "09/14/2016") << endl;
	//d
	cout << reverse_order("05/29/2016","06/02/2016")

    fin.close();
}
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
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

double mineast() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
    }
    string junk;
    getline(fin, junk);
    string date;
    double eastSt, eastEl, westSt, westEl, result;
	double min = east_storage("01/01/2016");
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
		if (eastSt < min){
			min = eastSt;
		}
	}
	fin.close();
	return min;
}



double maxeast() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
    }
    string junk;
    getline(fin, junk);
    string date;
    double eastSt, eastEl, westSt, westEl, result;
	double max = east_storage("01/01/2016");
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl){
		if (eastSt > min){
			max = eastSt;
		}
	}
	fin.close();
	return max;
}


string compare (string date1, string date2) {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
    }
    string junk;
    getline(fin, junk);
    string date;
    double eastSt, eastEl, westSt, westEl, result;
	string ans = "";
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
		if ((date >= date1) && (date <= date2)) {
			ans += date + " ";
			if (eastEl > westEl){
				ans += " East\n";
			}
			else if (eastEl < westEl) { 
				ans += " West\n";
			}
			else { 
				ans += " Equal\n";
			}
		}
	}
	fin.close();
	return ans;
}


string reverse_order (string date1, string date2) {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
      cerr << "File cannot be opened for reading." << endl;
      exit(1);
    }
    string junk;
    getline(fin, junk);
    string date;
    double eastSt, eastEl, westSt, westEl, result;
	string ans = "";
	while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
		if (date>= first_date && date<=second_date){	
			ans = date + " " + std::to_string(westEl) + "\n" + ans;
		}
	}
	fin.close();
	return ans;
}





	 


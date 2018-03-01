#include <iostream>
#include <string>
using namespace std;
string line(int l, string c){
	string s = "";
	for (int i=0; i<l; i++){
		s+=c;
	}
	return s;
	return "";
}


string box(int width, int height){
	string s = "";
	for (int i=0; i<=height; i++){
		s+=line(width,"*")+"\n";
	}
	return s;
	return "";
}

string checkerboard(int width, int height){
	string s ="";
	for (int row=0; row < height; row++){
		for (int col = 0; col < width; col++){
			if(row % 2 == 0){
				
				s+= " "+line(2*width-1,"*")+" "+"\n";
			}
			else{
				s+= line(width,"*")+"\n";
			}
		}	

	}
	return s;
	return "";
}

string lowertri(int h){
	string s = "";
	for (int i=0; i<1; i++){
		s+= line(h,"*")+"\n";
	}
	return s;
	return "";
}

string uppertri(int length){
	string s = "";
	for (int i =length; i>=1; i--){
		s+=line(length,"*") + "\n";
	}
	return s;
	return "";
}
/*
string upsidedowntrap(int width, int height){
	string s = "";
	for (int i=0; i>=1; i--){

	}
}
*/
int main(){
		//cout << checkerboard(11,6) << endl;
	cout << box(7,4) << endl;
		cout <<  uppertri(5) << endl;
}
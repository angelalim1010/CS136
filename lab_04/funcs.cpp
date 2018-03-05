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
			if(row % 2){
				
				s+= line(width/2-1," *")+"\n";
			}
			else{
				s+= line(width/2,"* ")+"\n";
			}
			

	}
	return s;
	return "";
}

string cross(int size){
	string s = "";
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(j==i || size-j-1==i){
				s+="*";
			}else{
				s+=" ";
			}
		}
		s+="\n";
	}
	return s;
}

string lowertri(int h){
	string s = "";
	for (int i=0; i<h; i++){
		s+= line(i+1,"*")+"\n";
	}
	return s;
	return "";
}

string uppertri(int length){
	string s = "";
	for (int i =length; i>=1; i--){
		s+=line(length-i," ") + line(i,"*") +"\n";
	}
	return s;
	return "";
}

string upsidedowntrap(int width, int height){
	string s = "";

	for(int i=0; i<height; i++){
		s+=line(i," ")+line(width-2*i,"*")+line(i," ")+"\n";
	}
	return s;
	return "";
}
string checkerboard3(int width, int height){
	string s = "";
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if ((i/3)%2 == 0){
				if ((j/3)%2 == 0) {
					s += "*";
				}
				else {
					s += " "; 
				}
			}
			else {
				if ((j/3)%2 == 0 ) {
					s += " ";
				}
				else { 
					s += "*"; 
				}
			}
		}
		s += "\n";
	}
	
	return s;
}
	


int main(){
	cout <<  box(7,4) << endl;
	cout <<  checkerboard(11,6) << endl;
	cout <<  cross(8) << endl;
	cout <<  lowertri(6) << endl;
	cout <<  uppertri(5) << endl;
	cout <<  upsidedowntrap(12,5) << endl;
	cout <<  checkerboard3(16,11) << endl;

}
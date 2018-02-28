#include <iostream>
#include <sstream>
using namespace std;
int main(){
	
	int sum = 0;
//    int x = 0;
    bool sign= false;
    bool isAnum = false;
    string num = "";
    char s;
 //   string s;
    while(cin >> s) { 
        if(s != 43 || s != 45)
            isAnum = true;    
        else if(isAnum)
            num = s + num;
        else if(s == 43){ //+
            sign = false;
            isAnum = false;
        }
        else if (s == 45){} //-
            sign = true;
            isAnum = false;
        }
        else if(!sign){
  //          stringstream geek(s);
  //          geek >> x;
            sum += s;
            cout << "ad";
  //          sum += x;
        }
        else{
  //  	   stringstream geek(s);
  //          geek >> x;
  //          sum -= x;
            cout<< "sub";
            sum -= s;
        }
    }
    cout << sum << "\n";
    return 0;
/*	int sum = 0;
	for (int i = 1; i <= number; i++){
		sum += i;
		return sum;
	}
*/
}

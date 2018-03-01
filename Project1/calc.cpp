#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
int main(){
	
	int sum = 0;
    int number;
    vector<int> arr;
    vector<string> op;
    int counter = 0;
    bool isAnum;
    string num = "";
    char s;

    while(cin >> s) { 
        isAnum = false;
        if(s != 43 || s != 45)
            isAnum = true;    
        else if(isAnum){
            num = s + num;
            stringstream geek(num);
            geek >> number;
            arr.push_back(number);
        }
        else if(s == 43){ 
            op.push_back("+");//+
        }
        else if (s == 45){ //-
            op.push_back("-");
            
        }
    }
    sum = arr.at(0);
    for(int i = 1; i < arr.size(); i++){
        if(op.at(counter) == "+")
            sum += arr.at(i);
        else
            sum -= arr.at(i);
        counter++;
    }
    cout << sum << "\n";
    return 0;

}

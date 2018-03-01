#include <iostream>
using namespace std;
int main(){
	
	int sum = 0;
    int s;
    while(cin >> s) { 
    /* While the reading operation is a success
   	print the read word
    */
    	sum += s;
    }
    cout << sum << "\n";
    return 0;

}

#include <iostream>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile(string usrn, string dspn){
    // Default Profile constructor (username="", displayname="")
    username = usrn;
    displayname = dspn;
    }
    Profile(){
        username = "";
        displayname = "";
    }
    // Return username
    string getUsername(){
        return username;
    }
    // Return name in the format: "displayname (@username)"
    string getFullName(){
        return displayname + "(@" + username + ")";
    }
    // Change display name
    void setDisplayName(string dspn){
        displayname = dspn;
    }
};

class Network {
private:
  static const int MAX_USERS = 20; // max number of user profiles
  int numUsers;                    // number of registered users
  Profile profiles[MAX_USERS];     // user profiles array:
                                   // mapping integer ID -> Profile
  bool following[MAX_USERS][MAX_USERS];    // new 
  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
  int findID (string usrn){
  	for (int i = 0; i < MAX_USERS; i++){
  		if(profiles[i].getUsername() == usrn){
  			return i;
  		}
  	}
  	return -1;
  }
public:
  // Constructor, makes an empty network (numUsers = 0)
  Network(){
  	numUsers = 0;
  	for (int i = 0; i < MAX_USERS; i++){
  		for(int j = 0; j < MAX_USERS; j++){
  			following[i][j] = false;
  		}
  	}
  }
  bool addUser(string usrn, string dspn);
  bool follow(string usrn1, string usrn2); // new
  void printDot();                         // new
};
bool alpha(string s){
	for (int i = 0; i < s.length(); i++){
		if (!isalpha(s[i]) && !isdigit(s[i])){
			return false;
		}
	}
	return true;
}

bool username(string usrn){
	return usrn != "" && alpha(usrn);
}
bool Network::addUser(string usrn, string dspn){
	if((usrn != "") && (alpha(usrn)) && (numUsers < MAX_USERS)){
		for (int i = 0; i < MAX_USERS; i++){
			if (profiles[i].getUsername() == usrn){
				return false;
			}
		}
		Profile new_user(usrn,dspn);
		profiles[numUsers] = new_user;
		numUsers += 1;
		return true;
	}
	else{
		return false;
	}
}

bool Network::follow(string usrn1, string usrn2){
	if((username(usrn1)) && (username(usrn2)) && (findID(usrn1) != -1) && (findID(usrn2) != -1)){
		following[findID(usrn1)] [findID(usrn2)] = true;
		return true;
	}
	else{
		return false;
	}
}

void Network::printDot() {
	cout << "digraph {" << endl;
	for (int i = 0; i < numUsers; i++) {
		cout << "\t\"@" + profiles[i].getUsername() + "\"" << endl;
	}
	
	cout << "\n";
	
	for (int i = 0; i < MAX_USERS; i++) {
		for (int j = 0; j < MAX_USERS; j++) {
			if (following[i][j]) {
				cout << "\t\"@" + profiles[i].getUsername() + "\" -> \"" + profiles[j].getUsername() + "\"" << endl;
			}
		}
	}
	cout << "}" << endl;
}

  int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
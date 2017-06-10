//regex matcher
#include <regex>
#include <string>
#include <iostream>

using namespace std;

int regSearch(string s){
	//cout<<"s: "<<s<<endl;
	regex UIN {R"(\d{3}-?(00)-?\d{4})"};
	smatch matches;	// matched strings go here
	regex_search(s, matches, UIN);
	if(matches.empty()){
		//cerr<<"There is an invalid UIN present";
	}
	return stoi(matches[0]);
}
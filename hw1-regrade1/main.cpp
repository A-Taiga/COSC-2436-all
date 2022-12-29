#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cctype>
#include "ArgumentManager.h"
using namespace std;

bool read_file(string, vector<string>&, bool);
void match(vector<string>&, int);
void filter(ostream& o, vector<string>& lines, vector<string>& first_4, vector<string>& last_4, int l);

int main(int argc, char* argv[]) {
	
	ArgumentManager am(argc,argv);
	string input = am.get("input");
	string output = am.get("output");
	string command = am.get("command");
	/*
	ifstream input("input2.txt");
	ifstream command("command2.txt");
	ofstream output("output1.txt");
	*/
	vector<string> inputs;
	vector<string> commands;
	vector<string> first_4;
	vector<string> last_4;

	ofstream out(output.c_str());
	read_file(input.c_str(),inputs,false);//read input files
	bool empty = read_file(command.c_str(),commands,true);//read command files
	match(inputs,0);
	if(empty) { // output everyting if command file is empty
		for(size_t i = 0; i < inputs.size(); i++) {
			out << inputs[i] << endl;
		}
		return 0;
	}
	for(size_t i = 0; i < commands.size(); i++) {
		string first = commands[i].substr(0,commands[i].find(':'));
		string second = commands[i].substr(commands[i].find(':')+1,commands[i].length());
		if(first == "first4") {
			first_4.push_back(second);
		}
		if(first == "last4") {
			last_4.push_back(second);
		}
	}
	filter(out,inputs,first_4,last_4,0);
	out.close();
	return 0;
}

bool read_file(string input, vector<string>& lines, bool isCommand) {
	ifstream in(input);
	if(isCommand) {
		if(in.peek() == EOF) {
			in.close();
			return true;
		} else {
			in.close();
			in.open(input);
		}
	}
	string line = "";
	while(getline(in,line)) {
		line.erase(remove(line.begin(),line.end(),'\r'),line.end());
		line.erase(remove(line.begin(),line.end(),'\n'),line.end());
		line.erase(remove(line.begin(),line.end(),' '),line.end());
		if(!isCommand) {
			if(line.find("id") == line.npos || line.find("id") == 0) {
				continue;
			}
		}
		lines.push_back(line);
	}
	in.close();
	return false;
}
void match(vector<string>& lines, int n) {
	if(n == lines.size()) {
		return;
	} else {
		string keys = lines[n].substr(0,lines[n].find("id"));
		string id = lines[n].substr(lines[n].find("id:")+3,lines[n].length());
		keys.erase(remove(keys.begin(),keys.begin(),':'),keys.end());
		string letter = "";
		string number = "";
		istringstream ss(lines[n]);
		char c;
		while(ss >> c) {
			if(c == ';') {
				while(id.find(letter) != id.npos) {
					id.replace(id.find(letter),1,number);
				}
				number = "";
				continue;
			}
			if(isalpha(c)) {letter = c;}
			if(isdigit(c)) {number += c;}
		}
		ss.clear();
		ss.str(id);
		string newID = "";
		int i = 0;
		while(ss >> c) {
			if(c == '#') {newID += to_string(i);} 
			else {newID += c;}
			i++;
		}
		lines[n] = newID;
		match(lines,n+1);
	}
}
void filter(ostream& o, vector<string>& lines, vector<string>& first_4, vector<string>& last_4, int l) {
	if(l == lines.size()) {
		return;
	} else {
		string head = lines[l].substr(0,4);
		string tail = lines[l].substr(lines[l].length()-4,lines[l].length());
		if(first_4.size() == 0 || last_4.size() == 0) {
			if(last_4.size() == 0) {
				for(size_t k = 0; k < first_4.size(); k++) {
					if(first_4[k] == head) {
						o << lines[l] << endl;
						break;
					}
				}
			}
			if(first_4.size() == 0) {
				for(size_t k = 0; k < last_4.size(); k++) {
					if(last_4[k] == tail) {
						o << lines[l] << endl;
						break;
					}
				}
			}
			filter(o,lines,first_4,last_4,l+1);
		} else {
			for(size_t k = 0; k < first_4.size(); k++) {
				if(first_4[k] == head) {
					for(size_t z = 0; z < last_4.size(); z++) {
						if(last_4[z] == tail) {
							o << lines[l] << endl;
						}
					}
				}
			}
			filter(o,lines,first_4,last_4,l+1);
		}
	}
}
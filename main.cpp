//main.cpp
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include "regex.cpp"
#include <list>
#include <vector>
using namespace std;


int main(){

	/*-------------------------------
	------Create Student Struct------
	--------------------------------*/
	struct student{
		int key;
		int value;
		student(int k, int v){key = k; value = v;}
	};

	vector< list < student >  > hashTable(100); //vector of lists of students
	vector<list < student > > gradeOutput(100);
	string filename;
	string name;
	string email;
	string uin;
	string grade;
	int nodeCount;
	int maxNode = 1;
	int tnode;
	int avgNode = 0;
	int minNode = 0;
	int inpInde;

	/*-----------------------------
	--------Read Input File--------
	------------------------------*/
	

	filename = "input.csv";
	ifstream in(filename);
	if (!in) cerr << "no file\n";
	if (in.is_open()){
    	cout<<filename<<"..."<<" Complete"<<endl;
	}
	
	while(getline(in,name,',')){
		getline(in,email,',');
		getline(in,uin,',');
		getline(in,grade);
		student temp = student(regSearch(uin),stoi(grade));
		inpInde = regSearch(uin)%100;
		hashTable[inpInde].push_back(temp);
		nodeCount++;
		avgNode++;
	}
	
	/*------------------------------
	--------Read Roster File--------
	-------------------------------*/
	ofstream myfile;
	myfile.open ("output.csv");
	int rostInde;
	ifstream rost("roster.csv");
	if (!rost) cerr << "no file\n";
	if (rost.is_open()){
    	cout<<"roster.csv"<<"..."<<" Complete"<<endl;
	}
	list<student>::iterator it;
	while(getline(rost,name,',')){
	 	getline(rost,email,',');
	 	getline(rost,uin);
		student temp = student(regSearch(uin),0);
		rostInde = regSearch(uin)%100; //get index of each student in roster
		
		if(hashTable[rostInde].empty()){
			myfile<<name<<','<<email<<','<<uin;
		}
		else{
			tnode = 0;
			for(it = hashTable[rostInde].begin(); it != hashTable[rostInde].end(); it++){
				tnode++;
				if(tnode > maxNode){
					maxNode = tnode;
					avgNode--;
				}
				if((it)->key == temp.key){
					temp.value = (it)->value;
					myfile<<name<<','<<email<<','<<temp.key<<','<<temp.value<<endl;
				}
				
			}
		}
	}
	cout<<"Writing to output.csv... Complete\n";
	cout<<"Max # of nodes = "<<maxNode<<endl;
	cout<<"Min # of nodes = "<<minNode<<endl;
	cout<<"Average # of nodes per list = "<<double(nodeCount)/double(avgNode)<<endl;
	cout<<"Total # of nodes = "<<nodeCount<<endl;
	return 0;
	}



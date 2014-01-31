/* 
 * File:   main.cpp
 * Author: jappie
 *
 * Created on January 31, 2014, 3:19 PM
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm> 
#include <math.h>
#include <stdio.h>
#include <time.h>

using namespace std;
vector<int>* eratoshenes(int &till){


	vector<int>* results = new vector<int>(0, 0);
	vector<int>* notpriemes = new vector<int>(0, 1);


	if(2 > till){
		throw "Het nummer is kleiner als 2";
	}

	// some optimilization
	if(2 <= till){
		results->push_back(2);
	}


	for(int i = 3; i <= till; i += 2){

		// notpriemes not contains
		if(find(notpriemes->begin(), notpriemes->end(), i) == notpriemes->end()){

			// add to results
			results->push_back(i);

			int notPrimeCandidate = 0;
			// add dubble trip etc to not priemes
			for(int tafel = 2; notPrimeCandidate < till; tafel++){


				notPrimeCandidate = i*tafel;

				// if already contains no need to add another
				if(find(notpriemes->begin(), notpriemes->end(), notPrimeCandidate) == notpriemes->end()){

					notpriemes->push_back(notPrimeCandidate);
				}
			}
		}
	}
	delete notpriemes;
	return results;
};

void println(string str){
	cout << str << endl;
};

int main(int argc, char** argv) 
{
	bool running = true;
	while(running){
		string command = "";
		int N = 0;
		println("Type help for a list off commands");
		cin >> command;
		if(command == "exit"){
			running = false;
		}else
		if(command == "help"){
			println("exit, to end the program");
			println("p1a, to print an ascii document with prime years and 11 consective prime numbers that sum to that 'year'. It also contains a beautifull date and my name and even a title, wow");

			println("any number to show a bunch of primes below that number");
		}else
		if(command == "p1a"){

		}
		else{
			N = atoi(command.c_str());

			try{

				vector<int> primeNumbers = (*eratoshenes(N));

				println("Prime numbers: ");

				for(int i = 0; i < primeNumbers.size(); i++){

					cout << primeNumbers[i] << ", ";
				}
				cout << endl;

			}catch(string s){
				cout << s;
			}
		}
	}
	return 0;
}

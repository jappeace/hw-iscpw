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
#include <stdio.h>
#include <time.h>
#include "PrimeNumberFactory.h"
using namespace std;
using namespace nl_jappieklooster;

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
				PrimeNumberFactory* factory = new PrimeNumberFactory();
				vector<int> primeNumbers = (*factory->eratoshenes(N));

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

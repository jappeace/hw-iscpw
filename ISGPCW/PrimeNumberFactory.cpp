#include "PrimeNumberFactory.h"
using namespace nl_jappieklooster;
vector<int>* PrimeNumberFactory::eratoshenes(int &till){
	results = new vector<int>(0, 0);
	notpriemes = new vector<int>(0, 1);


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
}
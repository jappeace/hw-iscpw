/* 
 * File:   primeNumberFactory.h
 * Author: jappie
 *
 * Created on January 31, 2014, 4:54 PM
 */

#ifndef PRIMENUMBERFACTORY_H
#define	PRIMENUMBERFACTORY_H

#include <cstdlib>
#include <vector>
#include <algorithm> 
#include <math.h>

namespace nl_jappieklooster{
	using namespace std;
	class PrimeNumberFactory{
	private:
		vector<int>* results;
		vector<int>* notpriemes;
	public:
		vector<int>* eratoshenes(int &till);
};
}
#endif	/* PRIMENUMBERFACTORY_H */


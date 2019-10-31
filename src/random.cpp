#include "random.h"
#include <iostream>
RandomNumbers::RandomNumbers(unsigned long int s)
{   
	if(s==0) {
	std::random_device rd;
	seed = rd();
    }else{
	seed = s;
    }
    
    rng = std::mt19937(seed);
	
}


void RandomNumbers::uniform_double(std::vector<double>& tab, double lower, double upper) 
{
	std::uniform_real_distribution<double> duni(lower,upper);
	if(tab.size() != 0)
	{
		for(size_t i = 0; i<tab.size(); ++i) {
		tab[i] = duni(rng);
	    }
    }	
}


double RandomNumbers::uniform_double(double lower, double upper)
{

	std::uniform_real_distribution<double> duni(lower,upper);
	return duni(rng);

}


void RandomNumbers::normal(std::vector<double>& tab, double mean, double sd)
{
	std::normal_distribution<double> dnorm(mean,sd);
	if(tab.size() != 0)
	{
		for(size_t i = 0; i<tab.size(); ++i) {
		tab[i] = dnorm(rng);
	    }
    }
}


double RandomNumbers::normal(double mean, double sd)
{
	
	std::normal_distribution<double> dnorm(mean,sd);
	return dnorm(rng);

}

void RandomNumbers::poisson(std::vector<int>& tab, double mean)
{
	std::poisson_distribution<int> dpoiss(mean);
	if(tab.size() != 0)
	{
		for(size_t i = 0; i<tab.size(); ++i) {
		tab[i] = dpoiss(rng);
	    }
    }
}
 
    
int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<int> dpoiss(mean);
	return dpoiss(rng);
	
}

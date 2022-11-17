#ifndef FESTIVAL_H
#define FESTIVAL_H

#include <iostream>

using namespace std;

class Festival{

    private:
        Concert *firstConcert;
        Concert *secondConcert;

    public:
        Festival(void);                     //default constructor
        Festival(Concert*, Concert*);       //constructor with parameters
        Concert* getFirstConcert();
        Concert* getSecondConcert();
        void setFirstConcert(Concert*);
        void setSecondConcert(Concert*);
        void displayInfo();
        Festival(const Festival&);                                  //copy constructor
	    Festival& operator=(Festival&);                             //copy assignment operator
        ~Festival(void);
};
#endif
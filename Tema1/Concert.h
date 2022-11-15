#ifndef CONCERT_H
#define CONCERT_H

#include <iostream>
#include <string>

using namespace std;

class Concert: public Event{

    private:
        string band;

    public:
        Concert(void);                                  //default constructor
        Concert(string, string, int, bool, string);     //constructor with parameters
        string getBand();
        void setBand(string);
        void displayInfo();
        Concert(const Concert&);                           //copy constructor
	    Concert operator=(Concert);                        //copy assignment operator
        ~Concert(void);                                    //destructor

};
#endif
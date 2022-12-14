#ifndef CONCERT_H
#define CONCERT_H

#include <iostream>
#include <string>

using namespace std;

class Concert: public Event{

    private:
        string band;
        bool booked;

    public:
        Concert(void);                                  //default constructor
        Concert(string, string, int, bool, string);     //constructor with parameters
        string getBand();
        void setBand(string);
        void displayInfo();
        Concert(const Concert&);                            //copy constructor
	    Concert operator=(Concert);                         //copy assignment operator
        //~Concert(void);                                   //destructor
        bool getBooked();                                   //added for item 14
        void setBooked(bool);                               //added for item 14
        void isConcertBooked();                             //added for item 14
        void lock(Concert&);
        void unlock(Concert&);

};
#endif
#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{

    protected:
        string venue;
        string date;
        int durationInHours;
        bool barAvailable;

    public:
        Event(void);                            //default constructor
        Event(string, string, int, bool);       //constructor with parameters
        string getVenue();
        string getDate();
        int getDurationInHours();
        bool getBarAvailable();
        void setVenue(string);
        void setDate(string);
        void setDurationInHours(int);
        void setBarAvailable(bool);
        void displayInfo();
        Event(const Event&);                    //copy constructor
	    Event operator=(Event);                 //copy assignment operator
        //~Event(void);                         //destructor
        Event* createEvent();                   //Item 13: Use objects to manage resources.

};
#endif
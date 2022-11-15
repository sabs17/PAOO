#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

using namespace std;

class Event{

    private:
        string venue;
        string date;
        int durationInHours;
        bool barAvailable;

    public:
        Event(void);                         //default constructor
        Event(string, string, int, bool);   //constructor with parameters
        string getVenue();
        string getDate();
        int getDurationInHours();
        bool getBarAvailable();
        void setVenue(string);
        void setDate(string);
        void setDurationInHours(int);
        void setBarAvailable(bool);
        void displayInfo();

};
#endif
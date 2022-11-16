#include "Event.h"
#include "Concert.h"
using namespace std;

//default constructor
//Item 4: Make sure that objects are initialized before they’re used.
Event::Event() :
    venue(),
    date(),
    durationInHours(0),
    barAvailable(false)
{}

//constructor with parameters
//Item 4: Make sure that objects are initialized before they’re used.
Event::Event(string venue, string date, int durationInHours, bool barAvailable) :
    venue(venue),
    date(date),
    durationInHours(durationInHours),
    barAvailable(barAvailable)
{}

string Event::getVenue(){
    return this->venue;
}

string Event::getDate(){
    return this->date;
}

int Event::getDurationInHours(){
    return this->durationInHours;
}

bool Event::getBarAvailable(){
    return this->barAvailable;
}

void Event::setVenue(string venue){
    this->venue = venue;
}

void Event::setDate(string date){
    this->date = date;
}

void Event::setDurationInHours(int durationInHours){
    this->durationInHours = durationInHours;
}

void Event::setBarAvailable(bool barAvailable){
    this->barAvailable = barAvailable;
}

void Event::displayInfo(){
    string bar;
    if(this->barAvailable == true)
        bar = "Bar available";
    else 
        bar = "Bar not available";
    cout<<"\nVenue: "<<this->venue<<"\n"<<"Date: "<<this->date<<"\n"<<"Duration: "<<this->durationInHours<<" hours \n"<<bar<<"\n";
}

//Item 5: Know what functions C++ silently writes and calls.
/*
Event::Event(const Event& e){
    cout<<"\nCopy constructor called from Event class.\n";
    venue = e.venue;
    date = e.date;
    durationInHours = e.durationInHours;
    barAvailable = e.barAvailable;
}

Event Event::operator = (Event e){
    cout<<"\nCopy assignment operator called from Event class.\n";
    venue = e.getVenue();
    date = e.getDate();
    durationInHours = e.getDurationInHours();
    barAvailable = e.getBarAvailable();
    return *this;
}
*/
//Item 6: Explicitly disallow the use of compiler generated functions you do not want
//copy constructor and copy assignment operator are declared private and have no implementation so
//they can't be called

Event::~Event(){
    cout<<"\nEvent is DESTROYED\n";
}

//Concert

//default constructor
//Item 4: Make sure that objects are initialized before they’re used.
Concert::Concert() :
    Event(),
    band()
{}

//constructor with parameters
//Item 4: Make sure that objects are initialized before they’re used.
Concert::Concert(string venue, string date, int durationInHours, bool barAvailable, string band) :
    Event(venue, date, durationInHours, barAvailable),
    band(band)
{}

string Concert::getBand(){
    return this->band;
}

void Concert::setBand(string band){
    this->band = band;
}

void Concert::displayInfo()
{
    Event::displayInfo();
    cout<<"Band: "<<this->band<<"\n";
}

//Item 5: Know what functions C++ silently writes and calls.

Concert::Concert(const Concert& c){
    cout<<"\nCopy constructor called from Concert class.\n";
    venue = c.venue;
    date = c.date;
    durationInHours = c.durationInHours;
    barAvailable = c.barAvailable;
    band = c.band;
}

Concert Concert::operator = (Concert c){
    cout<<"\nCopy assignment operator called from Concert class.\n";
    venue = c.getVenue();
    date = c.getDate();
    durationInHours = c.getDurationInHours();
    barAvailable = c.getBarAvailable();
    band = c.getBand();
    return *this;
}

Concert::~Concert(){
    cout<<"\nConcert is DESTROYED\n";
}

class Play: public Event{

};

int main(){ 

    Event e;
    Event e2("Acasa", "acu", 1, true);
    Concert c;
    Concert c2("tot acasa", "maine", 2, false, "eu");
    //cout<<e2.getDate()<<"\n"<<c2.getBand()<<"\n";
    //e.displayInfo();
    //e2.displayInfo();
    //c.displayInfo();
    //c2.displayInfo();

    //Item 4: Make sure that objects are initialized before they’re used.
    int duration = 0;   //initialization of a built-in type
    duration = 5;       //assignation
    c2.setDurationInHours(duration);
    //cout<<c2.getDurationInHours()<<"\n";
    //((Event)c2).displayInfo();

    //Item 5: Know what functions C++ silently writes and calls.
    Concert c3(c2);
    c = c2;

    //Item 6: Explicitly disallow the use of compiler generated functions you do not want
    //copy constructor is private => copy and assign will have errors

/*
    Event e3(e2);
    e = e2;

    Play p;
    Play p2(p);
    Play p3;
    p3 = p;
*/

    return 0;
}
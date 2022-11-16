#include "Event.h"
#include "Concert.h"
using namespace std;

//default constructor
Event::Event() :
    venue(),
    date(),
    durationInHours(0),
    barAvailable(false)
{}

//constructor with parameters
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

//copy constructor
Event::Event(const Event& e){
    cout<<"\nCopy constructor called from Event class.\n";
    venue = e.venue;
    date = e.date;
    durationInHours = e.durationInHours;
    barAvailable = e.barAvailable;
}

//copy assignment operator
Event Event::operator = (Event e){
    cout<<"\nCopy assignment operator called from Event class.\n";
    venue = e.getVenue();
    date = e.getDate();
    durationInHours = e.getDurationInHours();
    barAvailable = e.getBarAvailable();
    //Item 10: Have assignment operators return a reference to *this.
    return *this;
}

//destructor
Event::~Event(){
    cout<<"\nEvent is DESTROYED\n";
}

//Concert

//default constructor
Concert::Concert() :
    Event(),
    band()
{}

//constructor with parameters
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

//copy constructor
Concert::Concert(const Concert& c){
    cout<<"\nCopy constructor called from Concert class.\n";
    venue = c.venue;
    date = c.date;
    durationInHours = c.durationInHours;
    barAvailable = c.barAvailable;
    band = c.band;
}

//copy assignment operator
Concert Concert::operator = (Concert c){
    cout<<"\nCopy assignment operator called from Concert class.\n";
    venue = c.getVenue();
    date = c.getDate();
    durationInHours = c.getDurationInHours();
    barAvailable = c.getBarAvailable();
    band = c.getBand();
    //Item 10: Have assignment operators return a reference to *this.
    return *this;
}

//destructor
Concert::~Concert(){
    cout<<"\nConcert is DESTROYED\n";
}

class Play: public Event{

};

int main(){ 

    Event e;
    Event e1("Acasa", "acu", 1, true);
    Event e2;
    Concert c;
    Concert c1("tot acasa", "maine", 2, false, "eu");
    Concert c2;

    //Item 10: Have assignment operators return a reference to *this.
    e = e2 = e1;
    c = c2 = c1;
    e.displayInfo();
    c.displayInfo();

    return 0;
}
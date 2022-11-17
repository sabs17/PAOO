#include "Event.h"
#include "Concert.h"
#include "Festival.h"
using namespace std;

//default constructor
Event::Event() :
    venue(),
    date(),
    durationInHours(0),
    barAvailable(false)
{}

//Item 12: Copy all parts of an object.
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

//Item 12: Copy all parts of an object.
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
    //cout<<"\nEvent is DESTROYED\n";
}

//Concert

//default constructor
Concert::Concert() :
    Event(),
    band()
{}

//Item 12: Copy all parts of an object.
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

//Item 12: Copy all parts of an object.
//copy constructor
Concert::Concert (const Concert& c) : Event(c){
    cout<<"\nCopy constructor called from Concert class.\n";
    band = c.band;
}

//Item 12: Copy all parts of an object.
//copy assignment operator
Concert Concert::operator = (Concert c){
    cout<<"\nCopy assignment operator called from Concert class.\n";
    Event::operator=(c);
    band = c.band;
    //Item 10: Have assignment operators return a reference to *this.
    return *this;
}
//changed copy and assignment constructors to call Event copy and assignment constructors to
//cover possible parameter changes in Event class (only change Event constructors, not also
//Concert constructors -> item 12

//destructor
Concert::~Concert(){
    //cout<<"\nConcert is DESTROYED\n";
}

//Festival

//default constructor
Festival::Festival() :
    firstConcert(NULL),
    secondConcert(NULL)
{}

//Item 12: Copy all parts of an object.
//constructor with parameters
Festival::Festival(Concert *firstConcert, Concert *secondConcert) :
    firstConcert(firstConcert),
    secondConcert(secondConcert)
{}

Concert* Festival::getFirstConcert(){
    return this->firstConcert;
}

Concert* Festival::getSecondConcert(){
    return this->secondConcert;
}

void Festival::setFirstConcert(Concert *firstConcert){
    this->firstConcert = firstConcert;
}

void Festival::setSecondConcert(Concert *secondConcert){
    this->secondConcert = secondConcert;
}

void Festival::displayInfo()
{
    cout<<"\n***Festival***";
    cout<<"\nFirst concert: ";
    this->firstConcert->displayInfo();
    cout<<"\nSecond concert: ";
    this->secondConcert->displayInfo();
    cout<<"******\n";
}

//Item 12: Copy all parts of an object.
//copy constructor
Festival::Festival(const Festival& f){
    cout<<"\nCopy constructor called from Festival class.\n";
    firstConcert = f.firstConcert;
    secondConcert = f.secondConcert;
    
}

//copy assignment operator
Festival& Festival::operator = (Festival& f){
    cout<<"\nCopy assignment operator called from Festival class.\n";

    //Item 11: Handle assignment to self in operator=.
    //identity test
    if (this == &f){
        cout<<"Assignment to self\n";
         return *this;
    }
    delete firstConcert;
    delete secondConcert;
    firstConcert = new Concert(*f.firstConcert);
    secondConcert = new Concert(*f.secondConcert);
    
    //Item 10: Have assignment operators return a reference to *this.
    return *this;
}

int main(){ 

    Event e;
    Event e1("Acasa", "acu", 1, true);
    Event e2;
    Concert c;
    Concert c1("tot acasa", "maine", 2, false, "some band");
    Concert c2;

    //Item 10: Have assignment operators return a reference to *this.
    e = e2 = e1;
    c = c2 = c1;
    e.displayInfo();
    c.displayInfo();


    //Item 11: Handle assignment to self in operator=.
    Festival f(&c, &c1);
    Festival f1(f);
    Festival f2;
    f2 = f;
    f2.displayInfo();

    //Item 11: Handle assignment to self in operator=.
    //error if identity test doesn't exist
    f = f;
    f.displayInfo();


    //Item 12: Copy all parts of an object.
    Concert c3(c1);
    c3.displayInfo();

    return 0;
}
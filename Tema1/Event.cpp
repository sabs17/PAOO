#include "Event.h"
#include "Concert.h"
#include "Festival.h"
#include <memory>
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
    return *this;
}

//Item 13: Use objects to manage resources.
Event* createEvent(){
    return (new Event);
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
Concert::Concert (const Concert& c) : Event(c){
    cout<<"\nCopy constructor called from Concert class.\n";
    band = c.band;
}

//copy assignment operator
Concert Concert::operator = (Concert c){
    cout<<"\nCopy assignment operator called from Concert class.\n";
    Event::operator=(c);
    band = c.band;
    return *this;
}

//Festival

//default constructor
Festival::Festival() :
    firstConcert(NULL),
    secondConcert(NULL)
{}

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
    if(this->firstConcert != NULL) this->firstConcert->displayInfo();
    else cout<<"TBA\n";

    cout<<"\nSecond concert: ";
    if(this->secondConcert != NULL) this->secondConcert->displayInfo();
    else cout<<"TBA\n";
    cout<<"******\n";
}

//copy constructor
Festival::Festival(const Festival& f){
    cout<<"\nCopy constructor called from Festival class.\n";
    firstConcert = f.firstConcert;
    secondConcert = f.secondConcert;
    
}

//copy assignment operator
Festival& Festival::operator = (Festival& f){
    cout<<"\nCopy assignment operator called from Festival class.\n";

    //identity test
    if (this == &f){
        cout<<"Assignment to self\n";
         return *this;
    }
    delete firstConcert;
    delete secondConcert;
    firstConcert = new Concert(*f.firstConcert);
    secondConcert = new Concert(*f.secondConcert);
    
    return *this;
}

int demoNoRAII(){
    Event *ev = createEvent();
    ev->setDurationInHours(1);
    if(ev->getDurationInHours() == 1) return -1;
    cout<<"got to delete\n";
    delete ev;
    return 0;
}

int main(){ 

    Event e;
    Event e1("Acasa", "acu", 1, true);
    Concert c;
    Concert c1("tot acasa", "maine", 2, false, "some band");

    //Item 13: Use objects to manage resources.

    auto_ptr<Event> e2(createEvent());
    e2->setDurationInHours(5);
    auto_ptr<Event> e3(e2);
    //cout<<"\n"<<e2->getDurationInHours()<<"\n";       //SEGMENTATION FAULT -> e2 is now null
    cout<<"\n"<<e3->getDurationInHours()<<"\n"; 

    shared_ptr<Event> e4(createEvent());
    e4->setDurationInHours(7);
    shared_ptr<Event> e5;
    e5 = e4;
    cout<<"\n"<<e4->getDurationInHours()<<"\n";       //both e4 and e5 now point to the object
    cout<<"\n"<<e5->getDurationInHours()<<"\n"; 
    //shared_ptr and auto_ptr release resources in their destructors -> prevent resource leaks

    //demoNoRAII();
    //the delete statement isn't reached

    return 0;
}
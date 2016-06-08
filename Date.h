// Phung Tran
// 893977769
// Date.h

#ifndef Classes_Date_h
#define Classes_Date_h

// Definition of class Date in date.h

#include <iostream>
#include <string>

using namespace std;

class Date {
    friend ostream &operator<<( ostream &, const Date & ); // allows easy output to a ostream
    
public:
    Date( int m = 1, int d = 1, int y = 1900 ); // constructor, note the default values
    void setDate( int, int, int ); // set the date
    bool leapYear() const;    // is this a leap year?
    bool endOfMonth() const;   // is this end of month?
    int getMonth ( ) const { return month;}
    int getDay ( ) const {return day;}
    int getYear ( ) const {return year;}
    string getMonthString( ) const ; // You need to implement this
    void operator+=(int); // doesnt return anything
    Date& operator=(Date other);
private:
    int month;
    int day;
    int year;
    
    static const int days[];         // array of days per month
    static const string monthName[]; // array of month names
    void helpIncrement();            // utility function
};

#endif


// Phung Tran
// 893977769
//  Patient.h

#ifndef Classes_Patient_h
#define Classes_Patient_h
#include "Date.h"
#include <string>

struct procedure {
    Date dateOfProcedure;
    int procedureID;
    int procedureProviderID;
};

class Patient
{
    
private:
    int ID;
    char firstName[15];
    char lastName [15];
    Date  birthdate;
    int primaryDoctorID;  //Add
    procedure record[500];
    int currentCountOfProcedures;
public:
    
    Patient ( int, const char *, const char *, Date, int);
    Patient () : ID(0), firstName(" "), lastName(" "), birthdate(0,0,0), primaryDoctorID(0) {}
    void setID ( int);
    void setFirstName ( const char *);
    void setLastName ( const char *);
    void setBirthDate ( Date) ;
    void setPrimaryDoctorID (int ) ;
    
    int getID();
    const char * getFirstName();
    const char * getLastName() ;
    Date getBirthDate() ;
    int getPrimaryDoctorID() ;
    
    Patient& operator=(Patient other);
    
    bool enterProcedure(Date procedureDate, int procedureID,
                        int procedureProviderID);//tries to add a new entry to record array, returns 									 //true if added, false if cannot be added
    void printAllProcedures();
};
#endif

// Phung Tran
// 893977769
//  Patient.cpp


#include "Patient.h"

Patient::Patient ( int id, const char * first, const char *last , Date birth, int doctor) {
        setID(id);
        setFirstName(first);
        setLastName(last);
        setBirthDate(birth);
        setPrimaryDoctorID(doctor);
};

void Patient::setID ( int id )  {
    ID = id;
}

void Patient::setFirstName ( const char * first) {
        if (strlen(first) > 15)
            strncpy(firstName, first, 14);
        else
            strcpy(firstName, first);
}

void Patient::setLastName ( const char * last) {
        if (strlen(last) > 15)
            strncpy(lastName, last, 14);
        else
            strcpy(lastName, last);
    }
    
void Patient::setBirthDate ( Date birth) { birthdate = birth;}
void Patient::setPrimaryDoctorID (int doctor) {primaryDoctorID = doctor;}
    
int Patient::getID() {  return ID; }
const char * Patient::getFirstName() {return firstName; }
const char * Patient::getLastName() {return lastName;}
Date Patient::getBirthDate() {return birthdate; }
int Patient::getPrimaryDoctorID() { return primaryDoctorID; }

//tries to add a new entry to record array, returns
//true if added, false if cannot be added
bool Patient::enterProcedure(Date procedureDate, int procedureID, int procedureProviderID) {
    if (currentCountOfProcedures > 500) {
        cout << "Cannot add any more procedure" << endl;
        return false;
    }
    else {
        record[currentCountOfProcedures].dateOfProcedure = procedureDate;
        record[currentCountOfProcedures].procedureID = procedureID;
        record[currentCountOfProcedures].procedureProviderID = procedureProviderID;
        currentCountOfProcedures++;
        return true;
    }
}
void Patient::printAllProcedures() {
    cout << "Procedures of patient" << endl;
    for(int i = 0; i < currentCountOfProcedures; i++) {
        cout << "Date of Procedure: " << record[i].dateOfProcedure << endl;
        cout << "Procedure ID: " << record[i].procedureID << endl;
        cout << "Procedure Provider ID: " << record[i].procedureProviderID << endl;
    }
}

Patient& Patient::operator=(Patient other) {
    ID = other.ID;
    strcpy(firstName, other.firstName);
    strcpy(lastName, other.lastName);
    birthdate = other.birthdate;
    primaryDoctorID = other.primaryDoctorID;
    for(int i = 0; i < other.currentCountOfProcedures; i++) {
        record[i] = other.record[i];
    }
    currentCountOfProcedures = other.currentCountOfProcedures;
    return *this;
}

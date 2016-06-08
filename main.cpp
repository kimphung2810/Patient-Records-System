// Phung Tran
// Phung Tran
// 893977769
// Write and read to/from a binary file for patient records

#include <iostream>
#include <fstream>
#include "Patient.h"
#include "Date.h"

//read all patient[i]?

using namespace std;

void Menu();
void Remove(Patient checkIn[], int& count, int index);

int main(int argc, const char * argv[]) {
    Patient checkIn[10];
    Patient patient[20];
    char choice;
    int i = 0;
    int id = 0,
        doctor = 0,
        countAll = 0,
        count = 0;
    int day, month, year;
    char first[15], last[15];
    Date birthdate, current;
    bool found = false;
    
    ifstream inFile;
    inFile.open("CurrentPatients.txt", ios::in | ios::binary);
    if (inFile.is_open()) {
        inFile.read((char*)&countAll, sizeof(int));
        for (int i = 0; i < countAll; i++) {
            inFile.read((char*)&patient[i], sizeof(Patient));
        }
        inFile.close();
    }


    cout << "Enter current date" << endl;
    cout << "Day: ";
    cin >> day;
    cout<< "Month: ";
    cin >> month;
    cout << "Year: ";
    cin >> year;
    current.setDate(month, day, year);
     
    do {
        Menu();
        cin >> choice;
        switch (choice) {
                case 'N':   cout << "---------------------------" << endl;
                            cout << "Check in a new patient" << endl<< endl;
                            cout << "Patient ID: ";
                            cout << countAll+1 << endl;
                            checkIn[count].setID(countAll+1);
                            cout << "First name: ";
                            cin >> first;
                            checkIn[count].setFirstName(first);
                            cout << "Last name: ";
                            cin >> last;
                            checkIn[count].setLastName(last);
                            cout << "Doctor ID: ";
                            cin >> doctor;
                            checkIn[count].setPrimaryDoctorID(doctor);
                            cout << "Birthdate " << endl;
                            cout << "Day: ";
                            cin >> day;
                            cout << "Month: ";
                            cin >> month;
                            cout << "Year: ";
                            cin >> year;
                            birthdate.setDate(month, day, year);
                            checkIn[count].setBirthDate(birthdate);
                            patient[countAll] = checkIn[count];
                            count++;
                            countAll++;
                            break;
                    
               case 'R':    cout << "---------------------------" << endl;
                            cout << "Check in a returning patient" << endl << endl;
                            found = false;
                            i = 0;
                            do {
                                cout << "Enter patient's ID: ";
                                cin >> id;
                                do {
                                    if (patient[i].getID() == id) {
                                        checkIn[count] = patient[i];
                                        count++;
                                        found = true;
                                    }
                                    i++;
                                }while (!found && i < countAll);
                                if (!found) {
                                    cout << "Not found" << endl;
                                    cout << "Check in as a new patient? Y or N: ";
                                    cin >> choice;
                                }
                            }while (!found && choice == 'N');
    
                            break;
                
                case 'O':   found = false;
                            cout << "---------------------------" << endl;
                            cout << "Check out a patient" << endl;
                            i = 0;
                            do {
                                cout << "Enter checked out patient's ID: ";
                                cin >> id;
                                do {
                                    if (checkIn[i].getID() == id) {
                                        cout << "Provider ID: ";
                                        cin  >> doctor;
                                        cout << "Procedure ID: ";
                                        cin >> id;
                                        cout << checkIn[i].enterProcedure(current, id , doctor);
                                        for (int j= 0; j < countAll; j++)
                                            if(patient[j].getID() == checkIn[i].getID()) {
                                                patient[j].enterProcedure(current, id, doctor);
                                                cout << j;
                                                cout << "Patient ID: " << j+1 << " checked Out" << endl << endl;
                                            }
                                        Remove(checkIn, count, i);
                                        
                                        found = true;
                                    }
                                    i++;
                                } while (!found && i < count);
                                    if(!found) {
                                        cout << "Not found" << endl;
                                        cout << "Check in as a new patient or as a returning patient? Y or N: ";
                                        cin >> choice;
                                    }
                                    
                            }while (!found && choice == 'N');
                
                
                            break;
                
                case 'I':   found = false;
                            cout << "---------------------------" << endl;
                            cout << "Print all information of a patient" << endl<< endl;
                            cout << "Enter a patient's ID: ";
                            cin >> id;
                            i = 0;
                            do {
                                    if (patient[i].getID() == id) {
                                        cout << "Patient ID " << patient[i].getID() << endl;
                                        cout << "Name: " << patient[i].getFirstName() << " " << patient[i].getLastName() << endl;
                                        cout << "Birthdate: " << patient[i].getBirthDate() << endl;
                                        cout << "Doctor ID: " << patient[i].getPrimaryDoctorID() << endl;
                                        patient[i].printAllProcedures();
                                        found = true;
                                    }
                                i++;
                            } while (!found && i < countAll);
                            if(!found)
                                cout << "Not found" << endl;
                            break;
                
                case 'P':   cout << "---------------------------" << endl;
                            cout << "Patient checked in but not checked out yet" << endl<< endl;
                            if (count > 0) {
                                for (int i = 0; i < count; i++) {
                                cout << "Patient ID " << checkIn[i].getID() << endl;
                                cout << "Name: " << checkIn[i].getFirstName() << " " << checkIn[i].getLastName() << endl;
                                cout << "Birthdate: " << checkIn[i].getBirthDate() << endl;
                                cout << "Doctor ID: " << checkIn[i].getPrimaryDoctorID() << endl << endl;
                                }
                            }
                            
                            else
                                cout << "All patients checked out" << endl << endl;
                            break;
                
                case 'Q':    cout << "---------------------------" << endl;
                            if (count == 0) {
                                ofstream outFile;
                                outFile.open("CurrentPatients.txt", ios::out | ios::binary);
                                if(outFile.is_open()) {
                                    outFile.write((char*)&countAll, sizeof(int));
                                    for (int i = 0; i < countAll; i++)
                                        outFile.write((char*)&patient[i], sizeof(Patient));
                                    
                                    outFile.close();
                                    cout << "END" << endl;

                                }
                            }
                                
                            else {
                                for (int i = 0; i < count; i++) {
                                    cout << checkIn[i].getID() << endl;
                                    cout << checkIn[i].getFirstName() << " " << checkIn[i].getLastName() << endl;
                                    cout << checkIn[i].getBirthDate() << endl;
                                    cout << checkIn[i].getPrimaryDoctorID() << endl;
                                }

                                choice = 'A';
                            }
                            break;
                            
                            
        }
    }while (choice != 'Q' && choice != 'q');

    return 0;
}

void Menu() {
    cout << "-------------------------------" << endl;
    cout << "Menu" << endl;
    cout << "N : Check in new patient" << endl;
    cout << "R : Check in returning patient" << endl;
    cout << "O : Check out a patient" << endl;
    cout << "I : Print record of a patient" << endl;
    cout << "P : Print list of patients who checked in but not yet checked out" << endl;
    cout << "Q : Quit" << endl;
    cout << "Enter your choice (N, R, O, I, P, Q): ";
}

void Remove(Patient checkIn[], int& count, int index) {
    for (int i = index; i < count; i++)
        checkIn[i] = checkIn[i+1];
    count--;
}

#ifndef patients_h
#define patients_h
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
int const MAX_PATIENTS= 50; //Maximun number of patients that can be stored in the database

// Definining a patients structure which containts basic information of a patient
typedef struct {
  string name;
  string surname;
  string id;
  int age;
  string address;
  string email;
  string phone;
  bool with_arrangement = false;
  string idOfDoctorAsigned = "NULL";
} tPatient;

//Defining a atrcture with an array of patients using type tPatient, and its respective counter.
typedef struct {
tPatient patients[MAX_PATIENTS];
int patientCounter = 0;
} tPatientData;

extern tPatientData patientList;

//Loads the list of patients from the file "patients-data.txt". It stores the information into an array for the program to be used.
void load_patients(tPatientData &PatientData, bool &ok);
//It allows to add a new patient to the patient list already loaded into the program.
void register_patient(tPatientData &patientData, bool &ok);
//Shows every patient in the form of a list showing every field of information.
void show_all_patients(const tPatientData &patientData);
//Lets the user search for a patient by their ID. Returns true or false depending wheter the patient was founded.
void search_patient(const tPatientData &patientData, bool &ok, int &patientPosition, string IdForShearch);
//Shows the information of one especifict patient based on the position.
void show_found_patient(const tPatientData &patientData, int pos);
//This functions allows the user to edit very field of information of the patient.
int modify_menu();
//Allows the user to modify the fields of a patient. The user had to choose a field to edit with modify_menu.
void modify_patient(tPatientData &patientData, bool &ok, int &patientPosition , string idOfPatient);
//Once the user has made changes to the patients_list, this function saves the list into the "patiens_data.txt" file
void save_patients_list(const tPatientData &patientData);
//Call the other function so as to the code to work
void patient_interface(bool admin);
//Shows the menu of options to the admin for controlling patients
int admin_patients_menu();
//Delete one patient from the database is it does not have an arrangement
void delete_patient(tPatientData &patientData, int position, bool &ok);
//Orders the patients list in alphabetic order.
void order_patientlist(tPatientData &patientData);

#endif
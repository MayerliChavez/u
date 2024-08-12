#include <string>
using namespace std;
#ifndef doctors_h
#define doctors__h
const int MAX_DOCTORS = 50;

typedef struct{
    string name;
    string surname;
    string id;
    string email;
    string phone;
    char schedule;
    string speciality;
    bool available = true;
    string idOfPatientAsigned = "NULL";
}tDoctor;

typedef struct{
    tDoctor doctors[MAX_DOCTORS];
    int doctorsCounter = 0;
}tDoctorsList;


extern tDoctorsList doctorsList;

// Shows on screen all the information about a doctor
void show_all_doctors(const tDoctorsList &doctorList);
//Allows to modify the information of a doctor;
int modify_doctor_menu();
//Search a doctor based on the id number, recieves the list of the database of doctors, and modify a boolean verb if the doctor was founded or not. If the doctor was founded a variable is modified that tell the position of the doctor looked for.
void search_doctor(const tDoctorsList &doctorList, bool &ok , int &doctor_position, string idForSearch);
//Add a doctor to the database of the hospital, recieves the list of the database of doctors and the doctor to be added
void add_doctor(tDoctorsList &doctorlist, tDoctor doctor, bool &ok);
//Delete a doctor from the database , it recieves the doctor list and the position of the doctor that is going to be deleted.
void delete_doctor(tDoctorsList &doctorlist, int position , bool &ok);
//Recopilates data to construct a new doctor, that is going to be added to the database
tDoctor add_doctor_information();
//Modify the information of a doctor that is in the database. it recieves the list of doctors and the position of the doctors that will be modified
void modify_doctor_information(tDoctorsList &doctorList  , int doctor_position);
// main menu of the program for the doctors.
int doctors_main_menu();
//Call all the functions of the doctors menu.
void doctors_interface();
// Shows the information of an specifict doctor, recieves the data_base and the position of the doctor
void show_especific_doctor(const tDoctorsList &doctorList, int doctor_position);
//Saves all the information of the doctors in a txt file, recieves the list of all the doctors
void save_doctors_data(const tDoctorsList &doctorsList);
//Recover all the data of the doctor and save it in the array of doctors.
void load_doctors_data(tDoctorsList &doctorsList);
// Order the data by lastname
void order_doctors_list(tDoctorsList &doctorsList);
#endif
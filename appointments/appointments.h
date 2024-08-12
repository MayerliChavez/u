#ifndef appointments_h
#define appointments_h

#include <iostream>
#include <string>
#include "../doctors/doctors.h"
#include "../patients/patients.h"
using namespace std;

const int MAX_APPOINTMENTS = 100;

typedef struct {
    string id;
    string patientId;
    string medicId;
    string appointmentDate;
    string reason;
    bool valid_appointment = true;
} TAppointment;

typedef struct 
{
    TAppointment appointmentsList[MAX_APPOINTMENTS];
    int appointmentsCounter = 0;
} TAppointmentsList;

// extern TAppointmentsList appointments;

// Shows the menu of the options available for the appointments
int appointments_menu();
//Verifies if it does not exist an appoinment with  the same id.
void validate_appointment(TAppointmentsList &appointment_list, bool &ok , string appointment_id);
// Verifies if it exists a  patient to asing a doctor, modify a bool variable to verify this, and an integer variable that tell the position of the patient in the database
void validate_patient_existance(const tPatientData &patientsList , string patient_id , bool &ok , int &position);
//Verifies if it exists a doctor to be in charge of the appointment, modify a bool variable to verify this, and an integer variable that tell the position of the doctor in the database
void validate_doctor_existance(const tDoctorsList &doctorsList , string doctor_id, bool &ok , int &position);
// Search if an appointment exist in the database
void search_appointment(const TAppointmentsList &appointmentsList, bool &ok, int &appointmentPosition , string idForSearch);
// Shows all the valid appointments
void show_all_appointments(const TAppointmentsList &appointmentList);
//Show information of an specific appointment 
void show_especific_appointment(const TAppointmentsList &appointments, int pos);
//Calls all the functions so as to use the program
void appointment_interface();
//Save all the data in a txt file
void save_appoinments_data(const TAppointmentsList &appoinments);
//Load all the data from a txt file and save in in the array to use it troughout the programm.
void load_appoinments_data(TAppointmentsList &appoinments);
// Allows to change the date of an appointment
void modify_appointment_date(TAppointmentsList &appointments , string new_date , int position);
#endif
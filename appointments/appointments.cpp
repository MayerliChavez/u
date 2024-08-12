#include <iostream>
#include <string>
using namespace std;
#include <fstream>

#include "appointments.h"



int appointments_menu(){
     int option = -1;
      while ((option <= 0)|| (option > 6))
      {
          cout << "*** MENU DE GESTION DE CITAS MEDICAS ***" << endl;
          cout << "1. AGREGAR UNA NUEVA CITA" << endl;
          cout << "2. ELIMINAR UNA CITA EXISTENTE" << endl;
          cout << "3. VER TODAS LAS CITAS" << endl;
          cout << "4. BUSCAR UNA CITA" << endl;
          cout << "5. MODIFICAR LA FECHA DE UNA CITA" << endl;
          cout << "6. REGRESAR AL MENU PRINCIPAL " << endl;
          cout << "Ingrese el numero de opcion: ";
          cin >> option;
          if ((option <= 0)|| (option > 6)){
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Opcion no valida, ingrese una opcion valida." << endl;
          }     
      }
      return option;
}

void booking_and_appoinment(TAppointmentsList &appointment_list){
    string id;
    string patientId;
    string medicId;
    string appointmentDate;
    string reason;
    int positionOfObjectFound;
    int aux;
    bool ok = false;
   
    cin.clear();
    cin.ignore(256 , '\n');
    cout << "Ingresa la cedula del paciente al que se la va a asignar una cita: "; getline(cin, patientId);
    validate_patient_existance(patientList,patientId,ok,positionOfObjectFound);
    while(!ok){
        cout << "El paciente no existe en la base de datos, intente de nuevo: "; getline(cin, patientId);
        validate_patient_existance(patientList,patientId,ok,positionOfObjectFound);
    }
    appointment_list.appointmentsList[appointment_list.appointmentsCounter].patientId = patientId;
    patientList.patients[positionOfObjectFound].with_arrangement = true;
    aux = positionOfObjectFound;
    cout << "Ingrese el codigo para agendar la cita: " ; getline(cin , id);
    validate_appointment(appointment_list,ok,id);
    while(ok){
        cout << "Ya existe una cita con el codigo ingresado , intente de nuevo: "; getline(cin, id);
        validate_appointment(appointment_list,ok,id);
    }
    appointment_list.appointmentsList[appointment_list.appointmentsCounter].id = id;
    cout << "Ingrese la cedula del doctor que atendera al paciente: "; getline(cin , medicId);
    validate_doctor_existance(doctorsList ,medicId, ok , positionOfObjectFound);
    while(!ok){
        cout << "No existe un doctor con la cedula ingresada en la base de datos, intente de nuevo: " ; getline(cin , medicId);
        validate_doctor_existance(doctorsList ,medicId, ok , positionOfObjectFound);
    }
    appointment_list.appointmentsList[appointment_list.appointmentsCounter].medicId = medicId;
    doctorsList.doctors[positionOfObjectFound].available = false;
    doctorsList.doctors[positionOfObjectFound].idOfPatientAsigned = patientList.patients[aux].id;
    patientList.patients[aux].idOfDoctorAsigned =  doctorsList.doctors[positionOfObjectFound].id;
    cout << "Ingrese la fecha para atender al paciente: "; getline(cin ,appointmentDate);
    appointment_list.appointmentsList[appointment_list.appointmentsCounter].appointmentDate = appointmentDate;
    cout << "Ingrese una corta descripcion de la cita: "; getline(cin , reason);
    appointment_list.appointmentsList[appointment_list.appointmentsCounter].reason = reason;
    cout << "CITA AGENDADA EXITOSAMENTE" << endl ;
    appointment_list.appointmentsCounter++;
    
    
    
}

void validate_appointment(TAppointmentsList &appointment_list, bool &ok , string appointment_id){
    ok = false;
    for(int i = 0 ; i < appointment_list.appointmentsCounter ; i++){
        if(appointment_list.appointmentsList[i].id == appointment_id){
            ok = true;
        }
    }
}

void validate_patient_existance(const tPatientData &patientsList , string patient_id , bool &ok , int &position){
    ok = false;
    position = 0;
    for(int i = 0 ; i < patientsList.patientCounter ; i++){
        if(patientList.patients[i].id == patient_id){
            position = i;
            ok = true;
        }
    }
}

void validate_doctor_existance(const tDoctorsList &doctorsList , string doctor_id, bool &ok , int &position){
    ok = false;
    position = 0;
    for(int i = 0 ; i < doctorsList.doctorsCounter ; i++){
        if(doctorsList.doctors[i].id == doctor_id){
            ok = true;
            position = i;
        }
    }
}



void search_appointment(const TAppointmentsList &appointmentsList, bool &ok, int &appointmentPosition , string idForSearch)
{
  ok = false;
  
  for(appointmentPosition = 0; appointmentPosition < appointmentsList.appointmentsCounter; appointmentPosition++)
    {
      if(appointmentsList.appointmentsList[appointmentPosition].id == idForSearch)
      {
        ok = true;
        break;
      }
    }
 
}

void delete_appointment(TAppointmentsList &appointmentsList, int &appointmentPosition ,bool &ok ){
    appointmentsList.appointmentsList[appointmentPosition].valid_appointment = false;
}



void show_all_appointments(const TAppointmentsList &appointmentList){
    cout << "REGISTRO DE TODAS LAS CITAS" << endl;
    for(int i = 0 ; i < appointmentList.appointmentsCounter ; i++){
        if(appointmentList.appointmentsList[i].valid_appointment){
            cout << "CODIGO UNICO: " << appointmentList.appointmentsList[i].id << endl;
            cout << "CEDULA DEL PACIENTE: " << appointmentList.appointmentsList[i].patientId << endl;
            cout << "CEDULA DEL DOCTOR ASIGNADO: " << appointmentList.appointmentsList[i].medicId << endl;
            cout << "FECHA: " << appointmentList.appointmentsList[i].appointmentDate << endl;
            cout << "DESCRIPCION: " << appointmentList.appointmentsList[i].reason << endl;
            cout << "-----------------------------------------" << endl;
        }
       
    }
}

void show_especific_appointment(const TAppointmentsList &appointments, int pos){
     if(appointments.appointmentsList[pos].valid_appointment){
            cout << "CODIGO UNICO: " << appointments.appointmentsList[pos].id << endl;
            cout << "CEDULA DEL PACIENTE: " << appointments.appointmentsList[pos].patientId << endl;
            cout << "CEDULA DEL DOCTOR ASIGNADO: " << appointments.appointmentsList[pos].medicId << endl;
            cout << "FECHA: " << appointments.appointmentsList[pos].appointmentDate << endl;
            cout << "DESCRIPCION: " << appointments.appointmentsList[pos].reason << endl;
            cout << "-----------------------------------------" << endl;
        }else{
            cout << "NO SE ENCONTRO LA CITA O ESTA ES INVALIDA" <<endl; 
        }

}

void appointment_interface(){
    
    int option;
    string appointmentId;
    int positionOfAppoinmentFound;
    int positionOfObjectFound;
    string new_date;
    bool ok;
    TAppointmentsList appointments;
    load_appoinments_data(appointments);
    

    option = appointments_menu();
    while(option != 6){
        switch (option)
        {
        case 1:
            booking_and_appoinment(appointments);
            break;
        case 2:
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Ingrese el codigo unico de la cita que desea eliminar: " ; getline(cin , appointmentId);
            search_appointment(appointments,ok,positionOfAppoinmentFound,appointmentId);
            if(ok){
                delete_appointment(appointments,positionOfAppoinmentFound,ok);
                validate_patient_existance(patientList,appointments.appointmentsList[positionOfAppoinmentFound].patientId,ok,positionOfObjectFound);
                if(ok){
                    patientList.patients[positionOfObjectFound].with_arrangement = false;
                }
                validate_doctor_existance(doctorsList,appointments.appointmentsList[positionOfAppoinmentFound].medicId,ok,positionOfObjectFound);
                if(ok){
                    doctorsList.doctors[positionOfObjectFound].available = true;
                }
                cout << "CITA ELIMINADA EXITOSAMENTE " << endl; 
            }else{
                cout << "LA CITA NO EXISTE EN LA BASE DE DATOS " << endl;
            }
            break;
        case 3:
            show_all_appointments(appointments);
            break;
        case 4:
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Ingrese el codigo unico de la cita que desea buscar: " ; getline(cin , appointmentId);
            search_appointment(appointments,ok,positionOfAppoinmentFound,appointmentId);
            if(ok){
                show_especific_appointment(appointments,positionOfAppoinmentFound);
            }else{
                cout << "La cita no existe en el sistema " << endl;
            }
            break;
        case 5:
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Ingrese el codigo unico de la cita para modificar su fecha: "; getline(cin , appointmentId);
            search_appointment(appointments,ok,positionOfAppoinmentFound,appointmentId);
            if(ok){
                cout << "Ingrese la nueva fecha de la cita: " ; getline(cin, new_date);
                modify_appointment_date(appointments,new_date,positionOfAppoinmentFound);
                cout << "NUEVA FECHA ASIGNADA" << endl;
                show_especific_appointment(appointments,positionOfAppoinmentFound);
            }else{
                cout << "La cita no existe en el sistema " << endl;
            }
        }
        option = appointments_menu();
    }
    save_doctors_data(doctorsList);
    save_patients_list(patientList);
    save_appoinments_data(appointments);
   
}

void save_appoinments_data(const TAppointmentsList &appoinments){
    ofstream file;
    file.open("appoinments_data.txt");
    for(int i = 0 ; i < appoinments.appointmentsCounter ; i++){
        file << appoinments.appointmentsList[i].id <<endl;
        file << appoinments.appointmentsList[i].patientId <<endl;
        file << appoinments.appointmentsList[i].medicId <<endl;
        file << appoinments.appointmentsList[i].appointmentDate <<endl;
        file << appoinments.appointmentsList[i].reason <<endl;
        file << appoinments.appointmentsList[i].valid_appointment <<endl;
    }
    file << "XXX";
    file.close();
}

void load_appoinments_data(TAppointmentsList &appoinments){
    string id;
    string patientId;
    string medicId;
    string appointmentDate;
    string reason;
    bool valid_appointment = true;
    ifstream file;
    file.open("appoinments_data.txt");

    if(file.is_open()){
        getline(file, id);
        while(id != "XXX"){
            appoinments.appointmentsList[appoinments.appointmentsCounter].id = id;
            getline(file, patientId);
            appoinments.appointmentsList[appoinments.appointmentsCounter].patientId = patientId;
            getline(file, medicId);
            appoinments.appointmentsList[appoinments.appointmentsCounter].medicId = medicId;
            getline(file, appointmentDate);
            appoinments.appointmentsList[appoinments.appointmentsCounter].appointmentDate = appointmentDate;
            getline(file, reason);
            appoinments.appointmentsList[appoinments.appointmentsCounter].reason = reason;
            file >> valid_appointment;
            file.ignore();
            appoinments.appointmentsList[appoinments.appointmentsCounter].valid_appointment = valid_appointment;
            appoinments.appointmentsCounter++;
            getline(file,id);

        }
    }
    file.close();
}

void modify_appointment_date(TAppointmentsList &appointments , string new_date , int position){
    appointments.appointmentsList[position].appointmentDate = new_date;
}
#include <iostream>
#include <string>
using namespace std;
#include <cctype>
#include <fstream>

#include "doctors.h"
tDoctorsList doctorsList;
void add_doctor(tDoctorsList &doctorlist, tDoctor doctor, bool &ok){
    if(doctorlist.doctorsCounter < MAX_DOCTORS){
        doctorlist.doctors[doctorlist.doctorsCounter] = doctor;
        doctorlist.doctorsCounter++;
        ok = true;
    }else{
        ok = false;
    }
    order_doctors_list(doctorsList);
    
}

void delete_doctor(tDoctorsList &doctorlist, int position , bool &ok){
    if(doctorlist.doctors[position].available){
        for(int i = position ; i < doctorlist.doctorsCounter -1 ; i++){
        doctorlist.doctors[i] = doctorlist.doctors[i+1];
        ok = true;
    }
        doctorlist.doctorsCounter--;
    }else{
        ok = false;
    }
    
}

tDoctor add_doctor_information(){
    tDoctor doctor_to_add;
    char schedule;
    cin.clear();
    cin.ignore(256, '\n');
    cout<< "Ingrese el nombre del doctor: " ; getline(cin, doctor_to_add.name);
    cout<< "Ingrese el apellido del doctor: " ; getline(cin, doctor_to_add.surname);
    cout<< "Ingrese la cedula del doctor: " ; getline(cin, doctor_to_add.id);
    cout<< "Ingrese el email del doctor: " ; getline(cin, doctor_to_add.email);
    cout<< "Ingrese el telefono del doctor: " ; getline(cin, doctor_to_add.phone);
    cout<< "Ingrese la especialidad del doctor: " ; getline(cin, doctor_to_add.speciality);
    cout << "Ingrese el horario del doctor: (M/V/N) ";
    cin >> schedule;
    schedule = toupper(schedule);
    while(schedule != 'M'&& schedule != 'V' && schedule != 'N'){
        cout << "Solo se permiten los valores: " <<endl;
        cout << "M -----> HORARIO MATUTINO" <<endl;
        cout << "V -----> HORARIO VESPERTINO" <<endl;
        cout << "N -----> HORARIO NOCTURNO" <<endl;
        cin >> schedule;
        schedule = toupper(schedule);
    }
    doctor_to_add.schedule = schedule;
    return doctor_to_add;
}

void show_all_doctors(const tDoctorsList &doctorList){
    for(int i = 0; i< doctorList.doctorsCounter ; i++){
        cout << "Doctor " << i + 1 << ":" << endl;
        cout << "Apellido: " << doctorList.doctors[i].surname << endl;
        cout << "Nombre: " << doctorList.doctors[i].name << endl;
        cout << "Cedula: " << doctorList.doctors[i].id << endl;
        cout << "Email: " << doctorList.doctors[i].email << endl;
        cout << "Telefono: " << doctorList.doctors[i].phone << endl;
        cout << "Especialidad: " << doctorList.doctors[i].speciality << endl;
        cout << "Horario: " << doctorList.doctors[i].schedule << endl;
        if(doctorList.doctors[i].available){
            cout << "EL DOCTOR NO TIENE CITAS AGENDADAS EN ESTE MOMENTO" <<endl;
        }else{
            cout << "EL DOCTOR TIENE UNA CITA AGENDADA EN ESTE MOMENTO" <<endl;
        }
        cout << "----------------------------------------------" << endl;
    }
}

void show_especific_doctor(const tDoctorsList &doctorList, int doctor_position){
    cout << "Doctor " << doctor_position + 1 << ":" << endl;
    cout << "Apellido: " << doctorList.doctors[doctor_position].surname << endl;
    cout << "Nombre: " << doctorList.doctors[doctor_position].name << endl;
    cout << "Cedula: " << doctorList.doctors[doctor_position].id << endl;
    cout << "Email: " << doctorList.doctors[doctor_position].email << endl;
    cout << "Telefono: " << doctorList.doctors[doctor_position].phone << endl;
    cout << "Especialidad: " << doctorList.doctors[doctor_position].speciality << endl;
    cout << "Horario: " << doctorList.doctors[doctor_position].schedule << endl;
    if(doctorList.doctors[doctor_position].available){
            cout << "EL DOCTOR NO TIENE CITAS AGENDADAS EN ESTE MOMENTO" <<endl;
        }else{
            cout << "EL DOCTOR TIENE UNA CITA AGENDADA EN ESTE MOMENTO" <<endl;
        }
    cout << "----------------------------------------------" << endl;

}
void search_doctor(const tDoctorsList &doctorList, bool &ok , int &doctor_position, string idForSearch){
    ok = false;
    for(doctor_position = 0; doctor_position < doctorList.doctorsCounter; doctor_position++)
        {
        if(doctorList.doctors[doctor_position].id == idForSearch)
        {
            ok = true;
            break;
        }
        
    }
}

int modify_doctor_menu(){
    int option = -1;
      while ((option <= 0)|| (option > 7))
      {
          cout << "*** OPCIONES DE MODIFICACION ***" << endl;
          cout << "1. Modificar apellido." << endl;
          cout << "2. Modificar nombre." << endl;
          cout << "3. Modificar email." << endl;
          cout << "4. Modificar numero telefonico." << endl;
          cout << "5. Modificar horario" << endl;
          cout << "6. Modificar disponibilidad" << endl;
          cout << "7. Cancelar la accion." << endl;
          cout << "Ingrese el numero de opcion: ";
          cin >> option;
          if ((option <= 0)|| (option > 7)){
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Opcion no valida, ingrese una opcion valida." << endl;
          }     
      }
      return option;
}

void modify_doctor_information(tDoctorsList &doctorList , int doctor_position){
    int option_to_modify;
    char schedule;
    option_to_modify = modify_doctor_menu();
    while(option_to_modify != 7){
        switch (option_to_modify)
        {
        case 1:
            cout << "Ingrese el nuevo apellido del doctor: ";
            cin >> doctorList.doctors[doctor_position].surname;
            break;
        case 2:
            cout << "Ingrese el nuevo nombre del doctor: ";
            cin >> doctorList.doctors[doctor_position].name;
            break;
        case 3:
            cout << "Ingrese el nuevo email del doctor: ";
            cin >> doctorList.doctors[doctor_position].email;
            break;
        case 4:
            cout << "Ingrese el nuevo numero telefonico del doctor: ";
            cin >> doctorList.doctors[doctor_position].phone;
            break;
        case 5:
            cout << "Ingrese el nuevo horario del doctor: (M/V/N) ";
            cin >> schedule;
            schedule = toupper(schedule);
            while(schedule != 'M' && schedule != 'V' && schedule != 'N'){
                cout << "Solo se permiten los valores: " <<endl;
                cout << "M -----> HORARIO MATUTINO" <<endl;
                cout << "V -----> HORARIO VESPERTINO" <<endl;
                cout << "N -----> HORARIO NOCTURNO" <<endl;
                cin >> schedule;
                schedule = toupper(schedule);
            }
            doctorList.doctors[doctor_position].schedule == schedule;
            break;
        case 6:
            if(!(doctorList.doctors[doctor_position].available)){
                doctorList.doctors[doctor_position].available = true;
                cout << "El doctor ahora esta disponible: ";
            }else{
                cout << "El doctor no tiene citas asignadas en este momento";
            }
            
            break;
        }
        cout << "INFORMACION MODIFICADA CON EXITO: " << endl;
        show_especific_doctor(doctorList, doctor_position);
        option_to_modify = modify_doctor_menu();
    }
}

int doctors_main_menu(){
     int option = -1;
      while ((option <= 0)|| (option > 6))
      {
          cout << "*** MENU DE GESTION DE DOCTORES ***" << endl;
          cout << "1. MOSTRAR LA LISTA DE DOCTORES" << endl;
          cout << "2. AGREGAR UN DOCTOR" << endl;
          cout << "3. ELIMINAR UN DOCTOR" << endl;
          cout << "4. MODIFICAR LA INFORMACION DE UN DOCTOR" << endl;
          cout << "5. BUSCAR UN DOCTOR " << endl;
          cout << "6. REGRESAR AL MENU DE ADMINISTRADOR " << endl;
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

void doctors_interface(){
    tDoctor doctor;
    int option;
    int position;
    bool ok = true;
    int positionOfDoctorFounded;
    string idOfDoctor;
    char confirmDeleteOperation = 'Y';
    option = doctors_main_menu();
    while (option!=6)
    {
        switch (option)
        {
        case 1:
            show_all_doctors(doctorsList);
            break;
        case 2:
            doctor = add_doctor_information();
            add_doctor(doctorsList,doctor,ok);
            break;
        case 3:
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Ingrese la cedula del doctor que desea eliminar: " ; getline(cin , idOfDoctor);
            search_doctor(doctorsList,ok,positionOfDoctorFounded,idOfDoctor);
            if(ok){
                cout << "Se borrara el registro del siguiente doctor: " << endl;
                show_especific_doctor(doctorsList , positionOfDoctorFounded);
                cout << "Desea continuar? (Y/n): "; cin >> confirmDeleteOperation;
                confirmDeleteOperation = toupper(confirmDeleteOperation);
                if(confirmDeleteOperation =='N'){
                    cout << "Operacion cancelada" << endl;

                }else{
                    delete_doctor(doctorsList,positionOfDoctorFounded,ok);
                    if(ok){
                        cout << "Se ha eliminado al doctor de la base de datos" <<endl;
                    }else{
                        cout << "El doctor no se puede eliminar porque tiene una cita agendada" <<endl;
                    }
                    
                }
            }else{
                cout << "El doctor con la cedula ingresada no existe en la base de datos" << endl;
            }
            
            break;
        case 4:
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Ingrese la cedula del doctor que desea modificar: " ;  getline(cin , idOfDoctor);
            search_doctor(doctorsList,ok,positionOfDoctorFounded,idOfDoctor);
            if(ok){
                modify_doctor_information(doctorsList,positionOfDoctorFounded);

            }else{
                cout << "El doctor con la cedula ingresada no existe en la base de datos" << endl;
            }
            break;
        case 5:
            cin.clear();
            cin.ignore(255, '\n');
            cout << "Ingrese la cedula del doctor que desea buscar: " ; getline(cin , idOfDoctor);
            search_doctor(doctorsList,ok,positionOfDoctorFounded,idOfDoctor);
            if(ok){
                cout << "El doctor trabaja en el hospital" << endl;
                show_especific_doctor(doctorsList,positionOfDoctorFounded);
            }else{
                cout << "No se pudo encontrar al doctor especificado" << endl;
            }
            break;
        }
        
        option = doctors_main_menu();

    }
    save_doctors_data(doctorsList);

    
}

void save_doctors_data(const tDoctorsList &doctorsList){
    ofstream file;
    file.open("doctorsData.txt");
    for(int i = 0 ; i < doctorsList.doctorsCounter ; i++){
        file << doctorsList.doctors[i].name << endl;
        file << doctorsList.doctors[i].surname << endl;
        file << doctorsList.doctors[i].id << endl;
        file << doctorsList.doctors[i].email << endl;
        file << doctorsList.doctors[i].phone << endl;
        file << doctorsList.doctors[i].schedule << endl;
        file << doctorsList.doctors[i].speciality << endl;
        file << doctorsList.doctors[i].available << endl;
        file << doctorsList.doctors[i].idOfPatientAsigned << endl;
    }
    file << "XXX";
    file.close();
}

void load_doctors_data(tDoctorsList &doctorsList){
    string name;
    string surname;
    string id;
    string email;
    string phone;
    char schedule;
    string speciality;
    bool available;
    string idOfPatientAsigned;
    ifstream file;
    
    file.open("doctorsData.txt");
    if(file.is_open()){
        getline(file, name);
        while(name != "XXX"){
            doctorsList.doctors[doctorsList.doctorsCounter].name = name;
            getline(file, surname);
            doctorsList.doctors[doctorsList.doctorsCounter].surname = surname;
            getline(file, id);
            doctorsList.doctors[doctorsList.doctorsCounter].id = id;
            getline(file, email);
            doctorsList.doctors[doctorsList.doctorsCounter].email = email;
            getline(file, phone);
            doctorsList.doctors[doctorsList.doctorsCounter].phone = phone;
            file >> schedule;
            file.ignore();
            doctorsList.doctors[doctorsList.doctorsCounter].schedule = schedule;
            getline(file, speciality);
            doctorsList.doctors[doctorsList.doctorsCounter].speciality = speciality;
            file >> available;
            file.ignore();
            doctorsList.doctors[doctorsList.doctorsCounter].available = available;
            getline(file, idOfPatientAsigned);
            doctorsList.doctors[doctorsList.doctorsCounter].idOfPatientAsigned = idOfPatientAsigned;
            doctorsList.doctorsCounter++;
            getline(file, name);
        }
    }
    
    file.close();

    order_doctors_list(doctorsList);

}

void order_doctors_list(tDoctorsList &doctorsList){
    tDoctor aux_doctor;
    int pos;

    for(int i = 1 ; i < doctorsList.doctorsCounter ; i++){
        pos = i;
        while ((pos > 0) && (doctorsList.doctors[pos - 1].surname > doctorsList.doctors[pos].surname))
        {
            aux_doctor = doctorsList.doctors[pos];
            doctorsList.doctors[pos] = doctorsList.doctors[pos - 1];
            doctorsList.doctors[pos - 1] = aux_doctor;
            pos--;
        }
        
    }
}
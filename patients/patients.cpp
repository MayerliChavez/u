#include <iostream>
#include <string>
using namespace std;
#include <fstream>

#include "patients.h" // Include the patients.h header file

tPatientData patientList;
//Defining functions

void load_patients(tPatientData &patientData, bool &ok)
{
  tPatient patient;
  // patientData.patientCounter = 0;
  ifstream file;
  file.open("patients_data.txt");
  if (!file.is_open())
  {
    ok = false;
  }
  else
  {
    ok = true;
    getline(file, patient.name);
    while ((patientData.patientCounter < MAX_PATIENTS) && (patient.name != "XXX"))
      {
        getline(file, patient.surname);
        getline(file, patient.id);
        file >> patient.age;
        file.ignore();
        getline(file, patient.address);
        getline(file, patient.email);
        getline(file, patient.phone);
        file >> patient.with_arrangement;
        file.ignore();
        getline(file, patient.idOfDoctorAsigned);
        //Obtaining info related to their appointment
        //Loading the information in an array
        patientData.patients[patientData.patientCounter] = patient;
        patientData.patientCounter++;
        getline(file, patient.name);
      }
    file.close();
  }
  
  order_patientlist(patientData);
}

void register_patient(tPatientData &patientData, bool &ok)
{
  ok = true;
  //char aux;
  if (patientData.patientCounter == MAX_PATIENTS)
  {
    ok = false;
  }
  else
  {
    tPatient patient;
    cout << "Ingrese el apellido del paciente: ";
    getline(cin, patient.surname);
    cout << "Ingrese el nombre del paciente: ";
    getline(cin, patient.name);
    cout << "Ingrese la cedula del paciente: ";
    cin >> patient.id;
    cout << "Ingrese la edad del paciente: ";
    cin >> patient.age;
    getchar();
    cout << "Ingrese la direccion del paciente: ";
    getline(cin, patient.address);
    cout << "Ingrese el email del paciente: ";
    getline(cin, patient.email);
    cout << "Ingrese el telefono del paciente: ";
    getline(cin, patient.phone);

    //cout << "Ingrese la fecha de la cita: ";
    //Adding the patient to the array
    patientData.patients[patientData.patientCounter] = patient;
    patientData.patientCounter++;
  }
  order_patientlist(patientData);
}

void show_all_patients(const tPatientData &patientData)
{
  cout << "***Listado de pacientes***" << endl << endl;
  for(int i = 0; i < patientData.patientCounter; i++)
    {
      cout << "Paciente " << i + 1 << ":" << endl;
      cout << "Apellido: " << patientData.patients[i].surname << endl;
      cout << "Nombre: " << patientData.patients[i].name << endl;
      cout << "Cedula: " << patientData.patients[i].id << endl;
      cout << "Edad: " << patientData.patients[i].age << endl;
      cout << "Direccion: " << patientData.patients[i].address << endl;
      cout << "Email: " << patientData.patients[i].email << endl;
      cout << "Telefono: " << patientData.patients[i].phone << endl;
      if(patientData.patients[i].with_arrangement){
        cout << "El paciente tiene una cita agendada" << endl;
      }else{
        cout << "El paciente no tiene citas agendadas" << endl;
      }
      cout << "------------------------------------------------";
      cout << endl;
    }
}

void save_patients_list(const tPatientData &patientData)
{
  ofstream file;
  file.open("patients_data.txt");
  for(int patientpos = 0; patientpos < patientData.patientCounter; patientpos++)
  {
    file << patientData.patients[patientpos].name << endl;
    file << patientData.patients[patientpos].surname << endl;
    file << patientData.patients[patientpos].id << endl;  
    file << patientData.patients[patientpos].age << endl;
    file << patientData.patients[patientpos].address << endl;
    file << patientData.patients[patientpos].email << endl;
    file << patientData.patients[patientpos].phone << endl;
    file << patientData.patients[patientpos].with_arrangement << endl;
    file << patientData.patients[patientpos].idOfDoctorAsigned << endl;
  }
  file << "XXX";
  file.close();
}

void search_patient(const tPatientData &patientData, bool &ok, int &patientPosition , string idForSearch)
{
  ok = false;
  
  for(patientPosition = 0; patientPosition < patientData.patientCounter; patientPosition++)
    {
      if(patientData.patients[patientPosition].id == idForSearch)
      {
        ok = true;
        break;
      }
    }
 
}


void delete_patient(tPatientData &patientData, int position, bool &ok)
{
  if (position <= patientData.patientCounter && patientData.patients[position].with_arrangement == false){
        for(int i = position ; i < patientData.patientCounter - 1 ;i++){
            patientData.patients[i] = patientData.patients[i+1];
            ok = true;
        }
        patientData.patientCounter--;

  }else{ 
    ok = false;
  }
  
   
}


void show_found_patient(const tPatientData &patientData, int pos)
{
  cout << endl << endl;
  cout << "Paciente " << pos + 1 << ":" << endl;
  cout << "Apellido: " << patientData.patients[pos].surname << endl;
  cout << "Nombre: " << patientData.patients[pos].name << endl;
  cout << "Cedula: " << patientData.patients[pos].id << endl;
  cout << "Edad: " << patientData.patients[pos].age << endl;
  cout << "Direccion: " << patientData.patients[pos].address << endl;
  cout << "Email: " << patientData.patients[pos].email << endl;
  cout << "Telefono: " << patientData.patients[pos].phone << endl;
  if(patientData.patients[pos].with_arrangement){
        cout << "El paciente tiene una cita agendada" << endl;
      }else{
        cout << "El paciente no tiene citas agendadas" << endl;
      }
      cout << "------------------------------------------------";
  cout << endl;
}

int modify_menu()
{
  int option = -1;
      while ((option <= 0)|| (option > 9))
      {
          cout << "*** Que desea modificar del paciente ***" << endl;
          cout << "1. Modificar apellido." << endl;
          cout << "2. Modificar nombre." << endl;
          cout << "3. Modificar cedula." << endl;
          cout << "4. Modificar edad." << endl;
          cout << "5. Modificar direccion." << endl;
          cout << "6. Modificar email." << endl;
          cout << "7. Modificar numero telefonico." << endl;
          cout << "8. Cambiar estado de cita." << endl;
          cout << "9. Cancelar la accion." << endl;
          cout << "Ingrese el numero de opcion: ";
          cin >> option;
          if ((option <=0) || (option > 9)){
              cout << "Opcion no valida, ingrese una opcion valida." << endl;
          }     
      }
      return option;
}

void modify_patient(tPatientData &patientData, bool &ok, int &patientPosition , string idOfPatient)
{
  search_patient(patientData, ok, patientPosition , idOfPatient);
  if(ok == true)
  {
    show_found_patient(patientData, patientPosition);
    int valueToModify = modify_menu();
    while (valueToModify !=9)
    {
    cin.ignore();
    switch(valueToModify)
      {
    
      case 1:
      {
        cout << "Ingrese el nuevo apellido: ";
        getline(cin, patientData.patients[patientPosition].surname);
        order_patientlist(patientData);
        break;
      }
      case 2:
      {
        cout << "Ingrese el nuevo nombre: ";
        getline(cin, patientData.patients[patientPosition].name);
        break;
      }
      case 3:
      {
        cout << "Ingrese la nueva cedula: ";
        cin >> patientData.patients[patientPosition].id;
        break;
      }
      case 4:
      {
        cout << "Ingrese la nueva edad: ";
        cin >> patientData.patients[patientPosition].age;
      break;
      }
      case 5:
      {
        cout << "Ingrese la nueva direccion: ";
        getline(cin, patientData.patients[patientPosition].address);
        break;
      }
      case 6:
      {
        cout << "Ingrese el nuevo email: ";
        getline(cin, patientData.patients[patientPosition].email);
        break;
      }
      case 7:
      {
        cout << "Ingrese el nuevo numero telefonico: ";
        getline(cin, patientData.patients[patientPosition].phone);
        break;
      }
      case 8:
      {
        char atendido;
        cout << "El paciente ya ha sido atendido? (s/n): ";
        cin >> atendido;
        atendido = toupper(atendido);
    
        if (atendido == 'S')
        {
         patientData.patients[patientPosition].with_arrangement = false; 
        }

        break;
      }
      }
      cout << "Se ha modificado con exito: " << endl;
      show_found_patient(patientData, patientPosition);
      cout << endl;
      valueToModify = modify_menu();
    }
  }
  else
  {
    cout << "Nos es posible modificar al paciente, pues no se encuentra en la base de datos." << endl;
  }
}

int admin_patients_menu(){
     int option = -1;
      while ((option <= 0)|| (option > 5))
      {
          cout << "*** MENU DE GESTION DE PACIENTES ***" << endl;
          cout << "1. MOSTRAR LA LISTA DE PACIENTES" << endl;
          cout << "2. ELIMINAR UN PACIENTE" << endl;
          cout << "3. MODIFICAR LA INFORMACION DE UN PACIENTE" << endl;
          cout << "4. BUSCAR UN PACIENTE " << endl;
          cout << "5. REGRESAR AL MENU DE ADMINISTRADOR " << endl;
          cout << "Ingrese el numero de opcion: ";
          cin >> option;
          if ((option <= 0)|| (option > 5)){
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Opcion no valida, ingrese una opcion valida." << endl;
          }     
      }
      return option;
}

void patient_interface(bool admin){
    
    tPatient patient;
    int option;
    int positionOfPatientFounded;
    string idOfPatient;
    char confirmDeleteOperation = 'Y';
    bool ok = true;
    
    if(admin){
        option = admin_patients_menu();
        while(option!=5){
        switch (option){
            case 1:
                show_all_patients(patientList);
                break;
            case 2:
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Ingrese la cedula del paciente que desea eliminar: " ; getline(cin , idOfPatient);
                search_patient(patientList, ok ,positionOfPatientFounded,idOfPatient);
                if(ok){
                    cout << "Se borrara el registro del siguiente paciente: " << endl;
                    show_found_patient(patientList,positionOfPatientFounded);
                    cout << "Desea continuar? (Y/n): " ; cin >> confirmDeleteOperation;
                    confirmDeleteOperation = toupper(confirmDeleteOperation);
                    if(confirmDeleteOperation == 'N'){
                        cout << "Operacion cancelada" << endl;
                    }else{
                        delete_patient(patientList,positionOfPatientFounded,ok);
                        if(ok){
                            cout << "Se ha eliminado al paciente de la base de datos" << endl;
                        }else{
                            cout << "El paciente no se puede eliminar porque tiene una cita agendada" << endl;
                        }
                    }
                }else{
                cout << "El paciente con la cedula ingresada no existe en la base de datos" << endl;
                }   
                break;
            case 3:
                cin.clear();
                cin.ignore(256 , '\n');
                cout << "Ingrese la cedula del paciente que desea modificar: " ; getline(cin , idOfPatient);
                modify_patient(patientList,ok,positionOfPatientFounded,idOfPatient);
                break;
            case 4:
                cin.clear();
                cin.ignore(256 , '\n');
                cout << "Ingrese la cedula del paciente que desea buscar: " ; getline(cin , idOfPatient);
                search_patient(patientList,ok,positionOfPatientFounded,idOfPatient);
                if(ok){
                    cout << "INFORMACION DEL PACIENTE: " <<endl;
                    show_found_patient(patientList,positionOfPatientFounded);
                }else{
                    cout << "No se pudo encontrar al paciente especificado"<< endl;
                }
                break;
        }
    option = admin_patients_menu();
    }
    }else{
        cout << "*****REGISTRO DE INFORMACION DE PACIENTE NUEVO *******" << endl ;
        cin.clear();
        cin.ignore(256 , '\n');
        register_patient(patientList, ok);
    }
    save_patients_list(patientList);

    

}

void order_patientlist(tPatientData &patientData)
{
  tPatient patient_aux;
  int pos;

  for(int i = 1; i < patientData.patientCounter; i++)
  {
    pos = i;
    while((pos > 0) && (patientData.patients[pos - 1].surname > patientData.patients[pos].surname))
    {
        patient_aux = patientData.patients[pos];
        patientData.patients[pos] = patientData.patients[pos - 1];
        patientData.patients[pos - 1] = patient_aux;
        pos--;
    }
  }
}

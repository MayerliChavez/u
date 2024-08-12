#include <iostream>
#include <string>
using namespace std;
#include "admin_mode.h"
#include "../doctors/doctors.h"
#include "../patients/patients.h"
using namespace std;


void admin_menu(){

    string username;
    string password;
    int option;
    if(validate_admin_permissions()){
        cout << "BIENVENIDO AL SISTEMA USUARIO ADMINISTRADOR" <<endl;
        option = admins_menu_option();
        while(option != 3){
            switch (option)
            {
            case 1:
                doctors_interface();
                break;
            case 2:
                patient_interface(true);
                break;
            default:
                break;
            }
            option = admins_menu_option();
        }
    }else{
        cout << "NO TIENE PERMISOS DE ADMINISTRADOR - ACCESO DENEGADO" <<endl;
    }

}


bool validate_admin_permissions(){
    string username;
    string password;
    bool isadmin;
    cin.clear();
    cin.ignore(256, '\n');
    cout << "PARA INGRESAR AL MODO ADMINISTRADOR DEBE IDENTIFICARSE EN EL SISTEMA" << endl;
    cout << "Ingrese el nombre de usuario: "; getline(cin , username);
    cout << "Ingrese la contrasenia de usuario: "; getline(cin , password);
    if(username == USER_NAME && password == PASSWORD){
        isadmin = true;
    }else{
        isadmin = false;
    }
    return isadmin;
}

int admins_menu_option(){
     int option = -1;
     
      while ((option <= 0)|| (option > 3))
      {
          cout << "*** OPCIONES DISPONIBLES DE ADMINISTRADOR ***" << endl;
          cout << "1. GESTIONAR DOCTORES" << endl;
          cout << "2. GESTIONAR PACIENTES" << endl;
          cout << "3. SALIR DEL MODO DE ADMINISTRADOR" << endl;
          cout << "Ingrese el numero de opcion: ";
          cin >> option;
          if ((option <= 0)|| (option > 3)){
            cin.clear();
            cin.ignore(256 , '\n');
            cout << "Opcion no valida, ingrese una opcion valida." << endl;
          }     
      }
      return option;
}


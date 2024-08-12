#include <iostream>
#include <string>
#include "admin/admin_mode.h"
#include "appointments/appointments.h"
using namespace std;


// Shows the main menu of the program
int main_menu();
int main(){
    bool ok;
    
    load_doctors_data(doctorsList);
    load_patients(patientList,ok);
    int op;
    cout << "**** HOSPITAL CARLOS ANDRADE MARIN ****" << endl;
    op = main_menu();
    while(op != 4){
        switch (op)
        {
        case 1:
            patient_interface(false);
            break;
        case 2:
            appointment_interface();
            break;
        case 3:
            admin_menu();

            break;
        }
     op = main_menu();   
    }

}


int main_menu()
{
    int op = -1;
    while ((op <0) || ( op > 4))
    {

        cout << "1. REGISTRAR LA INFORMACION DE UN PACIENTE NUEVO " << endl;
        cout << "2. GESTIONAR CITAS " << endl;
        cout << "3. MODO ADMINISTRATIVO (GESTIONAR PACIENTES Y DOCTORES)" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione la opcion a realizar: ";
        cin >> op;
        if ((op <0)|| (op > 4)){
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Opcion no valida, ingrese una opcion valida." << endl;
        }     
    }
    return op;
}
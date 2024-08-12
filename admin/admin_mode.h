#include <string>
using namespace std;
#ifndef admin_mode_h
#define admin_mode_h

//Credential for accesing to admin mode
const string USER_NAME = "admin";
const string PASSWORD = "12345";
// Menu that shows the information for the admin operations.
void admin_menu();
//Validates if an user is able to modify the database of the hospital
bool validate_admin_permissions();
// Menu of the options available for the admin user
int admins_menu_option();

#endif
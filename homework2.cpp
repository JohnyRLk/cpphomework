#include <iostream>
#include<string>
using namespace std;
bool checkpass(const char* pass) { 
    int length = 0;
    bool digit = false; 
    bool lowercase = false;
    bool uppercase = false;
    bool alphanumeric = false;
    bool lengthBool = false;
    while (pass[length] != '\0') {
        length++;
    }
    if (length >= 8) {
        lengthBool = true;
    }
    for ( int  i = 0; i < length; ++i) {
            if (int(pass[i]) >= 48 && int(pass[i]) < 58) {
                digit = true;

            }
            if (int(pass[i]) >= 65 && int(pass[i]) < 91) {
                uppercase = true;
              
                
            }
           
            if (int(pass[i]) >= 97 && int(pass[i]) < 123) {
          
                lowercase = true;
              
            }
            
            if (int(pass[i]) == 46 || int(pass[i]) == 34 || int(pass[i]) == 44 ||
                int(pass[i]) == 58 || int(pass[i]) == 59 || int(pass[i]) == 63 ||
                int(pass[i]) == 96 || int(pass[i]) == 45 || int(pass[i]) == 33 ||
                int(pass[i]) == 41 || int(pass[i]) == 40 || int(pass[i]) == 60 ||
                int(pass[i]) == 62 || int(pass[i]) == 64){
                alphanumeric = true;
               
            }
            

    }  
    if (lengthBool == false) {
        cout << "Too short" << endl;
    }
    if (digit == false) {
        cout << "No digit" << endl;

    }
    if (uppercase == false) {
        cout << "No uppercase letter" << endl;

    }
    if (lowercase == false) {
        cout << "No lowercase letter" << endl;

    }
    if (alphanumeric == false) {
        cout << "No non-alphanumeric character" << endl;

    }
    if (digit && uppercase && lowercase && alphanumeric && lengthBool) {
        return true;
    }
    
     
}
int main() {
    const char* passes[] = { "AbcDe93",  "A1b:A1b>",  "Ab:Acb<","abc123><", "Zorro@123", nullptr };
    for (int i = 0; passes[i] != nullptr; ++i) {
        cout << "checking " << passes[i] << endl;
        if (checkpass(passes[i]))cout << "OK" << endl;
        cout << endl;
    }
    return 0;
}
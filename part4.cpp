#include <iostream>
using namespace std;

static int xdi = 0;  

void xd() {
    xdi++; 

    cout << "Numero " << xdi << " de veces usada" << endl;
}

int repeticiones() {
    return xdi;  
}

int main() {
    xd(); 
    xd();
    xd();
    xd();
    cout << "La funcion xd fue llamada " << repeticiones() << " veces." << endl;

    return 0;
}

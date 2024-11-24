/*1. Realizar un funcion que dados 2 pares de coordenadas, correspondientes al inicio y fin de dos lineas.
Devuelva 1 si las lineas se cruzan, 0 si son paralelas y -1 si no se cruzan ni son paralelas.
*/
#include <iostream>
using namespace std;

int orientacion(int px, int py, int qx, int qy, int rx, int ry) {
    int val = (qy - py) * (rx - qx) - (qx - px) * (ry - qy);

    if (val == 0) return 0; 
    return (val > 0) ? 1 : 2; 
}


bool estaEnSegmento(int px, int py, int qx, int qy, int rx, int ry) {
    return (qx <= max(px, rx) && qx >= min(px, rx) &&
            qy <= max(py, ry) && qy >= min(py, ry));
}


int interseccionDeLineas(int p1x, int p1y, int p2x, int p2y,
                         int p3x, int p3y, int p4x, int p4y) {
  
    int o1 = orientacion(p1x, p1y, p2x, p2y, p3x, p3y);
    int o2 = orientacion(p1x, p1y, p2x, p2y, p4x, p4y);
    int o3 = orientacion(p3x, p3y, p4x, p4y, p1x, p1y);
    int o4 = orientacion(p3x, p3y, p4x, p4y, p2x, p2y);

    if (o1 != o2 && o3 != o4) return 1;

    if (o1 == 0 && estaEnSegmento(p1x, p1y, p3x, p3y, p2x, p2y)) return 1;

    if (o2 == 0 && estaEnSegmento(p1x, p1y, p4x, p4y, p2x, p2y)) return 1;

    if (o3 == 0 && estaEnSegmento(p3x, p3y, p1x, p1y, p4x, p4y)) return 1;

    if (o4 == 0 && estaEnSegmento(p3x, p3y, p2x, p2y, p4x, p4y)) return 1;

    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) return 0;

    
    return -1;
}

int main() {
    int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
    cout << "Ingrese las coordenadas del primer segmento (inicio x1, y1 y fin x2, y2): ";
    cin >> p1x >> p1y >> p2x >> p2y;
    
    cout << "Ingrese las coordenadas del segundo segmento (inicio x3, y3 y fin x4, y4): ";
    cin >> p3x >> p3y >> p4x >> p4y;
    
    int resultado = interseccionDeLineas(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y);

    if (resultado == 1) {
        cout << "Las lineas se cruzan." << endl;
    } else if (resultado == 0) {
        cout << "Las lineas son paralelas." << endl;
    } else {
        cout << "Las lineas no se cruzan ni son paralelas." << endl;
    }

    return 0;
}
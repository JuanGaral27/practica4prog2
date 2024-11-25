#include <iostream>
#include <cmath> 

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

int interseccionDeLineas(int p1x, int p1y, int p2x, int p2y,
                         int p3x, int p3y, int p4x, int p4y, bool chequeoPendientes) {
    
    double pendiente1, pendiente2;

    if (p2x != p1x) {
        pendiente1 = static_cast<double>(p2y - p1y) / (p2x - p1x);
    } else {
        pendiente1 = 0; 
    }

    if (p4x != p3x) {
        pendiente2 = static_cast<double>(p4y - p3y) / (p4x - p3x);
    } else {
        pendiente2 = 0; 
    }

    
    if (pendiente1 == pendiente2) {
        return 0; 
    }

    
    if (pendiente1 * pendiente2 == -1) {
        return 1; 
    }


    int cruzan = interseccionDeLineas(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y);
    return (cruzan == 1) ? -1 : cruzan; 
}

int main() {
    int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;

    
    cout << "Ingrese las coordenadas del primer segmento (inicio x1, y1 y fin x2, y2): ";
    cin >> p1x >> p1y >> p2x >> p2y;

    cout << "Ingrese las coordenadas del segundo segmento (inicio x3, y3 y fin x4, y4): ";
    cin >> p3x >> p3y >> p4x >> p4y;

    
    int resultado = interseccionDeLineas(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, true);

    if (resultado == 1) {
        cout << "Las lineas son perpendiculares." << endl;
    } else if (resultado == 0) {
        cout << "Las lineas son paralelas." << endl;
    } else if (resultado == -1) {
        cout << "Las lineas se cruzan." << endl;
    } else {
        cout << "No se cruzan ni son paralelas." << endl;
    }

    return 0;
}

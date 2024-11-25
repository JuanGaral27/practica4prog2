#include <iostream>
#include <cmath> // Para atan, tan y operaciones matemáticas

using namespace std;

// Función para calcular la pendiente de una línea dada por dos puntos
double calcularPendiente(int x1, int y1, int x2, int y2) {
    if (x2 != x1) {
        return static_cast<double>(y2 - y1) / (x2 - x1);
    } else {
        return 0; // Asumimos pendiente cero para evitar infinito en líneas verticales
    }
}

// Función para convertir radianes a grados
double radianesAGrados(double radianes) {
    return radianes * (180.0 / M_PI);
}

// Función para calcular el ángulo entre dos líneas, por defecto en radianes
double calcularAngulo(int p1x, int p1y, int p2x, int p2y,
                      int p3x, int p3y, int p4x, int p4y,
                      bool enGrados = false) {
    // Calcular las pendientes de las dos líneas
    double pendiente1 = calcularPendiente(p1x, p1y, p2x, p2y);
    double pendiente2 = calcularPendiente(p3x, p3y, p4x, p4y);

    // Calcular el ángulo usando la fórmula del ángulo entre dos líneas
    double tanTheta = fabs((pendiente2 - pendiente1) / (1 + pendiente1 * pendiente2));
    double angulo = atan(tanTheta); // Ángulo en radianes

    // Si se requiere en grados, convertir
    if (enGrados) {
        angulo = radianesAGrados(angulo);
    }

    return angulo;
}

int main() {
    int p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y;
    bool enGrados;

    // Entrada para la función
    cout << "Ingrese las coordenadas del primer segmento (inicio x1, y1 y fin x2, y2): ";
    cin >> p1x >> p1y >> p2x >> p2y;

    cout << "Ingrese las coordenadas del segundo segmento (inicio x3, y3 y fin x4, y4): ";
    cin >> p3x >> p3y >> p4x >> p4y;

    // Preguntar si se desea el ángulo en grados o en radianes
    cout << "Desea el ángulo en grados? (1 para Sí, 0 para No): ";
    cin >> enGrados;

    // Calcular el ángulo
    double angulo = calcularAngulo(p1x, p1y, p2x, p2y, p3x, p3y, p4x, p4y, enGrados);

    if (enGrados) {
        cout << "El angulo entre las dos lineas es de " << angulo << " grados." << endl;
    } else {
        cout << "El angulo entre las dos lineas es de " << angulo << " radianes." << endl;
    }
    cout<<angulo<<endl;
    return 0;
}

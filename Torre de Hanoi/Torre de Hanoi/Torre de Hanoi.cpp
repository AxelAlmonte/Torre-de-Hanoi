/*

Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

*/

#include <iostream>

using namespace std;

void HanoiTower(int n, char src, char aux, char dest) {

    // Caso base: si solo hay un anillo, se mueve directamente
    // al destino y la recursión se detiene.
    if (n == 1) {
        cout << "Mover anillo 1 de " << src << " a " << dest << endl;
        return;
    }

    // Paso 1: mover los n-1 anillos de arriba desde el origen hasta
    // la torre auxiliar, usando el destino como apoyo.
    // (Se intercambian los roles de aux y dest.)
    HanoiTower(n - 1, src, dest, aux);

    // Paso 2: ahora el anillo más grande (n) está libre,
    // así que se mueve directamente del origen al destino.
    cout << "Mover anillo " << n << " de " << src << " a " << dest << endl;
    
    // Paso 3: mover los n-1 anillos desde la torre auxiliar hasta
    // el destino, colocándolos encima del anillo grande,
    // usando el origen como apoyo.
    HanoiTower(n - 1, aux, src, dest);
    
}
int main() {
    cout << "Torre de Hanoi\n" << endl;
    cout << "Ingrese la cantidad de anillos: ";
    int n;
    cin >> n;
    if (n < 3) {
        cout << "La cantidad de anillos debe ser mayor o igual a 3." << endl;
        return 1;
    }
    else {
        cout << "La cantidad de anillos es: " << n << endl;
    }

    HanoiTower(n, 'A', 'B', 'C');
    
    // El mínimo de movimientos para n anillos es 2^n - 1.
    // (1 << n) desplaza el 1 a la izquierda n posiciones, o sea, calcula 2^n.
    cout << "Total de movimientos: " << (1 << n) - 1 << endl << endl;
    
    return 0;
}
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
    if (n == 1) {
        cout << "Mover anillo 1 de " << src << " a " << dest << endl;
        return;
    }
    HanoiTower(n - 1, src, dest, aux);
    cout << "Mover anillo " << n << " de " << src << " a " << dest << endl;
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
    
    cout << "Total de movimientos: " << (1 << n) - 1 << endl << endl;
    return 0;
}
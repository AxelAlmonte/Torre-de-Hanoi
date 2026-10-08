/*
Fecha: 8/10/2026
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- ⁠Octavio Ramírez - 1132995
- ⁠José Pinales - 1133255
- Christian Acosta - 1132698

Realizar un programa C++ que permita resolver el problema de las Torres de Hanoi,
el cual consiste en trasladar una cantidad x de anillos desde una torre A a una torre B.
*/
#include <iostream>
#include <string>

using namespace std;

void leerEntero(string mensaje, int& pDato)
{
    string datoString;
    size_t position;
    bool error;

    do
    {
        try
        {
            cout << mensaje;
            cin >> datoString;
            pDato = stoi(datoString, &position);

            if (datoString.length() != position) {
                error = true;
                cout << "Entrada invalida, ingrese un numero entero\n" << endl;
            }
            else {
                error = false;
            }
        }
        catch (const exception&)
        {
            error = true;
            cout << "Entrada invalida, ingrese un numero entero\n" << endl;
        }
    } while (error);
}

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

    int n;
    leerEntero("Ingrese la cantidad de anillos: ", n);

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
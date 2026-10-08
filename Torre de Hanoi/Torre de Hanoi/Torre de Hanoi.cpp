/*
Fecha: 8/10/2026
Grupo 1:
- Alessandro Salamone - 1132116
- Carlos Minaya - 1132836
- Axel Almonte - 1131078
- Octavio Ramírez - 1132995
- José Pinales - 1133255
- Christian Acosta - 1132698

Realizar un programa C++ que permita resolver el problema de las Torres de Hanoi,
el cual consiste en trasladar una cantidad x de anillos desde una torre A a una torre C.
*/
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Limpia la consola (cls en Windows, clear en Linux/Mac).
void limpiarPantalla()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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
            if (!(cin >> datoString)) {
                // Si se cierra la entrada se termina el programa
                // para no quedar en un ciclo infinito.
                cout << endl;
                exit(0);
            }
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

// Pregunta si/no y solo acepta s, S, n o N. Devuelve true si la respuesta es si.
bool leerSiNo(string mensaje)
{
    string respuesta;
    bool valido;

    do
    {
        cout << mensaje;
        if (!(cin >> respuesta)) {
            cout << endl;
            exit(0);
        }

        valido = (respuesta == "s" || respuesta == "S" || respuesta == "n" || respuesta == "N");
        if (!valido) {
            cout << "Entrada invalida, escriba s o n.\n" << endl;
        }
    } while (!valido);

    return (respuesta == "s" || respuesta == "S");
}

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

void ResolverHanoi()
{
    int n;
    bool valido;

    cout << "Resolver Torre de Hanoi\n" << endl;

    do {
        leerEntero("Ingrese la cantidad de anillos: ", n);

        valido = (n >= 3);
        if (!valido) {
            cout << "La cantidad de anillos debe ser mayor o igual a 3.\n" << endl;
        }
    } while (!valido);

    cout << "La cantidad de anillos es: " << n << endl;

    HanoiTower(n, 'A', 'B', 'C');

    // El mínimo de movimientos para n anillos es 2^n - 1.
    // (1 << n) desplaza el 1 a la izquierda n posiciones, o sea, calcula 2^n.
    cout << "Total de movimientos: " << (1 << n) - 1 << endl << endl;
}

int main() {
    int opcion;
    bool valido;

    do
    {
        limpiarPantalla();

        cout << "===== TORRE DE HANOI =====" << endl;
        cout << "1. Resolver Torre de Hanoi" << endl;
        cout << "2. Salir" << endl;

        do {
            leerEntero("Seleccione una opcion: ", opcion);

            valido = (opcion == 1 || opcion == 2);
            if (!valido) {
                cout << "Opcion invalida, elija 1 o 2.\n" << endl;
            }
        } while (!valido);

        if (opcion == 1) {
            bool repetir;

            do {
                limpiarPantalla();
                ResolverHanoi();
                repetir = leerSiNo("Desea resolver otra vez? (s/n): ");
            } while (repetir);
        }
        else {
            cout << "\nHasta luego!" << endl;
        }
    } while (opcion != 2);

    return 0;
}
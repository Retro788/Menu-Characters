/**   $$$$$$$\   $$$$$$\ $$$$$$$$\         $$$$$$\  
     $$  __$$\ $$ ___$$\\__$$  __|       $$$ __$$\ 
    $$ |  $$ |\_/   $$ |  $$ | $$$$$$\  $$$$\ $$ |
   $$$$$$$  |  $$$$$ /   $$ |$$  __$$\ $$\$$\$$ |
  $$  __$$<   \___$$\   $$ |$$ |  \__|$$ \$$$$ |
 $$ |  $$ |$$\   $$ |  $$ |$$ |      $$ |\$$$ |
$$ |  $$ |\$$$$$$  |  $$ |$$ |      \$$$$$$  /
\__|  \__| \______/   \__|\__|       \______/ 
**/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

void generarArregloAleatorio(int arreglo[], int tamano) {
    srand(time(nullptr));
    for (int i = 0; i < tamano; ++i) {
        arreglo[i] = rand() % 100; // Genera números aleatorios entre 0 y 99
    }
}

void leerCadena(char cadena[], int tamanoMax) {
    cin.ignore(); // Limpiar el buffer antes de leer la cadena
    cout << "Ingresa una cadena (max. " << tamanoMax << " caracteres): ";
    cin.getline(cadena, tamanoMax);
}

int encontrarMayor(int arreglo[], int tamano) {
    int mayor = arreglo[0];
    for (int i = 1; i < tamano; ++i) {
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
    }
    return mayor;
}

int contarVocales(const char cadena[]) {
    int count = 0;
    int length = strlen(cadena);
    cout << "Vocales en la cadena: ";
    for (int i = 0; i < length; ++i) {
        char c = tolower(cadena[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++count;
            cout << cadena[i] << " ";
        }
    }
    cout << endl;
    return count;
}

int main() {
    const int tamanoArreglo = 10;
    int arreglo[tamanoArreglo];
    char cadena[81];
    int opcion;

    do {
        cout << "Menú:" << endl;
        cout << "1) Generar un arreglo aleatorio de 10 enteros" << endl;
        cout << "2) Leer una cadena de máx. 80 caracteres" << endl;
        cout << "3) Regresar el mayor del arreglo" << endl;
        cout << "4) Regresar cuántas vocales hay en la cadena" << endl;
        cout << "5) Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                generarArregloAleatorio(arreglo, tamanoArreglo);
                cout << "Arreglo generado: ";
                for (int i = 0; i < tamanoArreglo; ++i) {
                    cout << arreglo[i] << " ";
                }
                cout << endl;
                break;
            case 2:
                leerCadena(cadena, 80);
                break;
            case 3:
                if (arreglo[0]) {
                    int mayor = encontrarMayor(arreglo, tamanoArreglo);
                    cout << "El mayor del arreglo es: " << mayor << endl;
                } else {
                    cout << "El arreglo no ha sido generado aún." << endl;
                }
                break;
            case 4:
                if (cadena[0]) {
                    int numVocales = contarVocales(cadena);
                    cout << "Número de vocales en la cadena: " << numVocales << endl;
                } else {
                    cout << "La cadena no ha sido ingresada aún." << endl;
                }
                break;
            case 5:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Introduce un número del 1 al 5." << endl;
        }

    } while (opcion != 5);

    return 0;
}

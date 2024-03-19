/*Alejandro Pedro Steinman Cuesta - T00077151
Andres Felipe Rubiano Marrugo - T00077084
Tarea 2 */
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;
//
class Sueldo {
public:
    string nombre;
    int edad;
    float sueldoHora;
public:
    Sueldo(string n, int e, float s) : nombre(n), edad(e), sueldoHora(s) {}
    virtual float calcularSalarioDiario() const = 0;
    virtual float calcularSalarioSemanal() const = 0;
    virtual float calcularSalarioMensual() const = 0;
    virtual string getNombre() const = 0;
};

class Trabajador : public Sueldo {
public:
    Trabajador(string n, int e, float s) : Sueldo(n, e, s) {}

    string getNombre() const override{
        return nombre;
    }

    float calcularSalarioDiario() const override {
        return sueldoHora * 8; 
    }

    float calcularSalarioSemanal() const override {
        return sueldoHora * 8 * 5;
    }

    float calcularSalarioMensual() const override {
        return sueldoHora* 5 * 8 * 4;
    }
};

int main() {
    Trabajador **vector = NULL;
    int cant = 0;
    char opcion; char stop;
    do {
        cout << "----Ingreso de Datos----" << endl;
        string nombre;
        int edad;
        float sueldoHora;   

        cout << "Nombre del Trabajador " << cant + 1 << ": ";
        cin.ignore();
        getline(cin, nombre);
        cout << "Edad: "; cin >> edad;
        cout << "Sueldo por hora: "; cin >> sueldoHora;
        //
        Trabajador **pv = new Trabajador*[cant + 1]; //vector vacio temporal
        for(int i = 0; i < cant; i++){
            pv[i] = vector[i];//asignacion de espacios vacios
        }
        pv[cant] = new Trabajador(nombre, edad, sueldoHora);
        cant++;

        delete []vector;
        vector = pv;

        cout << "¿Agregar otro Trabajador? (S/N): ";
        cin >> opcion;
        stop = tolower(opcion);
        system("cls");
    } while (stop == 's');
	//
    cout << "\n--- Salarios ---\n";
    float salarioTotalSemanal = 0; float salarioTotalMensual = 0;
    for (int i = 0; i < cant; i++) {
        cout << "Sueldo de " << vector[i]->getNombre() << endl;
        cout << "Salario diario: $" << fixed << setprecision(2) << vector[i]->calcularSalarioDiario() << endl;
        cout << "Salario semanal: $" << fixed << setprecision(2) << vector[i]->calcularSalarioSemanal() << endl;
        cout << "Salario mensual: $" << fixed << setprecision(2) << vector[i]->calcularSalarioMensual() << endl;
        cout << endl;
        salarioTotalSemanal += vector[i]->calcularSalarioSemanal();//acceso al atributo
        salarioTotalMensual += vector[i]->calcularSalarioMensual();//acceso al atributo
    }
    float salarioPromedioSemanal = salarioTotalSemanal / cant;
    float salarioPromedioMensual = salarioTotalMensual / cant;

    cout << "Salario promedio por semana: $" << fixed << setprecision(2) << salarioPromedioSemanal << endl;
    cout << "Salario promedio por mes: $" << fixed << setprecision(2) << salarioPromedioMensual << endl;

    // Limpieza de memoria
    for (int i = 0; i < cant; i++) {
        delete vector[i];
    }
    delete []vector;

    return 0;
}
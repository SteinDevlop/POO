/*
Alejandro Pedro Steinman Cuesta - T00077151
Andres Felipe Rubiano Marrugo - T00077084
Tarea 2
*/
#include <iostream>
#include <iomanip>
using namespace std;
//Esta solucion se hizo con 15% sangre y 75% Cafe, 2 aves maria y una alabanza con incienzo al disco duro.
//Favor de dar opiniones constructivas (no opinar)
class Sueldo {
protected:
    string nombre;
    int edad;
    float sueldoHora;
public:
    Sueldo(string n, int e, float s) 
        : nombre(n), edad(e), sueldoHora(s) {}
    virtual float calcularSalarioDiario() const = 0;
    virtual float calcularSalarioSemanal() const = 0;
    virtual float calcularSalarioMensual() const = 0;
    string getNombre(){ return nombre; }
};
class Trabajador : public Sueldo {
public:
    Trabajador(string n, int e, float s)
        : Sueldo(n, e, s) {}

    float calcularSalarioDiario() const override {
        return sueldoHora * 8; // 8 horas diarias
    }

    float calcularSalarioSemanal() const override {
        return calcularSalarioDiario() * 5; // 5 días laborables a la semana
    }

    float calcularSalarioMensual() const override {
        return calcularSalarioSemanal() * 4; // 4 semanas al mes
    }
};

int main() {
    Sueldo* vector[100];
    int contador = 0;
    char stop;
    do {
        string nombre;
        int edad;
        float sueldoHora;
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Edad: ";
        cin >> edad;
        cout << "Sueldo por hora: ";
        cin >> sueldoHora;
        vector[contador] = new Trabajador(nombre, edad, sueldoHora);
        contador++;
        cout << "¿Agregar otro Sueldo? (S/N): ";
        cin >> stop;
    } while (stop == 'S');
    // Calcular y mostrar los salarios para cada Sueldo
    cout << "\n--- Salarios ---\n";
    for (int i = 0; i < contador; ++i) {
        cout << "Sueldo: " << vector[i]->getNombre() << endl;
        cout << "Salario diario: $" << fixed << setprecision(2) << vector[i]->calcularSalarioDiario() << endl;
        cout << "Salario semanal: $" << fixed << setprecision(2) << vector[i]->calcularSalarioSemanal() << endl;
        cout << "Salario mensual: $" << fixed << setprecision(2) << vector[i]->calcularSalarioMensual() << endl;
        cout << endl;
    }
    // Calcular y mostrar salario promedio por semana y por mes
    float salarioPromedioSemanal = 0;
    float salarioPromedioMensual = 0;
    for (int i = 0; i < contador; ++i) {
        salarioPromedioSemanal += vector[i]->calcularSalarioSemanal();
        salarioPromedioMensual += vector[i]->calcularSalarioMensual();
    }

    salarioPromedioSemanal /= contador;
    salarioPromedioMensual /= contador;

    cout << "Salario promedio por semana: $" << fixed << setprecision(2) << salarioPromedioSemanal << endl;
    cout << "Salario promedio por mes: $" << fixed << setprecision(2) << salarioPromedioMensual << endl;
    delete[] vector;

    return 0;
}
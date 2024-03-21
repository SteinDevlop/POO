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
protected:
    string nombre;
    int edad;
    float sueldoHora;
public:
    Sueldo(){}
    Sueldo(string n, int e, float s) : nombre(n), edad(e), sueldoHora(s) {}
    virtual float calcularSalarioDiario() const = 0;
    virtual float calcularSalarioSemanal() const = 0;
    virtual float calcularSalarioMensual() const = 0;
    virtual string getNombre() const = 0;
};
class Trabajador : public Sueldo {
public:
    Trabajador(){}
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
    void imprimir_info(){
        cout<<"----Salarios----"<<endl;
        cout<<"Salario por dia: "<<fixed<<setprecision(2)<< calcularSalarioDiario()<<endl;
        cout<<"Salario por semana: "<<fixed<<setprecision(2)<<calcularSalarioSemanal()<<endl;
        cout<<"Salario por mes: "<<fixed<<setprecision(2)<< calcularSalarioMensual()<<endl;
    }
};

int main() {
    int n,e;
    string na;
    float sh=0;
    float prom_s=0,prom_m=0;
    cout<<"Ingrese el numero de trabajadores: ";
    cin>>n;
    Trabajador * vector = new Trabajador[n];
    for(int i=0;i<n;i++){
        cout<<i+1<<endl;
        cout<<"Nombre: ";cin.ignore();getline(cin,na);
        cout<<"Edad: ";cin>>e;
        cout<<"Salario por hora: ";cin>>sh;
        vector[i]=Trabajador(na,e,sh);
        prom_s+=vector[i].calcularSalarioSemanal();
        prom_m+=vector[i].calcularSalarioMensual();
        vector[i].imprimir_info();
    }
    cout<<"---Promedios---"<<endl;
    cout<<"Promedio semanal: "<<fixed<<setprecision(2)<<prom_s/n<<endl;
    cout<<"Promedio mensual: "<<fixed<<setprecision(2)<<prom_m/n<<endl;
    delete[] vector;
    return 0;
}
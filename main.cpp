/*
Alejandro Pedro Steinman Cuesta - T00077151
[Name] - [Code]
Tarea 2
*/
#include <iostream>
#include <iomanip>
using namespace std;
class salario{
    protected:
        int edad;
        string nombre;
        float salario_h;
        float sal_s_d,sal_s_s,sal_s_m;
        float prom_s,prom_m;
        int contador;
    public:
        salario(int e,string n,float s): edad{e},nombre{n},salario_h{s},sal_s_d{s*8},sal_s_s{s*8*7},sal_s_m{s*8*7*4},contador{0}{}
        int s_prom(){
        }//recorrido de vectores
    virtual void imprimir() =0;
};
class dia: public salario{
    dia(int e,string n,float s):salario(e,n,s){}
	void imprimir() override
	{
		cout<<"Dia: "<< (sal_s_d)<<endl;
	}

};
class semana: public salario{
    semana(int e,string n,float s):salario(e,n,s){}
    void imprimir() override
	{
		cout<<"semana: "<< (sal_s_s)<<endl;
	}
};
class mes: public salario{
    mes(int e,string n,float s):salario(e,n,s){}
    void imprimir() override
	{
		cout<<"Mes: "<<fixed<<setprecision(2)<< (sal_s_m)<<endl;
	}
};
int main(){

    return 0;
}
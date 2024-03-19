#include <iostream>
using namespace std;
template <typename T>
class objeto{
    public:
    T mayor(T n1,T n2, T n3){
        int v[3]={n1,n2,n3};
        int may=0;
        for (int i=0; i<3;i++){
            if(v[i]>v[i+1]){may=v[i];}
        }
        return may;
    }
};
int main(){
    objeto<int> ob;
    int it = ob.mayor(5,20,500);
    cout<<"El mayor es "<<it<<endl;
    return 0;
}
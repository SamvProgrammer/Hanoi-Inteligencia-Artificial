#include<iostream>
#include"variables.h"
#include"funciones.h"
int main(){
  cout<<"----Torre de hanoi metodo de profunidad----"<<endl;
  cout<<"Cantidad de discos"<<endl;
  cin>>cantidadDiscos;
  int *apunTorre1=torre1;
  for(int x=cantidadDiscos;x>0;x--){
     *apunTorre1=x;
     apunTorre1++;
  }
  contadorTorre1=cantidadDiscos-1;
 imprimir();
 principal(0);
 cout<<endl;
cout<<"Cantidad de movimientos "<<cantidad<<endl;
  cin.get();
  return 0;
}

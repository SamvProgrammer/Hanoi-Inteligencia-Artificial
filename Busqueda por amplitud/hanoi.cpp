#include<iostream>
using namespace std;
struct torresitas{
   int contadorTorre1=-1;
   int contadorTorre2=-1;
   int contadorTorre3=-1;
   int torre1[20];
   int torre2[20];
   int torre3[20];
} cola[2000][2000];
int contadorCola=-1;
int anidamiento=0;
int contador=-1;
int platos;
 torresitas *apuntador;

void agregarCola(int ani);
void imprimir();
void sacarCola(int ani);
bool principal(int hijos,int ani,int destino);

void meter1a2(int ani);
void meter1a3(int ani);
void meter2a1(int ani);
void meter2a3(int ani);
void meter3a1(int ani);
void meter3a2(int ani);

int main(){
  int posicion=0;
  cout<<"AMPLITUD JUEGO DE HANOI"<<endl;
  cout<<"Ingrese el numero de platos"<<endl;
  cin>>platos;
  platos-1;

  contadorCola++;
  cola[contadorCola][0].contadorTorre1=platos-1;
  for(int x=platos;x>0;x--){
    cola[0][0].torre1[posicion]=x;
    posicion++;
  }

  if(principal(0,0,cola[0][0].contadorTorre1)){
    cout<<"Hanoi resuelto"<<endl;
    imprimir();
  }else{
    cout<<"Hanoi no se resolvio"<<endl;
  }

  cin.get();
  return 0;
}

bool principal(int hijos,int ani,int destino){
    cout<<"..................................anidamiento"<<ani<<".............."<<endl;
bool rep=false,repetido=false;
  int contadorHijos=0;
  int contador=1;
  cout<<"Cantidad de hijos:"<<hijos<<endl;
  do{
  if(cola[0][ani].contadorTorre3==cola[0][0].contadorTorre1){
     anidamiento=ani;
     return true;
  }else{
     if(ani<7){
         //Operaciones torre 1
    if(cola[0][ani].contadorTorre1!=-1){
       if(cola[0][ani].contadorTorre2==-1){
        //Mover torre1 a torre2
     //   cout<<"Vacio torre 2 metiendo torre 1 a torre 2"<<endl;
        contadorHijos++;
        agregarCola(ani);
        meter1a2(ani);

       }
       if(cola[0][ani].contadorTorre3==-1){
           //Mover torre1 a torre3
       //    cout<<"Vacio torre 3 metiendo torre 1 a torre 3"<<endl;
          contadorHijos++;
          agregarCola(ani);
          meter1a3(ani);
       }

        if(cola[0][ani].contadorTorre2!=-1){
            if(cola[0][ani].torre1[cola[0][ani].contadorTorre1]<
             cola[0][ani].torre2[cola[0][ani].contadorTorre2]){
                 //Mover torre1 a torre2
         //        cout<<"metiendo torre 1 a torre 2"<<endl;
             contadorHijos++;
             agregarCola(ani);
             meter1a2(ani);
          }
        }
        if(cola[0][ani].contadorTorre3!=-1){
               if(cola[0][ani].torre1[cola[0][ani].contadorTorre1]<
             cola[0][ani].torre3[cola[0][ani].contadorTorre3]){
                 //Mover torre1 a torre3
           //      cout<<"metiendo torre 1 a torre 3"<<endl;
            contadorHijos++;
            agregarCola(ani);
            meter1a3(ani);
          }
        }


    }
    //Operaciones torre 2
    if(cola[0][ani].contadorTorre2!=-1){
       if(cola[0][ani].contadorTorre1==-1){
            //Mover torre2 a torre1
            //cout<<"Vacio torre 1 metiendo torre 2 a torre 1"<<endl;
        contadorHijos++;
        agregarCola(ani);
        meter2a1(ani);
       }
       if(cola[0][ani].contadorTorre3==-1){
           //Mover torre2 a torre3
         //  cout<<"Vacio torre 3 metiendo torre 2 a torre 3"<<endl;
          contadorHijos++;
          agregarCola(ani);
          meter2a3(ani);
       }

          if(cola[0][ani].contadorTorre1!=-1){
            if(cola[0][ani].torre2[cola[0][ani].contadorTorre2]<
             cola[0][ani].torre1[cola[0][ani].contadorTorre1]){
            //Mover torre2 a torre1
           // cout<<"metiendo torre 2 a torre 1"<<endl;
             contadorHijos++;
             agregarCola(ani);
             meter2a1(ani);
           }
          }
          if(cola[0][ani].contadorTorre3!=-1){
              if(cola[0][ani].torre2[cola[0][ani].contadorTorre2]<
             cola[0][ani].torre3[cola[0][ani].contadorTorre3]){
                 //Mover torre2 a torre3
             //    cout<<"metiendo torre 2 a torre 3"<<endl;
            contadorHijos++;
            agregarCola(ani);
            meter2a3(ani);
          }
          }

    }
    //Operaciones torre 3
    if(cola[0][ani].contadorTorre3!=-1){
       if(cola[0][ani].contadorTorre1==-1){
            //Mover torre3 a torre1
           // cout<<"Vacio torre 1 metiendo torre 3 a torre 1"<<endl;
        contadorHijos++;
        agregarCola(ani);
        meter3a1(ani);
       }
       if(cola[0][ani].contadorTorre2==-1){
           //Mover torre3 a torre2
          // cout<<"Vacio torre 2 metiendo torre 3 a torre 2"<<endl;
          contadorHijos++;
          agregarCola(ani);
          meter3a2(ani);
       }
          if(cola[0][ani].contadorTorre1!=-1){
            if(cola[0][ani].torre3[cola[0][ani].contadorTorre3]<
             cola[0][ani].torre1[cola[0][ani].contadorTorre1]){
            //Mover torre3 a torre1
            //cout<<"metiendo torre 3 a torre 1"<<endl;
             contadorHijos++;
             agregarCola(ani);
             meter3a1(ani);
          }
          }
          if(cola[0][ani].contadorTorre2!=-1){
            if(cola[0][ani].torre3[cola[0][ani].contadorTorre3]<
             cola[0][ani].torre2[cola[0][ani].contadorTorre2]){
                 //Mover torre3 a torre2
              //   cout<<"metiendo torre 3 a torre 2"<<endl;
            contadorHijos++;
            agregarCola(ani);
            meter3a2(ani);
          }
          }

    }
     }
      //cout<<"Sacando de la cola<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl;
      sacarCola(ani);
      if(contadorCola!=-1){
        if(contador<hijos){
           contador++;
     }else{
        // cout<<"Entrando recursivo---------------------------->"<<endl;
       rep= principal(contadorHijos,(ani+1),destino);
       return rep;
     }
      }else{
         return false;
      }
   }
  }while(ani<=7);
  return rep;
}

void meter1a2(int ani){
  cola[contadorCola][ani+1].contadorTorre2++;
  cola[contadorCola][ani+1].torre2[cola[contadorCola][ani+1].contadorTorre2]=
  cola[contadorCola][ani+1].torre1[cola[contadorCola][ani+1].contadorTorre1];
  cola[contadorCola][ani+1].contadorTorre1--;
}
void meter1a3(int ani){
  cola[contadorCola][ani+1].contadorTorre3++;
  cola[contadorCola][ani+1].torre3[cola[contadorCola][ani+1].contadorTorre3]=
  cola[contadorCola][ani+1].torre1[cola[contadorCola][ani+1].contadorTorre1];
  cola[contadorCola][ani+1].contadorTorre1--;
}
void meter2a1(int ani){
  cola[contadorCola][ani+1].contadorTorre1++;
  cola[contadorCola][ani+1].torre1[cola[contadorCola][ani+1].contadorTorre1]=
  cola[contadorCola][ani+1].torre2[cola[contadorCola][ani+1].contadorTorre2];
  cola[contadorCola][ani+1].contadorTorre2--;
}
void meter2a3(int ani){
  cola[contadorCola][ani+1].contadorTorre3++;
  cola[contadorCola][ani+1].torre3[cola[contadorCola][ani+1].contadorTorre3]=
  cola[contadorCola][ani+1].torre2[cola[contadorCola][ani+1].contadorTorre2];
  cola[contadorCola][ani+1].contadorTorre2--;
}
void meter3a1(int ani){
  cola[contadorCola][ani+1].contadorTorre1++;
  cola[contadorCola][ani+1].torre1[cola[contadorCola][ani+1].contadorTorre1]=
  cola[contadorCola][ani+1].torre3[cola[contadorCola][ani+1].contadorTorre3];
  cola[contadorCola][ani+1].contadorTorre3--;
}
void meter3a2(int ani){
  cola[contadorCola][ani+1].contadorTorre2++;
  cola[contadorCola][ani+1].torre2[cola[contadorCola][ani+1].contadorTorre2]=
  cola[contadorCola][ani+1].torre3[cola[contadorCola][ani+1].contadorTorre3];
  cola[contadorCola][ani+1].contadorTorre3--;
}



void agregarCola(int ani){
  if(contadorCola!=-1){
     contadorCola++;
     apuntador=cola[contadorCola];
     for(int i=0;i<=ani;i++){
        *apuntador=cola[0][i];
        apuntador++;
    }
    *apuntador=cola[0][ani];
  }
}

void sacarCola(int ani){
 torresitas *apuntador1,*apuntador2;
  if(contadorCola!=-1){
   for(int x=0;x<contadorCola;x++){
     apuntador1=cola[x];
     apuntador2=cola[x+1];
     for(int y=0;y<=2000;y++){
       *apuntador1=*apuntador2;
       apuntador1++;
       apuntador2++;
     }
   }
   contadorCola--;
 }
}

void imprimir(){
   for(int x=0;x<=anidamiento;x++){
      cout<<"------------"<<x<<"-----------------\n";
      cout<<"\nTorre1"<<endl;
      for(int i=0;i<=cola[0][x].contadorTorre1;i++){
        cout<<cola[0][x].torre1[i]<<" ";
      }
      cout<<"\nTorre2"<<endl;
      for(int i=0;i<=cola[0][x].contadorTorre2;i++){
        cout<<cola[0][x].torre2[i]<<" ";
      }

      cout<<"\nTorre3"<<endl;
      for(int i=0;i<=cola[0][x].contadorTorre3;i++){
        cout<<cola[0][x].torre3[i]<<" ";
      }
      cout<<endl;
   }

}

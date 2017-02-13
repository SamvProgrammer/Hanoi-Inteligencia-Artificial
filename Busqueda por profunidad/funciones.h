int cantidad=0;
bool principal(int profundidad){
    cantidad++;
 cout<<"Profundidad-------------    "<<profundidad<<endl;

    if(contadorTorre3==cantidadDiscos-1){
    cout<<"\nHanoi resuelto"<<endl;
    return true;
  }else{
     if(profundidad!=profundidadMaxima){
          if(contadorTorre1!=-1){
              if(contadorTorre2==-1){
                //cout<<"Muevo de torre 1 a torre 2"<<endl;
                contadorTorre2++;
                torre2[contadorTorre2]=torre1[contadorTorre1];
                contadorTorre1--;
                imprimir();

                if(principal(profundidad+1)){
                    return true;
                }
               // cout<<"\nMueve a su estado anterior"<<endl;
                contadorTorre1++;
                torre1[contadorTorre1]=torre2[contadorTorre2];
                contadorTorre2--;

              } if(contadorTorre3==-1){
                contadorTorre3++;
                torre3[contadorTorre3]=torre1[contadorTorre1];
                contadorTorre1--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
               // cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre1++;
                torre1[contadorTorre1]=torre3[contadorTorre3];
                contadorTorre3--;
              }else{
               if(torre1[contadorTorre1]<torre2[contadorTorre2]){
                contadorTorre2++;
                torre2[contadorTorre2]=torre1[contadorTorre1];
                contadorTorre1--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
//                cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre1++;
                torre1[contadorTorre1]=torre2[contadorTorre2];
                contadorTorre2--;
              }else if(torre1[contadorTorre1]<torre3[contadorTorre3]){
                 contadorTorre3++;
                torre3[contadorTorre3]=torre1[contadorTorre1];
                contadorTorre1--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
                //cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre1++;
                torre1[contadorTorre1]=torre3[contadorTorre3];
                contadorTorre3--;
              }
            }}

       if(contadorTorre2!=-1){
                 if(contadorTorre1==-1){
                contadorTorre1++;
                torre1[contadorTorre1]=torre2[contadorTorre2];
                contadorTorre2--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
                //cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre2++;
                torre2[contadorTorre2]=torre1[contadorTorre1];
                contadorTorre1--;

              } if(contadorTorre3==-1){
                contadorTorre3++;
                torre3[contadorTorre3]=torre2[contadorTorre2];
                contadorTorre2--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
                //cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre2++;
                torre2[contadorTorre2]=torre3[contadorTorre3];
                contadorTorre3--;

              }else{
                  if(torre2[contadorTorre2]<torre1[contadorTorre1]){
                contadorTorre1++;
                torre1[contadorTorre1]=torre2[contadorTorre2];
                contadorTorre2--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
             //   cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre2++;
                torre2[contadorTorre2]=torre1[contadorTorre1];
                contadorTorre1--;

              }else if(torre2[contadorTorre2]<torre3[contadorTorre3]){
                 contadorTorre3++;
                torre3[contadorTorre3]=torre2[contadorTorre2];
                contadorTorre2--;

                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
              //  cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre2++;
                torre2[contadorTorre2]=torre3[contadorTorre3];
                contadorTorre3--;
              }
            }}

            if(contadorTorre3!=-1){
                  if(contadorTorre1==-1){
                contadorTorre1++;
                torre1[contadorTorre1]=torre3[contadorTorre3];
                contadorTorre3--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
              //  cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre3++;
                torre3[contadorTorre3]=torre1[contadorTorre1];
                contadorTorre1--;

              }if(contadorTorre2==-1){
                 contadorTorre2++;
                torre2[contadorTorre2]=torre3[contadorTorre3];
                contadorTorre3--;
                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
              //  cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre3++;
                torre3[contadorTorre3]=torre2[contadorTorre2];
                contadorTorre2--;
              }else{
                  if(contadorTorre2==-1){
                contadorTorre2++;
                torre2[contadorTorre2]=torre3[contadorTorre3];
                contadorTorre3--;

                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
              //  cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre3++;
                torre3[contadorTorre3]=torre2[contadorTorre2];
                contadorTorre2--;
              }else if(torre3[contadorTorre3]<torre1[contadorTorre1]){
                contadorTorre1++;
                torre1[contadorTorre1]=torre3[contadorTorre3];
                contadorTorre3--;

                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
              //  cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre3++;
                torre3[contadorTorre3]=torre1[contadorTorre1];
                contadorTorre1--;
              }else if(torre3[contadorTorre3]<torre2[contadorTorre2]){
                 contadorTorre2++;
                torre2[contadorTorre2]=torre3[contadorTorre3];
                contadorTorre3--;

                imprimir();
                if(principal(profundidad+1)){
                    return true;
                }
               // cout<<"Mueve a su estado anterior"<<endl;

                contadorTorre3++;
                torre3[contadorTorre3]=torre2[contadorTorre2];
                contadorTorre2--;
              }
            }}
     }else{
       return false;
     }


    }
    return false;

}

void imprimir(){
   cout<<"\nTorre 1"<<endl;
   for(int x=0;x<=contadorTorre1;x++){
      cout<<" "<<torre1[x];
   }
   cout<<endl<<"Torre 2"<<endl;
   for(int x=0;x<=contadorTorre2;x++){
      cout<<" "<<torre2[x];
   }
   cout<<endl<<"Torre 3"<<endl;
   for(int x=0;x<=contadorTorre3;x++){
      cout<<" "<<torre3[x];
   }
   cout<<"\n--------------------------------";
}
/*
int *mapSobreArreglo(int *arreglo,int contador){
  int arregloSalida[20];
   if(contador!=-1){
    cout<<"Si entra la torre"<<endl;
    for(int x=0;x<=contador;x++){

      arregloSalida[x]=arreglo[x];
    }
    return arregloSalida;
   }
  return arreglo;
}

*/

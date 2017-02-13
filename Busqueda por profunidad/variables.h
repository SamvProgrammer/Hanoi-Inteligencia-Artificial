using namespace std;
int cantidadDiscos=-1;
int contadorPila=-1;
int *pila[100][3];
int torre1[20];
int torre2[20];
int torre3[20];
int contadorTorre1=-1;
int contadorTorre2=-1;
int contadorTorre3=-1;
int profundidadMaxima=20;
//int pila[100][3];

bool principal(int profundidad);
void meterPila(int *arreglo);
void sacarPila();
int *mapSobreArreglo(int *arreglo,int contador);
void imprimir();

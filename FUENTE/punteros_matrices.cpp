#include<iostream>

using namespace std;
//Esta funcion cumple de entrada , para toamr los valores de la matriz
int entrada(){
  int a;
  cin>>a;
  return a;
}

//Esta funcion sirve para crear las columnas de cada una de las matrices
void creacion_mt(int **mt,int f,int c,int i=0){
    if (f==i) return;
    *(mt+i)=new int[c];
    i++;
    creacion_mt(mt,f,c,i);
  }
 
//Esta funion sirve para hacer el llenado de las matrices , con lo numeros que el usuaro dicte  
void llenado(int **mt,int f,int c,int i=0,int j=0){
    if (j==c){
        i++;
        j=0;
    }
    if (i==f) return;
    cout<<"valor :";
    *(*(mt+i)+j) = entrada();
    j++;
    llenado(mt,f,c,i,j);
}

//Esta funcion sirve para qque se impriman las matrices que queramos
void imprimir(int **mt,int f,int c,int i=0,int j=0){
    if (j==c){
       cout<<"\n";
        i++;
        j=0;
    }
    if (i==f) return;
    cout<<*(*(mt+i)+j)<<"  ";
    j++;
    imprimir(mt,f,c,i,j); 
}

//Esta funcion realiza la mulriplicaion de dos matrices
void multiplicacion(int **a,int **b,int **res,int f,int c,int c1,int suma,int pri,int seg,int i=0,int k=0,int j=0){
	if (k==c1){
        (*(*(res+i)+j))=suma;
        j++;
        k=0;
        suma=0;
		if (j==c){
        	i++;
        	j=0;
   		 }    
    }
    if (i==f) return;
    pri=*(*(a+i)+k);
    seg=*(*(b+k)+j);
    suma+=pri*seg;
    k++;
  	multiplicacion(a,b,res,f,c,c1,suma,pri,seg,i,k,j);
}  	

//Esta funcion elimina los espacios que fueron resevados para las matrices dinamicas  
void eliminar(int **mt,int f,int i=0){
		if (i==f){
			delete[] mt;
			return; 
		}
		delete[] *(mt+i);
		i++;
		eliminar(mt,f,i);		

}
 
//Todas las funciones son de forma recursiva , sin utilixar [] , y con punteros 
 
int main()
{
    //inicializamos las tres matrices con punnteros 
    int **mt1;
    int **mt2;
    int **mt3;
    cout<<"Verificar que para que salga la multiplicacion, columna1 debe ser igual a fila2\n";
    //Inicializamos la primera matriz
    cout<<"PRIMERA MATRIZ:\n";
    cout<<"Poner filas:\n";
    int filas1=entrada();
    cout<<"Poner columnas:\n";
    int columnas1=entrada();
    
    //Inicializamos la segunda matriz
    cout<<"SEGUNDA MATRIZ:\n";
    cout<<"Poner filas:\n";
    int filas2=entrada();
    cout<<"Poner columnas:\n";
    int columnas2=entrada();
    
    //Inicializamos la tercera matriz
    int filas3=filas1;
    int columnas3=columnas2;
    //iterador de la multiplicaion 
    int k=columnas1;
    
    //Desarrollo de la primera matriz
    mt1=new int*[filas1];
    creacion_mt( mt1,filas1,columnas1,0);
    llenado(mt1,filas1,columnas1,0,0);
    imprimir(mt1,filas1,columnas1,0,0);
    
    //Desarrollo de la segunda matriz
    mt2=new int*[filas2];
    creacion_mt( mt2,filas2,columnas2,0);
    llenado(mt2,filas2,columnas2,0,0);
    imprimir(mt2,filas2,columnas2,0,0);
    
    //Desarrollo de la tercera matriz o la matriz resultante de la multiplicacion
    mt3=new int*[filas3];
    int suma=0;
    int pri=0;
    int seg=0;
    creacion_mt( mt3,filas3,columnas3,0);
    multiplicacion(mt1,mt2,mt3,filas3,columnas3,k,suma,pri,seg,0,0,0);
    cout<<"RESULTADO DE LA MULTIPLICAION ES:\n"; 
    imprimir(mt3,filas3,columnas3,0,0);
    
    
    eliminar(mt1,filas1,0);
    eliminar(mt2,filas2,0);
    eliminar(mt3,filas3,0);
   
    return 0;
}


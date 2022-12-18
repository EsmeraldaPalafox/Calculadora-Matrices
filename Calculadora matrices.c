#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

float **mat;
float **transpuesta;
float **transpuesta2;
float **mattriangular;
float **matdiagonal;
float *vector1;
float *vectorresultante;
float **inversa;
void calcular_matriz_transpuesta_cofactor();
void calculardiagonal();
void calcularinversa();
void calcular_matriz_transpuesta();
float calculardeterminante(float **,int);
float cofa(float **,int,int,int);
void matrizescalonada();
void pedirdatos();
void producto_matriz_vector();
int filas=0;
int fila=0;
int columna=0;
float determinante=0;


void  main(){
    int opciones=0,opcion=0;
    printf("BIENVENIDOS A NUESTRO PROGRAMA PARA RESOLVER MATRICES\n");
    printf("Ingrese el numero de filas de su matriz:\n");
    scanf("%d",&filas);
    pedirdatos();
   do{
    printf("Por favor, elija la opcion que desea:\n");
    printf("1) MATRIZ TRANSPUESTA: \n");
    printf("2) MATRIZ INVERSA: \n");
    printf("3) MATRIZ TRIANGULAR: \n");
    printf("4) MATRIZ DIAGONAL \n");
    printf("5) MATRIZ POR VECTOR:\n");
    scanf("%d", &opciones);
    switch(opciones){
    case 1:
        calcular_matriz_transpuesta();
        break;
    case 2:
        printf("El determinante de su matriz es: %.4f\n",calculardeterminante(mat,filas));
        if(calculardeterminante(mat,filas)==0){
            printf("El determinante es 0, por lo que no tiene solucion\n ");
        }
        else{
        calcularinversa();
        }
        break;
    case 3:
        if(calculardeterminante(mat,filas)==0){
            printf("La matriz no tiene forma triangular por tener el determinante igual a 0");
            break;
        }
        else{
        printf("La matriz triangular seria:\n");
        matrizescalonada();
        }

        break;
    case 4:
        if(calculardeterminante(mat,filas)==0){
            printf("La matriz no tiene forma triangular por tener el determinante igual a 0");
            break;
        }
        else{
        printf("\n\tLa matriz diagonal es: \n");
        calculardiagonal();
        }
        break;
    case 5:
        printf("Ingrese el vector que desea operar:\n");
        producto_matriz_vector();
        break;

    default:
    printf("Opcion no valida\n");
    }
    printf("Desea realizar otra operacion?(1)si o (2)no:\n");
    scanf("%d",&opcion);
    }while(opcion==1);

printf("Gracias por usar el programa\n");
}

void pedirdatos(){
    mat=(float**)malloc(filas*sizeof(float*));
    for(int i=0; i < filas; i++){
    mat[i] = (float*)malloc(filas*sizeof(float));
    }
    printf("\n\tIngrese su matriz: \n");
    for (int i=0; i< filas ; i++){
        for (int j=0 ; j < filas; j++){
    printf("Ingresa elemento (%d)(%d): ",i+1,j+1);
    scanf("%f",&mat[i][j]);

        }
    }
     printf("Su matriz es: \n");
      for (int i=0; i< filas ; i++){
        for (int j=0 ; j < filas; j++){
        printf("\t%.4f",mat[i][j]);
}
printf("\n");
}
}
float cofa(float **mat,int filas, int fila, int columna){
     int numerofilas=filas-1;
    int a=0;
    int b=0;
    float **matrizpequena;
    matrizpequena=(float**)malloc((filas-1)*sizeof(float*));
    for(int i=0 ; i < filas ; i++){
        matrizpequena[i] = (float*)malloc((filas-1)*sizeof(float));
    }

    for (int i=0 ;i < filas ; i++){
        for (int j=0 ; j < filas ; j++){
            if(i != fila && j != columna){
                matrizpequena[a][b]=mat[i][j];
                b=b+1;
                if(b>=numerofilas){
                a= a+1;
                b=0;
                }
            }
        }
    }
    return pow(-1,fila+columna)*calculardeterminante(matrizpequena,numerofilas);
}
void calcular_matriz_transpuesta(){
    transpuesta=(float**)malloc(filas*sizeof(float*));
    for(int i=0 ;i< filas ; i ++){
            transpuesta[i] = (float*)malloc(filas*sizeof(float));
    }
    for(int i=0 ; i < filas ; i ++){
    for(int j=0 ;j < filas ;j ++){
    transpuesta[i][j] = mat[j][i];

        }
    }
    printf("Su matriz es: \n");
      for (int i=0; i< filas ; i++){
        for (int j=0 ; j < filas; j++){
        printf("\t%.4f",transpuesta[i][j]);
}
printf("\n");
}
}
float calculardeterminante(float **mat,int filas){
    float det=0;
    if(filas==1){
        det=mat[0][0];
    }
    else{
        for(int j=0;j<filas;j++){
            det=det+mat[0][j]*cofa(mat,filas,0,j);
        }
    }
    return det;
}

void producto_matriz_vector(){
    for(int i=0 ; i < filas ; i++ ){
        vector1=(float*)malloc(filas*sizeof(float));
    }
    for(int i=0 ; i <filas ; i++){
        vectorresultante=(float*)malloc(filas*sizeof(float));
    }
    for (int i=0 ; i <filas ; i++){
        printf("\n\tIngresa la componente %d del vector: ",i+1);
        scanf("%f",&vector1[i]);
    }

        for (int i=0 ; i < filas ; i++){
            float suma=0;
            for (int j=0;j<filas;j++){
                suma=suma+vector1[j]*mat[i][j];
            }
            vectorresultante[i]=suma;
        }
        printf("\n\tSu multiplicacion es la siguiente:\n\n");
        for (int i=0 ; i < filas ; i++){
            printf("\t%.4f\n",vectorresultante[i]);
        }

}
void calcular_matriz_transpuesta_cofactor(){
    transpuesta2=(float**)malloc(filas*sizeof(float*));
      for(int i=0 ;i < filas; i++){
        transpuesta2[i] = (float*)malloc(filas*sizeof(float));
        }
        for(int i=0 ;i < filas ;i++){
        for(int j=0 ;j < filas ; j++){
            transpuesta2[i][j]= inversa[j][i];
        }
    }

}


void calcularinversa(){
    inversa=(float**)malloc(filas*sizeof(float*));
      for(int i=0 ;i < filas ; i++){
        inversa[i] = (float*)malloc(filas*sizeof(float));
    }
    printf("\n\tLa matriz de cofactores es:\n\n");
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j <filas ; j++){
                inversa[i][j]=cofa(mat,filas,i,j);
        }
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ;  j <filas ; j++){

            printf("\t%.4f",inversa[i][j]);
            }
             printf("\n");
        }
    calcular_matriz_transpuesta_cofactor();
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < filas ; j++){
            transpuesta2[i][j]=(1/calculardeterminante(mat,filas))*transpuesta2[i][j];
        }
    }
    printf("\n\tLa matriz inversa es:\n\n");
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < filas ; j++){

            printf("\t%.4f",transpuesta2[i][j]);
            }
             printf("\n");
        }
}
void matrizescalonada(){
     mattriangular=(float**)malloc(filas*sizeof(float*));
    for(int i=0 ; i < filas ; i++){
        mattriangular[i] = (float*)malloc(filas*sizeof(float));

    }
    for(int i=0 ;i < filas ; i++){
        for(int j=0 ; j < filas  ;  j++){
         mattriangular[i][j]= mat[i][j];
        }
    }
   float div=0;
    for(int j=0 ; j < filas-1 ; j++){
        for(int i=j+1 ; i < filas ; i++){
            if (i>j){
                div=mattriangular[i][j]/mattriangular[j][j];
                for (int k=j;k<filas;k++){
                    mattriangular[i][k]=mattriangular[i][k]-div*mattriangular[j][k];
                }
            }
        }
    }
    for (int i=0; i< filas ; i++){
        for (int j=0 ; j < filas; j++){
        printf("\t%.4f",mattriangular[i][j]);
}
printf("\n");
}
}

void calculardiagonal(){
    matdiagonal=(float**)malloc(filas*sizeof(float*));
    for(int i=0  ; i <filas ; i++){
        matdiagonal[i] = (float*)malloc(filas*sizeof(float));
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < filas; j++){
         matdiagonal[i][j]= mat[i][j];
        }
    }

    float div=0;
    for(int j=0 ; j < filas-1; j++){
        for(int i=j+1 ; i<filas ;i++){
            if (i>j){
                div=matdiagonal[i][j]/matdiagonal[j][j];
                for (int k=j;k<filas;k++){
                    matdiagonal[i][k]=matdiagonal[i][k]-div*matdiagonal[j][k];
                }
            }
        }
    }
    for(int i=0 ; i < filas ;i++){
        for(int j=0 ; j < filas  ; j++){
            if (j>i){
                matdiagonal[i][j]=0;
            }
        }
    }
    for (int i=0; i< filas ; i++){
        for (int j=0 ; j < filas; j++){
        printf("\t%.4f",matdiagonal[i][j]);
}
printf("\n");
}
}


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void menu();
int validacion(char edad[100]);
void asignaciondetabla();
void asignaciondecoordenadas(FILE *archivo);
void MUESTRA();
void juego();
void felicidades();
void ubicasionesfinales();
void despedida(char nom[100]);
void registro(char nomb[100],char edad[100]);
void muestradepuntajes();
void comojugar();


int victorias;
int M[10][10];


int main()
{
    char nombre[100],e[100];
    int op;
    FILE *p;
    do{
        victorias=0;
        menu();
        op=0;
        scanf("%d",&op);
        fflush(stdin);
        system("cls");
        switch (op)
        {
            case 1:     printf("\t\t%c  %cCual es tu nombre? : ",207,168);
                        gets(nombre);
                        fflush(stdin);
                        printf("\n\t\t%c  %cCual es tu edad? : ",207,168);
                        gets(e);
                        fflush(stdin);
                        system("cls");
                        switch (validacion(e))
                        {
                            case 1: asignaciondetabla();
                                    asignaciondecoordenadas(p);
                                    juego();
                                    despedida(nombre);
                                    if (victorias!=10)
                                        ubicasionesfinales();
                                    if (victorias==10)
                                        felicidades();
                                    registro(nombre,e);
                                    break;
                            case 2: printf("\nIngresa una edad valida\n\n");
                                    system("pause");
                                    break;  
                            case 3: printf("\nEres menor de edad\nNo puedes jugar\n\n");
                                    system("pause");
                                    break; 
                            default:printf("\nerror");    
                        }
                        break;
            case 2:     printf("MANUAL\n");
                        comojugar();
                        break;
            case 3:     printf("HASTA LUEGO\n");
                        break;
            case 4:     printf("Aqui estan los puntajes mas recientes:\n\n");
                        muestradepuntajes();
                        break;
            default:    printf("\nIngrese algo valido\n");
        }
        system("cls");
    }while (op!=3);
}

void menu()
{
    printf("********************************************************************************");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°OOOOO°°°OOOO°°OOOOOO°OOOOOO°OO°°°°°OOOOOO°°OOOOO°°OO°OO°°OOOOOO°OOOOO°°°°°*");
    printf("*°°°°OO°°OO°OO°°OO°°°OO°°°°°OO°°°OO°°°°°OO°°°°°OO°°°°°°OO°OO°°°°OO°°°OO°°OO°°°°*");
    printf("*°°°°OOOOO°°OO°°OO°°°OO°°°°°OO°°°OO°°°°°OOOO°°°°°OOOO°°OOOOO°°°°OO°°°OOOO0°°°°°*");
    printf("*°°°°OO°°OO°OOOOOO°°°OO°°°°°OO°°°OO°°°°°OO°°°°°°°°°°OO°OO°OO°°°°OO°°°OO°°°°°°°°*");
    printf("*°°°°OOOOO°°OO°°OO°°°OO°°°°°OO°°°OOOOOO°OOOOOO°OOOOO°°°OO°OO°°OOOOOO°OO°°°°%c°°°*",169);
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°° °°°°°°°°°°°°°°°°°°°°°[1] JUGAR°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°   °°°°°°°°°°°°°°°°[2] COMO°JUGAR°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°  °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°° °°°°°°°°°°°°°°°°°°°°°[3] SALIR°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°° °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°° °°°°°°°°° °°°°°°°°°°°°°° °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°                          °°°°°°°°°°°°[4]PUNTAJES RECIENTES°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°                °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°            °°°°°°°°°°°°°°°°°°°°°°°°Erick Pichon Cuahtepitzi   2020°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("********************************************************************************");
}

int validacion(char edad[100])
{
  int valido=0; 
  valido=atoi(edad);
  if ((valido>=18)&&(valido<=150))
        valido=1;
  else{  
        if ((valido<=0)||(valido>=150))
        valido=2;
        else{
            if ((valido>0)&&(valido<18))
                valido=3;
        }
  }    
  return valido;      
}

void asignaciondetabla()
{
    int j,i;
    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
            M[i][j]=0;
    }
}

void asignaciondecoordenadas(FILE *archivo)
{
    int n,i,j,columna,fila;
    char car;
    srand(time(NULL));
    n=1+rand()%(10);
    if ((n<1)||(n>10))
        n=5;
    if (n==1)
        archivo=fopen("coordenadas1.txt","r");   
    if (n==2)
        archivo=fopen("coordenadas2.txt","r");
    if (n==3)
        archivo=fopen("coordenadas3.txt","r");
    if (n==4)
        archivo=fopen("coordenadas4.txt","r");
    if (n==5)
        archivo=fopen("coordenadas5.txt","r");
    if (n==6)
        archivo=fopen("coordenadas6.txt","r");
    if (n==7)
        archivo=fopen("coordenadas7.txt","r");
    if (n==8)
        archivo=fopen("coordenadas8.txt","r");
    if (n==9)
        archivo=fopen("coordenadas9.txt","r");
    if (n==10)
        archivo=fopen("coordenadas10.txt","r");
    if(archivo!=NULL)
    {
        for(i=0;i<10;i++)
        {
            fscanf(archivo,"%d%c%d",&fila,&car,&columna);
            for(j=0;j<3;j++)
            {
                M[fila][columna+j]=j+1;
            }
        }
    }
    else
        printf("No se pudo abrir el archivo");
    fclose(archivo);
}

void MUESTRA()
{
    int i,j;
    printf("\t\t    ");
    for(i=0;i<10;i++)
        printf("%d  ",i);
    printf("\n\n");
    for(i=0;i<10;i++)
    {
        printf("\t\t%d   ",i);
        for(j=0;j<10;j++)
        {
           if ((M[i][j]==0)||(M[i][j]==1)||(M[i][j]==2)||(M[i][j]==3))
                printf("%c  ",'~');
           if (M[i][j]==4)
                printf("%c  ",'*');
           if (M[i][j]==5)
                printf("%c  ",'X'); 
        }
        printf("\n");
    } 
}

void juego()
{
    
   int i=10,cora,corb; 
   printf("******************INGRESE LAS COORDENADAS PARA DERRIBAR A LOS BARCOS************\n");
   printf("Ingrese primero la fila seguido por la columna\n\n");
   printf("                         Este es el mar\n\n\n");
   MUESTRA();
   do
   {
      printf("\n\n\t\t\tOportunidades: %d\n\n",i);
      printf("DISPAROOOO  (numero,numero) : ") ; 
      cora=0;
      corb=0;
      scanf("%d,%d",&cora,&corb);
      fflush(stdin);
      if ((M[cora][corb]==1)||(M[cora][corb]==2)||(M[cora][corb]==3))
      {
           printf("\nDiste en el blanco!!!!!\n\nTe mereces un intento extra\n\n");
           system("pause");
           system("cls");
           switch(M[cora][corb])
           {
              case 1: if ((M[cora][corb+1]==4)&&(M[cora][corb+2]==4))
                        {
                            printf("\nY lograste derribar al barcoooooo!!!!!!!!\n\n");
                            victorias=victorias+1;
                        }  
                        break;
             case 2: if ((M[cora][corb-1]==4)&&(M[cora][corb+1]==4))
                        {
                            printf("\nY lograste derribar al barcoooooo!!!!!!!!\n\n");
                            victorias=victorias+1;
                        }  
                        break;
             case 3: if ((M[cora][corb-2]==4)&&(M[cora][corb-2]==4))
                        {
                            printf("\nY lograste derribar al barcoooooo!!!!!!!!\n\n");
                            victorias=victorias+1;
                        }  
                        break;
             default: printf("error");
            }
            M[cora][corb]=4;
            
                     
      }
      else 
      {
           switch(M[cora][corb])
           {
                case 4: printf("\nHaz dado las mismas coordenadas\n\nSe te restara una oportunidad\n\n");
                        break;
                case 0: printf("\n\n Haz fallado !!!!!\n\n");
                        M[cora][corb]=5;
                        break;
                case 5: printf("\nTiro fallido\n\nHaz dado las mismas coordenadas \n\n");
                        break;
           }
           system("pause");
           system("cls"); 
           i=i-1; 
      }
    printf("             Este es el mar\n\n\n");
    MUESTRA();  
   }while(i!=0&&victorias!=10);
   system("cls");
}

void despedida(char nom[100])
{
   if (victorias==0)
   {
        printf("\n\n\n\n\n\t\tGAME OVER");
        printf("\n\n\t\t%s No lograste derribar ningun barco\n\n\t\tPero no te desanimes, vuelve a intentarlo!!\n\n",nom);
   } 
   if ((victorias<=9)&&(victorias>0))
   {
        printf("\n\n\n\n\n\t\tGAME OVER");
        printf("\n\n\t\t%s Lograste derribar %d barcos\n\n",nom,victorias);
        if (victorias<5)
        {
            printf("\n\n\t\t%cPorque no lo vulves a intentar?\n\n\t\tANIMOOOOOOOOO!!!!!!!!!!\n\n",160);
        }
   } 
   if (victorias==10)
   {
        printf("\n\n\n\n\n\t\tSE TERMINOOO!!");
        printf("\n\n\t\t%s Lograste derribar todos los barcos completitos",nom);
        printf("\n\n\t\tTu nombre quedara grabado en este juego por siempre\n\n");
   }
   system("pause");
   system("cls");
}

void felicidades()
{
    printf("********************************************************************************");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°       °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°° °°°°°°° °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°   °°°°°   °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°     °°°     °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°       °       °°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°G R A C I A S   P O R   J U G A R°°°°°°°°°°°°°°°°°°°°°°*");
    printf("*°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°*");
    printf("********************************************************************************");
    system("pause");
    system("cls");
}

void ubicasionesfinales()
{
    int i,j;
    printf("ESTAS SON LAS UBICASIONES DE LOS BARCOS\n\nX-Tiro Fallido\n*-Tiro acertado\nB-Barco sin hundir\n\n");
    printf("\t\t    ");
    for(i=0;i<10;i++)
        printf("%d  ",i);
    printf("\n\n");
    for(i=0;i<10;i++)
    {
        printf("\t\t%d   ",i);
        for(j=0;j<10;j++)
        {
           if (M[i][j]==0)
                printf("%c  ",'~');
           if ((M[i][j]==1)||(M[i][j]==2)||(M[i][j]==3))
                printf("%c  ",'B');
           if (M[i][j]==4)
                printf("%c  ",'*');
           if (M[i][j]==5)
                printf("%c  ",'X'); 
        }
        printf("\n");
    } 
    printf("\n\n\tGRACIAS POR JUGAR\n\n");
    system("pause");
    system("cls");
}
void registro(char nom[100],char edad[100])
{
    FILE *p;
    p=fopen("registrofin.txt","a+");
    if (victorias==10)
        fprintf(p,"%s\t%s anios\tGANADOR\n",nom,edad);
    else 
        fprintf(p,"%s\t%s anios\tPERDEDOR\t%d barcos hundidos\n",nom,edad,victorias);
    fclose(p);
}

void muestradepuntajes()
{
    FILE *p;
    char car;
    p=fopen("registrofin.txt","r");
    do
       {
            car=getc(p);
            printf("%c",car);
       }while(car!=EOF);
    fclose(p); 
    printf("\n");
    system("pause");
    system("cls");
}

void comojugar()
{     
    printf("Antes de comenzar ingresa tu nombre y edad, si eres menor de edad no podras \njugar, ya que este juego es solo para grandes.\n\n") ;
    system("pause");
    system("cls");                                                                                            
    printf("Cuando se te muestre el mar, tendras que encontrar un total de >>10<< barcos\npara poder derribarlos, los cuales se encuentran escondidos en el mar y \nunicamente de forma horizontal. Esto barcos estan conformados de 3 casillas\nconsecutivas(de forma horizontal, por ejemplo: (6,6)(6,7)(6,8)) esparcidos \nen todo el mar.\n\n");
    MUESTRA();
    printf("Para poder derribarlos tendras que intentar adivinar su posicion y disparar,\ningresando primero el numero de la fila (del 0-9) seguido por una coma y\nterminando con el numero de la columna, al final presiona enter disparar.\n");
    printf("\n\t(numerode fila,numero de columna)\n\n");
    printf("Si tu disparo alcanzo a alguna parte del barco se vera refledo en el mar con\nun  '*' , y si logras encontar las otras dos partes de este lograras\nderribarlo. ");
    printf("Si tu disparo no encontro alguna parte del barco, se marcara en el\nmar con una 'X'.\n\n");
    printf("En la partida constaras de 10 OPORTUNIDADES las cuales disminuiran si fallas\nel disparo, o si ingresas una posicion en la que ya disparaste antes.\n\n");
    printf("Obtendras un disparo extra si logras hundir una parte del barco o todo este.\n\n");
    printf("El juego finalizara cuando agotes tus oportunidades o logres derribar a\ntodos los barcos, de esto depende si te llamo GANADOR o un losser.\n\n\n");
    
    system("pause");
}

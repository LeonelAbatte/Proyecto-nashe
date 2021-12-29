#include<stdio.h> //librerias
#include<stdlib.h>


void orden (int dia[], int cantdia[]); //prototipo de funcion

int main()
{
    
    int recorrido[32]={0}, automotor[37], dia[30], cantot[32]={0}, viajes[37]={0}, candia[30]={0}, chofer[15]={0}, canchof[15]={0}; //declaro e inicializo vectores
    int recor, chof, coche, cant, day, aux, aux2, min, tot, i, k; //declaro e inicializo variables
    int c32=32; //variable de valores que toma "i" en los ciclos for
    
    for (i=0; i<30; i++) //inicializo vector dia
    {
        dia[i]=i+1;
    }
    
    for (i=0; i<37; i++) //inicializo vector automotor
    {
        automotor[i]=i+1;
    }
    
    for (i=0; i<c32; i++) //se leen los recorridos
    {
        printf ("Ingrese recorrido %d: \n", i+1);
        scanf ("%d", &recorrido[i]);
    }
    
    tot=-1; //variable tot para busqueda e insercion
    
    printf("Ingrese automotor, chofer, recorrido, cantidad de boletos vendidos y dia (finaliza con chofer=000) : \n");
        scanf("%d%d%d%d", &coche, &chof, &recor, &cant);
        
    if (chof!=000)
    {
    
     do //leo informacion de los viajes, pongo como condicion que el dia este entre 1 y 30
     {
           scanf("%d", &day);
        
         if (day<1 || day>30)
         {
             printf ("Error, el dia debe estar entre 1 y 30 \n");
         }
     }
     while (day<1 || day>30);
    }
  
   
    while (chof!=000) //el ciclo termina cuando se ingresa un chofer codigo 000
    {
        i=0;
       
        while (chof!=chofer[i] && i<=tot)  //busqueda e insercion de choferes, se suma la cantidad de boletos vendidos por chofer
        {
            i=i+1;
        }
       
        if (i>tot) 
        {
            chofer[i]=chof;
            tot=tot+1;
            canchof[i]=canchof[i]+cant; 
        }
       
        else
        {
            canchof[i]=canchof[i]+cant;
        }
       
     for (i=0; i<c32; i++)  //busqueda en tabla por recorridos, se suma la cantidad de boletos por recorrido   
      {
            if (recorrido[i]==recor)
            {
                cantot[i]=cantot[i]+cant;
            }
      }
      
      for (i=0; i<37; i++)     //busqueda en tabla por automotor, se cuenta la cantidad de viajes que realizo cada uno
      {
            if (automotor[i]==coche)
            {
                viajes[i]=viajes[i]+1;
            }
      }
      
      for (i=0; i<30; i++)  //busqueda en tabla por dia, se suma la cantidad de boletos por dia   
      {
            if (dia[i]==day)
            {
                candia[i]=candia[i]+cant;
            }
      }      
      
       
        printf("Ingrese automotor, chofer, recorrido, cantidad de boletos vendidos y dia: (finaliza con chofer=000) \n");
        scanf("%d%d%d%d" , &coche, &chof, &recor, &cant);
        
    if (chof!=000)
    {
    
     do //leo informacion de los viajes, pongo como condicion que el dia este entre 1 y 30
     {
           scanf("%d", &day);
        
         if (day<1 || day>30)
         {
             printf ("Error, el dia debe estar entre 1 y 30 \n");
         }
     }
     while (day<1 || day>30);
    }
    
    }
    
    for (i=0; i<c32; i++) //imprimo cantidad de pasajeros por recorrido
    {
        printf ("En el recorrido %d viajaron %d pasajeros \n", recorrido[i], cantot[i]);
    }
    
    for (i=0; i<37; i++) //imprimo cantidad de viajes realizados por automotor
    {
        printf ("El automotor %d realizo %d viajes \n", automotor[i], viajes[i]);
    }
    
        orden(dia, candia); //invoco funcion orden
    
    
    for (i=0; i<15; i++) //busco minima cantidad de boletos vendidos por chofer
    {
        
        if (i==0)
        {
            min=canchof[i];
        }
        else
        {
            if (canchof[i]<min && canchof[i]!=0)
            {
               min=canchof[i];
            }
        }              
    }
    
    for (i=0; i<15; i++) //imprimo los choferes que vendieron la menor cantidad de boletos
    {
        if (canchof[i]==min)
        {
            printf ("El chofer %d vendio menos boletos \n", chofer[i]);
        }
    }
    
    system("pause");
    return(0);
    
}

void orden (int dia[], int candia[]) //funcion orden, ordena en forma ascendente e imprime la cantidad de boletos vendidos por dia
{
    int k, i, aux, aux2;
    
     for (k=0; k<29; k++)
    {
        for (i=0; i<29-k; i++)
        {
            if (candia[i]>candia[i+1])
            {
                aux=candia[i];
                candia[i]=candia[i+1];
                candia[i+1]=aux;
                aux2=dia[i];
                dia[i]=dia[i+1];
                dia[i+1]=aux2;
            }
        }
    }
    
     for (i=0; i<30; i++)
    {
        if (candia[i]!=0)
        {
        printf ("En el dia %d se vendiaron %d boletos \n", dia[i],candia[i]);
        }
    }
    
        return;  
}
    

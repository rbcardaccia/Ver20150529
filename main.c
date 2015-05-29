#include <stdio.h>
#include <stdlib.h>

#define MAX_STRLEN 25
#define Nragazze 4

struct s_elenco
{
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int cellulare;
    int eta;
    int indiceGradimento;
 };   

typedef struct s_elenco misterx; 

int main(int argc, char** argv) {
    FILE *evitare;
    FILE *ripetere;
    int i, j;
    
    misterx temp;
    misterx array[Nragazze];
    
    //inserimento dati ragazze
    for(i=0;i<Nragazze-1;i++){
        printf("Inserisci il nome della raggazza %d:", i+1);
        scanf("%s", array[i].nome);
        printf("Inserisci il cognome della raggazza %d:", i+1);
        scanf("%s", array[i].cognome);
        printf("Inserisci il cellulare della raggazza %d:", i+1);
        scanf("%d", &(array[i].cellulare));
        printf("Inserisci l' eta' della raggazza %d:", i+1);
        scanf("%d", &(array[i].eta));
        printf("Inserisci l' indice di gradimento della raggazza %d (da 0 a 4):", i+1);
        scanf("%d", &(array[i].indiceGradimento));
    }
        
        //ordinamento dati bubble-sort
    for(i=0;i<Nragazze-1;i++){
        for(j=0;j<Nragazze-1-i;i++){
            if((strcmp(array[j].cognome,array[j-1].cognome)>0))
            {
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
            }
        }
    }
    
     //apertura file   
    evitare = fopen("daevitare.csv", "wb");
    
     if (evitare == NULL)
        {
         printf("Apertura file non riuscita");
         exit(1);
        } 
    
    ripetere = fopen("daripetere.csv", "wb");
     
    if (ripetere == NULL)
        {
         printf("Apertura file non riuscita");
         exit(2);
        } 
      
    
    //inserimento dati dei record nei file
    for(i=0;i<Nragazze;i++){
        if(array[i].indiceGradimento < 3){
          fprintf("daevitare.csv", "%s, %s, %d, %d, %d", 
                array[i].nome,
                array[i].cognome,
                array[i].cellulare,
                array[i].eta,
                array[i].indiceGradimento);
        }
        else
        {
            fprintf("daripetere.csv", "%s, %s, %d, %d, %d", 
                array[i].nome,
                array[i].cognome,
                array[i].cellulare,
                array[i].eta,
                array[i].indiceGradimento);
        }
    }
      
    //chiusura file 
     ripetere= fclose("daevitare.csv");
     evitare= fclose("daripetere.csv");   
    
    
    return (EXIT_SUCCESS);
}


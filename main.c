#include<stdio.h>
 #include<stdlib.h>
 void red () {
  printf("\033[1;31m");
}//fonction qui affiche le text en rouge
void reset () {
  printf("\033[0m");
}//retour a la couleur par default


int main(int argc,char*argv[])
{
int i;
int p;//pointeur sur la case memoire
int nbp;//nombre de pages
int trouver;
int nb_def=0;//le nombre de défauts de page
int j;
int memory;//le nombre de case memoire
int ref_mem[20];
int case_mem[2];
printf("\n entrer le nombre de pages:\n");
scanf("%d",&nbp);                                       
printf("\n entrer les numeros de reference des pages memoire :\n");
  for(i=1;i<=nbp;i++)                                   
    scanf("%d",&ref_mem[i]);
memory=2;//par defaut on a une memoire physique de 2 page(ennoncé du tp )
   for(i=0;i<memory;i++)
    case_mem[i]= -1;//on initialise ici toutes le case a -1 pour dire quelle sont vides
p=0; //on initialise aussi un pointeur sur les casses memoire
red(); //ici on affiche le text ci dessous en rouge 
printf("\nref PM\t        cad1   cad2     DP   \n");//en rouge
    reset();
 for(i=1;i<=nbp;i++)
   {
     printf("%d\t\t",ref_mem[i]);
     trouver=0;  
     for(j=0;j<memory;j++)
     if(case_mem[j]==ref_mem[i]) //ici on compare le numero de reference de la page avec ceux qui existe en memoire
        {
         trouver=1; //on a trouver la page 
          for(j=0;j<memory;j++)
               printf("%d\t",case_mem[j]); 
              //on affiche le contenu des 2 cases memoire
            printf("already exist"); //on ne change rien car la valeur existe deja en memoire
        }
        else if (trouver==0)  //si notre page n'existe pas 
           {
            case_mem[p]=ref_mem[i];//on met le numero de notre page dans la casse memoire la plus ancienne
            p=(p+1)%memory;  //la ligne de code suivante utilise le principe de first in first out car elle localise la case la plus ancienne et pointe sur elle 
            //la prochine fois que (trouver==0) on changera la valeur d'une case differente
            nb_def++;         //bien sur on doit incrementer le compter de defaut de page
            for(j=0;j<memory;j++)
            printf("%d\t",case_mem[j]); //ici on doit signaler que nous avons decouvert un default de page 
            printf("dp+");            
            }
            
            printf("\n");
                
                
    }
red();              
printf("le nombre de defaut de page %d",nb_def);
return 0;
}


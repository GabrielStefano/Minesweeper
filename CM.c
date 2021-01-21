#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<conio.h>
int dificil[16][30],copia [16][30],i,j,k,p,cont=0,troll=0,testador=0,validador=0,a,b;
void Imprimir(int dificil[16][30],int caso);
void Verify(int dificil [16][30],int i,int j);
int VerifyReturn(int dificil [16][30],int i,int j);
int main(void){
    for (i=0;i<16;i++){
        for(j=0;j<30;j++){
                          dificil[i][j]=0;
        }
    }
    for (i=0;i<16;i++){
        printf("\n");
        printf("|");         
        for(j=0;j<30;j++){
             if(dificil[i][j]==0){
                  printf("o");
                  printf("|");
             }
        }
        
    }
    printf("\n");
    srand(time(NULL));
    for (k=0;k<99;k++){
        i= rand()%16;
        j= rand()%30;
        if(dificil[i][j]==0){
             dificil[i][j]=9;
        }
        else{
             k--;
             }
        i=0;
        j=0;
    }
    /*Imprimir();*/
    for(p=0;p<480;p++){
    printf("Entre com posição I de jogada:");
    scanf("%d",&i);
    printf("Entre com posição J de jogada:");  
    scanf("%d",&j);
    if((dificil[i][j])==9){
                          printf("BOMBA! You lose");
                          Imprimir(dificil,1);
                          system("pause");
                          return 0;                          
    }
                  
    else{
         cont=0;
         Verify(dificil,i,j);
         }         
    Imprimir(dificil,0);         
}
    
    
system("pause");
return 0;
}

void Imprimir (int dificil[16][30], int caso){
     if (caso==0){
         system("cls");
     }
     int i,j;
     for (i=0;i<16;i++){
         printf("\n");
         printf("|"); 
         for(j=0;j<30;j++){
                           if(((dificil[i][j])==0 || (dificil[i][j])==9)){
                                printf("o");
                                printf("|");
                           }
                           else if((dificil[i][j])==11){
                                printf(" |");
                           }
                           else if((dificil[i][j])!=0 && (dificil[i][j])!=9 && (dificil[i][j])!=11){
                                printf("%d",dificil[i][j]);
                                printf("|");
                           }
         }
     }
     printf("\n");     
}

void Verify(int dificil[16][30], int i, int j){
     cont=0;
     troll=0;
     validador=0;
     testador=0;
     while (testador<=1 && validador<=1){
     if(dificil[i-1][j]==9 && (i-1)>=0){
          cont++;
          testador++;
     }
     if (dificil[i-1][j+1]==9 && ((i-1)>=0 && (j+1)<30)){
          cont++;
          testador++;
     }
     if (dificil[i][j+1]==9 && (j+1)<30){
          cont++;
          testador++;
     }
     if(dificil[i+1][j+1]==9 && (i+1)<16 && (j+1)<30){
          cont++;
          testador++;
     }
     if(dificil[i+1][j]==9 && (i+1)<16){
          cont++;
          testador++;
     }
     if(dificil[i+1][j-1]==9 && (i+1)<16 && (j-1)>=0){
          cont++;
          testador++;
     }
     if(dificil[i][j-1]==9 && (j-1)>=0){
          cont++;
          testador++;
     }
     if(dificil[i-1][j-1]==9 && (j-1)>=0 && (i-1)>=0){
          cont++;
          testador++;
     }    
     if(cont!=0){
          dificil[i][j]=cont; 
          testador++;     
     }        
     else{
          dificil[i][j]=11;
          if (troll==0){
             a=i;
             b=j;
             troll++;
          }
               
          if(VerifyReturn(dificil,(i-1),j)==0){
               testador=0;
          }
          else if(VerifyReturn(dificil,(i-1),(j+1))==0){
               testador=0;
          }
          else if(VerifyReturn(dificil,(i),(j+1))){
               testador=0;
          } 
          else if(VerifyReturn(dificil,(i+1),(j+1))){
               testador=0;
          }
          else if(VerifyReturn(dificil,(i+1),(j))){
               testador=0;
          }
          else if(VerifyReturn(dificil,(i+1),(j-1))){
               testador=0;
          }
          else if(VerifyReturn(dificil,(i),(j-1))){
               testador=0;
          } 
          else if(VerifyReturn(dificil,(i-1),(j-1))){
               testador=0;
          }
          else{
               i=a;
               j=b;
               validador++;
               testador++;
               printf("%d", testador);
          }
    }
    }
    cont=0;
}
    
int VerifyReturn(int dificil [16][30],int i,int j){
     cont=0;
     if(dificil[i-1][j]==9 && (i-1)>=0){
          cont++;
     }
     if (dificil[i-1][j+1]==9 && ((i-1)>=0 && (j+1)<30)){
          cont++;
     }
     if (dificil[i][j+1]==9 && (j+1)<30){
          cont++;
     }
     if(dificil[i+1][j+1]==9 && (i+1)<16 && (j+1)<30){
          cont++;
     }
     if(dificil[i+1][j]==9 && (i+1)<16){
          cont++;
     }
     if(dificil[i+1][j-1]==9 && (i+1)<16 && (j-1)>=0){
          cont++;
     }
     if(dificil[i][j-1]==9 && (j-1)>=0){
          cont++;
     }
     if(dificil[i-1][j-1]==9 && (j-1)>=0 && (i-1)>=0){
          cont++;
     }    
     if(cont!=0){
          dificil[i][j]=cont;      
     }        
     else{
          dificil[i][j]=11;      
          return cont;
    }
    cont=0;
    return 1;
}


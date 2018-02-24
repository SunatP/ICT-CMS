/*
    THIS FILE CAN SORT ONLY
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <windows.h>

struct user{
    char ID[7];
    int IDs;
    char First[50];
    char Last[50];
    char Phone[11];
    char Email[50];
    char PWD[30];
    int Index;
};

int user_val;
struct user Alluser[100];
struct user sort;

void Listall(){
    // List all user in the struct
    int i;
    system("cls");
    for(i=0;i<user_val;i++){
        printf("[USER %2d]\n",i);
        printf("\tID: %s\n",Alluser[i].ID);
        printf("\tFirstname: %s\n",Alluser[i].First);
        printf("\tLastname: %s\n",Alluser[i].Last);
        printf("\tPhone number: %s\n",Alluser[i].Phone);
        printf("\tEmail: %s\n",Alluser[i].Email);
        printf("\tPassword: %s\n\n",Alluser[i].PWD);
    }
}

void Initialize(){
    FILE *userdata;
    int i;
    if ((userdata = fopen("D:\\Repositories\\Fundamental-Of-Programming-Lab\\Project\\udata.txt","r")) != NULL){
        printf("[SYSTEM] loaded!\n");
    }
    fscanf(userdata,"%d,\n",&user_val);
    for(i=0;i<user_val;i++){
        fscanf(userdata,"\n%8[^,],%49[^,],%49[^,],%15[^,],%49[^,],%29[^,],%d,%d",Alluser[i].ID,Alluser[i].First,Alluser[i].Last,Alluser[i].Phone,Alluser[i].Email,Alluser[i].PWD,&Alluser[i].IDs,&Alluser[i].Index);
    }
    printf("[SYSTEM] loaded %d user(s)!\n",user_val);
    fclose(userdata);
}

void insertionSort(struct user arr[], int n)
{
   int i, j;
   struct user key;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && -(strcmp(key.ID,arr[j].ID)))
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main(){
    printf("RUNN");
    Initialize();
    Listall();
}
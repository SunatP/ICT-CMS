/*
    THIS FILE CAN LOGIN ONLY
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

void updateID(){
    int IDs=0,i;
    for(i=0;i<user_val;i++){
        IDs = ((int)Alluser[i].ID[0]-48)*1000000 + ((int)Alluser[i].ID[1]-48)*100000 + ((int)Alluser[i].ID[2]-48)*10000 + ((int)Alluser[i].ID[3]-48)*1000 + ((int)Alluser[i].ID[4]-48)*100 + ((int)Alluser[i].ID[5]-48)*10 + ((int)Alluser[i].ID[6]-48);
        Alluser[i].IDs = IDs;
    }
        
}

void Updatedata(int user_index){
    int i,j;
    FILE *nuserdata;
    nuserdata = fopen("D:\\Repositories\\Fundamental-Of-Programming-Lab\\Project\\udata.txt","w");
    fprintf(nuserdata,"%d,\n",user_index+1);
    for(i=0;i<=user_index;i++){
        fprintf(nuserdata,"\n%s,%s,%s,%s,%s,%s,%d,%d",Alluser[i].ID,Alluser[i].First,Alluser[i].Last,Alluser[i].Phone,Alluser[i].Email,Alluser[i].PWD,Alluser[i].IDs,i);
        //fprintf(nuserdata,"\n");
    }
    printf("[SYSTEM] Updated!\n");
    fclose(nuserdata);
    user_val++;
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

void Login_home(){
    char loginID[7];
    char loginPWD[30];
    char login_temp;
    int printloop;
    int errorcode = 0;
    int loginID_idx = 0,loginPWD_idx = 0,isenterpwd = 0;
    int login_Response;
    do{
        system("cls");
        printf("Enter your ID: ");
        for(printloop = 0;printloop<loginID_idx;printloop++){
            printf("%c",loginID[printloop]);
        }
        while(!kbhit());
        login_temp = getch();
        if(login_temp >= '0' && login_temp <= '9'){
            if(loginID_idx <7){
                loginID[loginID_idx] = login_temp;
                loginID_idx++;
            }
        }
        if(login_temp == 8) {
            loginID_idx--;
            if(loginID_idx <= 0) loginID_idx = 0;
        }
        if(login_temp == 13 && loginID_idx == 7) {
            break;
        }
    }while(1);
    
    do{
        system("cls");
        printf("Your ID is: %s\n",loginID);
        printf("Enter your Password: ");
        for(printloop = 0;printloop<loginPWD_idx;printloop++){
            printf("*");
        }
        while(!kbhit());
        login_temp = getch();
        if(login_temp == 8){
            loginPWD_idx--;
            if(loginPWD_idx <= 0) loginPWD_idx = 0;
        }
        else{
            if(login_temp == 13) break;
            if(loginPWD_idx < 30){
                loginPWD[loginPWD_idx] = login_temp;
                loginPWD_idx++;
            }
        }
    }while(1);
    printf("%s||",loginID);
    errorcode = Login_Check(loginID,loginPWD);
    //Redirecting();
    if(errorcode < 0){
        if(errorcode == -1) {
            int retryptr = 1;
            char retryptr_temp;
            do{
                system("cls");
                printf("[ERROR] No relevant Data\n");
                retryptr == 1 ? printf("-->\t[1] Retry\n")      : printf("\t[1] Retry\n"); 
                retryptr == 2 ? printf("-->\t[2] Register\n")   : printf("\t[2] Register\n");
                retryptr == 0 ? printf("-->\t[0] Exit\n")       : printf("\t[0] Exit\n");
                while(!kbhit());
                retryptr_temp = getch();
                if(retryptr_temp == 13) break;
                if(retryptr_temp >= '0' && retryptr_temp <= '2'){
                    retryptr = (int) retryptr_temp - 48;
                }
            }while(1);
            if(retryptr == 1) Login_home();
            else if(retryptr == 2) Registeration();
        }
        else if(errorcode <= -2 && errorcode >= -3){
            int retryptr = 1;
            char retryptr_temp;
            do{
                system("cls");
                printf("[ERROR] Wrong Username or Password\n");
                retryptr == 1 ? printf("-->\t[1] Retry\n")      : printf("\t[1] Retry\n"); 
                retryptr == 2 ? printf("-->\t[2] Register\n")   : printf("\t[2] Register\n");
                retryptr == 0 ? printf("-->\t[0] Exit\n")       : printf("\t[0] Exit\n");
                while(!kbhit());
                retryptr_temp = getch();
                if(retryptr_temp == 13) break;
                if(retryptr_temp >= '0' && retryptr_temp <= '2'){
                    retryptr = (int) retryptr_temp - 48;
                }
            }while(1);
            if(retryptr == 1) Login_home();
            else if(retryptr == 2) Registeration();
        }
    }
    if (Alluser[errorcode].ID[0] == '0' && Alluser[errorcode].ID[1] == '0') admin_home();
    else user_home(errorcode);
}

int home() {
    int homeptr = 1;
    char homeptr_temp;
    do{
        system("cls");
        printf("WELCOME to ICT-CMS\n");
        homeptr == 1 ? printf("-->\t[1] Registeration\n")   : printf("\t[1] Registeration\n");
        homeptr == 2 ? printf("-->\t[2] Login\n")           : printf("\t[2] Login\n");
        homeptr == 0 ? printf("-->\t[0] Exit\n")            : printf("\t[0] Exit\n");
        while(!kbhit());
        homeptr_temp = getch();
        if(homeptr_temp == 13) break;
        if(homeptr_temp >= '0' && homeptr_temp <= '2'){
            homeptr = (int) homeptr_temp - 48;
        }
    }while(1);
    if(homeptr == 1) Registeration();
    else if(homeptr == 2) Login_home();
    return homeptr;
}

int main(){
    char homechoice;
    Initialize();
    while(1){
        homechoice = home();
        if(homechoice == 0) break;
    }
}
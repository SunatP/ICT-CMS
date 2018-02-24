#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// TODO : convert function to receive location to b used in edit data function

struct user{
    char ID[10];
    int IDs;
    char First[50];
    char Last[50];
    char Phone[16];
    char Email[50];
    char PWD[30];
    int Index;
};

int user_val;
struct user Alluser[100];
struct user sort;

// <-------------------------------------------------- REGISTERATION ----------------------------------------------------------------------->
void Regist_ID(int user_index){
    int z;
    Alluser[user_index].IDs = 0;
    printf("ID: ");
    scanf("%s",Alluser[user_index].ID);
    if(strlen(Alluser[user_index].ID) != 7) {
        printf("[ERROR] You can use only 7 digits for ID\n");
        printf("[Re-type] ");
        Regist_ID(user_index);
    }
    for(z=0;z<7;z++){
        Alluser[user_index].IDs = Alluser[user_index].IDs + Alluser[user_index].ID[z] * pow(10,(6-z));
    }
}

//              <-------------- NAME REGISTERATION ------------->
int Regist_isvalidName(char string[],int length){
    //isalpha(char ??) -- > use loop
    int i,result = 1;
    if((int) string[0] >= 97 && (int) string[0] <=122){
        return 2;
    }
    else {
        for(i=0;i<length;i++){
            if((int)string[i] < 65 || (int)string[i] > 172){
                result = 0;
                break;
            }
            else if((int)string[i] > 90 && (int)string[i] < 97){
                result = 0;
                break;
            }
        }
    }
    return result;
}

void Regist_Firstname(int user_index){
    int isvalid;
    printf("First name: ");
    scanf("%s",Alluser[user_index].First);
    isvalid = Regist_isvalidName(Alluser[user_index].First,strlen(Alluser[user_index].First));
    if(isvalid == 2) {
        //memset(Alluser[user_val].First, NULL, strlen(Alluser[user_val].First));
        printf("[ERROR] First character of First name should be \"CAPITAL\" letter\n");
        printf("[Re-type] ");
        Regist_Firstname(user_index);
    }
    else if(isvalid == 0){
        //memset(Alluser[user_val].First, NULL, strlen(Alluser[user_val].First));
        printf("[ERROR] Invalid First name\n");
        printf("[Re-type] ");
        Regist_Firstname(user_index);
    }
}

//Didn't check for error

void Regist_Lastname(int user_index){
    int isvalid;
    printf("Last name: ");
    scanf("%s",Alluser[user_index].Last);
    isvalid = Regist_isvalidName(Alluser[user_index].Last,strlen(Alluser[user_index].Last));
    if(isvalid == 2) {
        //memset(Alluser[user_val].Last, NULL, strlen(Alluser[user_val].Last));
        printf("[ERROR] First character of Last name should be \"CAPITAL\" letter\n");
        printf("[Re-type] ");
        Regist_Lastname(user_index);
    }
    else if(isvalid == 0){
        //memset(Alluser[user_val].Last, NULL, strlen(Alluser[user_val].Last));
        printf("[ERROR] Invalid Last name\n");
        printf("[Re-type] ");
        Regist_Lastname(user_index);
    }   
}
//              <-------------- PHONE REGISTERATION ------------->
int Regist_isvalidPhone(int user_index){
    if(strlen(Alluser[user_index].Phone) != 10){
        printf("[ERROR] You can use only 10 digits for phone number\n");
        printf("[Re-type] ");
        return 0;
    }
    else{
        int i,wrong = 1;
        for(i=0;i<10;i++){
            if((int)Alluser[user_index].Phone[i] < 48 || (int)Alluser[user_index].Phone[i] > 57){
                printf("%c %d",Alluser[user_index].Phone[i],(int)Alluser[user_index].Phone[i]);
                wrong = 0;
                printf("[ERROR] Invalid phone number\n");
                printf("[Re-type] ");
                break;
            }
        }
        return wrong;
    }
}

void Regist_Phone(int user_index){
    printf("Phone number: ");
    scanf("%s",Alluser[user_index].Phone);
    if(Regist_isvalidPhone(user_index) == 0) Regist_Phone(user_index);
    
}

// BUG when @ is the last char
//              <-------------- EMAIL REGISTERATION ------------->
void Regist_Email(int user_index){
    printf("Email: ");
    scanf("%s",Alluser[user_index].Email);
    if(strstr(Alluser[user_index].Email,"@.") != NULL){
        printf("[ERROR] Invalid Email\n");
        printf("[Re-type] ");
        Regist_Email(user_index);
    }
    else if(strstr(Alluser[user_index].Email,"@") == NULL){     //use strchr
        printf("[ERROR] Email must contain \'@\'\n");
        printf("[Re-type] ");
        Regist_Email(user_index);
    }
    else if(strstr(Alluser[user_index].Email,"@") != NULL){
        if(strstr(Alluser[user_index].Email,".") == NULL){
            printf("[ERROR] Invalid Email\n");
            printf("[Re-type] ");
            Regist_Email(user_index);
        }
    }
}

//              <-------------- PASSWORD REGISTERATION ------------->
int Regist_PWDconfirm(int user_index){
    char confPWD[30];
    printf("Confirmed Password: ");
    scanf("%s",confPWD);
    //printf("%d\n",strcmp(Alluser[user_val].PWD, confPWD));
    if(strcmp(Alluser[user_index].PWD, confPWD) != 0){
        printf("[ERROR] Password didn't match\n");
        printf("[Re-type] ");
        return 0;
    }
    else return 1;
}

void Regist_PWD(int user_index){
    printf("Password: ");
    scanf("%s",Alluser[user_index].PWD);
    //printf("%d",strlen(Alluser[user_val].PWD));
    if(strlen(Alluser[user_index].PWD) < 8){
        printf("[ERROR] You must use at least 8 characters for password\n");
        printf("[Re-type] ");
        Regist_PWD(user_index);
    }
    if(Regist_PWDconfirm(user_index) == 0){
        Regist_PWD(user_index);
    }
}

void Regist_Success(int user_index){
    printf("\n -- End of the Registration Process --\n\n");
    printf("Congratulation!! ");
    printf("%s,\n",Alluser[user_index].First);
    printf("Now you can login to the ICT Contact Management System and start to search for ICT faculty staffs' and friends' information.\n");
}

void Sortudata(){
    int i,j,k;
    for (i=0;i<user_val;i++){
        for(k=i+1;k<user_val;k++){
            if(Alluser[i].IDs>Alluser[k].IDs){
                for(j=user_val-1;j>0;j--){
                    if(Alluser[i].IDs>Alluser[j].IDs){
                        sort = Alluser[i];
                        Alluser[i] = Alluser[j];
                        Alluser[j] = sort;
                        break;
                    }
                }
            }
        }
    }
}

// <--------------------------------------------------   DATA INPUT   ----------------------------------------------------------------------->

void Initialize(){
    FILE *userdata;
    int i;
    if ((userdata = fopen("D:\\Repository\\Fundamental-Of-Programming-Lab\\Project\\udata.txt","r")) != NULL){
        printf("[SYSTEM] loaded!\n");
    }
    fscanf(userdata,"%d,\n",&user_val);
    for(i=0;i<user_val;i++){
        fscanf(userdata,"\n%15[^,],%49[^,],%49[^,],%15[^,],%49[^,],%29[^,],%d,%d",Alluser[i].ID,Alluser[i].First,Alluser[i].Last,Alluser[i].Phone,Alluser[i].Email,Alluser[i].PWD,&Alluser[i].IDs,&Alluser[i].Index);
    }
    printf("[SYSTEM] loaded %d user(s)!\n",user_val);
    fclose(userdata);
}

void Listall(){
    int i;
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

// <--------------------------------------------------   DATA OUTPUT   ----------------------------------------------------------------------->

void Updatedata(int user_index){
    int i;
    
    FILE *nuserdata;
    nuserdata = fopen("D:\\Repository\\Fundamental-Of-Programming-Lab\\Project\\udata.txt","w");
    fprintf(nuserdata,"%d,\n",user_index+1);
    for(i=0;i<=user_index;i++){
        fprintf(nuserdata,"\n%s,%s,%s,%s,%s,%s,%d,%d",Alluser[i].ID,Alluser[i].First,Alluser[i].Last,Alluser[i].Phone,Alluser[i].Email,Alluser[i].PWD,Alluser[i].IDs,i);
        //fprintf(nuserdata,"\n");
    }
    printf("[SYSTEM] Updated!\n");
    fclose(nuserdata);
    //Initialize();
}

void URegist(){
    printf(" [Registration]\n\n");
    printf("Please enter the following information\n");
    Regist_ID(user_val);
    Regist_Firstname(user_val);
    Regist_Lastname(user_val);
    Regist_Phone(user_val);
    Regist_Email(user_val);
    Regist_PWD(user_val);
    Regist_Success(user_val);
    Sortudata();
    Updatedata(user_val);
    //goto : MAINMENU;
}
// <-------------------------------------------------- ADMIN PART ------------------------------------------------------------------->

// <-------------------------------------------------- LOGIN ------------------------------------------------------------------->
int Login_Error(int err_code){
    int retry;
    printf("[ERROR] No Relevant User data\n");
    printf("Go to Registeration or Retry?\n");
    printf("\t[0] Registeration\n");
    printf("\t[1] Retry\n");
    while(1){
        printf("Your Choice: ");
        scanf("%d",&retry);
        if(retry == 1) break;
        else if(retry == 0) break;
        else printf("[ERROR] Wrong Choice.\n[Re-enter] ");
    }
    return retry;
}

void Login_Check(){
    char inID[10];
    int trash2;
    char inPWD[30];
    printf("Please enter yor ID: ");
    scanf("%s",inID);
    printf("Please enter your password: ");
    scanf("%s",&inPWD);
    int i,isvaliduser = 1;
    for(i = 0;i<user_val;i++){
        if(strcmp(Alluser[i].ID,inID) == 0){
            if(strcmp(Alluser[i].PWD,inPWD) == 0){
                if(Alluser[i].ID[0] == 0 && Alluser[i].ID[1] == 0){
                    printf("\n Now you are logged in as an admin in the system.");
                    printf("\n You can start using the following functions.");
                    //Home_Admin();
                }
                else{
                    printf("\n Now you are logged in as a student in the system.");
                    printf("\n You can start using the following functions.");
                    //Home_Student();
                }
                break;
            }
            else {
                isvaliduser = 2;
                printf("[ERROR] Wrong ID or Password\n");
                break;
            }
        }
        if(i == user_val-1) {
            if(isvaliduser != 2) isvaliduser =3;
        }
    }
    if(isvaliduser == 2 || isvaliduser == 3) {
        trash2 = Login_Error(isvaliduser);
    }
    if (trash2 == 1) Login_Check();
    else if(Login_Error(isvaliduser) == 0) URegist();

}

void Login(){
    printf(" [LOGIN Page]\n\n");
    Login_Check();
}


// <--------------------------------------------------   MAIN MENU   ----------------------------------------------------------------------->

int MMenu_routing (){
    int choice;
    printf("Enter the choice : ");
    scanf("%d",&choice);
    if(choice == 1) {
        URegist();
    }
    else if(choice == 2){
        Login();
    }
    else if(choice == 0) return 0;
    else if(choice != 0) MMenu_routing();
    return 1;
}

int MMenu(){
    int a;
    char Mchoice;
    printf("===============================\n");
    printf("ICT Contact Management Systems\n");
    printf("===============================\n");
    printf("[1] User Registration\n");
    printf("[2] Login\n");
    printf("[0] Exit\n");
    printf("-----------------------\n");
    a = MMenu_routing();
    return a;
}

int main(){
    int a;
    Initialize();
    do{
        a = MMenu();
    }while(a == 1);
} 
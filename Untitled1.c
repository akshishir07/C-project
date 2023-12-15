#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#define MAX_LENGTH 20
#define FILENAME "accounts.txt"
#define SECURITY_CODE "4859"


void gotoxy(int ,int );
int login();
void menu();
void add();
void view();
void search();
void modify();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    int rollno;
    char dept[20];
    char branch[20];
    char c1[20];
    char c2[20];
    char c3[20];
    char c4[20];
};


struct Account {
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

// Function to read account information from file
int readAccounts(struct Account accounts[], int maxAccounts) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    int count = 0;
    while (fscanf(file, "%s %s", accounts[count].username, accounts[count].password) == 2) {
        count++;
        if (count >= maxAccounts) {
            break;
        }
    }

    fclose(file);
    return count;
}

// Function to write account information to file
void writeAccounts(struct Account accounts[], int count) {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %s\n", accounts[i].username, accounts[i].password);
    }

    fclose(file);
}

// Function to reset password by username with security code verification
void resetPassword(struct Account accounts[], int count, char username[], char newPassword[], char securityCode[]) {
    if (strcmp(securityCode, SECURITY_CODE) != 0) {
            gotoxy(40,15);
        printf("Security code is incorrect. Password reset failed.\n");
        gotoxy(40,17);
        printf("Press any key to continue...");
        getch();
        login();
        return;

    }

    for (int i = 0; i < count; i++) {
        if (strcmp(username, accounts[i].username) == 0) {
            strcpy(accounts[i].password, newPassword);
            gotoxy(40,15);
            printf("Password reset successful for user %s.\n", username);
            gotoxy(40,17);
            printf("Press any key to continue...");
            getch();
            login();
return;
        }
    }
gotoxy(40,15);
    printf("Username not found.Password reset failed.Press any key to continue \n");
    gotoxy(40,17);
    printf("Press any key to continue...");
    getch();
    login();

}


int mainscreen(){

system("cls");
    gotoxy(40,8);
    printf("-| MINI STUDENT PORTAL |-");
    gotoxy(40,15);
    printf("Press any key to proceed");
    Beep(900,90);
    getch();
    menu();
    return;

}




int main()
{

login();


}





int login() {
    system("cls");
    struct Account accounts[MAX_LENGTH];
    int numAccounts = readAccounts(accounts, MAX_LENGTH);

    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
    char securityCode[MAX_LENGTH];
    char newPassword[MAX_LENGTH];
gotoxy(40,1);
    printf("Login using your credentials\n");
printf("\n");
    // Get username from the user


    gotoxy(40,3);
    printf("Enter username: ");
    scanf("%s", username);

    // Get password from the user

    printf("\n");
    gotoxy(40,5);
    printf("Enter password: ");
    scanf("%s", password);

    // Authenticate the user
    int authenticated = 0;
    for (int i = 0; i < numAccounts; i++) {
        if (strcmp(username, accounts[i].username) == 0 && strcmp(password, accounts[i].password) == 0) {
            authenticated = 1; // Authentication successful
            break;
        }
    }

    if (authenticated) {

        printf("Login successful. \n", username);

            system("cls");

            mainscreen();


    } else {
        gotoxy(40,7);
        printf("Login failed. Invalid username or password.\n");

        // Option to reset password with security code
        gotoxy(40,9);
        printf("Do you want to reset your password? (y/n): ");
        char resetOption;
        scanf(" %c", &resetOption);

        if (resetOption == 'y' || resetOption == 'Y') {
                gotoxy(40,11);
            printf("Enter security code for password reset: ");
            scanf("%s", securityCode);
gotoxy(40,13);
            // Get a new password
            printf("Enter a new password: ");
            scanf("%s", newPassword);

            // Reset password
            resetPassword(accounts, numAccounts, username, newPassword, securityCode);

            // Update accounts file
            writeAccounts(accounts, numAccounts);



        }else{

        login();

        }
    }

}


void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("-MINI STUDENT PORTAL-");
    gotoxy(10,5);
    printf("Enter the  serial  number to perform the  following task: ");
    gotoxy(10,7);
    printf("1 : Add Student Info");
    gotoxy(10,8);
    printf("2 : View Student Info.");
    gotoxy(10,9);
    printf("3 : Search for Students");
    gotoxy(10,10);
    printf("4 : Edit Student Info.");
    gotoxy(10,11);
    printf("5 : Delete Student");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 5:
        deleterec();
        break;

    case 6:
        exit(1);
        break;

    default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    int noc;
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD STUDENT INFO:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");
//        gets(std.name);///???
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Tuition Fee for this semester : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter ID No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Dept. : ");
//        gets(std.dept);///???
        gets(std.dept);
        gotoxy(10,11);
       // printf("Enter Branch : ");
       // printf("Enter Semester : ");
        //gets(std.branch);
//        gotoxy(10,12);
//        printf("Enter Father's Name : ");
//        gets(std.fathername);

printf("Enter the  name of the courses for registration :              (Max. 4 per Semester)\n");

fflush(stdin);
//getch();
printf("Name of course no. 1: ");
gets(std.c1);
//fflush(stdin);
printf("Name of course no. 2: ");
gets(std.c2);
printf("Name of course no. 3: ");
gets(std.c3);
printf("Name of course no. 4: ");
gets(std.c4);
//fflush(stdin);
printf("\n\n");
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,15);
        printf("\n\n");
        printf("\n\n");
        printf(" Press 'Y' to add another student details or Press 'N' to exit ");
        fflush(stdin);
//        another = getch();///???
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Student       Tuition Fee   ID No          Department           ");
    gotoxy(10,6);
    printf("-------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-15s%-19d%-15s%-15s",i,std.name,std.mobile,std.rollno,std.dept,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Tuition fee due : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,11);
            printf("Course No.1: %s",std.c1);
            gotoxy(10,12);
            printf("Course No.2: %s",std.c2);
            gotoxy(10,13);
            printf("Course No.3: %s",std.c3);
            gotoxy(10,14);
            printf("Course No.4: %s",std.c4);


        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,7);
            printf("Enter name: ");
            gets(std.name);
            gotoxy(10,8);
            printf("Enter Tuition fee : ");
            gets(std.mobile);
            gotoxy(10,9);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            gotoxy(10,10);
            printf("Enter Department : ");
            fflush(stdin);
            gets(std.dept);
            gotoxy(10,11);
            printf("Name of course no. 1: ");
            gets(std.c1);
           //fflush(stdin);
           gotoxy(10,12);
            printf("Name of course no. 2: ");
            gets(std.c2);
            gotoxy(10,13);
            printf("Name of course no. 3: ");
            gets(std.c3);
            gotoxy(10,14);
            printf("Name of course no. 4: ");
            gets(std.c4);
            //printf("Enter Branch : ");
            //fflush(stdin);
            //gets(std.branch);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void gotoxy(int x,int y)
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

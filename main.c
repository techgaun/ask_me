/***************************************************************************
*                Ask Me Telephone Directory System V. 1.0.0                *
*           Coded in C language as fun work in spare times                 *
*   By: Samar Dhwoj Acharya aka sam207 aka Deadly Ghos7       *
*        URLS: www.sampctricks.blogspot.com, www.smshell.hostei.com        *
*                           & http://nepali.netau.net                      *
*                 E-mail: samar_acharya[at]hotmail[dot]com                 *
*                  For Those Who Want To Learn By Samar                    *
***************************************************************************/

/*
Information:
Application Name: Ask Me telephone directory system
Version: 1.0.0
Platform: Win16/Win32
LICENSE: GNU GPL LICENSE
Compiler: Turbo C V. 3.0
Editor: Notepad++ v. 4.0
Description: Very simple telephone directory system with simple functionalities
Developer: Samar Dhwoj Acharya
Date: 2066/03/16 [From 11:34 A.M. to 1:56 P.M.]
Note:
I haven't done much validations and haven't made much effective functions.
A single person [& who doesn't like C] can't remain hanging on just C programming.
Anyway you people may improve various such aspects after viewing the APP.
URL: http://www.sampctricks.blogspot.com
http://www.nepsecvulns.blogspot.com
http://www.nepali.netau.net
http://www.smshell.hostei.com
you can use this source to make enhanced telephone directory system. It is just a basic program
*/


//inclusion of necessary library files for the program
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



//definition for TRUE & FALSE that I'll be returning during validation
#define TRUE 1
#define FALSE 0


//now structure for the phonebook tele_rec
struct phonebook
       {
          char name[30];
          char addr[30];
          char num[10];
       }tele_rec;


// file pointers to the FILEs I am gonna open
FILE *fp;

// arrays of various menus and submenus in the program.
char *main_menu[] = {
                  "[ 1 ] --> List all phone numbers",
                  "[ 2 ] --> Add new phone number",
                  "[ 3 ] --> Edit existing number",
                  "[ 4 ] --> Delete phone number",
                  "[ 5 ] --> Create backup file",
                  "[ 6 ] --> Credits/Developers",
                  "[ 7 ] --> Exit"
                  };

//======================Function Prototypes======================\\
void startup();
void menu(char **menuItems);
void credits();
void byebye();
void viewAll();
void addNew();
void edit();
int checkName(char *name);
void deleteNum();
void backup();
int validNum(char *number);

//========================Main Function==========================\\

void main()
{
     fp = fopen("telefone.dat","ab+");
     if (fp == NULL)
     {
            printf("Error opening file");
            printf("Please check for proper privilege");
            getch();
            exit(1);
     }
     else
     {
		 short int choice;
         startup();
		 getch();
         while (1)
         {
            menu(main_menu);
			scanf("%d",&choice);
			switch (choice)
			{
				case 1:
					viewAll();
					break;
					
				case 2:
					addNew();
					break;
				
				case 3:
					edit();
					break;
					
				case 4:
					deleteNum();
					break;
					
				case 5:
					backup();
					break;
					
				case 6:
					credits();
					break;
					
				case 7:
					byebye();
					break;
				
				default:
					printf("\t\tWrong choice");
			
			}        
         }
         
     }

}


//========================Startup function========================\\
void startup()
{
     register int i;
     printf("\t\t     _        _      __  __\n");
     printf("\t\t    / \\   ___| | __ |  \\/  | ___\n");
     printf("\t\t   / _ \\ / __| |/ / | |\\/| |/ _ \\\n");
     printf("\t\t  / ___ \\\\__ \\   <  | |  | |  __/\n");
     printf("\t\t /_/   \\_\\___/_|\\_\\ |_|  |_|\\___|\n\n");
     printf("\tASK ME TELEPHONE DIRECTORY SYSTEM");
     //system("color fc");
     printf("\n\tBy: Samar From Nepal");
     printf("\n\n\tLoading...");
     
     for (i = 0; i < 50; i++)
     {
         printf("°");
         delay(20);
     }
     printf("\n\n\tPress ENTER to continue...");
       
     
}

//======================Function for showing menuItems================\\
void menu(char **menuItems)
{
	 register int i;
	 short int a = 22, b = 10;
     clrscr();
     gotoxy(9,1);
     cprintf("**************************************************************");
     gotoxy(9,2);
     cprintf("*                    < WELCOME >                             *");
     gotoxy(9,3);
     cprintf("*           < ASK ME TELEPHONE DIRECTORY SYSTEM >            *");
     gotoxy(9,4);
     cprintf("*           < NEPAL : Never Ends Peace And Love >            *");
     gotoxy(9,5);
     cprintf("*          < By Leet Hell Hacker Samar Acharya   >           *");
	 gotoxy(9,6);
	 cprintf("**************************************************************");
     for (i = 0; i < 7; i++)
	 {
		gotoxy(a,b++);
		printf(menuItems[i]);
	 }
	 b = b + 3;
	 gotoxy(a,b);
	 printf("Enter your choice: ");
}

//===========================Credits Function====================\\
//case 6 will call this function and display the credits or developer of the app
void credits()
{
	 clrscr();
	 gotoxy(14,4);
     printf("######################################################");
     gotoxy(14,5);
     printf("#     ASK ME TELEPHONE DIRECTORY SYSTEM V.1.0.0      #");
     gotoxy(14,6);
     printf("#      (C)oded By LEET HELL HaXXoR From Nepal        #");
     gotoxy(14,7);
     printf("#             Handles: Samar Dhwoj Acharya           #");
     gotoxy(14,8);
     printf("#                      aka 5ilik0n                   #");
     gotoxy(14,9);
     printf("#                      aka sam207                    #");
     gotoxy(14,10);
     printf("#                      aka Nepali Hacker             #");
     gotoxy(14,11);
     printf("#      E-mail: samar_acharya[at]hotmail[dot]com      #");
     gotoxy(14,12);
     printf("#      URLs: http://www.sampctricks.blogspot.com     #");
     gotoxy(14,13);
     printf("#            http://www.smshell.hostei.com           #");
     gotoxy(14,14);
     printf("#            http://www.nepali.netau.net             #");
     gotoxy(14,15);
     printf("######################################################");
	 
	 
	 getch();

}

//===================Say ByeBye function==========================\\
void byebye()
{
	 credits();
	 clrscr();
	 gotoxy(18,10);
	 printf("Thanks for using ASK ME telephone System");
	 gotoxy(18,12);
	 printf("Visit http://www.sampctricks.blogspot.com");
	 fclose(fp);
	 getch();
	 exit(0);

}

//====================View Numbers function=========================\\
void viewAll()
{
     rewind(fp);
     clrscr();
     printf("\n\t\t=>List of all the available telephone numbers<=");
     printf("\n\t\tName\t\t  Address\t\t   Number");
     printf("\n");
     while (fread(&tele_rec,sizeof(tele_rec),1,fp) == 1)
     {
           printf("\n\t\t%-20s%-20s%-10s",tele_rec.name,tele_rec.addr,tele_rec.num);
     }
     gotoxy(24,24);
     printf("Press ENTER key to return to MAIN MENU");
     getch();
}

//===================Add new num function============================\\
void addNew()
{
     int i = 6;
     clrscr();
     rewind(fp);
     gotoxy(16,2);
     printf("\tADD NEW PHONEBOOK ENTRY");
     gotoxy(16,4);
     printf("\t\tEnter the name: ");
     fflush(stdin);
     gets(tele_rec.name);
     gotoxy(16,5);
     printf("\t Enter the address: ");
     fflush(stdin);
     gets(tele_rec.addr);
     do
     {
     gotoxy(16,i++);
     printf("\t Enter the valid number: ");
     fflush(stdin);
     gets(tele_rec.num);
     }while (validNum(tele_rec.num) == FALSE);
     fseek(fp,0,SEEK_END);
     fwrite(&tele_rec,sizeof(tele_rec),1,fp);
     gotoxy(16,i+2);     
     printf("\t Member Added Successfully");
     gotoxy(24,24);
     printf("Press ENTER key to return to MAIN MENU");
     getch();
}

//====================Edit number function=========================\\
void edit()
{
     int i = 8;
     char tempname[30];
     clrscr();
     gotoxy(20,2);
     printf("Modify Phonebook Entry");
     gotoxy(20,4);
     printf("Enter the name to modify: ");
     fflush(stdin);
     gets(tempname);
     if (checkName(tempname) == FALSE)
     {
         gotoxy(20,6);
         printf("No such name found in database");                         
     }
     else
     {
         FILE *temp;
         struct phonebook temp_rec;
         temp = fopen("temp.dat","wb");
         rewind(fp);
         clrscr();
         while (fread(&tele_rec,sizeof(tele_rec),1,fp) == 1)
         {
               if (strcmp(tele_rec.name,tempname))
                  fwrite(&tele_rec,sizeof(tele_rec),1,temp);
               else
                   temp_rec = tele_rec;
         }
         gotoxy(20,2);
         printf("Modify Phonebook Entry");
         gotoxy(20,4);
         printf("Now enter the new details\n");
         gotoxy(20,6);
         printf("Enter new name: ");
         fflush(stdin);
         gets(temp_rec.name);
         gotoxy(20,7);
         printf("Enter new address: ");
         fflush(stdin);
         gets(temp_rec.addr);
         do
         {
         gotoxy(20,i++);
         printf("Enter new number: ");
         fflush(stdin);
         gets(temp_rec.num);
         }while (validNum(temp_rec.num) == FALSE);
         fwrite(&temp_rec,sizeof(temp_rec),1,temp);
         fclose(temp);
         fclose(fp);
         remove("telefone.dat");
         rename("temp.dat","telefone.dat");
         fp = fopen("telefone.dat","ab+");
         gotoxy(20,i + 2);
         printf("Phone entry successfully edited");
         
     }
     gotoxy(24,24);
     printf("Press ENTER key to return to MAIN MENU");
     getch();
}

//===================Check number=======================\\
int checkName(char *checkname)
{
     rewind(fp);
     while (fread(&tele_rec,sizeof(tele_rec),1,fp) == 1)
     {
           if (!stricmp(checkname,tele_rec.name))
              return TRUE;
  
     }
     return FALSE;
     
}

//====================Delete number====================\\
void deleteNum()
{
     char temp_name[30];
     clrscr();
     gotoxy(20,2);
     printf("Delete Phonebook Entry");
     gotoxy(20,4);
     printf("Enter the name to delete: ");
     fflush(stdin);
     gets(temp_name);
     if (checkName(temp_name) == FALSE)
     {
         gotoxy(20,6);
         printf("No such name found in database");                         
     }
     else
     {
         FILE *temp;
         temp = fopen("temp.dat","wb");
         rewind(fp);
         clrscr();
         while (fread(&tele_rec,sizeof(tele_rec),1,fp) == 1)
         {
               if (strcmp(tele_rec.name,temp_name))
                  fwrite(&tele_rec,sizeof(tele_rec),1,temp);

         }
         fclose(temp);
         fclose(fp);
         remove("telefone.dat");
         rename("temp.dat","telefone.dat");
         fp = fopen("telefone.dat","ab+");
         gotoxy(20,6);
         printf("Phone entry successfully deleted");
         
     }
     gotoxy(24,24);
     printf("Press ENTER key to return to MAIN MENU");
     getch();
     
}

//===================Backup DB function=================\\
void backup()
{
     FILE *temp;
     mkdir("backup");
     temp = fopen("backup/telefone.dat","wb");
     while (fread(&tele_rec,sizeof(tele_rec),1,fp))
     {
           fwrite(&tele_rec,sizeof(tele_rec),1,temp);
     }
     gotoxy(20,21);
     printf("Database backup successful");
     gotoxy(24,24);
     printf("Press ENTER key to return to MAIN MENU");
     getch();
}

//===================Validate number=====================\\
int validNum(char *number)
{
    int len;
    int i;
    len = strlen(number);
    if (len >=9 &&len <= 14)
    {
       for (i = 0; i < len; i++)
       {
           if (!isdigit(number[i]))
              {
               return FALSE;
              }
       }   
       return TRUE;
    }
    else
        return FALSE;
    
}

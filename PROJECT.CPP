#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
void interface()                     //Interface
{
int i;
gotoxy(5,2);
printf("****************************************************");
gotoxy(5,18);
printf("****************************************************");
for(i=0;i<16;i++)
{
gotoxy(5,2+i);
printf("*");
}
for(i=0;i<16;i++)
{
gotoxy(56,2+i);
printf("*");
}
}
void load(int n)
{
gotoxy(25,9);
printf("Loading......");
gotoxy(12,10);
for(int i=0;i<34;i++)
{
printf("%c",177);
delay(n);
}
}


void add()
{
gotoxy(27,4);
printf("INSERTING INFORMATION");
  gotoxy(16,8);
  printf("ENTER NAME: ");
  char ar[20],br[20];
  fflush(stdin);
gets(ar);
fflush(stdin);
  gotoxy(16,10);
  printf("ENTER MOBILE NUMBER: ");
  fflush(stdin);
  gets(br);
  //cin.getline(br,11);
int i=0;
FILE *fp,*fw;
fp=fopen("name.txt","a");
fw=fopen("class.txt","a");
if(fp==NULL || fw==NULL)
{
gotoxy(20,15);
printf("PROBLEM WITH OPENING FILE");
gotoxy(20,18);
printf("TRY AGAIN AFTER SOME TIME");
return;
}
while(ar[i]!=NULL)
{
fputc(ar[i],fp);
i++;
}
i=0;
while(br[i]!=NULL)
{
fputc(br[i],fw);
i++;
}
fputc('\n',fp);
fputc('\n',fw);
fflush(stdin);
fcloseall();
}

void show()
{
int i=0,j=0;
char ch,cl;
FILE *fp,*fw;
fp=fopen("name.txt","r");
fw=fopen("class.txt","r");
if(fp==NULL || fw==NULL)
{
gotoxy(20,6);
printf("NO DATA INSERTED");
gotoxy(14,12);
printf("TRY AGAIN AFTER INSERTING DATA");
getch();
return;
}
while(ch!=EOF)
{
if(i==0)
{
gotoxy(12,8);
printf("NAME:");
++i;
j=0;
}
ch=fgetc(fp);

printf("%c",ch);
if(ch=='\n')
{
if(j==0)
{
gotoxy(12,12);
printf("MOBILE NUMBER:");
i=0;
fflush(stdin);
while(cl!=EOF)
{
cl=fgetc(fw);
printf("%c",cl);
if(cl=='\n')
{
getch();
gotoxy(20,12);
printf("Press <enter> to see next....");
clrscr();
interface();
load(10);
clrscr();
interface();
break;
}
}
}
}
}
}


void welcome()
{
gotoxy(10,6);
printf("WELCOME TO CONTACT INFORMATION MANAGEMENT");
gotoxy(16,10);
printf("THANKS FOR USING OUR SOFTWARE");
gotoxy(16,13);
printf("DEVELOPED BY:-Utkarsh Tiwari");
gotoxy(16,16);
printf("PRESS <ENTER> TO CONTINUE.....");
getch();
}







void main()
{
clrscr();
interface();
load(100);
clrscr();
interface();
welcome();
clrscr();
int i;
while(1)
{
clrscr();
interface();
gotoxy(20,6);
printf("1.ADD RECIPIENTS");
gotoxy(20,8);
printf("2.SHOW DATA INSERTED ");
gotoxy(20,10);
printf("3.DELETE ALL DATA ");
gotoxy(20,12);
printf("4.EXIT ");
gotoxy(8,14);
printf("ENTER CHOICE:");
scanf("%d",&i);
switch(i)
{
case 1:
clrscr();
fflush(stdin);
interface();
fflush(stdin);
add();
break;
case 2:
clrscr();
interface();
 load(10);
 clrscr();
 interface();
show();
break;
case 3:
clrscr();
interface();
load(30);
clrscr();
interface();
gotoxy(20,10);

if(remove("name.txt")==0)
{
if(remove("class.txt")==0)
 printf("....DATA DELETED SUCCESSFULY....");
 }
 else
printf("....NO DATA PRESENT....");
getch();
break;

case 4:
exit(0);
default:
printf("WRONG CHOICE");
}
}
//getch();
}
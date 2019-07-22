/*
Program Title : Student's Reportcard Maker
Student Name: Yash Jain
Class : XII-A
Roll No:42
*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<bios.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<ctype.h>

int menu(int,int,int,char a[25],char b[25],char c[25],char d[25],char e[25],char sl1[25],char sl2[25],char title[40],char under[2]);
void main_menu();

void student_menu();
void updown();
void mark_menu();
int records=0;

struct s_date
{
int dd,mm,yyyy;
};

//DEFINING OF Stuctures
struct student
{
char address[30];
char fname[30];
int redgno;
s_date dob;
char clas[5];
char name[20];
int sub1,sub2,sub3,sub4,sub5,total;
float avg,pre;
char div[10];
char st_code[10];
}s[10];


void message(int x,int y,int lines,char a[50],char b[50],char c[50],
			 char d[50],char e[50],char f[10],int back)
{
int l,i,j;
char f1[10];

l=strlen(a);
if(l<strlen(b))
 l=strlen(b);
if(l<strlen(c))
 l=strlen(c);
if(l<strlen(d))
 l=strlen(d);
if(l<strlen(e))
 l=strlen(e);
if(l<strlen(f))
 l=strlen(f);
l+=4;

textbackground(back);
for(i=1;i<l+2;i++)
for(j=1;j<lines+4;j++)
 {
 gotoxy(i+x,j+y);
 cputs(" ");
 }

gotoxy(x,y);
cputs("É");
for(i=x+1;i<l+x+1;i++)
 {
 gotoxy(i,y);
 cputs("Í");
 gotoxy(i,y+lines+3);
 cputs("Í");
 }
gotoxy(x+1+l,y);
cputs("»");

for(i=y+1;i<lines+4+y;i++)
 {
 gotoxy(x,i);
 cputs("º");
 gotoxy(x+l+1,i);
 cputs("º");
 }
gotoxy(x,y+lines+3);
cputs("È");
gotoxy(x+l+1,y+lines+3);
cputs("¼");

j=l-strlen(a);
j=j/2;
gotoxy(j+x+1,++y);
cputs(a);
j=l-strlen(b);
j=j/2;
gotoxy(x+j+1,y+1);
cputs(b);
j=l-strlen(c);
j=j/2;
gotoxy(x+j+1,2+y);
cputs(c);
j=l-strlen(d);
j=j/2;
gotoxy(x+j+1,3+y);
cputs(d);
j=l-strlen(e);
j=j/2;
gotoxy(x+j+1,4+y);
cputs(e);
j=l-strlen(f)-3;
j=j/2;
gotoxy(x+j+1,y+lines+1);
strcat(f1," ");
strcat(f1,f);
strcat(f1," ");
textbackground(BLACK);
cputs(f1);
textcolor(BLACK);
for(i=0;i<lines+3;i++)
 {
 gotoxy(x+l+2,i+y);
 cputs("Û");
 }
for(i=1;i<l+3;i++)
 {
 gotoxy(x+i,y+lines+3);
 cputs("ß");
 }
}


/****************************Function To Add Data***************************/
void add()
 {
 textbackground(16);
 textcolor(7);
 int i=0;
 char ch='y';
 char fn[20];
 fstream file;
 do
  {
  records++;
  ss:
  clrscr();
  int st;
  int t_redg,mark;
  gotoxy(20,2);
  cout<<"Students Data Collector";
  gotoxy(20,3);
  cout<<"=======================";
  gotoxy(19,7);
  cout<<"Enter The Following";
  gotoxy(19,8);
  cout<<"Registaration No:";gotoxy(36,8);cin>>t_redg;
  s[i].redgno=t_redg;
  gotoxy(20,10);
  cout<<"Name          :";gotoxy(35,10);gets(s[i].name);
  gotoxy(20,12);
  cout<<"Address       :";gotoxy(35,12);gets(s[i].address);
  gotoxy(20,14);
  cout<<"Father's Name :";gotoxy(35,14);gets(s[i].fname);
  gotoxy(20,16);
  cout<<"Class         :";gotoxy(35,16);gets(s[i].clas);
  gotoxy(20,18);
  cout<<"Date Of Birth :DD MM YYYY";gotoxy(35,18);
  cin>>s[i].dob.dd>>s[i].dob.mm>>s[i].dob.yyyy;

  sa:
  clrscr();
  gotoxy(20,2);
  cout<<"Student Data Entry Form";
  gotoxy(20,3);
  cout<<"=======================";
  gotoxy(10,7);
  cout<<"Enter The Stream Code:\n1.Science Stream\n2.Commerce Streame";
  gotoxy(32,7);
  cin>>st;
  switch(st)
   {
   case 1:strcpy(s[i].st_code,"Science");
   break;
   case 2:strcpy(s[i].st_code,"Commerce");
   break;
   default:cout<<"\n\t\t\tInvalid Type.\n\nDo you want to continue?(Y/N)...";
	   cin>>ch;
	   if (ch=='y'||ch=='Y')
	   {
	   clrscr();
	   goto sa;
	   }
	   else add();
   }

  clrscr();
  gotoxy(20,2);
  cout<<"Student Data Entry Form";
  gotoxy(20,3);
  cout<<"=======================";
  gotoxy(10,5);
  cout<<"Enter The Following Marks";
  gotoxy(10,10);
  cout<<"Sub1(Eng/Eng):";                                           //Sub 1
  gotoxy(30,10);
  cin>>s[i].sub1;
  gotoxy(10,12);
  cout<<"Sub2(Math/A/C):";                                          //Sub 2
  gotoxy(30,12);
  cin>>s[i].sub2;
  gotoxy(10,14);
  cout<<"Sub3(Phy/Eco):";					    //Sub 3
  gotoxy(30,14);
  cin>>s[i].sub3;
  gotoxy(10,16);
  cout<<"Sub4(Chem/B.st):";					     //Sub 4
  gotoxy(30,16);
  cin>>s[i].sub4;
  gotoxy(10,18);						     //Sub 5
  cout<<"Sub5(Bio/Comp):";
  gotoxy(30,18);
  cin>>s[i].sub5;
  s[i].total=s[i].sub1+s[i].sub2+s[i].sub3+s[i].sub4+s[i].sub5;
  if((s[i].sub1<33)||(s[i].sub2<33)||(s[i].sub3<33)||(s[i].sub4<33)||(s[i].sub5<33))
  strcpy(s[i].div,"Fail");
  else if(s[i].total>=375)
  strcpy(s[i].div,"Distintion");
  else if((s[i].total>=300)&&(s[i].total<375))
  strcpy(s[i].div,"First Class");
  else if((s[i].total>=250)&&(s[i].total<300))
  strcpy(s[i].div,"Second Class");
  else if(s[i].total<165)
  strcpy(s[i].div,"Fail");

  strcat(fn,s[i].name);
  strcat(fn,".txt");
  file.open(fn,ios::out);
   if(!file)
    {
    gotoxy(25,79);
    cout<<".";
    }
  file<<"                            Report Card Of "<<s[i].name
      <<"\nRegistration Number:"<<s[i].redgno<<"\nClass:"<<s[i].clas
      <<"\nAddress:"<<s[i].address<<"\nFather's Name:"<<s[i].fname
      <<"\nDate Of Birth:"<<s[i].dob.dd<<"-"<<s[i].dob.mm<<"-"<<s[i].dob.yyyy
      <<"\nStream:"<<s[i].st_code<<"\n\n\
-------------------------------------------------------------------------------\
	\nSubject Marks\n-------------\nSubject 1 :"
      <<s[i].sub1<<"\nSubject 2 :"<<s[i].sub2<<"\nSubject 3 :"<<s[i].sub3
      <<"\nSubject 4 :"<<s[i].sub4<<"\nSubject 5 :"<<s[i].sub5
      <<"\nTotal     :"<<s[i].total<<"\nGrade     :"<<s[i].div;
  file.close();

  i++;
  gotoxy(10,22);
  cout<<"Want More Record To Be Written?(Y/N)......";
  cin>>ch;
  }while(ch=='y'||ch=='Y');
  if(ch=='n'||ch=='N') student_menu();
 }

/******************************Function To Modify Marks**********************/
void mod()
 {
 int regno,flag=0,i;
 char ch;
 student te;
 clrscr();
 cout<<"\n\nEnter The Reg No to be modified:";
 cin>>regno;
 for(i=0;i<10;i++)
  {
  if(s[i].redgno==regno)
   {
   flag=1;
   cout<<"\nSubject 1    :"<<s[i].sub1;
   cout<<"\nDo you want to change this?[y/n]";
   ch=getch();
   if(ch=='y')
    {
    cout<<"\nEnter New Value:";
    cin>>te.sub1;
    s[i].sub1=te.sub1;
    }
   cout<<"\nSubject  2  :"<<s[i].sub2;
   cout<<"\nDo you want to change this?[y/n]";
   ch=getch();
   if(ch=='y')
    {
    cout<<"\nEnter New Value:";
    cin>>te.sub2;
    s[i].sub2=te.sub2;
    }
   cout<<"\nSubject 3   :"<<s[i].sub3;
   cout<<"\nDo you want to change this?[y/n]";
   ch=getch();
   if(ch=='y')
    {
    cout<<"\nEnter New Value:";
    cin>>te.sub3;
    s[i].sub3=te.sub3;
    }
   cout<<"\nSubject 4   :"<<s[i].sub4;
   cout<<"\nDo you want to change this?[y/n]";
   ch=getch();
   if(ch=='y')
    {
    cout<<"\nEnter New Value:";
    cin>>te.sub4;
    s[i].sub4=te.sub4;
    }
   cout<<"\nSubject 5   :"<<s[i].sub5;
   cout<<"\nDo you want to change this?[y/n]";
   ch=getch();
   if(ch=='y')
    {
    cout<<"\nEnter New Value:";
    cin>>te.sub5;
    s[i].sub5=te.sub5;
    }
   }
  }
  if(flag==0) cout<<"Invalid Reg No!";
 }

/****************************Function To View Help***************************/
void help()
{
//clrscr();
textcolor(WHITE);
message(12,8,6,"This Software is designed for aiding schools in",
	       "keeping report of students and their information.",
	       "This software is a interactive menu driven program.",
	       "This program will create a file with students name ",
	       "with his or her report","OK",LIGHTGRAY);
gotoxy(15,14);
textcolor(WHITE);
textbackground(LIGHTGRAY);
cputs("    Keys:-Up,-Down,Enter-Selecting,Esc-To Exit.");
getch();
textcolor(BLACK);
main_menu();
}

/************************Function To Show Credits****************************/
void updown()
{
int i;
textcolor(GREEN);
for (i=25;i>10;i--)
{
delay(180);
clrscr();
gotoxy(30,i);
cputs("PROGRAMERS");
gotoxy(30,i+2);
cputs("Navi Arora");

gotoxy(30,5+i);
cputs("               ");
}
delay(800);
clrscr();
for (i=25;i>10;i--)
{
delay(180);
clrscr();
gotoxy(30,i);
cputs("Special Effects By");
gotoxy(30,2+i);
cputs("Navi Arora");
gotoxy(30,3+i);
cputs("Simran Arora");
gotoxy(30,4+i);
cputs("              ");
}
delay(800);
clrscr();
for (i=25;i>10;i--)
{
delay(180);
clrscr();
gotoxy(30,i);
cputs("Special Thanks To");
gotoxy(30,2+i);
cputs("Nannu");
gotoxy(30,3+i);
cputs("cbse-sample-papers.blogspot.com");
gotoxy(30,4+i);
cputs("              ");
}
delay(800);
clrscr();
for (i=25;i>10;i--)
{
delay(180);
clrscr();
gotoxy(30,i);
cputs("Developed At");
gotoxy(30,2+i);
cputs("www.NaviArora.com");
gotoxy(30,4+i);
cputs("              ");
}
delay(800);
clrscr();
for (i=25;i>10;i--)
{
delay(180);
clrscr();
textcolor(RED+BLINK);
gotoxy(10,i);
cputs("                      WARNING!!");
textcolor(BLUE);
gotoxy(10,1+i);
cputs("        This program is protected by copyright laws");
gotoxy(10,2+i);
cputs("                and International Treaties");
gotoxy(10,4+i);
cputs("Illigal Copying or reproduction of this software is punishable ");
gotoxy(10,5+i);
cputs("               and is against the protocol    ");
}
delay(3000);
}

/*****************************Draws a box*****************************/
void box(int x,int y,int width,int height)
 {
 int i,j;
 //Clear the space.
 for(j=y;j<y+height;j++)
 for(i=x;i<x+width;i++)
  {
  gotoxy(i,j);cputs(" ");
  }
 //Draw the box
 for(i=x+1;i<x+width;i++)
  {
  gotoxy(i,y);cputs("Í");
  gotoxy(i,y+height);cputs("Í");
  }
 for(i=y+1;i<y+height;i++)
  {
  gotoxy(x,i);cputs("º");
  gotoxy(x+width,i);cputs("º");
  }
 //The Conners
 gotoxy(x,y);cputs("É");
 gotoxy(x+width,y);cputs("»");
 gotoxy(x,y+height);cputs("È");
 gotoxy(x+width,y+height);cputs("¼");
 }


//Default Colour Settings
int default_back=BLACK;
int default_fore=LIGHTGRAY;
int sel_back_color=LIGHTGRAY; //Selected Back Colour
int sel_text_color=WHITE; //Selected Text Colour
int back_color=BLACK; //Default Back Colour
int text_color=WHITE; //Default Text Colour

//Other options
int fill=1; //This will make all menus equal in length
int show_numbers=0; //Will show Item index

/********************BackMenu() for intractive menus***********************/
//The format is copied for 'Effects.h' but a lot of changes were made.
void text(int x,int y,int sel,char txt[25])
 {
 if(!sel) //Item is selected
  {
  textbackground(sel_back_color);
  textcolor(sel_text_color);
  }
 else
  {
  textbackground(back_color);
  textcolor(text_color);
  }
 gotoxy(x,y);
 cputs(txt);
 }
int menu(int x,int y,int num,char a[25],char b[25],char c[25],char d[25],char e[25],char f[25],char g[25],char title[40],char extra[2])
 {
 char h[25]="";
 char ch;
 int key=72,sel=1,lengthest=0;

 //Get all items in an array
 char item[8][25];
 strcpy(item[0],a);
 strcpy(item[1],b);
 strcpy(item[2],c);
 strcpy(item[3],d);
 strcpy(item[4],e);
 strcpy(item[5],f);
 strcpy(item[6],g);
 strcpy(item[7],h);

 for(int i=0;i<num;i++)
  {
  if(strlen(item[i])>lengthest) lengthest=strlen(item[i]);
  }
 if(strlen(title)>lengthest) lengthest=strlen(title);
 box(x,y-1,lengthest+1,num+3);

 x++;
 textbackground(default_back);textcolor(default_fore);
 gotoxy(x,y);cputs(title);
 y = y + 2;

 //Print the first menu with the first item sellected.
 textbackground(sel_back_color);textcolor(sel_text_color);
 gotoxy(x,y);cputs(a);
 textbackground(back_color);textcolor(text_color);
 //Then print the rest as default.
 for(i=1;i<num;i++)
  {
  gotoxy(x,y+i);
  cputs(item[i]);
  }

 while (key!=13) //Until Enter Key is pressed
  {
  key=getch();

  //Otherwise pressing any invalid key will remove the selection.
  //Note : 49 is the ascii code of '1'
  if((key==72)||(key==80)||(key<49+num&&key>49)||(key==27))
   text(x,y+sel-1,1,item[sel-1]);

  switch(key)
   {
   case 72: //UP
    //Note that 'sel' starts at 1 and not 0.
    if(sel==1) text(x,y+num-1,0,item[num-1]);
    else text(x,y+sel-2,0,item[sel-2]);

    if(sel==1) sel=num;
    else sel--;

    break;
   case 80: //DOWN
    if(sel==num) text(x,y,0,item[0]);
    else text(x,y+sel,0,item[sel]);

    if(sel==num) sel=1;
    else sel++;

   break;
   //Number selections.
   case '1':
    text(x,y,0,item[0]);
    sel=1;
    goto end;
   case '2':
    text(x,y+1,0,item[1]);
    sel=2;
    goto end;
   case '3':
    if(num>=3)
     {
     text(x,y+2,0,item[2]);
     sel=3;
     goto end;
     }
    else break;
   case '4':
    if(num>=4)
     {
     text(x,y+3,0,item[3]);
     sel=4;
     goto end;
     }
    else break;
   case '5':
    if(num>=5)
     {
     text(x,y+4,0,item[4]);
     sel=5;
     goto end;
     }
    else break;
   case '6':
    if(num>=6)
     {
     text(x,y+5,0,item[5]);
     sel=6;
     goto end;
     }
    else break;
   case '7':
    if(num>=7)
     {
     text(x,y+6,0,item[6]);
     sel=7;
     goto end;
     }
    else break;
   case '8':
    if(num==8)
     {
     text(x,y+7,0,item[7]);
     sel=8;
     goto end;
     }
    else break;

   case 27:sel=0; goto end; //Escape Button.
   default:break;
   }

  }

 end:
 textbackground(default_back);textcolor(default_fore);
 return sel;
 }

/*********************************Menus*************************************/
/********************************Menu To View Marks**************************/
void view()
 {
 int opt,i,reg,flag=0;
 char n[20],ch;
 view:
 opt=menu(1,5,5,"1.View All","2.Search Reg No","3.Show Failers","4.Read From File"
	       ,"5.Back","[","]", "Dispay Menu","=");
 switch(opt)
  {
  case 1:				//Show All Marks
  for(i=0;i<10;i++)
   {
   clrscr();
   if(s[i].redgno!=NULL)
    {
    cout<<"                            Report Card Of "<<s[i].name
      <<"\nRegistration Number:"<<s[i].redgno<<"\nClass:"<<s[i].clas
      <<"\nAddress:"<<s[i].address<<"\nFather's Name:"<<s[i].fname
      <<"\nDate Of Birth:"<<s[i].dob.dd<<"-"<<s[i].dob.mm<<"-"<<s[i].dob.yyyy
      <<"\nStream:"<<s[i].st_code<<"\n\n\
-------------------------------------------------------------------------------\
	\nSubject Marks\n-------------\nSubject 1 :"
      <<s[i].sub1<<"\nSubject 2 :"<<s[i].sub2<<"\nSubject 3 :"<<s[i].sub3
      <<"\nSubject 4 :"<<s[i].sub4<<"\nSubject 5 :"<<s[i].sub5
      <<"\nTotal     :"<<s[i].total<<"\nGrade     :"<<s[i].div;
    cout<<"\n\nPress Any Key To Continue..";
    getch();
    }
   else break;
   }
  break;
  case 3:clrscr();			      //Show Failers
  for(i=0;i<records;i++)
   {
   if((s[i].sub1<33)||(s[i].sub2<33)||(s[i].sub3<33)||(s[i].sub4<33)||(s[i].sub5<33))
    {
    cout<<"			    Report Card Of "<<s[i].name
      <<"\nRegistration Number:"<<s[i].redgno<<"\nClass:"<<s[i].clas
      <<"\nAddress:"<<s[i].address<<"\nFather's Name:"<<s[i].fname
      <<"\nDate Of Birth:"<<s[i].dob.dd<<"-"<<s[i].dob.mm<<"-"<<s[i].dob.yyyy
      <<"\nStream:"<<s[i].st_code<<"\n\n\
-------------------------------------------------------------------------------\
	\nSubject Marks\n-------------\nSubject 1 :"
      <<s[i].sub1<<"\nSubject 2 :"<<s[i].sub2<<"\nSubject 3 :"<<s[i].sub3
      <<"\nSubject 4 :"<<s[i].sub4<<"\nSubject 5 :"<<s[i].sub5
      <<"\nTotal     :"<<s[i].total<<"\nGrade     :"<<s[i].div;
      cout<<"\n\nPress Any Key To Continue...";
    flag=1;
    getch();
    }
   }
  if(flag==0)
   {
   cout<<"No Failers Found";
   getch();
   view();
   }
  break;
  case 2:clrscr();                           //Search By Reg No
  cout<<"\n\n\tEnter Number To Be Searched:";cin>>reg;
  for(i=0;i<10;i++)
   {
   if(s[i].redgno==reg)
    {
    cout<<"			    Report Card Of "<<s[i].name
      <<"\nRegistration Number:"<<s[i].redgno<<"\nClass:"<<s[i].clas
      <<"\nAddress:"<<s[i].address<<"\nFather's Name:"<<s[i].fname
      <<"\nDate Of Birth:"<<s[i].dob.dd<<"-"<<s[i].dob.mm<<"-"<<s[i].dob.yyyy
      <<"\nStream:"<<s[i].st_code<<"\n\n\
-------------------------------------------------------------------------------\
	\nSubject Marks\n-------------\nSubject 1 :"
      <<s[i].sub1<<"\nSubject 2 :"<<s[i].sub2<<"\nSubject 3 :"<<s[i].sub3
      <<"\nSubject 4 :"<<s[i].sub4<<"\nSubject 5 :"<<s[i].sub5
      <<"\nTotal     :"<<s[i].total<<"\nGrade     :"<<s[i].div;
    flag=1;
    getch();
    }
   }
  if(flag==0)
   {
   cout<<"Record Not Found";
   getch();
   view();
   }
  break;
  case 4:                                    //Read File
  clrscr();
  cout<<"\n\n\tEnter Name Of Student:";gets(n);
  ifstream fil;
  strcat(n,".txt");
  fil.open(n);
  while(!fil.eof())
  {
  fil.get(ch);
  cout<<ch;
  }
  cout<<"\n\nPress Any Key To Continue...";
  getch();
  clrscr();
  break;
  case 5:student_menu();                      //Exit
  default:student_menu();
  }
 goto view;
 }

/******************************Student Menu*********************************/
void student_menu()
 {
 textbackground(16);
 textcolor(15);
 unsigned int tredg;
 char ch='y',ch1;
 do
  {
  clrscr();
  ch1=menu(1,5,3,"1.Add Students","2.Display Student","3.Back","","","[","] "
		,"Student Menu","=");
  switch(ch1)
   {
   case 1:clrscr();                             //Marks
	  add();
	  break;
   case 2:clrscr();                             //View Marks
	  view();
	  break;
   case 3:main_menu();                          //Main Menu
	  getch();
	  break;
   case 6:main_menu();                  	//Main Menu
	  getch();
	  break;

   default:cout<<"\n\nWorng Choice!!";
   }
  cout<<"\n\nDo You Want to Continue?(Y/N)";
  cin>>ch;
  }
 while(ch=='y'||ch=='Y');
 main_menu();
 }

/*********************************Main Menu**********************************/
void main_menu()
{
textbackground(16);
textcolor(LIGHTGRAY);
char ch1;
do{
clrscr();

ch1=menu(1,4,4,"1. Students Details","2. Modify Students","3. Help","4. Exit"
		,""," [","]","Student Report Maker","=");
switch(ch1)
{
case 1:clrscr();                       //Student Menu
       student_menu();
       break;
case 2:clrscr();                       //Marks Menu
       mark_menu();
       break;
case 3:help();
       break;
case 4:clrscr();			//Exit
       updown();
       exit(0);
       break;
case 6:clrscr();                        //Exit
//       updown();
//       man();
//       exit(0);
       break;
default:cout<<"\n\nWorng Choice!!";
}
}while(ch1==4);
}

/**********************************Marks Menu********************************/
void mark_menu()
{
textbackground(BLACK);
textcolor(WHITE);
int t_redg,i,opt,flag=0;
char ch='y',na[20];
do
{
clrscr();
gotoxy(1,25);
cout<<"Press Esc to Quit";
opt=menu(1,5,3,"1.Modify Student","2.Remove Student","3.Back",
	       "",""," [","] "," Menu","=");
switch(opt)
{
case 1:	clrscr();				//Modify Student
	mod();
	getch();
	mark_menu();
	break;
case 2:	clrscr();				//Delete Student
	cout<<"Which Student Do you want to Delete\nEnter Reg No:";
	cin>>t_redg;
	for(i=0;i<10;i++)
	 {
	 if(s[i].redgno==t_redg)
	  {
	  strcat(na,s[i].name);
	  strcat(na,".txt");
	  if(remove(na)) cout<<"The Record of "<<s[i].name<<" is removed.";
	  else cout<<"Internal Error. "<<s[i].name<<" could not be removed.";
	  s[i].redgno = -1;
	  flag=1;
	  break;
	  }
	 }
	if(flag==0)
	cout<<"Record not found";
	mark_menu();
	break;
default:main_menu();
}
gotoxy(30,25);
cout<<"Do you want to Continue?(Y/N)...";
cin>>ch;
}while(ch=='y'||ch=='Y');
if(ch=='n'||ch=='N')
main_menu();
}

/******************************Main Function*********************************/
void main()
{
clrscr();
main_menu();
getch();
}

/************************************End*************************************/

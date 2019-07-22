#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class clothing
{
  char code[20];
  int size;
  char type[20];
  float price;
  char material[20];

 public:

  void calc()
  {
	if(strcmp(material,"cotton")==0)
	  {
	     if(strcmp(type,"trouser")==0)
		     price=1500;
	else if(strcmp(type,"shirt")==0)
		     price=1200;
	else
	    cout<<"ERROR! No such type";
	  }

   else
	  {
	    if(strcmp(type,"trouser")==0)
		   price=0.75*1500;
       else if(strcmp(type,"shirt")==0)
		   price=0.75*1200;
	     else
	       cout<<" ";
	   }
  }


  clothing()
  {
   strcpy(code,"null");
   strcpy(type,"null");
   strcpy(material,"null");
   price=0;
   size=0;
    calc();
    cout<<"\n";
    disp();
   }

  clothing(char *c,char *t, char *m)
  {
   strcpy(code,c);
   strcpy(type,t);
   strcpy(material,m);
   calc();
   cout<<"\n";
   disp();
   }

 clothing(clothing &a1)
 {
   strcpy(code,a1.code);
   strcpy(type,a1.type);
   strcpy(material,a1.material);
   price=a1.price;
   size=a1.size;
   calc();
   cout<<"\n";
   disp();
   }

 void enter()
 {
  cout<<"Enter the code of the cloth: ";
  gets(code);
  cout<<"\nEnter the size of the cloth: ";
  cin>>size;
  cout<<"\nEnter the type of cloth: ";
  gets(type);
  cout<<"\nEnter the material of cloth(cotton/other): ";
  gets(material);

  calc();
  }

  void disp()
  {
  cout<<"Code of the cloth: ";
  puts(code);
  cout<<"\nSize of the cloth: "<<size;
  cout<<"\nType of the cloth: ";
  puts(type);
  cout<<"\nMaterial of the cloth: ";
  puts(material);
  cout<<"\nPrice of the cloth: "<<price;
   }
  ~clothing(){}

  };

  void main()
  {
     clrscr();
     int c;
   do
   {
     cout<<"\n\n\t CONSTRUCTOR AND DESTRUCTOR   ";
     cout<<"\n\n 1.Default Constructor";
     cout<<"\n 2.Parameterized Constructor";
     cout<<"\n 3.Copy Constructor";
     cout<<"\n 4.No constructor";
     cout<<"\n\n Enter your choice: ";
     cin>>c;

     switch(c)
     {
       case 1:clrscr();
	      clothing c1;
	break;
       case 2:clrscr();
	      clothing c2("ABC","trouser","cotton");
       break;
       case 3:clrscr();
	      clothing c3=c1;
       break;
       case 4: clrscr();
	       clothing c4;
	      cout<<"\nEntering the values \n\n";
	       c4.enter();
	       cout<<"\n\n Displaying the values \n\n";
	       c4.disp();

	       break;
       }

      }while(c!=5);

      }
#include<fstream.h>
#include<conio.h>
#include<process.h>
void main()
{
  clrscr();
  char c[30]; int a=1;
  ifstream fin;

  fin.open("A.txt",ios::in);

   if(!fin)
   {
     cout<<"Error in opening";
     exit(0);
     }

     while(!fin.eof())
	{
	  fin>>c;
	  a++;
	  }
	  cout<<"No. of words: "<<a;
	  fin.close();
	  }


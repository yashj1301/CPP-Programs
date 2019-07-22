#include<fstream.h>
#include<conio.h>
#include<process.h>
void main()
{
  clrscr();
  char c; int a=0;
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
	  if(c=='a'||c=='i'||c=='o'||c=='e'||c=='u')
	  a++;
	  }
	  cout<<"No. of vowels: "<<a;
	  fin.close();
	  }


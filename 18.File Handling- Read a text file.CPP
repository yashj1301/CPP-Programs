#include<fstream.h>
#include<conio.h>
#include<process.h>
void main()
{
  clrscr();
  char c,word[30],line[80];
  ifstream fin;

  fin.open("A.txt",ios::in);

   if(!fin)
   {
     cout<<"Error in opening";
     exit(0);
     }

     while(fin)
	{
	  fin>>c;
	  cout<<c;
	  fin>>word;
	  cout<<word;
	  fin.getline(line,80);
	  cout.write(line,80);
	  }
	  fin.close();
	  }


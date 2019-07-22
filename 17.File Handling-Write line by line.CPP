#include<fstream.h>
#include<conio.h>
#include<stdio.h>
void main()
{
  clrscr();
  char ch[80],ans='Y';
  ofstream fout;

  fout.open("A.txt",ios::out);

  do
  {
    cout<<"Enter the line: ";
    cin.getline(ch,80,'.');
    fout<<ch;

    cout<<"Do you want to continue: ";
    cin>>ans;

    }while(ans=='Y');
     fout.close();

     }


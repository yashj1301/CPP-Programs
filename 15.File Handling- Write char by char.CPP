#include<fstream.h>
#include<conio.h>

void main()
{
  clrscr();
  char ch,ans='Y';
  ofstream fout;

  fout.open("A.txt",ios::out);

  do
  {
    cout<<"Enter the Character: ";
    cin>>ch;
    fout<<ch;

    cout<<"Do you want to continue: ";
    cin>>ans;

    }while(ans=='Y');
     fout.close();

     }


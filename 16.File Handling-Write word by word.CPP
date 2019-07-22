#include<fstream.h>
#include<conio.h>

void main()
{
  clrscr();
  char ch[30],ans='Y';
  ofstream fout;

  fout.open("A.txt",ios::out);

  do
  {
    cout<<"Enter the Character: ";
    cin.getline(ch,30);
    fout<<ch;

    cout<<"Do you want to continue: ";
    cin>>ans;

    }while(ans=='Y');
     fout.close();

     }


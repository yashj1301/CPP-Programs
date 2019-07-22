//program to illustrate static members of a class

#include<iostream.h>
#include<conio.h>

class X
{
 int b,c;
 static int a;

 public: void incre()
 {
  cout<<"Enter the value for b and c: ";
  cin>>b>>c;
  a++;
  }

  void disp()
  {
   cout<<a;
   }
 };

 int X::a=5;

 void main()
 { clrscr();
   X x1,x2,x3;

   x1.incre();
   x2.incre();
   cout<<"\nThe value of a for X2 is ";
   x2.disp();
   cout<<"\nThe value of a for X1 is ";
   x1.disp();
   cout<<"\n";
   x3.incre();
   cout<<"\nThe value of a for X3 is ";
   x3.disp();

   }

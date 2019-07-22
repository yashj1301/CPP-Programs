#include<iostream.h>
#include<stdio.h>
#include<conio.h>

  class base
   {
    public: int a;
    };

  class D1:virtual public base
   {
    public: int b;
    };
  class D2:virtual public base
     {
     public: int c;
      };
  class D3:public D1, public D2
     {
     public: int tot;
      };

   void main()
    {
	clrscr();
	D3 obj;
	obj.a=25;
	obj.b=50;
	obj.c=75;
	obj.tot=obj.a+obj.b+obj.c;
	cout<<"The sum is: "<<obj.tot;
	getch();

     }
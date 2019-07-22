#include<iostream.h>
#include<conio.h>

class outer
{
 int a;
 public:
 class inner
      {
	public:int b; int c;
		inner()
		{
		  b=3;
		  c=4;
		  }
		~inner()
		{
		  }
	    void prn()
	    {
	     cout<<"values of b and c are "<<b<<" and "<<c;
	     }
	     };

    inner ob1;
    inner ob2;
    outer()
    { a=5;}

    void second()
    {
     cout<<"values for c,b and a are "<<ob2.c<<","<<ob2.b<<" and "<<a; }
     };

     void main()
     { clrscr();
      cout<<"Nested Classes being public \n ";
      outer ab;
      outer::inner cd;
      ab.second();
      cout<<"\n";
       cd.prn();
      }

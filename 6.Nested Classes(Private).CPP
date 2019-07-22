#include<iostream.h>
#include<conio.h>

class outer
{
 int a;
 class inner
      {
	int b;
	public: int c;
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
    public: inner ob2;
    outer()
    { a=5;}

    void second()
    {
     cout<<"values for c and a are "<<ob2.c<<" and "<<a; }
     };

     void main()
     { clrscr();
      cout<<"Nested Classes being private \n ";
      outer ab;
      ab.second();
      cout<<"\n";
      ab.ob2.prn();
      }

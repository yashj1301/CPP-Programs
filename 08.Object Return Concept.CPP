#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class distance
{
 int feet;
 int inches;

 public:


	 void accept(int f,int i)
	 {
	    feet=f;
	    inches=i;

	  }
		void print()
	  {
	   cout<<feet<<" feet "<<inches<<" inches"<<"\n";
	   }
	  distance sum(distance d2);

	   };

	distance distance::sum(distance d2)
	{
	   distance d3;
	   d3.feet=feet+d2.feet+(inches+d2.inches)/12;
	   d3.inches=(inches+d2.inches)%12;
	   return (d3);
	   }

	void main()
	{
	 clrscr();
	 distance d1,d2,tot;
	 d1.accept(17,6);
	 d2.accept(13,8);
	 tot=d1.sum(d2);
	 cout<<"Length 1: ";
	 d1.print();
	 cout<<"\nLength 2: ";
	 d2.print();
	 cout<<"\n\n Total Length:";
	 tot.print();
	 }



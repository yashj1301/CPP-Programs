//Program to create a class metropolis

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class metropolis
{
  int mcode;
  char mname[20];
  float mpop;
  float area;
  float popdens;

  public:

    void enter()
 {
   cout<<"\nEnter the Metropolis Code: ";
   cin>>mcode;
   cout<<"\nEnter the City Name: ";
   gets(mname);
   cout<<"\nEnter the Population: ";
   cin>>mpop;
   cout<<"\nEnter the Area: ";
   cin>>area;
   calden();
  }

  void calden()
  {
   popdens=mpop/area;
   }

void viewall()
{
   cout<<"\nMetropolis Code: "<<mcode;
   cout<<"\nCity Name: ";
   puts(mname);
   cout<<"\nPopulation: "<<mpop;
   cout<<"\nArea: "<<area;
   cout<<"\nPopulation Density: "<<popdens;

  }

  };

  void main()
  {
   clrscr();
   cout<<"\n\t\t Entering Metropolis Details..... \n\n";
   metropolis m;
   m.enter();
   clrscr();
   cout<<"\t\t Displaying Metropolis Details....\n\n ";
   m.viewall();

      }





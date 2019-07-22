#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class student
{
   protected: int rollno,marks1,marks2;
   public: void get()
	   {
	     cout<<"Enter the roll no. of student: ";
	     cin>>rollno;
	     cout<<"\nEnter the marks of subject 1: ";
	     cin>>marks1;
	     cout<<"\nEnter the marks of subject 2: ";
	     cin>>marks2;
	     }
	 };

  class sports
  {
    protected: int marks_sport;

    public:  void getsm()
	     {
	       cout<<"\nEnter the Marks of Sports:  ";
	       cin>>marks_sport;

	       }

	  };

  class result:public sports,public student
  {
    int tot;
    int avg;

    public:   void calc()
		{
		   tot=marks1+marks2+marks_sport;
		   avg=tot/3;
		   }

	      void display()
	       {
		cout<<"\nTotal Marks: "<<tot;
		cout<<"\nAverage: "<<avg;
		cout<<"\nRoll No: "<<rollno;
		cout<<"\nMarks of Subject 1: "<<marks1;
		cout<<"\nMarks of Subject 2: "<<marks2;

		}

	   };

      void main()
      {
       clrscr();
       result r;
       cout<<"\n\n\t Entering Record....\n\n";
       r.get();
       r.getsm();
       r.calc();
       clrscr();
       cout<<"\n\n\t Showing Record....\n\n";
       r.display();

       }


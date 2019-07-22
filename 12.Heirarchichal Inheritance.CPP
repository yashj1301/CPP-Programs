#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class student
{
   public: int adno,eng;
	   char name[20];
	   char sname[20];
	     void in()
	   {
	     cout<<"Enter the Addmission no. of student: ";
	     cin>>adno;
	     cout<<"\nEnter the Name of the student:  ";
	     gets(name);
	     cout<<"\nEnter the Name of the School:  ";
	     gets(sname);
	     }

	     void disp()
	     {
	     cout<<"Admission no. of student:  "<<adno;
	     cout<<"\nName of the student:  ";
	     puts(name);
	     cout<<"\nName of the School:  ";
	     puts(sname);
	     }
	 };

  class arts:public student
  {
     public: int feesar;
	     float percentage;
	     int s1,s2,s3,s4;

	      void get()
	     {
	     cout<<"\n Enter the Fees: ";
	     cin>>feesar;
	     cout<<"\n\nEnter the Marks of Sociology: ";
	     cin>>s1;
	     cout<<"\nEnter the Marks of Psychology:  ";
	     cin>>s2;
	     cout<<"\nEnter the Marks of Hindi:  ";
	     cin>>s3;
	     cout<<"\nEnter the Marks of Music: ";
	     cin>>s4;
	     cout<<"\nEnter the Marks of English: ";
	     cin>>eng;
	       }

	     void calc()
	     {
	      percentage=(s1+s2+s3+s4+eng)/5;
	      }

	     void disp1()
	     {
	     cout<<"\nFees: "<<feesar;
	     cout<<"\n\nMarks of Sociology: "<<s1;
	     cout<<"\nMarks of Psychology:  "<<s2;
	     cout<<"\nMarks of Hindi:  "<<s3;
	     cout<<"\nMarks of Music: "<<s4;
	     cout<<"\nMarks of English: "<<eng;
             cout<<"\n\nPercentage: "<<percentage;
	     }

	  };

       class science:private student
  {
     public: int feesc;
	     float percentage;
	     int s1,s2,s3,s4;

	      void get()
	     {       in();
	     cout<<"\n Enter the Fees: ";
	     cin>>feesc;
	     cout<<"\n\nEnter the Marks of Chemistry: ";
	     cin>>s1;
	     cout<<"\nEnter the Marks of Maths/Physical Education:  ";
	     cin>>s2;
	     cout<<"\nEnter the Marks of Physics:  ";
	     cin>>s3;
	     cout<<"\nEnter the Marks of Computer Science/Biology: ";
	     cin>>s4;
	     cout<<"\nEnter the Marks of English: ";
	     cin>>eng;
	       }

	     void calc()
	     {
	      percentage=(s1+s2+s3+s4+eng)/5;
	      }

	     void disp2()
	     {            disp();
	     cout<<"\nFees: "<<feesc;
	     cout<<"\n\nMarks of Chemistry: "<<s1;
	     cout<<"\nMarks of Maths/Physical Education:  "<<s2;
	     cout<<"\nMarks of Physics:  "<<s3;
	     cout<<"\nMarks of Computer Science/Biology: "<<s4;
	     cout<<"\nMarks of English: "<<eng;
	     cout<<"\n\nPercentage: "<<percentage;
	     }

	  };

	   class commerce:protected student
  {
     public: int feescomm;
	     float percentage;
	     int s1,s2,s3,s4;

	      void get()
	     {   in();
	     cout<<"\n Enter the Fees: ";
	     cin>>feescomm;
	     cout<<"\n\nEnter the Marks of Economics: ";
	     cin>>s1;
	     cout<<"\nEnter the Marks of Business Studies:  ";
	     cin>>s2;
	     cout<<"\nEnter the Marks of Accountancy:  ";
	     cin>>s3;
	     cout<<"\nEnter the Marks of Maths/Physical Education: ";
	     cin>>s4;
	     cout<<"\nEnter the Marks of English: ";
	     cin>>eng;
	       }

	     void calc()
	     {
	      percentage=(s1+s2+s3+s4+eng)/5;
	      }

	     void disp3()
	     {
	       disp();
	     cout<<"\nFees: "<<feescomm;
	     cout<<"\n\nMarks of Economics: "<<s1;
	     cout<<"\nMarks of Business Studies:  "<<s2;
	     cout<<"\nMarks of Accountancy:  "<<s3;
	     cout<<"\nMarks of Maths/Physical Education: "<<s4;
	     cout<<"\nMarks of English: "<<eng;
	     cout<<"\n\n Percentage: "<<percentage;
	     }

	  };

      void main()
      {
       clrscr();
       student s;
       arts a;
       commerce c;
       science b;

       char stream[20];
       cout<<"\n\t\tSTUDENT RECORD\n";
       cout<<"Enter your stream: ";
       gets(stream);
       if(strcmp(stream,"arts")==0)
	{
	 clrscr();
       cout<<"\n\n\t Entering Record....\n\n";
	 s.in();
	 a.get();
	 a.calc();
	 clrscr();
       cout<<"\n\n\t Displaying Record....\n\n";
	 s.disp();
	 a.disp1();
	  }

	else if(strcmp(stream,"science")==0)
	{
	 clrscr();
       cout<<"\n\n\t Entering Record....\n\n";
	 b.get();
	 b.calc();
	 clrscr();
       cout<<"\n\n\t Displaying Record....\n\n";
	 b.disp2();
       }

       else if(strcmp(stream,"commerce")==0)
	{
	 clrscr();
       cout<<"\n\n\t Entering Record....\n\n";
	 c.get();
	 c.calc();
       cout<<"\n\n\t Displaying Record....\n\n";
	 c.disp3();

	 }

	 }
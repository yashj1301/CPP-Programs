/* DATA FILE HANDLING PROJECT ON "LIBRARY MANAGEMENT SYSTEM"
		      BY - YASH JAIN and RISHABH SHARMA
		      CLASS- XII-A */

//------------------------------------------------------------------------
//                HEADER FILES USED IN THE PROJECT
//------------------------------------------------------------------------

#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<iomanip.h>
#include<dos.h>

 struct date_book        // STRUCTURE MADE
 {
   int d,m,y;

   };
  int monthdays[]={31,28,31,30,31,30,31,31,30,31,30,31};

class book              // CLASS MADE FOR BOOK RECORDS
{
	int bno;
	char bname[50];
	char aname[20];
  public:
		int date_issue,month_issue,year_issue;
		char a;
	void create_book()
	{
		cout<<"\n\tNEW BOOK ENTRY...\n";
		cout<<"\n\tEnter The book no.:";
		cin>>bno;
		cout<<"\n\n\tEnter The Name of The Book: ";
		gets(bname);
		cout<<"\n\n\tEnter The Author's Name: ";
		gets(aname);
		cout<<"\n\n\n\tBook Created..";
	}

	void show_book()
	{
		cout<<"\n\tBook no. : "<<bno;
		cout<<"\n\tBook Name : ";
		puts(bname);
		cout<<"\tAuthor Name : ";
		puts(aname);
	}

	void modify_book()
	{
		cout<<"\n\tBook no. : "<<bno;
		cout<<"\n\tModify Book Name : ";
		gets(bname);
		cout<<"\n\tModify Author's Name of Book : ";
		gets(aname);
	}


	void get_date()
	{
	 struct date d;
	 getdate(&d);             // to take system date

	 date_issue=d.da_day;
	 month_issue=d.da_mon;
	 year_issue=d.da_year;

	 cout<<"\n\tDate of Issue: "<<date_issue<<"/"<<month_issue<<"/"<<year_issue;
	 }



  int count_leapyear(date_book d)
  {

    int years=d.y;
    if(d.m<=2)
    {
    years--;   }
    return years/4-years/100+years/400;
    }

       int retbno()
	{
		return bno;
	}

	void report()
	{
	  cout<<setw(10)<<bno<<setw(30)<<bname<<setw(20)<<aname<<endl;
	}

	int getdifference(date_book dt1,date_book dt2); // to find out no of days between date of issue and date of deposit
	void putdate();

};         //class ends here



  int book::getdifference(date_book dt1,date_book dt2)
  {
   long int n1=dt1.y*365+dt1.d;
   for(int i=0;i<dt1.m;i++)
    n1+=monthdays[i];
   n1+=count_leapyear(dt1);

   long int n2=(dt2.y*365+dt2.d);
   for(int j=0;j<dt2.m;j++)
    n2+=monthdays[j];
    n2+=count_leapyear(dt2);
    return (n2-n1);
    }

	void book::putdate()
	{
	  struct date d;
	  getdate(&d);
	  int day;
	int date_deposit=d.da_day;
	 int month_deposit=d.da_mon;
	 int year_deposit=d.da_year;

	 date_book dt1={date_issue,month_issue,year_issue};
	 date_book dt2={date_deposit,month_deposit,year_deposit};
	 day=getdifference(dt1,dt2);
   cout<<"\n\n\t Date of Issue: "<<date_issue<<"/"<<month_issue<<"/"<<year_issue;
   cout<<"\n\t Date of Deposit: "<<date_deposit<<"/"<<month_deposit<<"/"<<year_deposit;
   cout<<"\n\n\t Total No. of Days: "<<day;
   if(day>15)
   {
   cout<<"\n\tNo. of days after deadline: "<<day-15;
   cout<<"\n\t Fine: INR "<<(day-15)*2;
   }
    else
   cout<<"\n\n\tBook Returned before deadline";


   }


    class student:public book     // single inheritance used for accessibilty of members of previous class
   {
	int admno;
	char name[20];
	int stbno;
	int token;

	public:        void create_student(int ad);

	void show_student()
	{
		cout<<"\n\tAdmission no. : "<<admno;
		cout<<"\n\tStudent Name : ";
		puts(name);
		cout<<"\n\tNo of Book issued : "<<token;
	}

	void modify_student()
	{
		cout<<"\n\tAdmission no.: "<<admno;
		cout<<"\n\tModify Student Name: ";
		gets(name);
	}

	int retadmno()
	{
		return admno;
	}

	int retstbno()
	{
		return stbno;
	}

	int rettoken()
	{
		return token;
	}

	void addtoken()
	{
	       token=1;
	}

	void resettoken()
	{
	      token=0;
	}

	void getstbno(int t)
	{
		stbno=t;
	}

	void resetstbno()
	{
		stbno=0;
	 }

	void editdate()
	{
	 date_issue=0;
	 month_issue=0;
	 year_issue=0;
	 }
	void report()
	{
	cout<<setw(5)<<admno<<setw(20)<<date_issue<<'/'<<month_issue<<'/'<<year_issue<<setw(23)<<name<<setw(15)<<token<<endl;
	}

   };         //class ends here


  fstream fp,fp1;     // global variable for data file handling
  book bk;            // global object of class to avoid declaration of object in every function
  student st;         // global object of class to avoid declaration of object in every function


	void student::create_student(int ad)
	{
		int f=0;      // flag value for validation
		fp.open("student.dat",ios::in);
		while(fp.read((char*)this,sizeof(student)))
		{
		  if(admno==ad)
		   { f=1;


		   }
		  }
		  fp.close();
		   if(f==0)
		   {
		   fp.open("student.dat",ios::app);
		  admno=ad;
		cout<<"\n\n\tEnter The Name of The Student: ";
		gets(name);
		cout<<"\n\n\tStudent Record Created..";
		token=0;         // no of book issued preset to 0 as soon as new record is entered
		stbno=0;         // book no in student record preset to 0
		editdate();      // date of issue preset to 0/0/0
		fp.write((char*)&st,sizeof(student));
		fp.close();

		}

	       else
	       {
		cout
		<<"\n\n\tAdmission No. already exists";
		   }


		}


void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app); // app mode to insert new record at the end of file
	do
	{
		clrscr();
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		cout<<"\n\n\tDo you want to add more record..(y/n?):";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	fp.close();
}

void write_student()
{
	char ch;
	int ad;
	      do
	      { clrscr();
	      cout<<"\n\n\tENTER NEW STUDENT DETAILS....";
	      cout<<"\n\n\tEnter the Admission No: ";
		cin>>ad;
		st.create_student(ad);
		cout<<"\n\n\t Do you want to Continue(y/n): ";
		cin>>ch;
	       }while(ch=='y'||ch=='Y');

}

void display_spb(int n)
{
	cout<<"\n\tBOOK DETAILS\n";
	int flag=0;                 // flag value for validation
	fp.open("book.dat",ios::in);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(bk.retbno()==n)
		{
			bk.show_book();
			flag=1;
		}
	}

	fp.close();
	if(flag==0)
		cout<<"\n\n\tBook does not exist";
	getch();
}

void display_sps(int n)
{
	cout<<"\n\tSTUDENT DETAILS\n";
	int flag=0;                      // flag value for validation
	fp.open("student.dat",ios::in);
	fp1.open("book.dat",ios::in);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()==n)
		{
			st.show_student();
			while(fp1.read((char*)&bk,sizeof(book)))
			 {
			       if(st.retstbno()==bk.retbno())
			       bk.show_book();

			 }

			flag=1;
		}
	}


	fp1.close();
	fp.close();
	if(flag==0)
		cout<<"\n\n\tStudent does not exist";
	getch();
}


void modify_book()
{
	int n;
	int found=0;                  // flag value for validation
	clrscr();
	cout<<"\n\n\tMODIFY BOOK RECORD.... ";
	cout<<"\n\n\tEnter The book no. of The book: ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);  // file opened in I/O mode because first we have to read the record and then modify(writing) it
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(bk.retbno()==n)
		{
			bk.show_book();
			cout<<"\n\n\n\tEnter The New Details of Book";
			cout<<"\n\t-----------------------------------\n\t";
			bk.modify_book();
			int pos=-1*sizeof(bk); // takes us to the beginning of record and stores in pos
			fp.seekp(pos,ios::cur); // takes the put pointer from pos to cursor
			fp.write((char*)&bk,sizeof(book));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n\t Record Not Found ";
	getch();
}


void modify_student()
{
	int n;
	int found=0;
	clrscr();
	cout<<"\n\n\tMODIFY STUDENT RECORD... ";
	cout<<"\n\n\tEnter The admission no. of The student:";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()==n)
		{
			st.show_student();
			cout<<"\n\n\n\tEnter The New Details of Student";
			cout<<"\n\t-----------------------------\n\t";
			st.modify_student();
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			cout<<"\n\n\t Record Updated";
			found=1;
		}
	}

	fp.close();
	if(found==0)
		cout<<"\n\n\t Record Not Found ";
	getch();
}

void delete_student()
{
	int n;
	int flag=0;
	clrscr();
	cout<<"\n\n\n\tDELETE STUDENT RECORD...";
	cout<<"\n\n\tEnter The admission no. of the Student You Want To Delete : ";
	cin>>n;
	fp.open("student.dat",ios::in|ios::out);  // file opens in I/O
	fp1.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);           // temporary data file created for deletion
	fp.seekg(0,ios::beg);     // takes the get pointer to beginning of file
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()!=n)  // storing all the records except the record to delete, to temp.dat
			fp2.write((char*)&st,sizeof(student));
		else
		 {
			st.show_student();  //if record matches, show before deletion
			flag=1;
			while(fp1.read((char*)&bk,sizeof(book)))
			{
			  if(st.retstbno()==bk.retbno())
			  bk.show_book();
			}

	}
	 }
	fp2.close();
	fp1.close();
	fp.close();
	remove("student.dat");    // deleting the original data file that contains only the record to be deleted
	rename("Temp.dat","student.dat");
	if(flag==1)
		cout<<"\n\n\tRecord Deleted ..";
	else
		cout<<"\n\n\tRecord not found";
	getch();
}
		 void display_alls();

void delete_studentall()
{       clrscr();
	cout<<"\n\n\n\tDELETE ALL STUDENT RECORDS...";
	display_alls();
	fp.open("student.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(!st.retadmno())
			fp2.write((char*)&st,sizeof(student));
	}

	fp2.close();
	fp.close();
	remove("student.dat");     // removing original data file
	rename("Temp.dat","student.dat"); //  renaming temporary to original data file name
		cout<<"\n\n\tRecords Deleted ..";

	getch();
}

void delete_book()
{
	int n;  int f=0;
	clrscr();
	cout<<"\n\n\n\tDELETE BOOK ...";
	cout<<"\n\n\tEnter The Book no. of the Book You Want To Delete : ";
	cin>>n;
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(bk.retbno()!=n)
			fp2.write((char*)&bk,sizeof(book));

			else
		       {
			f=1;
			bk.show_book();  }
	}

	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	if(f==1)
	cout<<"\n\n\tRecord Deleted ..";
	else
	cout<<"\n\n\t Record not found";
	getch();
}
		void display_allb();

void delete_bookall()
{
	clrscr();
	cout<<"\n\n\n\tDELETE ALL BOOKS ...";
	display_allb();
	cout<<"\n\n\t";
	fp.open("book.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(!bk.retbno())
		{
			fp2.write((char*)&bk,sizeof(book));
		}
	}

	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	cout<<"\n\n\tRecords Deleted ..";
	getch();
}


void display_alls()
{
	fp.open("student.dat",ios::in);
	if(!fp)
	{
		cout<<"\n\n\tERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"============================================================================\n";
	cout<<setw(15)<<"Admission No."<<setw(20)<<"Date of Issue"<<setw(20)<<"Name"<<setw(20)<<"Book Issued\n";
	cout<<"============================================================================\n";

	while(fp.read((char*)&st,sizeof(student)))
	{
		st.report();
	}

	fp.close();
	getch();
}

void display_allb()
{
	fp.open("book.dat",ios::in);
	if(!fp)
	{
		cout<<"\n\n\tERROR!!! FILE COULD NOT BE OPEN ";
		getch();
		return;
	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<setw(15)<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
	cout<<"=========================================================================\n";

	while(fp.read((char*)&bk,sizeof(book)))
	{
		bk.report();

	}
	fp.close();
	getch();
}

void book_issue()
{
	int sn,bn,date,month,year;
	int found=0,flag=0;   // flag values for validations
	clrscr();
	cout<<"\n\n\tBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.:";
	cin>>sn;
	cout<<"\n";

	fp.open("student.dat",ios::in|ios::out);
	fp1.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.retadmno()==sn)
		{
			found=1;
			if(st.rettoken()==0) // checking if the student has already issued any book or not
			{
				cout<<"\tEnter the book no.: ";
				cin>>bn;
				while(fp1.read((char*)&bk,sizeof(book)))
				{
					if(bk.retbno()==bn) // checking book no for student's record
					{
						st.get_date(); // taking system date as date of issue
						bk.show_book();
						flag=1;
						st.addtoken();  // no of book issued changes to 1
						st.getstbno(bk.retbno()); // book no in book record copies to book no in student record
						int pos=-1*sizeof(st); // takes us to the beginning of record and stores to pos
						fp.seekp(pos,ios::cur); // takes the put pointer from pos to cursor
						fp.write((char*)&st,sizeof(student));
						cout<<"\n\n\t Book issued successfully\n\n\tPlease Note: Write the current date in backside of your book and submit \twithin 15 days. Fine= Rs. 2 for each day after 15 days period";
					}
				}

				if(flag==0)
					cout<<"\n\n\tBook no does not exist";
			}
			else
				cout<<"\n\n\tYou have not returned the last book ";

		}
	}

	if(found==0)
		cout<<"\n\n\tStudent record does not exist...";
	getch();
	fp.close();
	fp1.close();
}

void book_deposit()
{
    int sn,bn;
    int found=0,flag=0,day,fine;  // flag values for validation
    clrscr();
    cout<<"\n\n\tBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The student's admission no.: ";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)))
       {
	    if(st.retadmno()==sn)
	    {
		    found=1;
		    if(st.rettoken()==1) // checking if student has issued any book or not
		    {
			while(fp1.read((char*)&bk,sizeof(book)))
			{
			   if(bk.retbno()==st.retstbno())
			{
				bk.show_book();
				flag=1;
				       st.putdate(); // takes system date as date of deposit
					st.resettoken(); // no of book issued resets to 0 after deposit
					st.resetstbno(); // book no in student record resets to 0
					st.editdate();   // date of issue resets to 0/0/0
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);
					fp.write((char*)&st,sizeof(student));
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(flag==0)
		    cout<<"\n\n\tBook no does not exist";
		      }
		 else
			cout<<"\n\n\tNo book is issued..please check!!";
		}
	   }
      if(found==0)
	cout<<"\n\n\tStudent record does not exist...";
	getch();
  fp.close();
  fp1.close();
  }

void intro()
{
    clrscr();

    gotoxy(20,11);      //gotoxy used for indentation
    cputs("LIBRARY");
    gotoxy(23,12);
    cout<<"MANAGEMENT";
    gotoxy(26,13);
    cout<<"PROJECT";

    gotoxy(15,17);
    cout<<"NAME: YASH JAIN and RISHABH SHARMA";
    gotoxy(16,18);
    cout<<"CLASS: XII-A";
    gotoxy(20,20);
    textcolor(WHITE+BLINK);             // textcolor used for blinking text
    cputs("Press any key to continue");
    textcolor(WHITE);
      textmode(C80);                  // textmode for screen resolution
      getche();
    }


    void student_menu()
     {
	   clrscr();
	   char ch;
	   gotoxy(10,2);
	   cout<<"STUDENT MENU";
	   gotoxy(10,3);
	   cout<<"-----------------";
	   gotoxy(10,4);
	   cout<<"1.Create Student Record";
	   gotoxy(10,5);
	   cout<<"2.Display All Student Records";
	   gotoxy(10,6);
	   cout<<"3.Display Specific Student Record";
	   gotoxy(10,7);
	   cout<<"4.Modify Student Record";
	   gotoxy(10,8);
	   cout<<"5.Delete Student Record";
	   gotoxy(10,9);
	   cout<<"6.Delete All Student Records";
	   gotoxy(10,10);
	   cout<<"7.Back to Admin Menu";
	   gotoxy(10,11);
	   cout<<"8.Exit";
	   gotoxy(10,14);
	   cout<<"Enter your choice(1-8): ";
	   cin>>ch;

	   switch(ch)
	   {
	    case '1':   clrscr();
		      write_student();
		      break;

	    case '2':    clrscr();
		       display_alls();
		       break;

	    case '3': 	int num;
			clrscr();
			cout<<"\n\n\tPlease Enter The Admission No.: ";
			cin>>num;
			display_sps(num);
			break;

	    case '4': modify_student();
			break;

	    case '5': delete_student();
			break;

	    case '6': delete_studentall();
			break;

	    case '7':  return;

	    case '8': exit(0);

	     default: cout<<"\a";

	     }

	     student_menu();
	     }

     void book_menu()
     {
	   clrscr();
	   char ch;
	   gotoxy(10,2);
	   cout<<"BOOK MENU";
	   gotoxy(10,3);
	   cout<<"-----------------";
	   gotoxy(10,4);
	   cout<<"1.Create New Book";
	   gotoxy(10,5);
	   cout<<"2.Display All Books";
	   gotoxy(10,6);
	   cout<<"3.Display Specific Book";
	   gotoxy(10,7);
	   cout<<"4.Modify Book";
	   gotoxy(10,8);
	   cout<<"5.Delete Book";
	   gotoxy(10,9);
	   cout<<"6.Delete All Books";
	   gotoxy(10,10);
	   cout<<"7.Back to Admin Menu";
	   gotoxy(10,11);
	   cout<<"8.Exit";
	   gotoxy(10,14);
	   cout<<"Enter your choice(1-9): ";
	   cin>>ch;

	   switch(ch)
	   {
	    case '1':   clrscr();
		      write_book();
		      break;

	    case '2':    clrscr();
		       display_allb();
		       break;

	    case '3': 	int num;
			clrscr();
			cout<<"\n\n\tPlease Enter The Book No.: ";
			cin>>num;
			display_spb(num);
			break;

	    case '4': modify_book();
			break;

	    case '5': delete_book();
			break;

	    case '6': delete_bookall();
			break;

	    case '7':  return;

	    case '8': exit(0);

	     default: cout<<"\a";

	     }
       book_menu();
       }


void admin_menu()
{
	clrscr();
	char ch;
	gotoxy(10,2);
	cout<<"ADMINISTRATOR MENU";
	gotoxy(10,3);
	cout<<"-------------------";
	gotoxy(10,4);
	cout<<"1.Student Menu";
	gotoxy(10,5);
	cout<<"2.Book Menu";
	gotoxy(10,6);
	cout<<"3.Back to Main Menu";
	gotoxy(10,7);
	cout<<"4.Exit";
	gotoxy(10,10);
	cout<<"Enter your choice(1-4): ";
	cin>>ch;
	switch(ch)
	{
	  case '1':
		  student_menu();
		  break;

	  case '2':
		  book_menu();
		  break;

	  case '3': return;

	  case '4': exit(0);

	  default: cout<<"\a";

	}
	admin_menu();
}

void main()
{       textmode(C80);
	char ch;
	intro();
	do
	{
		clrscr();
		gotoxy(10,2);
		cout<<"MAIN MENU";
		gotoxy(10,3);
		cout<<"----------";
		gotoxy(10,4);
		cout<<"01.Book Issue";
		gotoxy(10,5);
		cout<<"02.Book Deposit";
		gotoxy(10,6);
		cout<<"03.Administrator Menu";
		gotoxy(10,7);
		cout<<"04.Exit";
		gotoxy(10,10);
		cout<<"Please Select Your Option (1-4): ";
		cin>>ch;
		switch(ch)
		{
			case '1':  clrscr();
				 book_issue();
				 break;
			case '2':  book_deposit();
				 break;
			case '3':  admin_menu();
				 break;
			case '4':  exit(0);
			default :cout<<"\a";
		}
	}while(ch!=5);
}

/* -------------------------------------------------------------
		      END OF PROJECT
   -------------------------------------------------------------*/
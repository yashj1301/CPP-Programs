 #include<iostream.h>
 #include<conio.h>
 #include<stdio.h>
 #include<string.h>

 class bank
 {
   int acno;
   char name[50];
   char pass[10];
   float bal;

   public:  void init();   int retno();   void deposit();

	    char *password()
	    {
	      return pass;
	       }
	    void withdraw(); void disp();

	    }b[2];

 void bank::init()
 {
   char c; char p[10]={0};
   int i=0;

   cout<<"\n Enter the Account no. for the employee: ";
   cin>>acno;
   cout<<"\n Enter your password: ";
   while((c=getch())!=13)
   {
     p[i++]=c;
     cout<<'*';
     }

    strcpy(pass,p);
    cout<<"\n\n Enter the Name of the Account Holder: ";
    gets(name);

    do
    {
     cout<<"\n Enter the current balance (min. INR 5000): INR ";
     cin>>bal;
     }while(bal<5000);
     }

     int bank::retno()
     {
      return acno;
      }

     void bank::deposit()
     {
      float y;
      cout<<"\n Enter the money to be deposited: INR ";
      cin>>y;

      bal+=y;
      cout<<"\n Your Current Balance is: INR "<<bal;
      getch();
      }

      void bank::withdraw()
      {
       float y;
       cout<<"\n Enter the money you want to withdraw: INR ";
       cin>>y;

       if(bal-y>=5000)
       {
	 bal-=y;
	 cout<<"\n Your current account balance is: INR "<<bal;
	 }
       else

       cout<<"\n Sorry! You cannot withdraw more than INR "<<bal-5000
	   <<"from your account";
	   getch();
	   }

      void bank::disp()
      {
       cout<<"\n The Name of the Account Holder: ";
       puts(name);
       cout<<"\n Your Current Account Balance is: INR "<<bal;
       getch();
       }

       void main()
       {
	clrscr(); char pass[10]={0};
	int j=0;
	int i,p,r,flag=0;
	char ch;
	cout<<"\n Entering the details of customers.... ";
	for(i=0;i<2;i++)
	 b[i].init();

       do
       {
	clrscr();
	cout<<"\n\n THE CITY BANK PVT. LTD.";
	cout<<"\n -------------------------";
	cout<<"\n 1.Deposit Money";
	cout<<"\n 2.Withdraw Money";
	cout<<"\n 3.Balance";
	cout<<"\n 4.Exit";
	cout<<"\n\n Enter your choice: ";
	cin>>p;

	switch(p)
	{
	  case 1: {

		  cout<<"\nEnter the Account Number:  ";
		  cin>>r;
		  for(i=0;i<2;i++)
		  {
		   if(r==b[i].retno())
		   {
		      cout<<"Enter your password: ";
		      while((ch=getch())!=13)
		      {
		       pass[j++]=ch;
		       cout<<'*';
		       }
		    if(strcmp(pass,b[i].password())==0)
		      {
			flag=1;
			cout<<"\nPassword Matched\n";
			b[i].deposit();
			break;
			}
		     else
		     {
		       cout<<"\nPassword Not Matched\n";
		       }
		     }
		   }         // for loop closed
		      if(flag==0)
		      {
		       cout<<"\n This Account does not exist";
		       getch();
		       }
			  break;
			    }

	  case 2:  {

		    cout<<"\nEnter the Account Number:  ";
		    cin>>r;
		  for(i=0;i<2;i++)
		  {
		   if(r==b[i].retno())
		   {
		      cout<<"Enter your password: ";
		      while((ch=getch())!=13)
		      {
		       pass[j++]=ch;
		       cout<<'*';
		       }
		    if(strcmp(pass,b[i].password())==0)
		      {
			flag=1;
			cout<<"\nPassword Matched\n";
			b[i].withdraw();

			  break;

			  }
		     else
		       {
			  cout<<"\nPassword not matched\n";
			  }
			}
		     }    //loop closed

		       if(flag==0)
		       {
			 cout<<"\n This Account does not exist";
			 getch();
			 break;
		       }


	  case 3: {

		   cout<<"\nEnter the Account Number:  ";
		  cin>>r;
		  for(i=0;i<2;i++)
		  {
		   if(r==b[i].retno())
		   {
		      cout<<"Enter your password: ";
		      while((ch=getch())!=13)
		      {
		       pass[j++]=ch;
		       cout<<'*';
		       }
		    if(strcmp(pass,b[i].password())==0)
		      {
			flag=1;
			cout<<"\nPassword Matched\n";
			b[i].disp();

			break;
		      }
		   else
		     {
		       cout<<"\nPassword not matched\n";
		       }

		    }
		  }            //for loop closed

		     if(flag==0)
		     {
		      cout<<"\n This account does not exist";
		      getch();
		      break;
		      }
		    }
		       }
		      }while(p!=4);


			      }while(p!=4);

			  }








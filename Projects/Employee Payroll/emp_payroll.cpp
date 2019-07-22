/******************************************************
* Project : Employee Payroll                          *
* Student : Yash Jain                                 *
* Class  : XII-A                                      *
* Roll no: 42                                         *
******************************************************/

#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>

void MainMenu();
int GetCount();
void ProcessSales();
double GetSalesData();
double SalesGT500(double WeeklySales);
double SalesLT500(double WeeklySales);
double DisplayPay(double Commision);


void MainMenu()
{
	system ("cls");
	cout << "**************************[ Welcome To ABC Company ]**************************\n"
		<< "*                         Payroll By: Carlos Quinones                        *\n"
		<< "******************************************************************************\n\n";
}

GetCount()
{
	int Count;
	int GreaterThen1; // <---------- To make sure that they enter the right amount!!
	
	cout << "How many sales people: ";
	cin >> Count; // <-------- this is how many Sales people they have.
	
	do 
	{
		if (Count >= 1)                                      
		{                                                    
			return Count;                                   
			GreaterThen1 = 0;                                
		}
		else
		{
			cout << "Sorry Please Enter A Ral Number!\n\n";
		}
		
	}while (GreaterThen1 == 1);
}

void ProcessSales()
{

	int Count;
	int Counter = 0;                                         // This function is the heart of
	int UID;                                                 // this program. 
	double WeeklySales;                                      
	double Commision;                                        
	double Pay;                                              
	char FirstName[32];                                      
	char LastName[32];                                       
	Count = GetCount();
	
	do
	{
		cout << "Please Enter Sales Person Name (First & Last): ";
		cin >> FirstName >> LastName;
		cout << "Please Enter Sales ID: ";
		cin >> UID;                              
		WeeklySales = GetSalesData();              
	                                                
		if (WeeklySales >= 500)
		{
			Commision = SalesGT500(WeeklySales);
			Pay = DisplayPay(Commision);
		}
		else
		{
			Commision = SalesLT500(WeeklySales);
			Pay = DisplayPay(Commision);
		}

		system ("cls");
		MainMenu();
		cout << "Sales Person: " << FirstName << " " << LastName << "\n"
			<< "Sales ID    : " << UID << "\n"
			<< "Weekly Sales: " << WeeklySales << "\n"
			<< "Commision   : " << Commision << "\n"
			<< "Pay         : " << Pay << "\n\n"
			<< "******************************************************************************\n\n\n\n\n";
		Counter++;

	}while (Counter < Count);
	
	
}

double GetSalesData()
{
/*	int UID;     */                         // This function lets you enter the Sales
	double WeeklySales;                     // Data. 
/*                                           
	cout << "Please Enter Sales ID: ";      
	cin >> UID;                             
*/	                                        
	cout << "Please Enter Weekly Sales: ";   
	cin >> WeeklySales;                     
	                                        
	return WeeklySales;                     
}

double SalesGT500(double WeeklySales)
{
	double Commision;                       // This function will get the commision for the
	double First500;                        // sales person who has more then 500 dollars in
	double Over500;                         // weekly sales. 
	Over500 = (WeeklySales - 500) * .15;    
	First500 =  500 * .10;                  
	                                        
	Commision = First500 + Over500;        
	return Commision;                       
}

double SalesLT500(double WeeklySales)
{
	double Commision;                       // This function will get the commision for the
	                                        // sales person who did not make the 500 dollars
	Commision = WeeklySales * .10;          // in weekly sales.
	return Commision;                       
	                                        
}

double DisplayPay(double Commision)
{
	double pay;                             
	pay = Commision + 300;                  
	return pay;                             
}

void main ()
{
        clrscr();
	ProcessSales(); 
}


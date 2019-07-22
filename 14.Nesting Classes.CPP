#include<iostream.h>
#include<conio.h>
#include<process.h>

  class mail
 {
   int shipper,postage;

   public:
	   void set(int a,int b)
	   {
	     shipper=a;
	     postage=b;

	     }

	     int getpost()
	     {
	      return postage;
	      }

	     };

  class box
  {
   int length,width;
   mail label;

   public:  void set(int l,int w,int ship,int post)
	    {
	      length=l;
	      width=w;
	      label.set(ship,post);
	      }

	     int area()
	     {
	       return (length*width);
	       }

	    };

    void main()
    {
      clrscr();
      box small,medium,large;
      small.set(2,4,1,35);
      medium.set(5,6,2,72);
      large.set(8,10,4,98);

      cout<<"\n\nArea of small box label is: "<<small.area()<<endl;
      cout<<"Area of medium box label is: "<<medium.area()<<endl;
      cout<<"Area of large box label is: "<<large.area()<<endl;

      }



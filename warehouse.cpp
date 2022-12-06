/*
 * Dulguun Narmandakh
 *
 */

#include <iostream>
using namespace std;

int main()
{
  start:

  cout<<"Order # \t\t Name \t\t\t\t Status"<<endl<<endl;
  cout<<" 1 \t\t\tBrian Jen \t\t\t Complete"<<endl; 
  cout<<" 2 \t\t\tJessy Pen \t\t\t Incomplete"<<endl;
  cout<<" 3 \t\t\tWilliams Yen \t\t\t Incomplete"<<endl;
  cout<<" 4 \t\t\tAnn Pan \t\t\t Incomplete\n"<<endl;

  string ans,answ, answe;
  int num;
  cout<<"choose by order number: ";
  cin>>num;

  if(num==1)
  {
	cout<<"Order Status: COMPLETE"<<endl;
	cout<<"Print shipping label? (Y/N): ";
	cin>>ans;
		
		if(ans=="Y"||ans=="y")
		{
		  cout<<"9809 Margo Street, Albuquerque, NM 87104"<<endl;
		}else{
		  goto start;
     		}

	cout<<"Is the Order Shipped?(Y/N):";
	cin>>answe;
	if(answe=="Y"||answe=="y")
		{
		  cout<<"Confirmation Email Sent!"<<endl;
		}else{
		  cout<<"Confirmation email will be sent when the order is shipped"<<endl;
     		}
  
  }else if(num==2){
	cout<<"Order Status: Incomplete"<<endl;
	cout<<"Return to List?(Y/N): ";
	cin>>answ;
	if(answ=="Y"||answ=="y")
	{
	  goto start;
	}else{
	  return 0;
	}
  }else if(num==3){
	cout<<"Order Status: Incomplete"<<endl;
	cout<<"Return to List?(Y/N): ";
	cin>>answ;
	if(answ=="Y"||answ=="y")
	{
	  goto start;
	}else{
	  return 0;
	}
  }else if(num==4){
	cout<<"Order Status: Incomplete"<<endl;
	cout<<"Return to List?(Y/N): ";
	cin>>answ;
	if(answ=="Y"||answ=="y")
	{
	  goto start;
	}else{
	  return 0;
	}
  } 
return 0; 
}
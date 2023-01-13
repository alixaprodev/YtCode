#include <iostream>
void menu ();
void unionofsets();
void intersectionofsets();
void differenceofsets();
void complementofset();
void exit ();
using namespace std;
int main (){
	char ch='y';
	while(ch=='y')
	{
	
	menu ();            // the menu function called
	int choice;
	cout <<"waiting for your choice:";
	cin >>choice;       //this is the entered choice of the user from menu.
	switch (choice){
		case 1:
			unionofsets();
			break;
		case 2:
			intersectionofsets();
			break;
		case 3:
			differenceofsets();
			break;
		case 4:
			complementofset();
			break;
		case 5:
			exit ();
			break;
		default :
			cout <<"THE SYSTEM FIND SOME ERROR.TRY AGAIN.......\n THANK YOU";
	}
	cout<<"\n do you want to continue(y/n)";
	cin>>ch;
}
	
	return 0;
}
void menu ()
{
	cout <<"*****************************MENU**************************************\n";
	cout <<"******SELECT THE OPERATION FROM THE MENU BY SELECTING THE NUMBER******\n";
	cout <<"	1.	UNION OF TWO SETS"<<endl;
	cout <<"	2.	INTERSECTION OF TWO SETS"<<endl;
	cout <<"	3.	DIFFERENCE OF TWO SETS"<<endl;
	cout <<"	4.	COMPLEMENT OF A GIVEN SET"<<endl;
	cout <<"	5	EXIT THE PROGRAM"<<endl;
	cout <<"***********************************************************************\n";
}
void unionofsets()
{
	int size1,size2;
	int set1[100];
	int set2[100];
	cout <<"****THANK YOU****\n YOUR CHOICE MATCHED TO UNION OF SETS.\n";
	cout <<"Enter the number of elements in the first set:";
	cin >>size1;
	cout <<"Enter the number of elements in  the second set:";
	cin >>size2;
	cout <<"Enter "<<size1 <<" elements for first set:";
	for (int i=0;i<size1;i++)
	{
		cin >>set1[i];
	}
	cout <<"Enter "<<size2<<" elements for the second set:";
	for (int j=0;j<size2;j++)
	{
		cin >>set2[j];
	}
	///////////////////////union ///////////////////
	cout <<"The union of set 1 and set 2 = {";
	int k;
	for (int a=0;a<size1;a++)
	{
		cout <<set1[a]<<" ,";
	}
	for (int i=0;i<size2;i++)
	{
		for (k=0;k<size1;k++)
		{
			if (set2[i]==set1[k])
			{
				break;
			}
		}
		if (k==size1)
		{
			cout<<set2[i]<<" ,";
		}
	}
	cout <<"}";
	cout<<"*****************************************************************\n";
}

void intersectionofsets(){
	int set1[20];
	int set2[20];
	int sizeofset1,sizeofset2;
	cout <<"*****THANK YOU*****\n YOUR CHOICE MET TO THE INTERSECTION OF TWO SETS."<<endl;
	cout <<"Enter the number of elements in first set:";
	cin  >>sizeofset1;
	cout <<"Enter the number of elements in second set:";
	cin  >>sizeofset2;
	cout <<"Enter "<<sizeofset1<<"  elements for first set separated by spaces.";
	cout <<endl;
	for (int i=0;i<sizeofset1;i++)
	{
		cin>>set1[i];
	}
	cout <<"Now enter "<<sizeofset2<<" elements for second set precisely.";
	cout <<endl;
	for (int j=0;j<sizeofset2;j++)
	{
		cin>>set2[j];
	}
	///////////////////////calculation of the intersection///////////////////////
	cout<<"The intersection set of first and second set is :";
	cout<<"  { ";
	for (int i=0;i<sizeofset1;i++)
	{
		for (int j=0;j<sizeofset2;j++)
		{
			if (set1[i]==set2[j])
			cout <<set1[i]<<", ";
	    }
	}
	cout<<"}";
	cout <<"\n*************************************************************";
}
void differenceofsets (){
	int size1;
	int size2;
	int set1[34];
	int set2[54];
	cout <<"*****THANK YOU*****\n YOUR CHOICE IS TO FIND THE DIFFERENCE OF TWO SETS.\n";
	cout <<"enter the number of elements in set1:";
	cin >>size1;
	cout <<"enter the number of elements in set2:";
	cin >>size2;
	cout <<"enter the first set:";
	for (int i=0;i<size1;i++)
	{
		cin >>set1[i];
	}
 	cout <<"enter the second set:";
 	for (int k=0;k<size2;k++)
 	{
 		cin >>set2[k];
	 }
	 ///////////////////////////////difference///////////////
	 cout <<"The difference  of two sets you have  entered is {";
	 int l;
	 for (int i=0;i<size1;i++)
	 {
	 	for (l=0;l<size2;l++)
	 	{
	 		if (set1[i]==set2[l]){
	     	break;
		    }
		 }
		 if (l==size2)
		  cout <<set1[i]<<" ,";
	 }
	 cout <<"}"<<"\n********************************************************";
}
void complementofset(){
	int sizefuni=100;
	int sizefgiv;
	int uniset[100];
	int userset[100];
	uniset[0]=0;
	cout <<"*****THANK YOU*****\n YOU WANT TO FIND THE COMPLEMETN OF A SET\n";
	cout <<"The universal set for your set i suppose to be \n\n {";
	for (int i=0;i<sizefuni;i++)
	{
	uniset[i]=uniset[0]+i;
	cout <<uniset[i]<<" ,";
	}
	cout <<"}\n\n"<<endl;
	cout<<"enter the size of set :";
	cin>>sizefgiv;
	cout <<"enter the element of the set to find the complenet.";
	for (int k=0;k<sizefgiv;k++)
	{
		cin >>userset[k];
	}
	/////////////////////////complement///////////////////////////////
	 int l;
	 cout <<"The complement of the given set is ={";
	 for (int i=0;i<sizefuni;i++)
	 {
	 	for (l=0;l<sizefgiv;l++)
	 	{
	 		if (uniset[i]==userset[l]){
	     	break;
		    }
		 }
		 if (l==sizefgiv)
		  cout <<uniset[i] <<" ,";
	 }
	 cout <<"}\n ********************************************************";
}
void exit(){
	cout <<"THANK YOU FOR NOT HURTING ME";
}
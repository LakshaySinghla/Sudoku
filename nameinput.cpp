#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
using namespace std;
class nam{
		char n[20];
	public:
   	void in(char ch[20])
	   {	strcpy(ch,n);
      }
      void out(char ch[20])
      {	strcpy(n,ch);
      }
      void dis()
      {	cout<<n;
      }
}n1,n2;
int main()
{
char ch;
do{
ifstream fin;
ofstream fout;
char name[20]={"Gazal"},ch1;
int i;
/*
fout.open("name.dat",ios::binary);               //put data in
for(i=0;i<1;i++)                                  //name file
{	n1.out(name);
   cout<<fout.tellp()<<" ";
	fout.write((char*)&n1,sizeof(n1));
	cout<<fout.tellp()<<" ";
}
cout<<"\n";
fout.close();
*/
/*
fin.open("name.dat" , ios::app , ios::binary);   //check data in
for(i=0;fin.eof() == 0;i++)                      //name file
{	cout<<fin.tellg()<<" ";
	fin.read((char*)&n1,sizeof(n1));
   if(fin.eof()) break;
   n1.dis();
}
cout<<"\n"<<i;
fin.close();
*/
/*
fout.open("nameno.dat", ios::binary);               //input & check
fout<<"1";                                          //data in nameno file
fout.close();
fin.open("nameno.dat",ios::app, ios::binary);
fin.get(ch1);
cout<<ch1 ;
*/

cout<<"\nDo you want to play again?(y/n) ";
cin>>ch;
}while(ch=='y');
}//main

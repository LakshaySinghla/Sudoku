#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<process.h>
int a[9][9],r,c,x=0,y=0,flag=0,flag1=0,flag2=0,flag3=0;
int temp1,temp2,rndm,namei=0,ch3;                     //ch=main dowhile
char ch='y',ch1,ch2,name[10][20];                          //ch1=what we enter in game
ofstream fout;                                                             //ch2=switch (menu)
ifstream fin , fin1;                                                      //ch3=choosen player no.
class nam{                                                                   //namei= no. of names
	char n[20];
	public:
   	void in(char ch[20])
      {	strcpy(ch,n);
      }
      void out(char ch[20])
      {	strcpy(n,ch);
      }
}n1;
class save{
	int b[9][9];
	public:
   	int in(int r1,int c1)
      {  return b[r1][c1];
      }
      void out(int ch1,int r1,int c1)
      {  b[r1][c1]=ch1;
      }
}s1;
void info();
void nameput();
void put();
void display();
void check();
void fileinput();
void ending();

void main()
{
nameput();
do{
	clrscr();
   	cout<<setw(60)<<"Current Player - "<<name[ch3]<<"\n";
	cout<<setw(45)<<"      MENU       \n\n";
    cout<<setw(45)<<"1.) New Game     \n\n";
   	cout<<setw(45)<<"2.) Continue     \n\n";
   	cout<<setw(45)<<"3.) Choose Player\n\n";
   	cout<<setw(45)<<"4.) Instructions \n\n";
   	cout<<setw(45)<<"5.) Exit         \n\n";
   	cin>>ch2;
   switch(ch2)
   {
   case '1':randomize();
            fin.open("put.dat",ios::app, ios::binary);
            fin1.open("save.dat",ios::app, ios::binary);
            fout.open("temp.dat",ios::binary);
            for(r=0;!fin1.eof();r++)
            {	fin1.read((char*)&s1,sizeof(s1));
                if(fin1.eof()) break;
               	if(r==ch3)
               	{	rndm = random(8);
                    fin.seekg(rndm*324);                               //select randomly from any sudoku
                    fin.read((char*)&s1,sizeof(s1));             //save values in s1 from 'put'
                    fout.write((char*)&s1,sizeof(s1));        //save valuse in 'save' from s1
                }
               	else fout.write((char*)&s1,sizeof(s1));
            	}
            fout.close();
            fin1.close();
            fin.close();
            remove("save.dat");
            rename("temp.dat","save.dat");
case '2':	x=0;y=0;flag1=0;flag=0;                                         //flag1 for (x,y)pointer
            put();                                                                        //flag for checking
            while(!flag2)                                                           //flag2 for ending
            {  	flag1=0;
                display();
                if(flag1==1) continue;
               	if(flag3==1) break;
                check();
                fileinput();
                ending();
            }
            if(flag3==1) break;
            cout<<"You Won!! \n";
            cout<<"Yipeeeee!!\n\n";
            break;
case '3':	clrscr();
            flag3=1;r=0;
            cout<<"\n"<<setw(40)<<"Choose Players\n\n\n";
            for(;r<namei;r++)
            	cout<<setw(25)<<(r+1)<<". "<<name[r]<<"\n\n";
            cout<<setw(25)<<(r+1)<<". Any Other \n";
            cin>>ch3;
            ch3--;
            if(ch3 == namei)
            {	fout.open("name.dat",ios::app, ios::binary);
                cout<<"Enter your name - ";
               	cin>>name[ch3];
               	n1.out(name[ch3]);
               	fout.seekp(ch3*20);
               	fout.write((char*)&n1,sizeof(n1));                //saving new players name
               	fout.close();                                     //in name file
               	namei++;

                randomize();
                fin.open("put.dat",ios::app, ios::binary);               //creating new save data
                fout.open("save.dat",ios::app ,ios::binary);         //for new player
                rndm = random(8);
                fin.seekg(rndm*324);                                         //select randomly from any sudoku
                fin.read((char*)&s1,sizeof(s1));                       //save values in s1 from 'put'
                fout.write((char*)&s1,sizeof(s1));                  //save valuse in 'save' from s1
                fout.close();
                fin.close();
            }
            fout.open("nameno.dat",ios::binary);
            fout<<(ch3+1);
            fout.close();
            break;
   case '4':info();
            flag3=1;
            break;
   case '5':exit(0);
   };         //switch ends
   if(flag3==1)                                        //flag3 -> to return to main menu after info
   {	flag3=0;
      	continue;
   }
cout<<"\nDo you want to play again?(y/n) ";
cin>>ch;
}while(ch=='y');
}//main

void info()
{
 clrscr();
 cout<<"                      INSTRUCTIONS\n\n\n";
 cout<<"1.) You can use pointer('*') by pressing \n    'w' for up\n";
 cout<<"    's' for down\n    'd' for right\n    'a' for left\n";
 cout<<"    Pointer by default will be at 1st box of 1st block\n\n";
 cout<<"2.) Pointer will not be displayed on predefined numbers or\n";
 cout<<"    the numbers you entered.\n\n";
 cout<<"3.) Predefined numbers are represented as -ve numbers\n\n";
 cout<<"4.) If you enter any number which is not according to SUDOKU rules\n ";
 cout<<"    'Wrong Input' message will be displayed.\n\n";
 cout<<"5.) If you want to return to MAIN MENU in between the game you\n";
 cout<<"    have to enter 'n' .\n\n";
 cout<<"6.) If you press the continue button the game will be continued\n";
 cout<<"    from where that particular player has left.\n";
 cout<<"    That is, if there are two players .If Player 1 press continue,\n";
 cout<<"    then game is resumed where Player 1 has left his game. And\n";
 cout<<"    if Player 2 press continue then game will be resumed from \n";
 cout<<"    where Player 2 has left his game .\n\n";
 cout<<"7.) Best of Luck .\n\n";
 cout<<"    Press any key to return to MENU.\n";
 cin>>ch2;
 }// info ends

void nameput()
{
fin.open("name.dat" , ios::app , ios::binary);
for(namei=0;fin.eof() ==0;namei++)            //since eof runs 1 time extra
{	fin.read((char*)&n1,sizeof(n1));          //so namei will get proper value
   	if(fin.eof()) break;
  	 n1.in(name[namei]);
}
fin.close();
fin.open("nameno.dat",ios::app, ios::binary) ;
fin.get(ch2);
ch3=ch2-49;
fin.close();
}   //name put ends

void put()
{
 fin.open("save.dat" , ios::app , ios::binary);
 fin.seekg(ch3*324);
 fin.read((char*)&s1,sizeof(s1));
 for(r=0;r<9;r++)
    for(c=0;c<9;c++)
   		a[r][c]=s1.in(r,c);
 fin.close();

}          //put ends

void display()
{
clrscr();
cout<<name[ch3]<<"\n";
cout<<setw(62)<<"===========================================\n";
for(r=0;r<9;r++)
{	cout<<setw(20)<<"||";
	for(c=0;c<9;c++)
   	{	if(r==y && c==x && a[r][c]==0)
   			cout<<" * ";
   		else if(a[r][c]==0)
      			cout<<"   ";                      //3 spaces if nothing is filled
      		else if(a[r][c]<0)
      			cout<<a[r][c]<<" ";              //for predefined no.
   		else cout<<" "<<a[r][c]<<" ";

      		if(c==2 || c==5 || c==8)            //double line for block
      			cout<<"|| ";
      		else cout<<"|";
   }
   cout<<"\n";
   if(r==2 || r==5 || r==8)
   cout<<setw(63)<<"===========================================\n\n";
   else cout<<setw(62)<<"-------------------------------------------\n";
}
if(flag==1) cout<<"Wrong Input!! \nTry Again\n";
flag=0;
cout<<"Enter - ";
//getc(ch1);
cin>>ch1;
switch(ch1)
{	case 'w':y=y-1;flag1=1;break;
	case 's':y=y+1;flag1=1;break;
   	case 'd':x=x+1;flag1=1;break;
   	case 'a':x=x-1;flag1=1;break;
   	case '1':a[y][x]=1;break;
   	case '2':a[y][x]=2;break;
   	case '3':a[y][x]=3;break;
   	case '4':a[y][x]=4;break;
   	case '5':a[y][x]=5;break;
   	case '6':a[y][x]=6;break;
   	case '7':a[y][x]=7;break;
   	case '8':a[y][x]=8;break;
   	case '9':a[y][x]=9;break;
   	case 'n':flag3=1;break;
   	default :break;
}
}       //display ends

void check()
{
temp1=y; temp2=x;r=0;c=0;
for(;temp1!=0 && temp1!=3 && temp1!=6;temp1--);           // for attaining first
for(;temp2!=0 && temp2!=3 && temp2!=6;temp2--);           // letter of each block
for(r=temp1;r<(temp1+3);r++)
	for(c=temp2;c<(temp2+3);c++)
   	{	if(r==y && c==x) continue;
   		if(a[r][c]==a[y][x] || a[r][c]==(-a[y][x]) )
      		flag=1;                                                             //checking in block
   	}
for(r=0;r<9;r++)
{ 	 if(r==x) continue;                                                       //neglecting that particular box
	if(a[y][r]==a[y][x] || a[y][r]==(-a[y][x]) )
   	flag=1;                                                                          //checking in row
}
for(r=0;r<9;r++)
{  	if(r==y) continue;
	if(a[r][x]==a[y][x] || a[r][x]==(-a[y][x]) )
   	flag=1;                                                                        //checking in column
}
if(flag==1) a[y][x]=0;                                                             //correcting the value
}//check ends

void fileinput()
{
fin.open("save.dat",ios::app, ios::binary);                   //modifying only that particular
fout.open("temp.dat",ios::binary);               //data in save file
for(r=0;!fin.eof();r++)
{	fin.read((char*)&s1,sizeof(s1));
	if(fin.eof()) break;
   	if(r==ch3)
   	{	for(r=0;r<9;r++)
            for(c=0;c<9;c++)
                s1.out(a[r][c],r,c);
      		fout.write((char*)&s1,sizeof(s1));
   	}
   	else fout.write((char*)&s1,sizeof(s1));
}
fout.close();
fin.close();
remove("save.dat");
rename("temp.dat","save.dat");

}           //fileinput ends

void ending()
{r=0;c=0;
for(r=0;r<9;r++){
	for(c=0;c<9;c++)
   	{	if(a[r][c]==0)
            flag2=0;
            break;
   	}
   	if(flag2==0) break;
}
} //ending ends


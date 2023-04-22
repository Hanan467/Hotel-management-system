#include <iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
class guest
{
public:
    char g_name[30];
    char adr[30];
    int phone_no;
    int Id,room_type,book_date,to_date,days;

};

class room:public guest
{
 public:
  int book_fee;
  int fday;
  int tday;
  int room_no;
   char c;
  void select_room()
  {
  char f[100];
 do
 {
        cout<<"\t\t\t\tPlease Select a room"<<endl;
        cout<<"\t\t\t\tEnter 'A' for single."<<endl;
        cout<<"\t\t\t\tEnter 'B' for double."<<endl;
        cout<<"\t\t\t\tEnter 'C' for king."<<endl;
        cout<<"\t\t\t\tEnter 'D'for  twin."<<endl;
        cout<<endl;
        cout<<"\t\t\t\tChoose a room from the above options: ";
        cin>>c;
 switch (c)
{
    case 'A':{
    system("CLS");
    cout<<"you have chosen a single room"<<endl;
    cout<<"the room costs 2000 birr per day"<<endl;
    break;}
  case 'B':{
    system("CLS");
    cout<<"you have chosen a double room"<<endl;
    cout<<"the room costs 3000 birr per day"<<endl;
    break;}
case 'C':{
    system("CLS");
   cout<<"you have chosen a king room"<<endl;
    cout<<"the room costs 4000 birr per day"<<endl;
    break;}
case 'D':{
    system("CLS");
   cout<<"you have chosen a twin room"<<endl;
    cout<<"the room costs 3500 birr per day"<<endl;
    break;}
default:
    cout<<"invalid room type please try again!"<<endl;
  }
 }
 while(c!='A'&&c!='B'&&c!='C'&&c!='D');
  }
void calculate(){
    system("CLS");
     int days=tday-fday;
     if(c=='A')
        book_fee=(days)*2000;
     if(c=='B')
        book_fee=(days)*3000;
     if(c=='C')
        book_fee=(days)*4000;
     if(c=='D')
        book_fee=(days)*3500;
        cout<<book_fee;
}
int check_room(int r)
{
    int x=0;
    ifstream B;
    B.open("booked.txt",ios::in);
    if(B.is_open())
    {
    while(!B.eof())
    {
            B.read((char*)this,sizeof(room));
            if(room_no==r)
            {
            x=1;
            break;
            }
     }
    }
    else
        cout<<"could not open the file"<<endl;
     B.close();
     return(x);
}
void book()
{
int r,x;
ofstream C;
C.open("booked.txt",ios::app);
if(C.is_open())
{
cout<<"enter room number"<<endl;
cin>>r;
x=check_room(r);
if(x==1)
    cout<<"room is already booked"<<endl;
else
{
        cin.ignore();
    system("CLS");
    cout << "Please provide following information: "<<endl;
    cout<<"\t\t\t please enter your name"<<endl;
    cin.getline(g_name,30);
    cin.ignore();
    cout<<"\t\t\t please enter your ID"<<endl;
    cin.ignore();
    cin>>Id;
    cin.ignore();
    cout<<"please enter your address"<<endl;
    cin.get(adr,30);
    cin.ignore();
    cout<<"please enter your phone number "<<endl;
    cin>>phone_no;
    cout<<"\t\t\t please enter the the day from you are going to book"<<endl;
    cin>>fday;
    cout<<"\t\t\t please enter the the day to which you are going to book"<<endl;
    cin>>tday;
    C.write((char*)this,sizeof(room));
    cout<<"room is booked successfully"<<endl;
   C.close();
}
}
}
};
class Admin:public room
{
  protected:
  string Admin_name;
  int Id;
  string setAdmin_name(string name)
  {
      Admin_name=name;
  }
  string getadmin_name()
  {
      return Admin_name;
  }
  int setId(int id)
  {
      Id=id;
  }
  int getId()
  {
      return Id;
  }
  public:
 void login()
{
   string p;
   char c;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t  HOTEL MANAGEMENT SYSTEM\n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t\t     LOGIN \n";
   cout<<"\t\t\t\t\t------------------------------\n\n";
   cout << "\t\t\t\t\tEnter Password: ";
       c=getch();

   while(c != 13)
    {
      p.push_back(c);
      cout << '*';
      c=getch();
   }
   if(p == "1234"){
      cout << "\n\n\n\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }else{
      cout << "\n\n\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
void modify()
{
  int x,r;
  char c;
  ofstream C;
C.open("booked.txt",ios::app);
if(C.is_open())
{
cout<<"enter room number"<<endl;
cin>>r;
x=check_room(r);
if(x==1)
   cout<<"Enter New Informations";
   cout<<"\n -----------------";
   cin.ignore();
   cout<<"please enter Name: ";
   cin.getline(g_name,30);
   cin.ignore();
   cout<<" please enter Address: ";
   cin.get(adr,30);
   cin.ignore();
   cout<<" please enter Phone no: ";
   cin>>phone_no;
   cin.ignore();
   cout<<" please enter the number of Days: ";
   cin>>days;
   C.write((char*)this,sizeof(room));
			cout<<"\n Record modified....!!";
}
C.close();
}
void Delete()
{
  int x,r;
  char c;
  ifstream C;
  ofstream D;
C.open("booked.txt",ios::in);
D.open("del.txt",ios::app);
if(C.is_open())
{
while(!C.eof())
{
  C.read((char*)this,sizeof(room));}
  cout<<"enter room number"<<endl;
  cin>>r;
  x=check_room(r);
  if(x==1)
{
    cout<<"\n Name: "<<g_name;
    cout<<"\n Address: "<<adr;
    cout<<"\n Phone No: "<<phone_no;
    cout<<"\n Days: "<<days;
    cout<<"\n\n Do you want to delete this record(y/n): ";
    cin>>c;
    if(c=='Y')
    {
     D.write((char*)this,sizeof(room));
     remove("booked.dat");
     rename("del.dat","booked.dat");

    }
}}}
};
room b;
  Admin a;
void menu()
{
   char s;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t choose \n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t 1  Modify record\n";
   cout << "\t\t\t\t\t 2  Delete record \n ";
   cin>>s;
   if (s=='1')
       a.modify();
   if (s=='2')
       a.Delete();
}
int main()
{

   int g;
   cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t  HOTEL MANAGEMENT SYSTEM\n\n";
   cout<<"\t\t\t\t\t------------------------------";
   cout<<"\n\t\t\t\t\t 1 ADMIN \n";
   cout << "\t\t\t\t\t 2 GUEST \n ";
   cin>>g;
   switch(g)
   {
case 1:
       system("CLS");
       a.login();
        menu();
       break;
case 2:
         system("CLS");
         b.select_room();
         system("PAUSE");
         system("CLS");
         b.book();
         break;
default:
         cout<<"invalid input please try again"<<endl;
   }
    return 0;
}




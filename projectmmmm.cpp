#include <iostream>
#include<fstream>

using namespace std;
class shopping{
    private :
         int Pcde;
         float Prc;
         float Dis;
         string  Pnm;

         public :
         void menu();
         void administrator();
         void buyer();
         void add();
         void edit();
         void rem();
         void list();
         void receipt();
};
void shopping ::menu()
{  m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t_________________________ \n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t  Supermarket Main menu   \n";
    cout<<"\t\t\t\t                          \n";
    cout<<"\t\t\t\t_________________________ \n";
    cout<<"\t\t\t\t|   1)administartor      |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t|   2)buyer              |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\t\t\t\t|   3)exit               |\n";
    cout<<"\t\t\t\t|                        |\n";
    cout<<"\n\t\t\tenter your choice:";
    cin>>choice;

    switch(choice)
    {
    case 1:
        {
        cout<<"\t\t\t Please login\n";
        cout<<"\t\t\tenter your email:";
        cin>>email;
        cout<<"\t\t\t possword :";
        cin>>password;
        if(email=="hari@gmail.com"&&password=="hari1234@")
        {
          administrator();
        }
        else
        {

            cout<<"invalid email /password";

         }
         break;
      }
    case 2:
     {
        buyer();
       // break;
     }
    case 3:
     {
        exit(0);
        //break;
     }
    default :
    {
        cout<<"please select from the given options: ";

     }


}
goto m;
}

void shopping::administrator()
{   m:
    int choice ;

   cout<<"\n\n\n\t\t\t Administrator menu";
   cout<<"\n\t\t\t|_____1)Add the product___ |";
   cout<<"\n\t\t\t|                          |";
   cout<<"\n\t\t\t|_____2)modify the product_|";
   cout<<"\n\t\t\t|                          |";
   cout<<"\n\t\t\t|_____3)Delete the product_|";
   cout<<"\n\t\t\t|                          |";
   cout<<"\n\t\t\t|_____4)back to main  menu_|";

   cout<<"please enter the choice :  ";
   cin>>choice;
  switch (choice)
   {

       case 1:
             add();
             break;

       case 2:
              edit();
              break;

       case 3:
              rem();
              break;

       case 4:
              menu();
              break;


       default :
              cout<<"invalid choice!";


    }
 goto m;
}

void shopping::buyer(){
    m:
    int choice ;

    cout<<"\t\t\t Buyer   \n";
    cout<<"\t\t\t__________    \n";
    cout<<"\t\t\t1)buy product \n";
    cout<<"                    \n";
    cout<<"\t\t\t2)go back     \n";
    cout<<"\t\t\tenter your choice:";
    cin>>choice;

    switch (choice)
    {
        case 1:
             receipt();
               break;
        case 2:
               menu();
                break;
        default:
               cout<<"invalid choice";


    }
goto m;
}
void shopping::add()
{   m:
    fstream data;
  int c;
  int token=0;
  float p;
  float d;
  string n;

cout<<"\n\n\t\t\t add new product";
cout<<"\n\n\tproduct code of the product :";
cin>>Pcde;
cout<<"\n\n\t name of the product : ";
cin>>Pnm;
cout<<"\n\n\t price of the product : ";
cin>>Prc;
cout<<"\n\n\t discount on product: ";
cin>>Dis;

data.open("database.txt",ios::in);

 if(!data)
   {
    data.open("database.txt", ios::app|ios::out);
    data<<" "<<Pcde<<" "<<Pnm<<" "<<Prc<<" "<<Dis<<"\n";
    data.close();

   }
 else
 {
     data>>c>>n>>p>>d;
     while(!data.eof())
    {
       if(c==Pcde)
       {
         token++;
        }
        data>>c>>n>>p>>d;

    }
    data.close();


    if(token==1)
    goto m;

    else
    {data.open("database.txt",ios::app|ios::out);
     data<<" "<<Pcde<<" "<<Pnm<<" "<<Prc<<" "<<Dis<<"\n";
    data.close();

    }
 }

     cout<<"\n\n\t\t record inserted !";

}
void shopping::edit()
{  fstream data,data1;
   int pkey;
   int token=0;
   int c;
   float p;
   float d;
   string n;

   cout<<"\n\t\t\t modify the record";
   cout<<"\n\t\t\t product code:";
   cin>>pkey;
   data.open("database.text",ios::in);
   if(!data)
   {
      cout<<"\n\n file doesn't exist" ;

   }
   else {
       data1.open("database1.text",ios::app|ios::out);
       data>>Pcde>>Pnm>>Prc>>Dis;
       while(!data.eof())
       {
           if(pkey==Pcde)
           {
               cout<<"\n\t\t product new code:";
               cin>>c;
               cout<<"\n\t\t name name of the product :";
               cin>>n;
               cout<<"\n\t\t price";
               cin>>p;
               cout<<"\n\t\t discount: ";
               cin>>d;
               data1<<" "<<c<<""<<n<<" "<<p<<" "<<d<<"\n";

               cout<<"\n\t\t\t record edited";
               token ++;
            }
           else
           {
               data1<<" "<<Pcde<<" "<<Pnm<<" "<<Prc<<" "<<Dis<<"\n";

           }
           data>>Pcde>>Pnm>>Prc>>Dis;
       }
       data.close();
       data1.close();
       remove("database.txt");
       rename("database1.txt","database.txt");
       if(token==0)
       {
           cout<<"\n\n record  not found sorry !";
       }
    }

}
void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t delete product ";
    cout<<"\n\n\t product code:";
    cin>>pkey;
    data.open("database.txt ",ios::in);
    if(!data)
    {

      cout<<"file doesn't exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>Pcde>>Pnm>>Prc>>Dis;
        while(!data.eof())
        {
            if(Pcde==pkey){
                cout<<"\n\n\t product delete succesfully";
                token++;
            }
            else
            {
              data1<<" "<<Pcde<<" "<<Pnm<<" "<<Prc<<" "<<Dis<<"\n";
            }
            data>>Pcde>>Pnm>>Prc>>Dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n record not found";

        }
    }

}

void shopping::list()
{ fstream data;
  data.open("database.txt",ios::in);
  cout<<"\n\n|____________________________________\n";
  cout<<"Prono \t\tname\t\tprice\n";
  cout<<"\n\n|___________________________________\n";
  data>>Pcde>>Pnm>>Prc>>Dis;
  while(!data.eof())
  {
      cout<<Pcde<<"\t\t"<<Pnm<<"\t\t"<<Prc<<"\n";
      data>>Pcde>>Pnm>>Prc>>Dis;

  }
  data.close();


}
void shopping::receipt()
{
    fstream data;
int arrc[100];
int arrq[100];
string choice;
int c=0;
float amount=0;
float Dis=0;
float total=0;

cout<<"\n\n\t\t\t\t receipt";
data.open("database.txt",ios::in);
   if(!data)
    {
     cout<<"\n\n empty database";

    }
    else{
       data.close();
         list();
        cout<<"_________________________________\n";
         cout<<"\n                              \n";
         cout<<"\n  please place the order                            \n";
        cout<<"_________________________________\n";
    do
    { m:
         cout<<"\n\n enter  product code :";
         cin>>arrc[c];
         cout<<"\n\nenter the product quantity :";
         cin>>arrq[c];
     for(int i=0; i<c;i++)
     {
         if(arrc[c]==arrc[i])
           {
             cout<<"\n\n duplicate product code . please try again !";
             goto m;
            }
     }
      c++;
      cout<<"\n\n do you want to buy another product? if yes then press y else no: ";
      cin>>choice;
    }
    while(choice=="y");
    cout<<"\n\n\t\t\t_______________receipt__________\n";
    cout<<"\nproduct no \tproduct name\t product quantity \ttprice\tamount\ttamount\tamount with discount\n";
    for(int i=0;i<c;i++)
    {
        data.open("database.txt",ios::in);
        data>>Pcde>>Pnm>>Prc>>Dis;
        while(!data.eof())
        {
            if(Pcde==arrc[i])
           // {
                amount=Prc*arrq[i];
                Dis=amount-(amount*Dis/100);
                total=total+Dis;
                cout<<"\n"<<Pcde<<"\t\t"<<Pnm<<"\t\t"<<arrq[i]<<"\t\t"<<Prc<<"\t"<<amount<<"\t\t"<<Dis;
            //}
            data>>Pcde>>Pnm>>Prc>>Dis;
        }
    }
    data.close();
}
   cout<<"\n\n_____________________________________";
   cout<<"\ntotal amount :"<<total;
}

int main(){
        shopping s;
        s.menu();

    //return 0;
}


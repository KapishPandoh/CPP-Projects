#include<bits/stdc++.h>
using namespace std;


struct Bank
{
   string acc_holder;
   string acc_no;
   float bal;

}bk[100];

map<string,bool> acc_exist;
map<string,int> acc_pos;
int cnt;



void NewAcc()
{
  srand(time(NULL));
  long long int n = rand()%10000000000 + 10000000000;

  string str = to_string(n);

  if(acc_exist[str])
    NewAcc();

  else
  {
      bk[cnt].acc_no = str;

      string name;
      cout<<"\nEnter Account Holder Name : ";
      cin>>name;
      fflush(stdin);

      bk[cnt].acc_holder = name;

      bk[cnt].bal = 0.0;
      acc_pos[str] = cnt ;

      cout<<"\nAccount Created !!!\n";
      cout<<bk[cnt].acc_holder<<" your account no is : "<< bk[cnt].acc_no<<"\n\n";
      cnt++;
      acc_exist[str]=1;
  }
}



void DepAcc()
{
  string acc;
  cout<<"\nEnter Account No. : ";
  cin>>acc;

  if(!acc_exist[acc])
   {
     cout<<"\nAccount Doesn't exist ";
     return;
   }

  int val;
  cout<<"\nEnter Amount to be deposit : ";
  cin>>val;

  int n = acc_pos[acc];
  bk[n].bal += val;

  cout<<"\n"<<val<<" Amount has been Deposited !!";
  cout<<"\nCurrent Account Balance : "<<bk[n].bal;
}



void WithAcc()
{
  string acc;
  cout<<"\nEnter Account No. : ";
  cin>>acc;

  if(!acc_exist[acc])
   {
     cout<<"\nAccount Doesn't exist ";
     return;
   }

  int val;
  cout<<"\nEnter Amount to be withdrawal : ";
  cin>>val;

  int n = acc_pos[acc];

  if(bk[n].bal < val)
  {
    cout<<"\nInSufficient Amount !! ";
    return;
  }

  bk[n].bal -= val;
  cout<<"\n"<<val<<" Amount has been withdrawal !!";
  cout<<"\nCurrent Account Balance : "<<bk[n].bal;
}



void AccEnq()
{
  string acc;
  cout<<"\nEnter Account No. : ";
  cin>>acc;

  if(!acc_exist[acc])
   {
    cout<<"\nAccount Doesn't exist ";
    return;
   }

  int n = acc_pos[acc];
  cout<<"\nAccount Holder    : "<<bk[n].acc_holder;
  cout<<"\nAccount Number    : "<<bk[n].acc_no;
  cout<<"\nAmount in Account : "<<bk[n].bal;

}



int main()
{
   string st(100,'-');
   int x;

   do
   {
      cout<<st<<endl;
      cout<<"\t\t\t\tBanking Record System\n";
      cout<<st<<endl;

      cout<<"\t\tMain Menu\n";
      cout<<"\t 1.New Account \n\t 2.Deposit Amount \n\t 3.Withdraw Amount \n\t 4.Balance Enquiry\n";
      cout<<"\t 5.Exit\n";

      int ch;
      cout<<"\nEnter choice : ";
      cin>>ch;

      switch(ch)
      {
        case 1 :
                 NewAcc();
                 break;

        case 2 :
                  DepAcc();
                  break;

        case 3 :
                 WithAcc();
                 break;

        case 4 :
                  AccEnq();
                  break;

        case 5 :
                  cout<<"\n\nThank You!!!!"<<"\n\n\n";
                  exit(0);

        default :
                  cout<<"\nInvalid choice \n";
                  break;
      }

       cout<<"\n\nEnter 0 to exit or any other no. to continue : ";
       cin>>x;

    system("cls");

   }while(x!=0);

cout<<"\n\nThank You!!!!"<<"\n\n\n";
return 0;
}

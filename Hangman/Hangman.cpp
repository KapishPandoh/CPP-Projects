#include<bits/stdc++.h>
using namespace std;

const int max_tries=5;
vector<string>country {
                      "India" ,
                      "Afghanistan",
                      "Armenia",
                      "Azerbaijan",
                      "Bahrain",
                      "Bangladesh",
                      "Bhutan",
                      "Brunei",
                      "Burma",
                      "Cambodia",
                      "China",
                      "East Timor",
                      "Georgia",
                      "Hong Kong",
                      "Indonesia",
                      "Iran",
                      "Iraq",
                      "Israel",
                      "Japan",
                      "Jordan",
                      "Kazakhstan",
                      "Kuwait",
                      "Kyrgyzstan",
                      "Laos",
                      "Lebanon",
                      "Malaysia",
                      "Mongolia",
                      "Nepal",
                      "North Korea",
                      "Oman",
                      "Philippines"
                      };

bool check(char letter , string cntry , string &unknown)
{
    int i,l=cntry.size();
    int res=0;

    for(i=0;i<l;i++)
    {
       if(letter==cntry[i])
       {
         unknown[i] = letter;
         res++;
       }
    }
return res;
}

int main()
{
   int wrong_guess=0;                      // count no of wrong guesses made
   char letter;                          // user will guess name of country letter by letter

   srand(time(NULL));
   int n = rand()%31;

   string cntry = country[n];
   string unknown(cntry.length(),'*');

   cout<<"\t\t\t\t\t\tH A N G M A N\n";
   cout<<"\n\t\t\tYou have to guess the Country";
   cout<<"\nYou have "<<max_tries<<" guess";


   while(wrong_guess < max_tries)
   {
      cout<<"\n\nGuess the Country : "<<unknown;
      cout<<"\nEnter a letter : ";cin>>letter;

      if(check(letter,cntry,unknown))
        cout<<"\nYou found a letter";

      else
      {
         cout<<"\nWhoops!,Wrong guess";
         wrong_guess++;
      }

      cout<<"\nYou have "<<max_tries-wrong_guess<<" guess left\n";

      if(cntry==unknown)
      {
        cout<<"\n\t\t"<<cntry;
        cout<<"\n\t\tCongratulation!,You got it\n";
        break;
      }
   }

   if(max_tries == wrong_guess)
   {
       cout<<"\n\tSorry you Loose....";
       cout<<"\nYou have been hanged.\n";
       cout<<"\n\t\tThe Country Name was : "<<cntry;
       cout<<"\n\n";
   }
return 0;
}

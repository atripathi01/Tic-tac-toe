#include <iostream>
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

using namespace std;
class Game{
  public:
    int sum;
    int a[9];
    char b[9];
   Game()
    {
      sum=0;
      for(int i=0;i<9;i++)
      {  
      a[i]=0;      
      }
      for(int i=0;i<9;i++)
      {
        b[i]=' ';
      }
    }
    bool checkWinner()
    {
      int winner=0;
      //Horizontal row one      
      if(b[0]==b[1]&&b[1]==b[2]&&a[0]!=0)
      {
        cout<<b[0]<<" wins"<<endl<<endl;          
        winner=1;
      }    
      //Horizontal row two  
      if(a[3]!=0&&b[3]==b[4]&&b[4]==b[5])
      {
        cout<<b[3]<<" wins"<<endl<<endl;
        winner=1;
      }
      //Horizontal row three  
      if(a[6]!=0&&b[6]==b[7]&&b[7]==b[8])
        {
          cout<<b[6]<<" wins"<<endl<<endl;
          winner=1;
        }    
      //Vertical columm one  
      if(a[0]!=0&&b[0]==b[3]&&b[3]==b[6])
        {
          cout<<b[0]<<" wins"<<endl<<endl;
          winner=1;
        }        
      //Vertical columm two  
      if(a[1]!=0&&b[1]==b[4]&&b[4]==b[7])
        {
          cout<<b[1]<<" wins"<<endl<<endl;
          winner=1;
        }        
      //Vertical columm three
      if(a[2]!=0&&b[2]==b[5]&&b[5]==b[8])
        {
          cout<<b[2]<<" wins"<<endl<<endl;
          winner=1;
        }        
      //Diagonal one  
      if(a[0]!=0&&b[0]==b[4]&&b[4]==b[8])
        {
          cout<<b[0]<<" wins"<<endl<<endl;
          winner=1;
        }        
      //Diagonal two  
      if(a[2]!=0&&b[2]==b[4]&&b[4]==b[6])
        {
          cout<<b[2]<<" wins"<<endl<<endl;
          winner=1;
        }
      if(winner==1)
      {
        return true;
      }
      else if(winner==0&&sum>=9)
      {
        cout<<"Tie"<<endl;
        return true;
      }
      else
      {
        return false;
      }
    }
   void turnPlayed(int x)
   {
     if(sum%2==0)
     {
       if(a[x-1]==0)
       {
         a[x-1]=1;
         b[x-1]='X';
         sum++;
       }
       else
       {
         cout<<"Invalid turn"<<endl<<endl;
       }
       cout<<"player one turn played "<<endl<<endl;
     }
     else
     {
       if(a[x-1]==0)
       {
         a[x-1]=1;
         b[x-1]='O';
         sum++;
       }
       else
       {
         cout<<"Invalid turn"<<endl<<endl;
       }
       cout<<"Player two turn played "<<endl<<endl;
     }
   }
   bool continueGame()
   {
     if(checkWinner())
     {
       return false;
     }  
     else{
       return true;
     }
   }
};
int main(){
Game g1;
int option, pos;
cout << "What operation do you want to perform? "<<endl
     <<"0 - Exit Game. "<<endl
     <<"1 - Play Game. "<<endl;
cin>>option;
  cout<<"1  |2  |3  "<<endl;
  cout<<" "<<g1.b[0]<<" | "<<g1.b[1]<<" | "<<g1.b[2]<<" "<<endl;
  cout<<"___|___|___"<<endl;
  cout<<"4  |5  |6  "<<endl;
  cout<<" "<<g1.b[3]<<" | "<<g1.b[4]<<" | "<<g1.b[5]<<" "<<endl;
  cout<<"___|___|___"<<endl;
  cout<<"7  |8  |9  "<<endl;
  cout<<" "<<g1.b[6]<<" | "<<g1.b[7]<<" | "<<g1.b[8]<<" "<<endl;
  cout<<"   |   |   "<<endl<<endl;

do
{
  if(option==0)
  {
    cout<<"You have closed the game"<<endl;
  }
  else if(option==1)
  {
    if(g1.continueGame())
    {
      cout<<"Enter the position"<<endl;
      if(g1.sum%2==0)
      {
        cout<<"player one turn (X turn)"<<endl;
      }
      else
      {
        cout<<"player two turn (O turn)"<<endl;
      }
      cin>>pos;
      if(pos==0)
      {
        cout<<"You have closed the game"<<endl;
        option=0;
        break;
      }
      g1.turnPlayed(pos);
      if(g1.checkWinner())
      {
        cout<<"1  |2  |3  "<<endl;
        cout<<" "<<g1.b[0]<<" | "<<g1.b[1]<<" | "<<g1.b[2]<<" "<<endl;
        cout<<"___|___|___"<<endl;
        cout<<"4  |5  |6  "<<endl;
        cout<<" "<<g1.b[3]<<" | "<<g1.b[4]<<" | "<<g1.b[5]<<" "<<endl;
        cout<<"___|___|___"<<endl;
        cout<<"7  |8  |9  "<<endl;
        cout<<" "<<g1.b[6]<<" | "<<g1.b[7]<<" | "<<g1.b[8]<<" "<<endl;
        cout<<"   |   |   "<<endl<<endl;
        cout<<"Game over"<<endl;
        option=0;
      }
    }
  }
  
  else
  {
    cout << "Enter Proper Option number " << endl<<endl;
    cin>>option;
  }
  if(option==1)
  {
    cout<<"1  |2  |3  "<<endl;
    cout<<" "<<g1.b[0]<<" | "<<g1.b[1]<<" | "<<g1.b[2]<<" "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"4  |5  |6  "<<endl;
    cout<<" "<<g1.b[3]<<" | "<<g1.b[4]<<" | "<<g1.b[5]<<" "<<endl;
    cout<<"___|___|___"<<endl;
    cout<<"7  |8  |9  "<<endl;
    cout<<" "<<g1.b[6]<<" | "<<g1.b[7]<<" | "<<g1.b[8]<<" "<<endl;
    cout<<"   |   |   "<<endl<<endl;
  }
} while (option!=0);
  return 0;
}
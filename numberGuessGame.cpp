#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#include <iostream>
string game(int number);

int main()
{
    srand(time(0));
    int randomized = rand();
    while(true){

    randomized = randomized % 100;
  //  cout<<randomized<<endl; //delete this line later
    string word = game(randomized); 
    if(word == "Win"){
        break;
    }
        
    }
    
    return 0;
}
     
    string game(int number){
        int guess;
        cout<<"Enter your guess: "<<endl;
        cin>>guess;
        if(guess < number){
            cout<<"It's Higher"<<endl;
            return "g";
            
        }
        else if(guess > number){
            cout<<"It's Lower"<<endl;
            return "g";
            
        }
        else if(guess == number){
            cout<<"You win!"<<endl;
            return "Win";
            
            
        }
        
        
    }

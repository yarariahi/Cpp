using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int flag = 0;


    class Human{
        public: 
            int attack;
            int health;
            bool dead = false;
            bool armor = true;
            
            void Attack(){
                
                srand(time(0));
                attack = rand();
                attack = attack % 20;
                //cout<<"human attack "<<attack<<endl;
            }
            
             
                
            
        };
    
    class Monster{
        public:
            int attack;
            int health;
            bool dead = false;
            int random;
             
           
            void Attack(){
                attack = rand();
                attack = attack % 20;
                
                //cout<<"monster attack "<<attack<<endl;
                
            }
        
    };

    

void Duel(Human &warrior, Monster &badguy){

    badguy.health = badguy.health - warrior.attack;
    cout<<"The monster's health is "<<badguy.health<<endl;
    
    if(badguy.attack >= 15){
        if(flag == 0){
            cout<<"The monster has broken your armor"<<endl;
            warrior.armor = false;
            flag = 1;
        }   
    }
    
   
    if(warrior.armor == false){
        warrior.health = warrior.health - (badguy.attack * 1.5);
        cout<<"Your health is "<<warrior.health<<endl;
    }
    else if(warrior.armor == true){
        warrior.health = warrior.health - badguy.attack;
        cout<<"Your health is "<<warrior.health<<endl; 
    }
    
    
    
    if(warrior.health <= 0){
        warrior.dead = true;
    }
    if(badguy.health <= 0){
        badguy.dead = true;
    }
    // int counter = 1;
    // while(counter < 200000000){
    //     counter++;
    //}
    usleep(1000000);
}



int main()
{
    
        Human warrior;
        Monster badguy;
        
        
        warrior.health = 100;
        badguy.health = 100;
        
        
   while(warrior.dead == false){
       
        warrior.Attack();
        badguy.Attack();
        
        Duel(warrior, badguy);
        
      
        
        if(warrior.dead == true){
            cout<<"You died"<<endl;
            break;
        }
        if(badguy.dead == true){
            cout<<"You killed the monster, congrats"<<endl;
            break;
        }   
            
    }

   return 0;
}




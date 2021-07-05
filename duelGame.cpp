using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int flag = 0;
bool flag1 = false;

    class Human{
        public: 
            int attack= 10;
            int health;
            bool dead = false;
            bool armor = true;
            
            void Attack(){
                attack = rand();
                attack = attack % 20;
            }
            
             
                
            
        };
    
    class Monster{
        public:
            int attack;
            int health;
            bool dead = false;
            int random;
             
           
            void Attack(){
                srand(time(0));
                attack = rand();
                attack = attack % 20;
            }
        
    };

void Check(Human warrior, Monster badguy){
        
    
    if(warrior.health <= 0 && badguy.health <= 0){
        cout<<"You both died at the same time"<<endl;
        badguy.dead = true;
        warrior.dead = true;
        flag1 = true;
        return;
    }
    else if(warrior.health <= 0){
        cout<<"You died..."<<endl;
        warrior.dead = true;
        flag1 = true;
        return;
    }
    else if(badguy.health <= 0){
        cout<<"You killed the monster!"<<endl;
        badguy.dead = true;
        flag1 = true;
        return;
    }
}    

void Duel(Human warrior, Monster badguy){

    while(badguy.dead == false || warrior.dead == false){
        
        cout<<flag1<<endl;
        
        Check(warrior, badguy);
        if(flag1 == true){
            return;
        }
        
        badguy.health = badguy.health - warrior.attack;
        cout<<"The monster's health is "<<badguy.health<<endl;
        
        usleep(500000);
        

        
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
        
        Check(warrior, badguy);
        if(flag1 == true){
            return;
        }
       
        usleep(500000);

    }
}

int main()
{
    
        Human warrior;
        Monster badguy;
        
        warrior.health = 100;
        badguy.health = 100;
       
        warrior.Attack();
        badguy.Attack();
        
        Duel(warrior, badguy);

   return 0;
}


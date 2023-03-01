//Siva fam safvepalli      CS202      01/17/22`
//This file contains the main classes or this program 
//The Game class displays the basic rules and gets the input from the external data file and sends it to the Deck class(which is a CLL)


#include "player.h"
//This is the main class for this program most of the game is done here 
class Game
{
   
    public:
             Game();       //class constructor
//             ~Game();      //class destructor
          
	     int read(Deck & call_deck);    //reads in the number of cards reuired for the game
             int load_deck(Deck & call_deck);       //loads in the cards from an external data file 
//             int display_deck(const Deck & call_deck);      //displays the deck of cards
	     int toss();  
         
           //need to implement     
             int player_turn(int toss);   //manages the turns of the players                          
             int display_intro() const;

    protected:
              int num_of_cards;   //The number of cards that are required for the game selected by the players

              player player_one;  //player object that represents player 1
              player player_two;  //player object that represents player 2   

};





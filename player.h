// siva ram sarvepalli   CS202    01/17/22
//This file has classes that maintain the data about the players and their cards 
//The objects of these classes will be used in the Game class to process the game

#include "node.h"
//This class manages the operations of player cards in the array of linear linked lists 
class player_cards
{

	public:
		player_cards();    //class constructor
		//~player_cards();   //class destructor 


		int add_new_card(char * c_name,int c_type,int c_damage);    //adds new card to the list 
		//int add_new_card(card * new_card);    //adds new card to the list 
		int choose_a_card(const char * c_name,int & c_damage);     //allows player to choose a card from the hand based on the cards name
		int display_cards(); //displays the cards that player currently has 
		int remove_a_card(const char * c_name);  //removes a card after it is used in the game
		int display_list(node * head);
                int find_in_list(node * head,const char * c_name,int & damage);
               
              
	protected:

		node ** current_cards;   //pointer to array of LLL
		//recursive functions


};
//This class manages the information about a player 
class player 
{
	public:
		player();    //class constructor
		~player();    //class destructor 

		player(char * p_name,int l_line); //copy constructor 1
		player(player & a_player); //copy constructor 2
                 
        	int read();   
                int add_card(char * c_name,int c_type,int c_damage);
                int play(int & hit_points);
        	int random_cards(int num_of_cards,Deck & call_deck); //picks random cards from the deck 
		int display_stats();
		int use_a_card(char * c_name);
                int edit_lifeline(int damage);              
//		int use_a_card(char * name);      
                int display_hand();
	 
 	protected:

		char * player_name;       //name of the player
		int lifeline;             //player's lifeline 

		player_cards hand_cards;    //represents the cards for the player  


};







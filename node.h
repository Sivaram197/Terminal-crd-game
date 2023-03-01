//Siva ram sarvepalli      CS202      01/17/22
//This file contains the classes the manage a node 
//The card class contains the data for a single card in the deck
//The node class manages the node each node has a card and a next pointer


#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <string>
#include <fstream>
//This is a card class which contains the information of a single card 
class card
{
	public:
		card();    //class constructor
//	          ~card();    //class destructor, added virtual because dynamic binding is used 

		card(char * c_name,int c_type);   //copy constructor 1
		card(const card * to_copy);        //copy constructor 2        

		virtual void display() const;   //dislays the information of one card          
		virtual bool compare(const char * c_name);
                int is_attack();
                int is_defense();
                int is_spell();
	
		
	
               //need to implement 
                virtual int is_match(const char * c_name,int & c_damage);  //used to call the use functions in the derived classes
 		// compare(const char * c_name,card & found_card);	      //compares the names of the cards and returns it

	protected:
		//private: 
		char * card_name;     //name of the card
		int card_type;     //type of the card 
		//bool is_picked;       //mentions if the card is picked or not
};
//This is a node class that manages the operations required for the node 
class node
{

	public:	
                node();  //class constructor 
		node(char * c_name,int c_type,int c_damage);   //copy constructor 1
                node(card * to_copy);                           //copy constructor 2

                
               int add(char * c_name,int c__type,int c_damage);
               int display();
	       int copy(card * &random_card);
               int find(const char * c_name,int & damage);	

               bool cll_hasNext();
               node * cll_getNext();
               void cll_setNext(node * n);
	              
          
	protected:
		node * next; //next pointer 
		card * a_card;  //card pointer  
};


//This class manages a circular linked list which has the deck of cards in it
class Deck
{

	public:
		Deck();      //class constructor 
//		~Deck();       //class destructor 	

		int add(char * card_name,int c_type,int c_damage);       //Adds a new card that is passed in the arguments to the deck 


               //need to implement
		int pick_a_random(card * random_card); //picks a random card from deck and returns it by reference
		int remove_a_card(char * c_name);    //removes a card from the deck 
		int retrive_a_card(char * c_name);   //retrives a card base on its name 
		bool display_cards();

	protected:

		node * rear;    //rear pointer to the circular linked list
		//recursive functions
                int add(node * &rear,char * card_name,int c_type,int c_damage);       //Adds a new card that is passed in the arguments to the deck 

                int pick_a_random(node * rear,card * &random_card,int random_num,int count);
		bool display_cards(node * rear);
};


//This class manages the attack cards
class attack: public card 
{
	public:
		attack();      //class constructor 
		attack(char * c_name,int c_type,int c_damage);  //copy constructor ~ hit_points = damage
                attack(const attack * to_copy);   


		void display() const; //displays the card's details

                  bool compare(const char * c_name);	
		  int is_match(const char * c_name,int & c_damage);
                  
               //need to implement                
              //  void use(const char * c_name);    //uses the card when player plays the game 
                //int action(int c_damage);   //manages the action when the card is used 


	protected:

		int damage;   //damage done by the card

};

//this class manages the defense cards 
class defense: public card
{
	public:
		defense();
		defense(char * c_name,int c_type,int c_hp);
                defense(const defense * to_copy);

               void display() const;
               int is_match(const char * c_name,int & c_damage);
                  bool compare(const char * c_name);	

               //need to implement  
          //      void use(const char * c_name);    //uses the card when player plays the game 
                        
	//	bool is_match(char * name);
            //    int action(int c_hp);   //manages the action when the card is used 

	protected:
		int hp;   //Hp gained by the card

};

//This class manages the spell cards 
class spell: public card 
{
	public:
		spell();
		spell(char * c_name,int c_type,int c_effect);
                spell(const spell * to_copy);
           
                   void display() const; 
		  bool compare(const char * c_name);	
		  int is_match(const char * c_name, int & c_damage);

             //need to implement 
                //void use(const char * c_name);    //uses the card when player plays the game 
                 //int action(int c_effect);   //manages the action when the card is used 

	protected:
		int effect;   //effect that can be caused by the card 


};



















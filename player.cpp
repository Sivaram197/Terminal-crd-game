//siva ram sarvepalli    CS202      01/19/22
//This .cpp file contains the implementation of functions that are in player.h

#include "player.h"
using namespace std;


////////////////////////////////////////// PLAYER FUNCTIONS ////////////////////////////////////////////////
player :: player():player_name(nullptr), lifeline(10) {}    //class constructor
player :: ~player()    //class destructor 
{
	if(player_name)
		delete [] player_name;

	player_name = nullptr;

}
player :: player(char * p_name,int l_line) //copy constructor 1
{
	player_name = new char[strlen(p_name) + 1];
	strcpy(player_name,p_name);

	lifeline = l_line;


}
player :: player(player & a_player) //copy constructor 2
{

	player_name = new char[strlen(a_player.player_name) + 1];
	strcpy(player_name,a_player.player_name);

	lifeline = a_player.lifeline;

}
int player :: edit_lifeline(int damage)
{

    lifeline -= damage;
  return 1;
}
int player :: read()
{

	char p_name[100];

	cout << "Enter the players name: ";
	cin.get(p_name,100,'\n');
	cin.ignore(100,'\n');
	player_name = new char[strlen(p_name) + 1];
	strcpy(player_name,p_name);


	return 1;

}
int player :: play(int & hit_points)
{

	char find_card[100];

	int action;
	int c_damage{0};
	bool turn {true};

	while(turn)
	{	
		cout << "\nIt is " << player_name << "'s turn " << endl;

		cout   << " Here are your options! \n " <<endl
			<< "1.Display my stats" <<endl
			<< "2.Display my cards " <<endl
			<< "3.Use a card " <<endl
			<< "4.Quit game" <<endl
			<< "Enter the serial number to perform the action : ";
		cin >> action;
		cin.ignore(100,'\n');

		switch(action) 
		{

			case 1:     
				display_stats();

				break;

			case 2:

				hand_cards.display_cards();
				break;

			case 3:

				cout << "Enter the name of the card you want to use :";
				cin.get(find_card,100,'\n');
				cin.ignore(100,'\n');


				hand_cards.choose_a_card(find_card,c_damage);

	                        
                                hit_points = c_damage;			
                             
				turn = false;
                                     
                                 

				break;

			case 4:
				cout << "Are you sure you want to Quit the game?(1 for yes, 0 for no):" ;
				cin >> action;
				cin.ignore(100,'\n');

				if(action == 1)
				      return 0;	

				break;


		}

	}
	return 1;

}
int player :: add_card(char * c_name, int c_type, int c_damage)
{

	hand_cards.add_new_card(c_name,c_type,c_damage);

	return 1;
}
int player :: random_cards(int num_of_cards,Deck & call_deck)
{

	card * random_card;

	for(int i = 0; i < num_of_cards; ++i)
	{
		call_deck.pick_a_random(random_card);

		//		         random_card->display();
		//hand_cards.add_new_card(random_card);

	}       

	return 1;
}
int player :: display_stats()
{
	cout << "Player : " << player_name<<endl
		<< "health : " << lifeline << "/10" << endl;

	return 1;

}

int player :: use_a_card(char * name)
{

	int c_damage {0};

	hand_cards.choose_a_card(name,c_damage); 

	return c_damage;

}
int player ::display_hand()
{

	hand_cards.display_cards(); 

	return 1;      
}

//////////////////////////////////////////// PLAYER CARD FUNCTIONS //////////////////////////////////////////////
player_cards :: player_cards()    //class constructor
{
	current_cards = new node * [3];

	for(int i = 0; i < 3; ++i) 
		current_cards[i] = nullptr;  


}
//~player_cards(){}   //class destructor 

//adds new card to the list 
//int player_cards :: add_new_card(card * new_card)
int player_cards :: add_new_card(char * c_name,int c_type,int c_damage)    //adds new card to the list 
{
	int i {0};


	if(c_type == 1)
		i = 0;

	if(c_type == 2)
		i = 1;

	if(c_type == 3)
		i = 2;



	if(!current_cards[i])
	{
		current_cards[i] = new node;
		current_cards[i]->add(c_name,c_type,c_damage);

		return 1;
	}

	node * temp = new node;
	temp->add(c_name,c_type,c_damage);             

	temp->cll_setNext(current_cards[0]);
	current_cards[i] = temp;         


	return 1;          

}  

//allows player to choose a card from the hand based on the cards name
int player_cards :: choose_a_card(const char * c_name,int & damage)
{

	for(int i = 0; i < 3; ++i)
	{
		if(current_cards[i])
		{
		     find_in_list(current_cards[i],c_name,damage);
		}
	}

     return 1;
}

int player_cards :: find_in_list(node * head,const char * c_name,int & damage)
{
	if(!head)  
		return 0;

	head->find(c_name,damage);

	return  display_list(head->cll_getNext());

}
//int player_cards :: remove_a_card(const char * c_name){return 0;}  //removes a card after it is used in the game

//displays the cards that player currently has 
int player_cards :: display_cards() 
{ 
	//   if(!current_cards[0] && !current_cards[1] && !current_cards[2])

	for(int i = 0; i < 3; ++i)
	{
		if(current_cards[i])
		{
			display_list(current_cards[i]);
		}
	}
	return 0;

} 
int player_cards :: display_list(node * head)
{
	if(!head)  
		return 0;

	head->display();

	return  display_list(head->cll_getNext());

}
int player_cards :: remove_a_card(const char * c_name){return 0;}  //removes a card after it is used in the game





















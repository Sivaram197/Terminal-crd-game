//siva ram sarvepalli    CS202    01/24/22
//This .h has all the function implements in the Game class
#include "game.h"
using namespace std;
/*
   data members in the Game class 

   int num_of_cards;   //The number of cards that are required for the game selected by the players
   player player_one;  //player object that represents player 1
   player player_two;  //player object that represents player 2   

 */
Game :: Game():num_of_cards(0)       //class constructor
{}
//Game :: ~Game(){}      //class destructor
//{}
int Game :: read(Deck & call_deck)    //reads in the number of cards reuired for the game
{

//	cout << "Enter the number of cards for each player(max.9 cards per player) : ";
//	cin >> num_of_cards;
//	cin.ignore(100,'\n');

	if(num_of_cards > 9)
	{
		cout << "Please enter valid number for cards " <<endl;

		return 0;
	}

	cout << "\n----- Player one Info -----\n" << endl;
	//    player_one = new player;
	player_one.read();    

	//    player_one.random_cards(num_of_cards,call_deck);

	cout << "\n----- Player two Info ----- \n" << endl;
	//  player_two = new player;
	player_two.read();    

	//  player_two.random_cards(num_of_cards,call_deck);
	return 1;

}
int Game :: load_deck(Deck & call_deck)       //loads in the cards from an external data file 
{

	//temperory variables to get the input   
	char c_name[100];
	int  c_type;
	int c_damage;//	int random_num,i,j = 0;

	ifstream cards;

	cards.open("cards.txt");

	if(cards)
	{
		// for(int i = 0; i < 6; ++i)
		while(!cards.eof())
		{
			cards.get(c_name,100,',');
			cards.ignore(100,',');


			cards >> c_type;
			cards.ignore(100,',');

			cards >> c_damage;
			cards.ignore(100,'\n');


			if(!cards.eof())
				call_deck.add(c_name,c_type,c_damage);


		}


	}

	cards.close();


	//assigning random cards to the players 
	cards.open("cards.txt");



	if(cards)
	{


		for(int i = 0; i < 6; ++i)
		{

			cards.get(c_name,100,',');
			cards.ignore(100,',');


			cards >> c_type;
			cards.ignore(100,',');

			cards >> c_damage;
			cards.ignore(100,'\n');


			// srand(time(NULL));
			// random_num = rand() % 2 + 1;

			//if(i % 2 == 0;i < 8 && !cards.eof())
			//{
			player_one.add_card(c_name,c_type,c_damage);      
			//			++i;
		}

		for(int i = 6; i < 13; ++i)
		{
			//		if(j % 7 == 0 && j < 8 && !cards.eof())
			//		{
			cards.get(c_name,100,',');
			cards.ignore(100,',');


			cards >> c_type;
			cards.ignore(100,',');

			cards >> c_damage;
			cards.ignore(100,'\n');

			player_two.add_card(c_name,c_type,c_damage);

			//		}


		}

		cards.close();
		return 1;

		}
		//int display_deck(const Deck & call_deck);      //displays the deck of cards
		//{}
  return 1;
}
int Game :: player_turn(int toss)   //manages the turns of the players                          
{

			int end{1};
			int hit_points{0};

			while(end) // && player_one->is_alive() && player_two->is_alive())
			{

				if(toss == 1)
				{
					end = player_one.play(hit_points);
					player_two.edit_lifeline(hit_points);   
					++toss;
				}

				else if(toss == 2)
				{
					end = player_two.play(hit_points);
					player_one.edit_lifeline(hit_points);   
					--toss;
				}


			}
    return 1;
}
int Game :: toss()
{

			srand(time(NULL));
		int random_num = rand() % 2 + 1;

		if(random_num == 1)
		{
			cout << "Player 1 won the toss!" << endl;
			return 1;
		}
		else 
			cout << "Player 2 won the toss!" << endl;


		return 2;

}

int Game :: display_intro() const
{

		cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ALIEOMON CARDS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl 
			<< "This is Player on Player card game is based of my childhood fantacies, when me and my friends came up with a unique game that we wanted to create once we get good knowledge on Game designing \n" 
			<< "Our imaginary game was much more complex than this but I used the basic concepts of that game to fill the stats of the cards that are used in this game.\n"
			<< "\nALIEOMON CARDS has a deck of 21 cards that are either Attack, defence or spell type and each player has a lifeline of 10.Each player is given 7 cards at random " <<endl
			<< "A set of random cards will be distributed to each player from the deck at the start of the game, players can view all the cards in the deck pre-game." <<endl
			<< "Each player can use one card per turn and the winner is decided if the opponent player lifeline goes to 0 or the player who has lesser lifeline points at the end of the game. " <<endl
			<< "To start the game a player is chosen randomly and the player turns are decided based on that. " << endl
			<< "Player options are displayed when you start the game. Hope you enjoy this game!" <<endl
			<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n" <<endl;



		return 1;
}



































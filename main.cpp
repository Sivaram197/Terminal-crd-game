//siva ram sarvepalli    CS202    01/19/22
//This is the main file the client calls are done here and the main prompts to the user are given from here too


#include "game.h"
using namespace std;



int main()
{
    Deck call_deck;
    Game call_game;
    player a_player;
    card * random_card;
     
    call_game.load_deck(call_deck);

//     call_deck.display_cards();
    int end {0};
    int resp {0};
    int resp1{0};
  
    call_game.display_intro(); 
   
          
      cout << "Are you ready to START the game(Enter 1 for yes,0 for no) : " ;
      cin >> end;
      cin.ignore(100,'\n');

   
      if(end == 1)
      { 
         //reads in the names of the players 
            resp = call_game.read(call_deck);
  

          cout << "Do you want to display the deck before going into the program? ";
          cin >> resp1;
          cin.ignore(100,'\n');

          if(resp1)
              call_deck.display_cards();
         

        if(resp)
        {
             cout << "Cards have been distibuted to the players !! \nThe Game is on !! \n" << endl;
                
            int toss = call_game.toss();
 
            call_game.player_turn(toss);
       
            //call_deck.pick_a_random(random_card); 
       }
 
   

     } 
         cout << "Thank you for tuning in, Have a Nice day !" << endl;
 
   

   return 1;
 
   
}

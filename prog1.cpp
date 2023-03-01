//siva ram sarvepalli    CS202      01/19/22
//This .cpp file contains the implementation of functions that are in game.h and node.h



#include "game.h"

using namespace std;

/////////////////////////////////////////// CARD FUCNTIONS ////////////////////////////////////////////////////////////

//class constructor
card :: card(): card_name(nullptr),card_type(0)
{}
//class destructor
//card :: ~card()
//{

//	if(card_name)
	//	delete [] card_name;

//	card_name = nullptr;
//}
//copy constructor 1
card :: card(char * c_name,int c_type):card_name(nullptr),card_type(0)
{
	card_name = new char[strlen(c_name) + 1];
	strcpy(card_name,c_name);

	card_type = c_type;

	//       cout << "\n card name = " << card_name <<endl;
	//      cout << "card card  " <<endl;

}
//copy constructor 2        
card :: card(const card * to_copy)
{
	card_name = new char[strlen(to_copy->card_name) + 1];
	strcpy(card_name,to_copy->card_name);

	card_type = to_copy->card_type;

}

/*void card :: add(const card & a_card){}   //used to call the add functions in the derived classes
void card :: use(const char * c_name){}  //used to call the use functions in the derived classes
//compares the names of the cards and returns it
bool card :: compare(const char * c_name,card & found_card) 
{

	return false;
}*/
//dislays the information of one card          
void card :: display() const
{

//	cout <<  "card display : Name of the card : " << card_name <<endl;

	return;

}
int card :: is_match(const char * c_name,int & damage)
{
   return 0;
}
bool card :: compare(const char * c_name)
{
   return false;
}
int card :: is_attack()
{
	//cout << "Here "<<endl;
	if(card_type == 1)
		return 1;

	return 0;

}
int card :: is_defense()
{
	if(card_type == 2)
		return 1;

	return 0;

}
int card :: is_spell()
{
	if(card_type == 3)
		return 1;

	return 0;

}
//////////////////////////////////////////////////////// NODE FUNCTIONS ////////////////////////////////////////////////////////////


node :: node():next(nullptr), a_card(nullptr)  //class constructor 
{}
/*
node :: node(char * c_name, int c_type,int c_damage)   //copy constructor 1
{

	if(c_type == 1) 
	{
 	//        cout << "node add " <<endl;
		a_card = new attack(c_name,c_type,c_damage);

		return 1;
	}

	if(c_type == 2) 
	{
		a_card = new defense(c_name,c_type,c_damage);
		return 1;
	}

	if(c_type == 3) 
	{
		a_card = new spell(c_name,c_type,c_damage);
		return 1; 
	}

}
*/
node :: node(card * to_copy)                           //copy constructor 2
{


    const attack * attack_ptr = dynamic_cast<const attack *>(to_copy);
    const defense * defense_ptr = dynamic_cast<const defense *>(to_copy);
    const spell * spell_ptr = dynamic_cast<const spell *>(to_copy);
	
        if(attack_ptr) 
	{

		//        cout << "node add " <<endl;
		a_card = new attack(attack_ptr);
	}

	if(defense_ptr) 
	{
		a_card = new defense(defense_ptr);
	}

	if(spell_ptr) 
	{
		a_card = new spell(spell_ptr);
	}
  

}
//node *& node :: go_next()  //traverses the pointer to next      
//{}
int node :: find(const char * c_name,int & damage)
{

      a_card->is_match(c_name,damage);

   return 1;
} 
int node :: add(char * c_name,int c_type,int c_damage)
{

	if(c_type == 1) 
	{		//        cout << "node add " <<endl;
		a_card = new attack(c_name,c_type,c_damage);
 
		return 1;
	}

	if(c_type == 2) 
	{
		a_card = new defense(c_name,c_type,c_damage);
		return 1;
	}

	if(c_type == 3) 
	{
		a_card = new spell(c_name,c_type,c_damage);
		return 1; 
	}

       cout << "nothing is added " << c_type <<endl;

	return 0;
}
int node :: display()
{

          a_card->display();

	return 0;
}

int node :: copy (card * &random_card)
{
       
      
//      random_card->copy(a_card);
 
   
    const attack * attack_ptr = dynamic_cast<const attack *>(a_card);
 
    if(attack_ptr)
    {
        random_card = new attack(attack_ptr);
         return 1;
    }

    const defense * defense_ptr = dynamic_cast<const defense *>(a_card);
    if(defense_ptr)
    { 
        random_card = new defense(defense_ptr);
        return 1;
    }

    const spell * spell_ptr = dynamic_cast<const spell *>(a_card);
    if(spell_ptr)
    {
         random_card = new spell(spell_ptr);
         return 1;
     }

/*       if(a_card->is_attack()) 
	{		//        cout << "node add " <<endl;


		random_card = new attack(a_card);

		return 1;
	}

	if(a_card->is_defense()) 
	{
		random_card = new defense(a_card);
		return 1;
	}

	if(a_card->is_spell()) 
	{
		random_card = new spell(a_card);
		return 1; 
	}

   //    cout << "nothing is added " << c_type <<endl;
  */ 
   return 0;
}

bool node :: cll_hasNext()
{
    if(next)
         return true;

    return false; 

}
node * node :: cll_getNext()
{
   if(next)
     return next;

   return nullptr;
}
void node :: cll_setNext(node * n)
{
     next = n;

}

//:void node :: connect_cll()  //connects the list 
//{
//if(!next)
// rear->next = rear;  



//}

///////////////////////////////////////////////////////////// DECK FUCNTIONS /////////////////////////////////////////////////////////////////////

Deck ::  Deck(): rear(nullptr)     //class constructor 
{}
//~Deck(){}       //class destructor 	


int Deck :: add(char * c_name,int c_type,int c_damage)       //Adds a new card that is passed in the arguments to the deck
{
    
    return add(rear,c_name,c_type,c_damage);
}
int Deck :: add(node * &rear,char * c_name,int c_type,int c_damage)       //Adds a new card that is passed in the arguments to the deck
{

	if(!rear)
	{
		rear = new node;
		rear->add(c_name,c_type,c_damage);       
                rear->cll_setNext(rear);
	//	rear->display();
                return 1;
	
        }  

                   
 
        node * new_node = new node;
        new_node->add(c_name,c_type,c_damage);
    
        node * temp = rear->cll_getNext();   //temp = rear->next

        new_node->cll_setNext(temp);   //new_node->next = rear-next
        rear->cll_setNext(new_node);   //rear->next = new_node
        this->rear = new_node;                        //rear = new_node 

       
	return 1;          
} 

 //picks a random card from deck and returns it by reference
int Deck :: pick_a_random(card * random_card)
{
    
     	srand(time(NULL));
     int random_num = rand() % 20 + 1;

     int count = 0; 

     pick_a_random(rear->cll_getNext(),random_card,random_num,count);
 
   //cout << "rand nu " << random_num <<endl;//     cout << "retrived card : " << random_card.display() <<endl;
   return 1;         

}

int Deck :: pick_a_random(node * rear,card * &random_card,int random_num,int count)
{
     if(count == random_num)
     {
            rear->copy(random_card);
           
          
    //     rear->display();
//        cout << "Display retrive " << endl;
  //      random_card->display();
         return 1;
     }
       
     ++count;

    pick_a_random(rear->cll_getNext(),random_card,random_num,count);
   
    return 0;
    
}
int Deck :: remove_a_card(char * c_name){return 0;}    //removes a card from the deck 
int Deck :: retrive_a_card(char * c_name){return 0;}   //retrives a card base on its name 
bool Deck :: display_cards()
{
	//cout << "Deck display " <<endl;
	return display_cards(rear->cll_getNext());
//	return true; 
}
bool Deck :: display_cards(node * rear)
{

    if(rear == this->rear)
    { 
          rear->display();     
          return true;
     }

	   rear->display();

	return display_cards(rear->cll_getNext());
}

//////////////////////////////////////////////// ATTACK FUCNTIONS ///////////////////////////////////////////

attack :: attack():damage(0){}   //class constructor 
attack :: attack(char * c_name,int c_type,int c_damage):card(c_name,c_type)  //copy constructor ~ hit_points = damage
{
     damage = c_damage;
    //cout << "Attack damage : " << damage <<endl;
}
attack :: attack(const attack * to_copy):card(to_copy)
{
	damage = to_copy->damage;
}

/*void attack :: add(const card & a_card)    //adds the card to the data structure 
  {
  attack(a_card);

  return;
  }*/
//void attack ::use(const char * c_name)   //uses the card when player plays the game 
//{ 
//	return;
//}
//int attack ::action(int c_damage){ return 0;}   //manages the action when the card is used 

//displays the card's details
int attack :: is_match(const char * c_name,int & c_damage)
{        
     if(compare(c_name))
         c_damage = damage;

   return 0;
}
bool attack :: compare(const char * c_name)
{

     if(strcmp(card_name,c_name) == 0)\
              return true;

      return false;


}
void attack ::display() const
{
   if(card_type == 1)
   {
       
	cout << "Card name : " << card_name <<endl ;
	cout   << "Card type : Attack " <<endl
		<< "Damage : " << damage <<endl;
    }


	return; 
} 


////////////////////////////////////////// DEFENSE FUNCTIONS /////////////////////////////////////////////////////////////

defense :: defense():hp(0) {}
defense :: defense(char * c_name,int c_type,int c_hp):card(c_name,c_type),hp(c_hp)
{
    //cout << " Def damage : " << hp <<endl;
}
defense :: defense(const defense * to_copy):card(to_copy)
{
	hp = to_copy->hp;
    //cout << " Def damage : " << hp <<endl;

}
//void defense :: add(const card & a_card){}    //adds the card to the data structure 
//void defense :: use(const char * c_name){return; }   //uses the card when player plays the game 

//int defense :: action(int c_hp){return 0;}   //manages the action when the card is used 
void defense :: display() const
{
    	
	  //  cout << "Card name : " << card_name <<endl ;
   if(card_type == 2)	
   {
	cout << "Card name : " << card_name <<endl ;
     //a_card->display_name();      
        cout   << "Card type : Defense " <<endl
		<< "Hit points" << hp <<endl;
   }

	return;

}

int defense :: is_match(const char * c_name,int & c_damage)
{        
     if(compare(c_name))
            c_damage = hp;

   return 0;
}
bool defense :: compare(const char * c_name)
{

     if(strcmp(card_name,c_name) == 0)
              return true;

      return false;


}

//////////////////////////////////////// SPELL FUNCTIONS ////////////////////////////////////////////////////

spell :: spell(): effect(0) {}
spell :: spell(char * c_name,int c_type,int c_effect):card(c_name,c_type),effect(c_effect)
{ 
   //cout << "spell damage : " << effect <<endl;
}
spell :: spell(const spell * to_copy):card(to_copy)
{
	effect = to_copy->effect;

}

//void spell :: add(const card & a_card){}    //adds the card to the data structure 
//void spell :: use(const char * c_name){return;}   //uses the card when player plays the game 

//int spell :: action(int c_effect){return 0;}   //manages the action when the card is used 
void spell :: display() const
{
	//card :: display_name();      
	    //cout << "Card name : " << card_name <<endl ;
  if(card_type == 3)
  {
	cout << "Card name : " << card_name <<endl ;
    //a_card->display_name();      
      cout   << "Card type : Attack " <<endl
  		<< "Effects : " << effect << endl;
  }
	return;
} 


int spell :: is_match(const char * c_name,int & c_damage)
{        
     if(compare(c_name))
         c_damage = effect;

   return 0;
}
bool spell :: compare(const char * c_name)
{

     if(strcmp(card_name,c_name) == 0)\
              return true;

      return false;


}


















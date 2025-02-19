
/* Pack.cpp
 *
 * Represents a pack of playing cards
 *
 * by Andrew DeOrio <awdeorio@umich.edu>
 * 2014-12-21
 */
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include "Pack.hpp"
//make Pack_public_tests.exe
// ./Pack_public_tests.exe
  // EFFECTS: Initializes the Pack to be in the following standard order:
  //          the cards of the lowest suit arranged from lowest rank to
  //          highest rank, followed by the cards of the next lowest suit
  //          in order from lowest to highest rank, and so on. 
  // NOTE: The standard order is the same as that in pack.in.
  // NOTE: Do NOT use pack.in in your implementation of this function
  // NOTE: The pack is initially full, with no cards dealt.
  Pack::Pack(){
    int count = 0;
    for (int s = SPADES; s <= DIAMONDS; s++) {
      Suit suit = static_cast<Suit>(s);
      //std::cout << "Suit: " << suit << std::endl;
      for(int r = NINE; r <=ACE; r++){
        Rank rank = static_cast<Rank>(r);
        //std::cout << "Rank: " << rank << std::endl;
        Card card(rank, suit);
        
        cards[count] = card;
        //std::cout << "Added " << cards[count] << " at index " << count << std::endl;
        count++;

      }
    }

    next = 0;
  }
  //make Pack_public_tests.exe
//./Pack_public_tests.exe
  // REQUIRES: pack_input contains a representation of a Pack in the
  //           format required by the project specification
  // MODIFIES: pack_input
  // EFFECTS: Initializes Pack by reading from pack_input.
  // NOTE: The pack is initially full, with no cards dealt.
  Pack::Pack(std::istream& pack_input){
    Card card;
    while(pack_input >> card){
      cards[next] = card;
      next++;
    }
  }

  // REQUIRES: cards remain in the Pack
  // EFFECTS: Returns the next card in the pack and increments the next index
  Card Pack::deal_one(){
    Card card = cards[next];
    next++;
    return card;

  }
  // EFFECTS: Resets next index to first card in the Pack
  void Pack::reset(){
    next = 0; 
  }

  // EFFECTS: Shuffles the Pack and resets the next index. This
  //          performs an in shuffle seven times. See
  //          https://en.wikipedia.org/wiki/In_shuffle.
  void Pack::shuffle(){
    for (int i = 0; i < 7; i++){
      std::vector<Card> temp;
      std::vector<Card> temp69;
      

      for(int i = 0; i < cards.size()/2; i++){
        temp.push_back(cards[i]);
      }
      for(int i = cards.size()/2; i < cards.size(); i++){
        temp69.push_back(cards[i]);
      }
      for(int i = 0; i < cards.size(); i++){
        if(i%2==0){
          cards[i] = temp[i/2];
        }
        else{
          cards[i] = temp69[i/2];
        }
      }
    }
  }

  // EFFECTS: returns true if there are no more cards left in the pack
  bool Pack::empty() const{
    //if next is card size then no more cards left
    return next >= cards.size();
  }
  



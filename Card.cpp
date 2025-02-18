#include <cassert>
#include <iostream>
#include <array>
#include "Card.hpp"

using namespace std;

/////////////// Rank operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const RANK_NAMES[] = {
  "Two",   // TWO
  "Three", // THREE
  "Four",  // FOUR
  "Five",  // FIVE
  "Six",   // SIX
  "Seven", // SEVEN
  "Eight", // EIGHT
  "Nine",  // NINE
  "Ten",   // TEN
  "Jack",  // JACK
  "Queen", // QUEEN
  "King",  // KING
  "Ace"    // ACE
};

Card::Card() {
  
}
Card::Card(Rank rank_in, Suit suit_in){

  rank = rank_in;
  suit = suit_in;
}
//EFFECTS Returns the rank
Rank Card::get_rank() const {
  return rank;
}

//EFFECTS Returns the suit.  Does not consider trump.
Suit Card::get_suit() const {
  return suit;
}

//EFFECTS Returns the suit
//HINT: the left bower is the trump suit!
Suit Card::get_suit(Suit trump) const{
  if(is_left_bower(trump)){
    return trump;
  }
  return suit;
}

//EFFECTS Returns true if card is a face card (Jack, Queen, King or Ace)
bool Card::is_face_or_ace() const{

  if(rank == JACK || rank == QUEEN || rank == KING || rank == ACE){
    return true;
  }
  return false;
}

//EFFECTS Returns true if card is the Jack of the trump suit
bool Card::is_right_bower(Suit trump) const{
  
  if(suit == trump && rank == JACK){
    return true;
  }
  return false;
}

//EFFECTS Returns true if card is the Jack of the next suit
bool Card::is_left_bower(Suit trump) const{
  if(suit == Suit_next(trump) && rank == JACK){
    return true;
  }
  return false;
}

//EFFECTS Returns true if the card is a trump card.  All cards of the trump
// suit are trump cards.  The left bower is also a trump card.
bool Card::is_trump(Suit trump) const{
  if(suit == trump){
    return true;
  }
  if(rank == JACK && is_left_bower(trump)){
    return true;
  }
  return false;
}
//non-member non-operator functions-------------------------------------
Suit Suit_next(Suit suit) {
  return static_cast<Suit>((suit + 1) % 4);//mod 4 to wrap around
}

bool Card_less(const Card &a, const Card &b, Suit trump) {
  if(a.get_rank() == JACK && b.get_rank() == JACK){
    if(a.get_rank() == JACK && a.is_right_bower(trump)){
      return false;
    }
    else{
    return true;
    }
  }
  if(a.get_rank() == JACK){
    return false;
  }
  if(b.get_rank() == JACK){
    return true;
  }
  return (a<b);
}
bool Card_less(const Card &a, const Card &b, const Card &led_card, Suit trump){

  //checks trumps
  if(a.get_suit() == trump && b.get_suit() != trump){
    return false;
  }

  if(a.get_suit() != trump && b.get_suit() == trump){
    return true;
  }

  if(led_card.get_suit() == trump && a.get_suit() == trump && b.get_suit() == trump){
    if(a.get_rank() == JACK && b.get_rank() == JACK){
    if(a.get_rank() == JACK && a.is_right_bower(trump)){
      return false;
    }
    else{
    return true;
    }
  }
  if(a.get_rank() == JACK){
    return false;
  }
  if(b.get_rank() == JACK){
    return true;
  }
  return (a<b);
  }

  //if not trumps then check following suit
  if(a.get_suit() == led_card.get_suit() && b.get_suit() != led_card.get_suit()){
    return false;
  }

  else if(a.get_suit() != led_card.get_suit() && b.get_suit() == led_card.get_suit()){
    return true;
  }

  else if(a.get_suit() == led_card.get_suit() && b.get_suit() == led_card.get_suit()){
    return (a<b);
  }

  return (a<b);

}
//OPERATORS------------------------------------------------------------


//EFFECTS Returns true if lhs is lower value than rhs.
//  Does not consider trump.
bool operator<(const Card &lhs, const Card &rhs){
  
  if(lhs.get_rank() < rhs.get_rank()){
    return true;
  }
  
  return false;
}

//EFFECTS Returns true if lhs is lower value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator<=(const Card &lhs, const Card &rhs){
  if(lhs.get_rank() < rhs.get_rank() || lhs.get_rank() == rhs.get_rank()){
    return true;
  }
  return false;
}

//EFFECTS Returns true if lhs is higher value than rhs.
//  Does not consider trump.
bool operator>(const Card &lhs, const Card &rhs){
  if(lhs.get_rank() > rhs.get_rank()){
    return true;
  }
  return false;
  
}

//EFFECTS Returns true if lhs is higher value than rhs or the same card as rhs.
//  Does not consider trump.
bool operator>=(const Card &lhs, const Card &rhs){
  if(lhs.get_rank() > rhs.get_rank() || lhs.get_rank() == rhs.get_rank()){
    return true;
  }
}

//EFFECTS Returns true if lhs is same card as rhs.
//  Does not consider trump.
bool operator==(const Card &lhs, const Card &rhs){
  if(lhs.get_rank() == rhs.get_rank() && lhs.get_suit() == rhs.get_suit()){
    return true;
  }
  return false;
}

//EFFECTS Returns true if lhs is not the same card as rhs.
//  Does not consider trump.
bool operator!=(const Card &lhs, const Card &rhs){
  if(lhs.get_rank() != rhs.get_rank() || lhs.get_suit() != rhs.get_suit()){
    return true;
    
  }
  return false;
}






//REQUIRES str represents a valid rank ("Two", "Three", ..., "Ace")
//EFFECTS returns the Rank corresponding to str, for example "Two" -> TWO
Rank string_to_rank(const std::string &str) {
  for(int r = TWO; r <= ACE; ++r) {
    if (str == RANK_NAMES[r]) {
      return static_cast<Rank>(r);
    }
  }
  assert(false); // Input string didn't match any rank
  return {};
}

//EFFECTS Prints Rank to stream, for example "Two"
std::ostream & operator<<(std::ostream &os, Rank rank) {
  os << RANK_NAMES[rank];
  return os;
}

//REQUIRES If any input is read, it must be a valid rank
//EFFECTS Reads a Rank from a stream, for example "Two" -> TWO
std::istream & operator>>(std::istream &is, Rank &rank) {
  string str;
  if(is >> str) {
    rank = string_to_rank(str);
  }
  return is;
}



/////////////// Suit operator implementations - DO NOT CHANGE ///////////////

constexpr const char *const SUIT_NAMES[] = {
  "Spades",   // SPADES
  "Hearts",   // HEARTS
  "Clubs",    // CLUBS
  "Diamonds", // DIAMONDS
};

//REQUIRES str represents a valid suit ("Spades", "Hearts", "Clubs", or "Diamonds")
//EFFECTS returns the Suit corresponding to str, for example "Clubs" -> CLUBS
Suit string_to_suit(const std::string &str) {
  for(int s = SPADES; s <= DIAMONDS; ++s) {
    if (str == SUIT_NAMES[s]) {
      return static_cast<Suit>(s);
    }
  }
  assert(false); // Input string didn't match any suit
  return {};
}

//EFFECTS Prints Suit to stream, for example "Spades"
std::ostream & operator<<(std::ostream &os, Suit suit) {
  os << SUIT_NAMES[suit];
  return os;
}

//REQUIRES If any input is read, it must be a valid suit
//EFFECTS Reads a Suit from a stream, for example "Spades" -> SPADES
std::istream & operator>>(std::istream &is, Suit &suit) {
  string str;
  if (is >> str) {
    suit = string_to_suit(str);
  }
  return is;
}


/////////////// Write your implementation for Card below ///////////////


// NOTE: We HIGHLY recommend you check out the operator overloading
// tutorial in the project spec before implementing
// the following operator overload functions:
//   operator<<
//   operator>>
//   operator<
//   operator<=
//   operator>
//   operator>=
//   operator==
//   operator!=

#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}
TEST(test_getRank){
    Card c(KING, HEARTS);
    ASSERT_EQUAL(KING, c.get_rank());
}
TEST(test_getSuit){
    Card c(KING, HEARTS);
    ASSERT_EQUAL(HEARTS, c.get_suit());
}
TEST(test_isFaceOrAceTrue){
    Card c(QUEEN, HEARTS);
    ASSERT_TRUE(c.is_face_or_ace());
}
TEST(isFaceOrAceFalse){
    Card c(TWO, SPADES);
    ASSERT_FALSE(c.is_face_or_ace());
}

// Add more test cases here

TEST_MAIN()

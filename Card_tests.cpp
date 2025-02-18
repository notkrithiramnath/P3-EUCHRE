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
TEST(test_isrightbowerTrue){
    Card c(JACK, SPADES);
    ASSERT_TRUE(c.is_right_bower(SPADES));
}
TEST(test_isrightbowerFALSE){
    Card c(JACK, SPADES);
    ASSERT_EQUAL(c.is_right_bower(HEARTS), false);

}
TEST(test_isleftbowerTrue){
    Card c(JACK, SPADES);
    ASSERT_TRUE(c.is_left_bower(CLUBS));
}

// Add more test cases here

TEST_MAIN()

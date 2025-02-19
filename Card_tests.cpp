#include "Card.hpp"
#include "unit_test_framework.hpp"
#include <iostream>

using namespace std;


TEST(test_card_ctor) {
    Card c(ACE, HEARTS);
    ASSERT_EQUAL(ACE, c.get_rank());
    ASSERT_EQUAL(HEARTS, c.get_suit());
}
TEST(test_card_ctorDefault) {
    Card c;
    ASSERT_EQUAL(TWO, c.get_rank());
    ASSERT_EQUAL(SPADES, c.get_suit());
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
TEST(test_suitNext){
    ASSERT_EQUAL(Suit_next(CLUBS), SPADES);
}
TEST(test_isTrumpTrue){
    Card c(TWO, SPADES);
    ASSERT_FALSE(c.is_trump(HEARTS));
}
TEST(test_isTrumpFalse){
    Card c(TWO, SPADES);
    ASSERT_TRUE(c.is_trump(SPADES));
}
TEST(test_cardLessTrue){
    Card a(TWO, HEARTS);
    Card b(FIVE, HEARTS);
    ASSERT_TRUE(Card_less(a, b, HEARTS));
}
TEST(test_cardLessFalse){
    Card a(NINE, SPADES);
    Card b(THREE, SPADES);
    ASSERT_FALSE(Card_less(a, b, SPADES));
}
TEST(test_operatorLess){
    Card a(THREE, SPADES);
    Card b(NINE, SPADES);
    ASSERT_TRUE(a < b);
}
TEST(test_operatorLessorEqual){
    Card a(THREE, CLUBS);
    Card b(THREE, CLUBS);
    ASSERT_TRUE(a <= b);
}
TEST(test_operatorGreater){
    Card a(FOUR, CLUBS);
    Card b(THREE, CLUBS);
    ASSERT_TRUE(a > b);
}
TEST(test_operatorGreaterorEqual){
    Card a(FOUR, CLUBS);
    Card b(FOUR, CLUBS);
    ASSERT_TRUE(a >= b);
}
TEST(test_operatorEqual){
    Card a(FOUR, CLUBS);
    Card b(FOUR, CLUBS);
    ASSERT_TRUE(a == b);
}
TEST(test_operatorNotEqual){
    Card a(FOUR, CLUBS);
    Card b(THREE, CLUBS);
    ASSERT_TRUE(a != b);
}
// Add more test cases here

TEST_MAIN()

#include "gtest/gtest.h"
#include <string>
#include <iostream>
class KMPMatcher {
 public:
 KMPMatcher(){
 for(auto&& index : nextPos)
   index = 1;
 }
 unsigned int NextComparedIndex(std::string matchedString, std::string::size_type comparedIndex) {
  CalculateKMP(matchedString); 
  return nextPos[comparedIndex];
 }
 private:
 void CalculateKMP(std::string matchedString){
   for(std::string::size_type index = 3;index <= matchedString.size();index++){
      auto previousComparedIndex = index - 1;
      if(matchedString.at(previousComparedIndex - 1) == matchedString.at(nextPos[previousComparedIndex] - 1)){
	nextPos[index] = nextPos[previousComparedIndex] + 1;
      }
   } 
 }
 enum { max_size = 1000};
 std::string::size_type nextPos[max_size];
};
class KMPMatcherTest : public testing::Test {
 protected:
 virtual void SetUp(){
 }

 virtual void TearDown(){
 }
 KMPMatcher matcher;
};
TEST_F(KMPMatcherTest, NextComparedIndex) {
 std::string matchedString = "abcad"; 
 EXPECT_EQ(1u, matcher.NextComparedIndex(matchedString, 1));
 EXPECT_EQ(1u, matcher.NextComparedIndex(matchedString, 2));
 EXPECT_EQ(1u, matcher.NextComparedIndex(matchedString, 3));
 EXPECT_EQ(1u, matcher.NextComparedIndex(matchedString, 4));
 EXPECT_EQ(2u, matcher.NextComparedIndex(matchedString, 5));
}
TEST_F(KMPMatcherTest, NextComparedIndex2){
 std::string matchedString = "aabaabd";
 EXPECT_EQ(2u, matcher.NextComparedIndex(matchedString, 3)); 
 EXPECT_EQ(4u, matcher.NextComparedIndex(matchedString, 7));
}
int main(int argc, char ** argv){
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

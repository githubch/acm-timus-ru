#include "gtest/gtest.h"
#include<string>
#include<iostream>
#include<array>
#include<cstring>
class StrangeDialog {
 enum { Max = 10000000};
 std::string str;
 /*static std::string  words[]={"puton", "out", "output","in","input","one"};*/
 std::array<std::string, 6>  words{{"puton", "out", "output", "in", "input", "one"}};
 int cached[Max];
 public:
 StrangeDialog(std::string inputStr){
  this->str = inputStr;
  std::memset(cached, -1, sizeof(int) * Max); 
 }
 
 bool IsMatched(int index, int wordIndex){
  if(str.compare(index, words[wordIndex].length(), words[wordIndex]) == 0)
    return true;
  return false;
 }

 int IsStrangeDialog(int index){
  if(index >= str.length()) cached[index] =1;
 
  if(cached[index] != -1) return cached[index];
  for(int i = 0;i < 6;i++)
   if(index + words[i].length() <= str.length() && IsMatched(index, i)){
     cached[index] = IsStrangeDialog(index + words[i].length());
     if(cached[index] == 1)
       return cached[index];
   }
  cached[index] = 0; 
  return cached[index];
 }
};

class StrangeDialogTest : public testing::Test{
 protected:
 virtual void SetUp(){
 }

 virtual void TearDown(){
 }

 StrangeDialog* stringDialog;
};

TEST_F(StrangeDialogTest, TestIsStringDialog) {
 std::string dialog = "inonputin";
 stringDialog = new StrangeDialog(dialog);
 EXPECT_EQ(0, stringDialog->IsStrangeDialog(0));
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn1WhenInmputStringArePuton){
 stringDialog = new StrangeDialog("puton");
 EXPECT_EQ(1, stringDialog->IsStrangeDialog(0));
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn1WhenInputStringAreOneputonininputoutoutput){
 stringDialog = new StrangeDialog("oneputonininputoutoutput");
 EXPECT_EQ(1, stringDialog->IsStrangeDialog(0));
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn0WhenInputStringAreOneininputwooutoutput){
 stringDialog = new StrangeDialog("oneininputwooutoutput");
 EXPECT_EQ(0, stringDialog->IsStrangeDialog(0));
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn0WhenInputStringAreoutpu){
 stringDialog = new StrangeDialog("outpu");
 EXPECT_EQ(0, stringDialog->IsStrangeDialog(0));
 delete stringDialog;
}

TEST_F(StrangeDialogTest, should_return_0_when_input_string_are_utput){
 stringDialog = new StrangeDialog("utput");
 EXPECT_EQ(0, stringDialog->IsStrangeDialog(0));
 delete stringDialog;
}

int main(int argc, char ** argv){
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

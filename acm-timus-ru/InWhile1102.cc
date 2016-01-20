#include "gtest/gtest.h"
#include<string>
#include<iostream>
#include<array>
#include<cstring>
class StrangeDialog {
  std::string str;
  std::array<std::string, 6>  words{{"puton", "out", "output", "in", "input", "one"}};
  public:
  StrangeDialog(std::string inputStr){
    this->str = inputStr;
  }

  bool IsMatchedOne(int index){
    auto one = words[5];
    return index < str.length() && str.compare(index, one.length(), one) == 0;
  }

  bool IsMatchedByPuton(int index){
    auto puton = words[0];
    return index < str.length() && str.compare(index, puton.length(), puton) == 0;
  } 

  int NextIndexAfterOne(int index){
    auto one = words[5];
    auto isMatchedWithOne = IsMatchedOne(index);
    if(isMatchedWithOne)
      return one.length();
    return 0;
  }

  int NextIndexAfterPuton(int index){
    auto puton = words[0];
    auto isMatchedWithPuton = IsMatchedByPuton(index);
    if(isMatchedWithPuton)
      return puton.length();
    return 0;
  }

  int NextIndexAfterOut(int index){
    auto out = words[1];
    auto output = words[2];
    auto one = words[5];
    auto puton = words[0];
    
    auto isMachedWithOut = str.compare(index, out.length(), out) == 0;
    if(isMachedWithOut){
        auto isMachedWithOutput = str.compare(index, output.length(), output) == 0;
        auto isMatchedPutonAfterOut = IsMatchedByPuton(index + out.length());
        auto isMathcedWithOneAfterOutput = IsMatchedOne(index + output.length());
        if(isMatchedPutonAfterOut){
          if(isMathcedWithOneAfterOutput){
            return output.length() + one.length();
          }
          else
            return out.length() + puton.length();
        }
        else if(isMachedWithOutput){
          return output.length();
        }

        return out.length();
    }
    return 0;
  }

  int NextIndexAfterIn(int index){
    auto in = words[3];
    auto input = words[4];
    auto one = words[5];
    auto puton = words[0];

    auto isMatchWithIn = str.compare(index, in.length(), in) == 0;
    if(isMatchWithIn){
      auto isMatchedWithInput = str.compare(index, input.length(), input) == 0;
      auto isMatchedPutonAfterIn = IsMatchedByPuton(index + in.length());
      auto isMatchedWithOneAfterInput = IsMatchedOne(index + input.length());
      if(isMatchedPutonAfterIn){
        if(isMatchedWithOneAfterInput){
          return input.length() + one.length();
        }
        return in.length() + puton.length();
      }
      else if(isMatchedWithInput){
        return input.length();
      }
      return in.length();
    }
    return 0;
  }

  bool IsStrangeDialog(){
    auto index = 0;
    auto nextIndex = 0;
    while(index < str.length()){
      auto isMatched = (nextIndex = NextIndexAfterOne(index)) != 0 || (nextIndex = NextIndexAfterPuton(index)) != 0 || (nextIndex = NextIndexAfterIn(index)) != 0 || (nextIndex = NextIndexAfterOut(index)) != 0;
      if(!isMatched || nextIndex == 0)
        return false;
      index = nextIndex + index;
    } 
    return true; 
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
 EXPECT_EQ(false, stringDialog->IsStrangeDialog());
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn1WhenInmputStringArePuton){
 stringDialog = new StrangeDialog("puton");
 EXPECT_EQ(true, stringDialog->IsStrangeDialog());
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn1WhenInputStringAreOneputonininputoutoutput){
 stringDialog = new StrangeDialog("oneputonininputoutoutput");
 EXPECT_EQ(true, stringDialog->IsStrangeDialog());
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn0WhenInputStringAreOneininputwooutoutput){
 stringDialog = new StrangeDialog("oneininputwooutoutput");
 EXPECT_EQ(false, stringDialog->IsStrangeDialog());
 delete stringDialog;
}

TEST_F(StrangeDialogTest, ShouldReturn0WhenInputStringAreoutpu){
 stringDialog = new StrangeDialog("outpu");
 EXPECT_EQ(false, stringDialog->IsStrangeDialog());
 delete stringDialog;
}

TEST_F(StrangeDialogTest, should_return_0_when_input_string_are_utput){
 stringDialog = new StrangeDialog("utput");
 EXPECT_EQ(false, stringDialog->IsStrangeDialog());
 delete stringDialog;
}

int main(int argc, char ** argv){
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

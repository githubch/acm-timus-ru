#include "gtest/gtest.h"
#include <stdio.h>
#include <stdlib.h>
bool IsMatchedStrangeDialog(char*);
TEST(IsStrageDialog, UseDFAToVerify){
  char input[] = "ininputon";
  ASSERT_EQ(true, IsMatchedStrangeDialog(input));
  
  char input1[] = "puton";
  ASSERT_EQ(true, IsMatchedStrangeDialog(input1));

  char input2[] = "inonputin";
  ASSERT_EQ(false, IsMatchedStrangeDialog(input2));

  char input3[] = "oneputonininputoutoutput";
  ASSERT_EQ(true, IsMatchedStrangeDialog(input3));

  char input4[] = "oneininputwooutoutput";
  ASSERT_EQ(false, IsMatchedStrangeDialog(input4));

  char input5[] = "outpu";
  ASSERT_EQ(false, IsMatchedStrangeDialog(input5));

  char input6[] = "utput";
  ASSERT_EQ(false, IsMatchedStrangeDialog(input6));
}

bool IsMatchedStrangeDialog(char* input){
  int state[15][26];
  memset(state, -1, 15 * 26 * sizeof(int));
  state[0]['o' - 'a'] = 1;
  state[0]['p' - 'a'] = 3;
  state[0]['i' - 'a'] = 7;
  state[1]['n' - 'a'] = 2;
  state[1]['u' - 'a'] = 9;
  state[2]['e' - 'a'] = 0;
  state[3]['u' - 'a'] = 4;
  state[4]['t' - 'a'] = 5;
  state[5]['o' - 'a'] = 6;
  state[6]['n' - 'a'] = 0;
  state[7]['n' - 'a'] = 8;
  state[8]['i' - 'a'] = 7;
  state[8]['o' - 'a'] = 1;
  state[8]['p' - 'a'] = 10;
  state[9]['t' - 'a'] = 8;
  state[10]['u' - 'a'] = 11;
  state[11]['t' - 'a'] = 12;
  state[12]['i' - 'a'] = 7;
  state[12]['p' - 'a'] = 3;
  state[12]['o' - 'a'] = 13;
  state[13]['n' - 'a'] = 14;
  state[13]['u' - 'a'] = 9;
  state[14]['p' - 'a'] = 3;
  state[14]['e' - 'a'] = 0;
  state[14]['o' - 'a'] = 1; 
  state[14]['i' - 'a'] = 7;

  /*int acceptedState[] = {0, 8, 12, 14}; this is the accepted state*/ 
  int stateIndex = 0;
  for(int i = 0; i < strlen(input); i ++)
  {
    stateIndex = state[stateIndex][input[i] - 'a'];
    if(stateIndex == -1) return false;
  }
  return stateIndex == 0 || stateIndex == 8 || stateIndex == 12 || stateIndex == 14;
}
int main(int argc, char ** argv){
 ::testing::InitGoogleTest(&argc, argv);
 return RUN_ALL_TESTS();
}

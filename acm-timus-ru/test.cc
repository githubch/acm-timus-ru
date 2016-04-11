#include <iostream>
#include <string.h>
using namespace std;

int state[15][26];
long n;
char s[10000000];
bool IsMatchedStrangeDialog(char* input){
  int stateIndex = 0;
  for(int i = 0; i < strlen(input); i ++)
  {
    stateIndex = state[stateIndex][input[i] - 'a'];
    if(stateIndex == -1) return false;
  }
  return stateIndex == 0 || stateIndex == 8 || stateIndex == 12 || stateIndex == 14;
}

 
int main ()
{
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

    cin>>n;
    for (int i=0;i<n;i++)
    {
      cin>>s;
      if (IsMatchedStrangeDialog(s)) cout<<"YES"<<endl;                                                                                            
      else cout<<"NO"<<endl;
    }
    return (0);
}

#include <iostream>
#include <string.h>
using namespace std;
//        *,  e,  i,  n,  o,  p,  t,  u
int state[][8]={
        {-1, -1,  7, -1,  1,  3, -1, -1},
        {-1, -1, -1,  2, -1, -1, -1,  9},
        {-1,  0, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1,  4},

        {-1, -1, -1, -1, -1, -1,  5, -1},
        {-1, -1, -1, -1,  6, -1, -1, -1},
        {-1, -1, -1, 0,  -1, -1, -1, -1},
        {-1, -1, -1, 8,  -1, -1, -1, -1},

        {-1, -1,  7, -1,  1, 10, -1, -1},
        {-1, -1, -1, -1, -1, -1,  8, -1},
        {-1, -1, -1, -1, -1, -1, -1, 11},
        {-1, -1, -1, -1, -1, -1, 12, -1},
        {-1, -1,  7, -1, 13,  3, -1, -1},

        {-1, -1, -1, 14, -1, -1, -1,  9},
        {-1,  0,  7, -1,  1,  3, -1, -1}

    };
//            'a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z'
int indexOfAlpha[] = {0, 0, 0, 0, 1, 0, 0, 0, 2, 0, 0, 0, 0, 3, 4, 5, 0, 0, 0, 6, 7, 0, 0, 0, 0, 0};

long n;
char s;
int stateIndex = 0;

bool IsMatchedStrangeDialog(){
  return stateIndex == 0 || stateIndex == 8 || stateIndex == 12 || stateIndex == 14;
}

int main ()
{   
    cin>>n;
    for (int i=0;i<n;i++)
    {
      stateIndex = 0;
      cin >> s;
      while(s != '\n' && stateIndex != -1){
        stateIndex = state[stateIndex][indexOfAlpha[s - 'a']];
        cin >> s;
      }
      
      if (IsMatchedStrangeDialog()) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
    return (0);
}


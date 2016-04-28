#include<iostream>
#include<vector>
using namespace std;
vector<int> getPartialMatch(const string N)
{
	int m = N.size();
	vector<int> pi(m, 0);
	auto begin = 1, matched = 0;
	while(begin + matched < m){
		if(begin == 6){
			cout<<N[begin+matched]<<endl;
			cout<<N[matched]<<endl;
			cout<<matched<<endl;
		}
		if(N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else{
			if(matched == 0) begin++;
			else{
				begin += matched - pi[matched-1];
				matched = pi[matched-1];
			}
		}
	}
	return pi;
}

int main(int argc, char**argv){
	string N = "aabaabac";
	auto pi = move(getPartialMatch(N));
	for(auto item : pi){
		cout<<item<<endl;
	}
}

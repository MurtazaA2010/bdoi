#include <bits/stdc++.h>
using namespace std;

struct Candidate {
	 long long score;
	 long long id;
	vector <int>pref;
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	 long long  n, m, x;
	cin>> n>>m>>x;
	
	if(n== 1) {
		cout << 1 <<"\n";
		return 0;
	}
	
	
	vector <int>seats(m);
	for( long long i= 0; i<m; i++) {
		cin>> seats[i];
	}
	vector <Candidate>candidates(n);
	for( long long i= 0; i<n; i++) {
		candidates[i].id = i;
		cin>> candidates[i].score;
		candidates[i].pref.resize(m);
		for( long long j =0; j<m; j++) {
			cin>> candidates[i].pref[j];
			candidates[i].pref[j]--;
		}
	};
	sort(candidates.begin(), candidates.end() , 
		[](const Candidate &a, const Candidate &b) {
			return a.score > b.score ;
		}
	);
	vector <int>acol(n, 0);
	
	for(auto &cand : candidates) {
		for( long long col : cand.pref) {
			if(seats[col] > 0) {
				seats[col]--;
				acol[cand.id] = col;
				break;
			}
		}
	}
	if(acol[x-1] == -1) {
		cout << -1 <<"\n";
	}else {
		cout << acol[x-1]+1 <<"\n";
	}
	
	return 0;
}
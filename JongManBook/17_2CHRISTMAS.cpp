#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int waysToBuy(vector<int> &psum, int K){
	const int MOD = 20091101;
	int result = 0;

	vector<long long> count(K, 0);
	for (int i = 0; i < psum.size(); i++)
		count[psum[i]]++;

	for (int i = 0; i < K; i++)
		if (count[i] >= 2)

			result = (result + ((count[i] * (count[i] - 1)) / 2)) % MOD;

	return result;
}

int maxBuys(vector<int> &psum,int K){
	vector<int> result(psum.size(),0);
	vector<int> previous(K,-1);
	
	for (int i = 0; i < psum.size(); i++)
	{
		if (i > 0)
			result[i] = result[i - 1];
		else
			result[i] = 0;
		
		int loc = previous[psum[i]];

		if (loc != -1)
			result[i] = max(result[i], result[loc] + 1);
			previous[psum[i]] = i;
        
        }
	return result.back();
}

int main() {
	int T;
	cin >> T;

	for(int i = 0;i<T;i++){
		int N,K;
		cin >> N >> K;
		vector<int> D(N);

		for(int j = 0;j<N;j++){
			cin >> D[j];	
		}
		
		vector<int> psum(N+1);
		psum[0] = 0;
		
		for(int z = 1;z<=N;z++){
			psum[z] = (psum[z-1] + D[z-1]) % K;	
		}

		cout << waysToBuy(psum,K) << " "<< maxBuys(psum,K) << endl;
		
	}	
	return 0;
}
checkPrime(){
    check[0] = check[1] = true;
    for(int i = 2; i <= 1000001; i++){
        if(check[i] == false) {
            prime[pn++] = i;
            for(int j = i*2; j <=1000001; j+=i){
                check[j] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    checkPrime();
    int x;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        long long cnt = 0;
        if(x == 0) {
            cout << 0 << '\n';
            continue;
        }
        for(int j = 1; prime[j] < x; j++){
            if(!check[x-prime[j]] && x > prime[j]){
                cnt++;
            }
        }
        if (!check[x / 2])
			cout << cnt / 2 + 1 << '\n';
		else
			cout << cnt / 2 << '\n';
    }
}
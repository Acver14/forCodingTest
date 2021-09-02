
    int num = 2;
    for(int i = 1; i < n+2; i++){
        for(int j = 1; j < n+2; j++){
            int cnt = 0;
            if(a[i][j] == 1) {
                cnt = dfs(i, j, num, 0);
                complex.push_back(cnt);
            }
        }
    }

    sort(complex.begin(), complex.end());
    cout << num-2 << '\n';
    for(int i: complex){
        cout << i << '\n';
    }
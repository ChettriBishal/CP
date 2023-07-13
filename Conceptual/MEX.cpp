    vector<int> a(n);
    for(auto &x: a) cin >> x;

		set<int> mex;

		for(int i=0;i <= n;i++)	mex.insert(i);

		for(int i=0;i < n;i++)
		{
			if (mex.find(a[i]) != mex.end())
				mex.erase(a[i]);
		}

		int currmex = *(mex.begin());

// https://codeforces.com/contest/1375/submission/86004255
// https://codeforces.com/blog/entry/81287

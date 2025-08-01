vector<vector<ll>> generate_subsets(const vector<ll>& arr) {
    ll n = arr.size();
    vector<vector<ll>> all_subsets;

    for (ll mask = 0; mask < (1 << n); ++mask) {
        vector<ll> subset;
        for (ll i = 0; i < n; ++i) {
            if (mask & (1 << i))
                subset.push_back(arr[i]);
        }
        all_subsets.push_back(subset);
    }

    return all_subsets;
}

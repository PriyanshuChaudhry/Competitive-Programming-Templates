ll inclusion_exclusion(const vector<ll>& primes, ll upto) {
    ll n = primes.size();
    ll result = 0;

    for (ll mask = 1; mask < (1 << n); ++mask) {
        ll lcm = 1, bits = 0;

        for (ll i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                bits++;
                lcm = lcm * primes[i] / gcd(lcm, primes[i]);
                if (lcm > upto) break;
            }
        }

        if (lcm > upto) continue;

        ll count = upto / lcm;
        if (bits % 2 == 1)
            result += count;
        else
            result -= count;
    }

    return result;
}

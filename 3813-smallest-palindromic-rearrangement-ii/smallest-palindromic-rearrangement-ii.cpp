class Solution {
public:
    using ll = long long;

    ll LIMIT;

    // Computes C(n,r), but stops if answer exceeds LIMIT.
    ll comb(int n, int r) {
        r = min(r, n - r);

        ll res = 1;

        for (int i = 1; i <= r; i++) {
            res = res * (n - r + i) / i;

            if (res > LIMIT)
                return LIMIT + 1;
        }

        return res;
    }

    // Count number of distinct permutations for current frequencies
    ll countWays(vector<int>& cnt) {

        int rem = 0;
        for (int x : cnt)
            rem += x;

        ll ans = 1;

        int left = rem;

        for (int i = 0; i < 26; i++) {

            if (cnt[i] == 0)
                continue;

            ll c = comb(left, cnt[i]);

            if (ans > LIMIT / c)
                return LIMIT + 1;

            ans *= c;

            if (ans > LIMIT)
                return LIMIT + 1;

            left -= cnt[i];
        }

        return ans;
    }

    string smallestPalindrome(string s, int k) {

        LIMIT = k;

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string mid = "";

        vector<int> half(26);

        int len = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] & 1)
                mid.push_back(char('a' + i));

            half[i] = freq[i] / 2;

            len += half[i];
        }

        if (countWays(half) < k)
            return "";

        string first = "";

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                ll ways = countWays(half);

                if (ways >= k) {

                    first.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        return first + mid + second;
    }
};
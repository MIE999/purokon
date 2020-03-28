#include <bits/stdc++.h>
using namespace std;

//def
#define debug(x) cout << #x << ": " << x << endl
#define out(x) cout << x << endl
#define repeat(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define revrepeat(i, a, b) for (int i = (int)(b)-1; i >= (int)(a); i--)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define revrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define foreach(e, v) for (auto &e : v)
#define all(x) (x).begin(), (x).end()
#define CYES cout << "Yes" << endl
#define CNO cout << "No" << endl
#define SPC(x) cout << fixed << setprecision(x)
#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<ll> vl;
typedef vector<vector<ll>> vll;
typedef pair<int, int> P;
constexpr int MOD = 1e9 + 7;
constexpr int INF = __INT_MAX__;               // 2^31 - 1
constexpr long long INFLL = __LONG_LONG_MAX__; // 2^61 - 1
constexpr int MAX_N = 1e5 + 5;
constexpr double PI = acos(-1);

template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> choco(h);
    rep(j, h) cin >> choco[j];

    int ans = INF;
    rep(bit, (1 << (h - 1))) {
        int cnt = __builtin_popcount(bit);
        bool ok = true;
        vi cum(h + 1, 0);
        vi cusum(h + 1, 0);

        rep(x, w) {
            if (!ok) break;

            auto init = [&]() {
                rep(z, h) {
                    if (choco[z].at(x) == '1')
                        cum[z + 1] = cum[z] + 1;
                    else
                        cum[z + 1] = cum[z];
                }
            };
            init();
            rep(y, h + 1) cusum[y] += cum[y];

            int pre = 0;
            int curr = 0;
            rep(y, h) {
                curr = y + 1;
                if (y > 0 and (bit >> (y - 1) & 1))
                    pre = y;

                int num = cum[curr] - cum[pre];
                if (num > k) {
                    ok = false;
                    break;
                }

                int cunum = cusum[curr] - cusum[pre];
                if (cunum > k) {
                    cnt++;
                    copy(all(cum), cusum.begin());
                    break;
                }
            }
        }
        if (ok) chmin(ans, cnt);
    }

    out(ans);
    return 0;
}

/*
    author : rxhanggs
*/
#include <bits/stdc++.h>
using namespace std;
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()

/*
    Happy Coding
*/

void solve()
{
    long long n, l, r;
    cin >> n >> l >> r;

    vector<long long> a(n);
    for (auto &x : a)
    {
        cin >> x;
    }

    long long sum = 0;
    long long wins = 0;
    bool carried = true;

    for (long long i = 0; i < n; i++)
    {
        if (a[i] >= l && a[i] <= r)
        {
            wins++;
            sum = 0;
        }
        else
        {
            sum += a[i];
            if (sum >= l && sum <= r && carried)
            {
                wins++;
                sum = 0;
                carried = true;
            }
            else
            {
                if (sum < l)
                {
                    carried = true;
                }
                else
                {
                    sum = a[i];
                    carried = true;
                }
            }
        }
    }

    cout << wins << "\n";
}

int main()
{

    fastio;

    solve();

    return 0;
}
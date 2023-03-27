/* __now__or__never__ */
// Good is not good enough.
// Date: 2023-03-27 11:41:38
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
  os << '{';
  for (const auto &x : v)
    os << gap << x;
  return os << '}';
}
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << gap << p.second << ')';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
#ifdef KAMOL
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')' << ':', dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
#define ll long long
#define lll __int128_t
#define pb push_back
#define mp make_pair
#define All(x) (x).begin(), (x).end()
#define sz(z) (int)((z).size())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;
mt19937 rng((uint_fast32_t)chrono::steady_clock::now().time_since_epoch().count());
ll hashPrime = 1610612741;

// Came Up with a simple Idea.
void printMap(map<int, int> x) {
  for (auto i : x) {
    cout << i.first << " ";
  }
  cout << endl;
}
void solve() {
  cout << "Enter the number of referance string length: ";
  int n;
  cin >> n;
  vector<int> ref(n);

  cout << "Enter the referance string: " << endl;

  for (auto &it : ref) {
    cin >> it;
  }
  // dbg(ref);
  cout << "Enter the Frame capacity: " << endl;
  int m;
  cin >> m;
  // cout << "frame cpacity : " << m << endl;
  int falut_number = 0;
  deque<int> last_access;
  for (auto it : ref) {
    auto i = last_access.begin();
    bool found = false;
    for (; i != last_access.end(); i++) {
      if (*i == it) {
        last_access.erase(i);
        last_access.push_back(it);
        found = true;
        break;
      }
    }
    if (found)
      continue;
    if (last_access.size() < m) {
      falut_number++;
      last_access.push_back(it);
    } else {
      falut_number++;
      int victim = last_access.front();
      last_access.pop_front();
      last_access.push_back(it);
      dbg(victim);
    }
  }

  cout << "The nummber of fault page is : " << falut_number << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifdef KAMOL
#endif
  int test = 1;
  // cin>>test;
  while (test--) {
    solve();
  }
  return 0;
}
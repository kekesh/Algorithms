/* ID: ekfrmd1
   LANG: C++
   TASK: pprime
*/
#include <math.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)

using namespace std;

void init();
bool is_palindrome(int num);
void setIO();

ifstream fin("pprime.in");
ofstream fout("pprime.out");

ll a, b;

/* STL identifies bool vectors as special containers, so we should use
   char vectors instead. They are more efficient. */
vector<char> sieve(100000005);
vector<char> is_prime(100000005, true);
vector<ll> primes;
vector<ll> multiples;

void setIO() {
  ios_base::sync_with_stdio(0);
  fin.tie(0);
  fout.tie(0);
}

void segmented_sieve(ll a, ll b) {
  /* sqrt(N) separations. */
  ll segment_size = sqrt(b);
  ll count = (b < 2) ? 0 : 1;

  /* We sieve one segment in each iteration of the outer
     sieving loop. Each segment corresponds to the interval
     [i, i + segment_size - 1]. */
  for (ll low = 0; low <= b; low += segment_size) {
    fill(sieve.begin(), sieve.end(), true);
    ll high = low + segment_size - 1;

    /* Simple Sieve of Eratosthenes */
    for (ll i = 3; i * i <= high; i += 2) {
      if (is_prime[i]) {
        primes.push_back(i);
        multiples.push_back(i * i - low);
        for (ll j = i * i; j <= segment_size; j += i) {
          is_prime[j] = false;
        }
      }
    }

    /* Sieve the current segment. */
    F0R(i, primes.size()) {
      ll j = multiples[i];
      for (ll k = 2 * primes[i]; j < segment_size; j += k) {
        sieve[j] = false;
      }
      multiples[i] = j - segment_size;
    }
  }
}

int main() {
  setIO();
  init();

  return 0;
}

ll segment_size;

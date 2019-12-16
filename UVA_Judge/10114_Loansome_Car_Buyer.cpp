#include <assert.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
const ll INFTY = 10e8;

#define F0R(i, a) for (int i = 0; i < (a); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PRINT_ARRAY(a, N)        \
  F0R(z, N) cout << a[z] << " "; \
  cout << "\n"


ofstream fout("output.txt");
ifstream fin("input.in");

int main() {

	double downPay, loan, noRecords;
	int months;
	while (cin >> months >> downPay >> loan >> noRecords) {

		if (months < 0) exit(0);
		double monthlyPayment = loan/months;
		double carWorth = downPay + loan;
		double amountOwed = loan;


		double currRate;
		int currDay;
		double rates[months + 5];
		memset(rates, -1, sizeof(rates));

		F0R(i, noRecords) {
			cin >> currDay >> currRate;
			rates[currDay] = currRate;
		}

		int currMonth = 0;
		double lastUsableRate = rates[currMonth];
		carWorth *= (1 - rates[0]);
		while (amountOwed > carWorth) {

			amountOwed -= monthlyPayment;
			currMonth++;

			if (abs(rates[currMonth] - -1) > 0.005) {
				lastUsableRate = rates[currMonth]; /* Always go in here on iteration 1. */
			}

			carWorth *= (1 - lastUsableRate);
//			cout << "(" << amountOwed << "," << carWorth << ")" << endl; debug
		}

		cout << currMonth << " month";
		if (currMonth != 1) cout << "s";
		cout << endl;
	}

	return 0;

}

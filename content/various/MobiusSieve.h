/**
 * Author: Alex Yu
 * License: CC0
 * Source: Codeforces
 * Description: Linear sieve for Mobius function (can be adapted for multiplicative functions generally)
 * Status: tested in previous contest
 */
// Calculates mobius function values up to n
// 0 if n not square free
// (-1)^k if n product of k distinct primes
// Note mu(1) = 1
vector<int> prime;
bool is_composite[MAXN];
int mu[MAXN]; // -1, 0, 1
void mobius_sieve (int n) {
    mu[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!is_composite[i]) {
            prime.push_back(i);
            mu[i] = -1; // i is prime
        }
        for (size_t j = 0; j < prime.size() &&
                i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) {
                mu[i * prime[j]] = 0; //prime[j] divides i
                break;
            } else {
                mu[i * prime[j]] = -mu[i]; //prime[j] doesnt divide i
            }
        }
    }
}

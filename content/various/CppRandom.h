/**
 * Author: Alex Yu
 * License: CC0
 * Source: CppReference
 * Description: Random (include random, chrono)
 * Status: tested
 */
mt19937 rng(
   chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<int> uid(1, 6);
int x = uid(rng); // 1...6 inclusive
uniform_real_distribution<double> urd(0.0, 1.0);
double y = urd(rng); // [0.0, 1.0)
normal_distribution<double> nd(5.0,2.0);
double z = nd(rng); // mean, stddev (sqrt(var))


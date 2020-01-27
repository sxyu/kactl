/**
 * Author: Alex Yu
 * License: CC0
 * Source: Boost
 * Description: Basic hash for vector/pair
 * Status: tested
 */
// Combine two hashes (from Boost library)
inline void hash_combine(size_t& a, size_t b) {
    a ^= b + 0x9e3779b9 + (a << 6) + (a >> 2)
}
// Hash entire vector using above
template<class T> class vector_hasher {
public:
    size_t operator()(const vector<T> & vec) const {
        size_t seed = vec.size();
        for(auto& i : vec) hash_combine(seed, i);
        return seed;
    }
};

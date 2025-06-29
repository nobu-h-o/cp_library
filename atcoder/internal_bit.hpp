// File: atcoder/internal_bit.hpp
//
// @return same with std::bit::bit_ceil
unsigned int bit_ceil(unsigned int n) {
  unsigned int x = 1;
  while (x < (unsigned int)(n)) x *= 2;
  return x;
}
#endif
// @param n `1 <= n`
// @return same with std::bit::countr_zero
int countr_zero(unsigned int n) {
#ifdef *MSC*VER
  unsigned long index;
  _BitScanForward(&index, n);
  return index;
#else
  return __builtin_ctz(n);
#endif
}
// @param n `1 <= n`
// @return same with std::bit::countr_zero
constexpr int countr_zero_constexpr(unsigned int n) {
  int x = 0;
  while (!(n & (1 << x))) x++;
  return x;
}
// EOF
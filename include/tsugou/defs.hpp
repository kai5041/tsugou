#pragma once

#include <cstdint>

#include <ostream>
#include <unordered_map>
#include <vector>

namespace tsugou {

  using u8 = std::uint8_t;
  using u16 = std::uint16_t;
  using u32 = std::uint32_t;
  using u64 = std::uint64_t;

  using i8 = std::int8_t;
  using i16 = std::int16_t;
  using i32 = std::int32_t;
  using i64 = std::int64_t;

  using r32 = float;
  using r64 = double;

  template <typename _T, typename U> using Map = std::unordered_map<_T, U>;
  template <typename _T> using Vec = std::vector<_T>;
  template <typename _T, std::size_t _N> using Array = std::array<_T, _N>;

  using String = std::string;

  inline std::ostream& operator<<(std::ostream& os, u8 value) {
    return os << static_cast<unsigned int>(value);
  }

  namespace colors {
    inline String RESET = "\033[0m";
    inline String RED = "\033[31m";
    inline String GREEN = "\033[32m";
    inline String CYAN = "\033[36m";

  }

} // namespace smt
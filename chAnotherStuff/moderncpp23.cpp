#include <algorithm>
#include <cctype>
#include <charconv>
#include <cstdint>
#include <cstdlib>
#include <gtest/gtest.h> // Google Test
#include <limits>
#include <string>
#include <string_view>

namespace CppUtils {

// Integer to String (Fast, modern, and concise using std::to_chars)
static auto toString(std::int32_t number) -> std::string {
  std::string buffer(12, '\0'); // Sufficient buffer for int32_t
  auto [ptr, ec] = std::to_chars(buffer.data(), buffer.data() + buffer.size(), number);
  if (ec == std::errc{}) {
    return std::string(buffer.data(), static_cast<size_t>(ptr - buffer.data())); // Trim to actual length
  }
  return {}; // Return empty string on conversion failure - clear error indication
}

// String to Integer (Robust, modern, and handles errors more explicitly)
template <typename IntType>
static auto toInt(std::string_view str) -> IntType {
  if (str.empty()) {
    return 0; // Явно обрабатываем пустой ввод
  }

  str.remove_prefix(std::min(str.find_first_not_of(" \t\n\r\f\v"),
                             str.size())); // Обрезаем начальные пробелы

  bool negative = str.starts_with('-');
  if (negative || str.starts_with('+')) {
    str.remove_prefix(1); // Пропускаем знак
  }

  IntType result = 0;
  const auto [ptr, ec] =
      std::from_chars(str.data(), str.data() + str.size(), result);

  if (ec == std::errc::result_out_of_range) {
    return negative
               ? std::numeric_limits<IntType>::min()
               : std::numeric_limits<IntType>::max(); // Ограничиваем диапазоном
  }
  if (ec != std::errc{}) {
    return 0; // Возвращаем 0 для любых других ошибок преобразования (неверный формат и т.д.) - четкое указание ошибки
  }

  return negative ? -result : result;
}

} // namespace CppUtils

// Google Test Fixture aliase
using ::testing::Test;

TEST_F(Test, Itoa) {
  EXPECT_EQ(CppUtils::toString(123), "123");
  EXPECT_EQ(CppUtils::toString(-456), "-456");
  EXPECT_EQ(CppUtils::toString(0), "0");
  EXPECT_EQ(CppUtils::toString(std::numeric_limits<std::int32_t>::max()),
            "2147483647");
  EXPECT_EQ(CppUtils::toString(std::numeric_limits<std::int32_t>::min()),
            "-2147483648");
  EXPECT_EQ(CppUtils::toString(9999999),
            "9999999"); // Added test for larger positive number
}

TEST_F(Test, Atoi) {
  EXPECT_EQ(CppUtils::toInt<int32_t>("123"), 123);
  EXPECT_EQ(CppUtils::toInt<int32_t>("-456"), -456);
  EXPECT_EQ(CppUtils::toInt<int32_t>("+789"), 789);
  EXPECT_EQ(CppUtils::toInt<int32_t>("  0  "), 0);
  EXPECT_EQ(CppUtils::toInt<int32_t>(""), 0);
  EXPECT_EQ(CppUtils::toInt<int32_t>("abc"), 0);
  EXPECT_EQ(CppUtils::toInt<int32_t>("123abc"), 123);
  EXPECT_EQ(
      CppUtils::toInt<int32_t>("  - 123"),
      0); // Now correctly returns 0 for invalid format with space after sign
  EXPECT_EQ(
      CppUtils::toInt<int32_t>(" + 123"),
      0); // Now correctly returns 0 for invalid format with space after sign
  EXPECT_EQ(CppUtils::toInt<int32_t>("-2147483648"),
            std::numeric_limits<std::int32_t>::min());
  EXPECT_EQ(CppUtils::toInt<int32_t>("2147483647"),
            std::numeric_limits<std::int32_t>::max());
  EXPECT_EQ(CppUtils::toInt<int32_t>("-2147483649"),
            std::numeric_limits<std::int32_t>::min()); // Underflow clamped
  EXPECT_EQ(CppUtils::toInt<int32_t>("2147483648"),
            std::numeric_limits<std::int32_t>::max()); // Overflow clamped
  EXPECT_EQ(CppUtils::toInt<int32_t>("  +  123 "),
            0); // More whitespace and invalid format
  EXPECT_EQ(CppUtils::toInt<int32_t>(" -  123 "),
            0); // More whitespace and invalid format
}

auto main(int argc, char **argv) -> int {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#include <cstdlib>
#include <cstring>
#include <bitset>
#include <iostream>
#include <ostream>

#include "UNICODE.H"

bool testCodepointEncode(char32_t codepoint, char expected) {
  char encoded = unicode_to_cp437(codepoint);
  if(encoded == expected) {
    return true;
  }

  std::cerr << "Could not encode " << codepoint << " properly:" << std::endl
            << " " << "Encoded : " << encoded  << " (binary: " << std::bitset<32>(encoded ) << ')' << std::endl
            << " " << "Expected: " << expected << " (binary: " << std::bitset<32>(expected) << ')' << std::endl;
  return false;
}

template <unsigned C_SIZE>
bool testEncode(char const (&c)[C_SIZE], char const* expected) {
  char result[C_SIZE];
  unicode_to_cp437(c, result, C_SIZE);
  if(std::strcmp(result, expected) == 0) {
    return true;
  }

  std::cerr << "Could not encode " << c << " properly:" << std::endl
            << " " << "Encoded : " << result   << std::endl
            << " " << "Expected: " << expected << std::endl;
  return false;
}

template <unsigned C_SIZE>
bool testArray(char const (&c)[C_SIZE], char const* expected) {
  auto array = cp437string_array(c);
  if(std::strcmp(array.data(), expected) == 0) {
    return true;
  }
  std::cerr << "Could not encode " << c << " properly:" << std::endl
            << " " << "Encoded : " << array.data() << std::endl
            << " " << "Expected: " << expected     << std::endl;
  return false;
}

template <unsigned C_SIZE>
bool testView(char const (&c)[C_SIZE], char const* expected) {
  auto array = cp437string_array(c);
  auto view = cp437string_view(array.data(), array.size());
  if(std::strncmp(view.data(), expected, view.length()) == 0) {
    return true;
  }
  std::cerr << "Could not view " << c << " properly" << std::endl
            << " " << "Viewed  : " << view.data() << std::endl
            << " " << "Expected: " << expected    << std::endl;
  return false;
}

int main() {

  constexpr cp437string_array<20> smallerArrayConstruction[] = {
    "I",
    "AM"
    "HERE"
  };
  if(!testCodepointEncode(U'\u221A', '\xFB') ||
     !testCodepointEncode(U'\u0040', '\x40') ||
     !testCodepointEncode(U'\u03A3', '\xE4') ||
     !testCodepointEncode(U'\U00020C96', '\xFE')) {
    return 1;
  }

  // Test 1 byte
  if(!testEncode("\u0040", "\x40")) {
    return 2;
  }

  // Test 2 byte
  if(!testEncode("\u03A3", "\xE4")) {
    return 3;
  }

  // Test 3 byte
  if(!testEncode("\u2502", "\xB3")) {
    return 4;
  }

  // Test 4 byte
  if(!testEncode("\U00020C96", "\xFE")) {
    return 5;
  }

  if(!testArray("F ⌠ Z", "\x46\x20\xF4\x20\x5A")) {
    return 6;
  }

  if(!testView("F ⌠ Z", "\x46\x20\xF4\x20\x5A")) {
    return 7;
  }

  const char* foo = "test";
  cp437string_array<5> a(foo, std::strlen(foo) + 1);

  constexpr cp437string_view defaultA;
  constexpr cp437string_view defaultB;

  if(defaultA != defaultB) {
    return 8;
  }

  return 0;
}


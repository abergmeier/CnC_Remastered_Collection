#ifndef UNICODE_H
#define UNICODE_H

#include <cassert>
#include <cinttypes>

constexpr unsigned char unicode_to_cp437(char32_t codepoint) {
    if (codepoint >= 0x0020 && codepoint <= 0x007E) {
        // Matchching values between unicode and cp437
        return codepoint & 0x00FF;
    }

    switch(codepoint) {
    case 0x0000: return 0x00;
    case 0x263A: return 0x01;
    case 0x263B: return 0x02;
    case 0x2665: return 0x03;
    case 0x2666: return 0x04;
    case 0x2663: return 0x05;
    case 0x2660: return 0x06;
    case 0x2022: return 0x08;
    case 0x25CB: return 0x09;
    case 0x25D9: return 0x0A;
    case 0x2642: return 0x0B;
    case 0x2640: return 0x0C;
    case 0x266A: return 0x0D;
    case 0x266B: return 0x0E;
    case 0x263C: return 0x0F;
    case 0x25BA: return 0x10;
    case 0x25C4: return 0x11;
    case 0x2195: return 0x12;
    case 0x203C: return 0x13;
    case 0x00B6: return 0x14;
    case 0x00A7: return 0x15;
    case 0x25AC: return 0x16;
    case 0x21A8: return 0x17;
    case 0x2191: return 0x18;
    case 0x2193: return 0x19;
    case 0x2192: return 0x1A;
    case 0x2190: return 0x1B;
    case 0x221F: return 0x1C;
    case 0x2194: return 0x1D;
    case 0x25B2: return 0x1E;
    case 0x25BC: return 0x1F;
    // Other mappings see above
    case 0x2302: return 0x7F;
    case 0x00C7: return 0x80;
    case 0x00FC: return 0x81;
    case 0x00E9: return 0x82;
    case 0x00E2: return 0x83;
    case 0x00E4: return 0x84;
    case 0x00E0: return 0x85;
    case 0x00E5: return 0x86;
    case 0x00E7: return 0x87;
    case 0x00EA: return 0x88;
    case 0x00EB: return 0x89;
    case 0x00E8: return 0x8A;
    case 0x00EF: return 0x8B;
    case 0x00EE: return 0x8C;
    case 0x00EC: return 0x8D;
    case 0x00C4: return 0x8E;
    case 0x00C5: return 0x8F;
    case 0x00C9: return 0x90;
    case 0x00E6: return 0x91;
    case 0x00C6: return 0x92;
    case 0x00F4: return 0x93;
    case 0x00F6: return 0x94;
    case 0x00F2: return 0x95;
    case 0x00FB: return 0x96;
    case 0x00F9: return 0x97;
    case 0x00FF: return 0x98;
    case 0x00D6: return 0x99;
    case 0x00DC: return 0x9A;
    case 0x00A2: return 0x9B;
    case 0x00A3: return 0x9C;
    case 0x00A5: return 0x9D;
    case 0x20A7: return 0x9E;
    case 0x0192: return 0x9F;
    case 0x00E1: return 0xA0;
    case 0x00ED: return 0xA1;
    case 0x00F3: return 0xA2;
    case 0x00FA: return 0xA3;
    case 0x00F1: return 0xA4;
    case 0x00D1: return 0xA5;
    case 0x00AA: return 0xA6;
    case 0x00BA: return 0xA7;
    case 0x00BF: return 0xA8;
    case 0x2310: return 0xA9;
    case 0x00AC: return 0xAA;
    case 0x00BD: return 0xAB;
    case 0x00BC: return 0xAC;
    case 0x00A1: return 0xAD;
    case 0x00AB: return 0xAE;
    case 0x00BB: return 0xAF;
    case 0x2591: return 0xB0;
    case 0x2592: return 0xB1;
    case 0x2593: return 0xB2;
    case 0x2502: return 0xB3;
    case 0x2524: return 0xB4;
    case 0x2561: return 0xB5;
    case 0x2562: return 0xB6;
    case 0x2556: return 0xB7;
    case 0x2555: return 0xB8;
    case 0x2563: return 0xB9;
    case 0x2551: return 0xBA;
    case 0x2557: return 0xBB;
    case 0x255D: return 0xBC;
    case 0x255C: return 0xBD;
    case 0x255B: return 0xBE;
    case 0x2510: return 0xBF;
    case 0x2514: return 0xC0;
    case 0x2534: return 0xC1;
    case 0x252C: return 0xC2;
    case 0x251C: return 0xC3;
    case 0x2500: return 0xC4;
    case 0x253C: return 0xC5;
    case 0x255E: return 0xC6;
    case 0x255F: return 0xC7;
    case 0x255A: return 0xC8;
    case 0x2554: return 0xC9;
    case 0x2569: return 0xCA;
    case 0x2566: return 0xCB;
    case 0x2560: return 0xCC;
    case 0x2550: return 0xCD;
    case 0x256C: return 0xCE;
    case 0x2567: return 0xCF;
    case 0x2568: return 0xD0;
    case 0x2564: return 0xD1;
    case 0x2565: return 0xD2;
    case 0x2559: return 0xD3;
    case 0x2558: return 0xD4;
    case 0x2552: return 0xD5;
    case 0x2553: return 0xD6;
    case 0x256B: return 0xD7;
    case 0x256A: return 0xD8;
    case 0x2518: return 0xD9;
    case 0x250C: return 0xDA;
    case 0x2588: return 0xDB;
    case 0x2584: return 0xDC;
    case 0x258C: return 0xDD;
    case 0x2590: return 0xDE;
    case 0x2580: return 0xDF;
    case 0x03B1: return 0xE0;
    case 0x00DF: return 0xE1;
    case 0x0393: return 0xE2;
    case 0x03C0: return 0xE3;
    case 0x03A3: return 0xE4;
    case 0x03C3: return 0xE5;
    case 0x00B5: return 0xE6;
    case 0x03C4: return 0xE7;
    case 0x03A6: return 0xE8;
    case 0x0398: return 0xE9;
    case 0x03A9: return 0xEA;
    case 0x03B4: return 0xEB;
    case 0x221E: return 0xEC;
    case 0x03C6: return 0xED;
    case 0x03B5: return 0xEE;
    case 0x2229: return 0xEF;
    case 0x2261: return 0xF0;
    case 0x00B1: return 0xF1;
    case 0x2265: return 0xF2;
    case 0x2264: return 0xF3;
    case 0x2320: return 0xF4;
    case 0x2321: return 0xF5;
    case 0x00F7: return 0xF6;
    case 0x2248: return 0xF7;
    case 0x00B0: return 0xF8;
    case 0x2219: return 0xF9;
    case 0x00B7: return 0xFA;
    case 0x221A: return 0xFB;
    case 0x207F: return 0xFC;
    case 0x00B2: return 0xFD;
    case 0x00A0: return 0xFF;
    case 0x25A0:
    default:
       return 0xFE; // Fallback to ■
    }
}

constexpr void unicode_to_cp437(char const *in, char* out, unsigned const inSize) {
    for (unsigned i = 0, iOut = 0; i != inSize; i++, iOut++) {

      std::uint8_t firstByte = in[i];

      if ((firstByte & 0b10000000) == 0) {
          // 1 byte
          firstByte = firstByte & 0b01111111;
          char32_t const codepoint = firstByte;
          out[iOut] = static_cast<char>(unicode_to_cp437(codepoint));
          continue;
      }

      i++;
      assert(i != inSize);
      //static_assert(i != N, "second byte of utf-8 not available");

      // First bit is 1
      // Handle multiple chars now

      std::uint8_t twoByteId = firstByte & 0b11100000;
      
      std::uint8_t secondByte = in[i] & 0b00111111;

      if (twoByteId == 0b11000000) {
          // 2 byte
          firstByte = firstByte & 0b00011111;
          char32_t const codepoint = firstByte << 6 | secondByte;
          out[iOut] = static_cast<char>(unicode_to_cp437(codepoint));
          continue;
      }

      i++;
      assert(i != inSize);
      //static_assert(i != N, "third byte of utf-8 not available");

      std::uint8_t thirdByte = in[i] & 0b00111111;

      std::uint8_t threeByteId = firstByte & 0b11110000;

      if (threeByteId == 0b11100000) {
          // 3 bytes
          firstByte = firstByte & 0b00001111;
          char32_t const codepoint = firstByte << 12 | secondByte << 6 | thirdByte;
          out[iOut] = static_cast<char>(unicode_to_cp437(codepoint));
          continue;
      }

      i++;
      assert(i != inSize);
      //static_assert(i =! N, "fourth byte of utf-8 not available");

      std::uint8_t fourthByte = in[i] & 0b00111111;

      std::uint8_t fourByteId = firstByte & 0b11111000;

      //static_assert(fourByteId == 0b11110000, "Invalid utf-8 encoding");

      // 4 bytes
      firstByte = firstByte & 0b00000111;
      char32_t const codepoint = firstByte << 18 | secondByte << 12 | thirdByte << 6 | fourthByte;
      out[iOut] = static_cast<char>(unicode_to_cp437(codepoint));
    }
}

template <unsigned N>
class cp437string_array {
public:
  using value_type = char;
  using reference = value_type&;
  using size_type = unsigned;

  constexpr cp437string_array(char const (&text)[N]) :
    chars(), sizes(N) {
    unicode_to_cp437(text, chars, N);
    chars[N - 1] = '\0';
  }

  template <size_type SN>
  constexpr cp437string_array(char const (&text)[SN]) :
    chars(), sizes(SN) {
    static_assert(SN <= N);
    unicode_to_cp437(text, chars, SN);
    chars[SN - 1] = '\0';
  }

  cp437string_array(char const *text, size_type textSize) :
    chars(), sizes(textSize) {
    assert(textSize <= N);
    unicode_to_cp437(text, chars, textSize);
    chars[textSize - 1] = '\0';
  }

  constexpr char* data() noexcept {
      return chars;
  }

  constexpr char const* data() const noexcept {
      return chars;
  }

  constexpr size_type size() const noexcept {
    return sizes;
  }

  reference operator[]( size_type pos ) {
    return chars[pos];
  }
private:
  char chars[N];
  size_type const sizes;
};

// Cannot use std::string_view since its header wants exceptions enabled :(

// Model this after std::string_view
class cp437string_view {
public:
  using CharT = char;
  using const_pointer	= const CharT*;
  using const_reference	= const CharT&;
  using size_type = unsigned;

  constexpr cp437string_view() noexcept :
  chars(nullptr), lengths(0) {
  }

  template<unsigned N>
  constexpr cp437string_view(cp437string_array<N> const& a) :
  chars(a.data()), lengths(a.size() - 1) {
  }

  constexpr cp437string_view(const_pointer data, size_type length) :
  chars(data), lengths(length) {
  }

  constexpr const_pointer data() const noexcept {
    return chars;
  }

  constexpr size_type length() const noexcept {
    return lengths;
  }

  constexpr const_reference operator[](size_type pos) const {
    return chars[pos];
  }
private:
  const CharT*chars;
  size_type lengths;
};

constexpr bool operator==(cp437string_view const& lhs, cp437string_view const& rhs) {
  if (lhs.data() != rhs.data()) {
    return false;
  }

  return lhs.length() == rhs.length();
}

constexpr bool operator!=(cp437string_view const& lhs, cp437string_view const& rhs) {
  return !operator==(lhs, rhs);
}

template <unsigned N>
void strcpy(cp437string_array<N>& dest, cp437string_view const& src) {
  assert(src.length() <= (N - 1));

  strcpy(dest.data(), src.data());
}

cp437string_view::size_type strlen(cp437string_view const& text) {
  return text.length();
}

#endif // UNICODE_H

/*
 * A simple class to perform stream I/O on individual bits.
 * Before reading any bits, ensure your input stream still has valid inputs.
 */
#include <iostream>
#include <cassert>
#include <vector>

class BitIO {
 public:
  // Construct with one of either an input stream or output (the other null)
  BitIO(std::ostream* os, std::istream* is);
  using bits_t = std::vector<bool>;

  // Flushes out any remaining output bits and trailing zeros, if any:
  ~BitIO();

  BitIO(const BitIO&) = default;
  BitIO(BitIO&&) = default;
  BitIO& operator=(const BitIO&) = default;
  BitIO& operator=(BitIO&&) = default;

  // Output a single bit (buffered)
  void output_bit(bool bit);

  // Read a single bit (or trailing zero)
  bool input_bit();

  private:
    std::ostream* os_;
    std::istream* is_;
    int bitnum_; //int that tracks which bit is the next bit that we're outputting.
    unsigned char writeByte_  = 0x0;
    unsigned char storedByte_ = 0x0;
};

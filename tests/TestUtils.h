#pragma once

#include <iostream>
#include <sstream>
#include <string>

// Captures std::cout output for the lifetime of the object.
class CoutCapture {
public:
  CoutCapture() : old_buf_(std::cout.rdbuf(buffer_.rdbuf())) {}
  ~CoutCapture() { std::cout.rdbuf(old_buf_); }

  std::string str() const { return buffer_.str(); }

private:
  std::ostringstream buffer_;
  std::streambuf *old_buf_;
};

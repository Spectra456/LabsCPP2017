#ifndef IMPL_HPP
#define IMPL_HPP

#include <iostream>
#include <string>

  class TextEditer {
    public:
    explicit TextEditer(const size_t bufferSize = 40, std::istream *input = &std::cin);
    ~TextEditer();
    void formatText();

    private:
    std::string buffer_;
    std::istream *input_;
    char lastChar_;
    size_t bufferMaxSize_;

    void readNumber(std::string &tempString);
    void readWord(std::string &tempString);
    void readDash(std::string &tempString);
    void skipSpace();
  };

#endif //IMPL_HPP


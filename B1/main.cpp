#include "impl.hpp"

enum parts {
  FIRST_PART = 1,
  SECOND_PART,
  THIRD_PART,
  FOURTH_PART
};
int main(int argc, const char * argv[])
{
  if (argc == 1){
    std::cerr << "Incorrect input data";
    return 1;
  }
  int code = 0;
  const int partNumber = atoi(argv[1]);

  switch (partNumber) {
    case FIRST_PART:{
      if (argc < 3 ){
        std::cerr << "Incorrect input data";
        return 1;
      }
      code = firstPart(argv[2]);
      break;
    }
    case SECOND_PART:{
      if (argc < 3){
        std::cerr << "Incorrect input data";
        return 1;
      }
      code = secondPart(argv[2]);
      break;

    }
    case THIRD_PART:{
      code = thirdPart();
      break;
    }
    case FOURTH_PART:{
      if (argc < 4){
        std::cerr << "Incorrect input data";
        return 1;
      }
      code = fourthPart(argv[2],argv[3]);
      break;

    }
    default:
      std::cerr << "Incorrect input data";
      return 1;
  }
  return code;
}

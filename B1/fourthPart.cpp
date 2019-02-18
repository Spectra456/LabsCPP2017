#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <vector>
#include <ctime>
#include "impl.hpp"

void fillRandom(double *array, int size) {
  srand(time(0));
  for (int i = 0; i < size; i++) {
    double randomValue = (static_cast<double>(rand())/RAND_MAX)*2-1;
    randomValue = round (randomValue * 10)/10;
    array[i] = randomValue;
  }
}
int fourthPart(const char *direction, const char *num){
  if (std::strcmp(direction, "ascending") != 0 && std::strcmp(direction, "descending") != 0){
    std::cerr << "Incorect input data, wrong direction";
    return 1;
  }

  const size_t numElements = atoi(num);
  if (numElements <= 0){
    std::cerr << "Incorect input data, invalid lentgh";
    return 1;
  }

  using Collection = std::vector<double>;
  Collection vector(numElements);
  fillRandom(vector.data(), numElements);
  printCollection(vector.begin(), vector.end());
  bool reverse = false;

  if (std::strcmp(direction, "descending") == 0){
    reverse = true;
  }

  sortCollection<Collection, AccesswithAt>(vector, reverse);
  printCollection(vector.begin(), vector.end());

  return 0;
}

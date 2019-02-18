#include <string.h>
#include "impl.hpp"

int firstPart(const char *direction) {
  if (strcmp(direction,"ascending") != 0 && strcmp(direction, "descending") !=0){
    std::cerr << "Wrong direction";
    return 1;
  }
  using VectorCollection = std::vector<int>;
  using ListCollection = std::forward_list<int>;

  VectorCollection vectorAt = {};
  int i = -1;
  while (std::cin && !(std::cin>>i).eof()) {
    if (std::cin.fail() || std::cin.bad()) {
      std::cerr << "Error of reading data";
      return 1;
    }
    vectorAt.push_back(i);
  }

  VectorCollection vectorBracket(vectorAt.begin(),vectorAt.end());
  ListCollection listIterator(vectorAt.begin(),vectorAt.end());

  bool reverseSorting = false;
  if (strcmp(direction,"descending") == 0) {
    reverseSorting = true;
  }

  sortCollection<VectorCollection, AccesswithAt>(vectorAt, reverseSorting);
  sortCollection<VectorCollection, AccessWithBracket>(vectorBracket, reverseSorting);
  sortCollection<ListCollection, AccesswithIterator>(listIterator, reverseSorting);

  printCollection(vectorAt.begin(), vectorAt.end());
  printCollection(vectorBracket.begin(), vectorBracket.end());
  printCollection(listIterator.begin(), listIterator.end());
  
  return 0;
}

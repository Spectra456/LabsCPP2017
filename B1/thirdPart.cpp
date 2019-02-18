#include <vector>
#include <iterator>
#include <iostream>

int thirdPart(){
  std::vector<int> vector = {};
  int i = -1;
  size_t multiplesOf3 = 0;

  while (std::cin && !(std::cin>>i).eof()) {
    if (std::cin.fail() || std::cin.bad()) {
      std::cerr << "Incorect input data ";
      return 1;
    }
  
  if (i == 0){
    break;
  }

  if (i == 3){
    multiplesOf3++;
  }
  vector.push_back(i);
}

if (vector.empty()){
  return 0;
}

if (i != 0) {
  std::cerr << "Incorect input data, missing 0";
  return 1;
}

if (vector.back() == 1) {
  auto it = vector.begin();

  while (it != vector.end()){
    if (*it % 2 == 0) {
      it --;
      vector.erase(it + 1);
    }
    it ++;
  }
}

if(vector.back() == 2) {
  vector.reserve(vector.capacity() + multiplesOf3 * 3);
  auto it = vector.begin();

  while (it != vector.end()){
    if (*it % 3 == 0){
      it = vector.insert(it + 1, 3, 1);
      it += 2;

    }
    it ++;
  }
}
for (auto i = vector.begin(); i != vector.end(); i++){
  std::cout << *i << " ";
}
return 0;
}

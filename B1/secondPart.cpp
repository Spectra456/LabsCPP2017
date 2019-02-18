#include <fstream>
#include <memory>
#include <vector>
#include <iostream>

int secondPart(const char *fileName){
  std::ifstream InputStream(fileName);
  if (!InputStream){
    std::cerr << "Incorrect input file";
    return 1;
  }

  InputStream.seekg(0,InputStream.end);
  const size_t lentgh = InputStream.tellg();
  InputStream.seekg(0,InputStream.beg);

  std::unique_ptr<char[]> array (new char[lentgh]);
  InputStream.read(array.get(),lentgh);

  if (InputStream){
    std::vector<char> vector(array.get(),array.get() + lentgh);
    for (auto i = vector.begin(); i != vector.end(); i++){
      std::cout << *i;
    }
  }
  InputStream.close();
  return 0;
}

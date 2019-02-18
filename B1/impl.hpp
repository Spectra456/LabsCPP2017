#ifndef IMPL_HPP_
#define IMPL_HPP_

#include <vector>
#include <forward_list>
#include <iostream>
#include <memory>

template <typename T>
class MainAccess
{
public:
  using type = typename T::value_type;

  virtual ~MainAccess() = default;
  virtual type* getElement(const T &collection, const typename T::iterator iter) const = 0;

};

template <typename T>
class AccesswithAt: public MainAccess<T>
{
public:
  using type = typename MainAccess<T>::type;

  type* getElement(const T &collection, const typename T::iterator iter) const
  {
    const size_t index = std::distance<typename T::const_iterator>(collection.begin(),iter);
    return const_cast<type*>(&collection.at(index));
  };

};

template <typename T>
class AccessWithBracket: public MainAccess<T>
{
public:
  using type = typename MainAccess<T>::type;

  type* getElement(const T &collection, const typename T::iterator iter) const
  {
  const size_t index = std::distance<typename T::const_iterator>(collection.begin(),iter);
  return const_cast <type*>(&collection[index]);
  };
};

template <typename T>
class AccesswithIterator: public MainAccess<T>
{
public:
  using type = typename MainAccess<T>::type;
  type* getElement(const T &/*collection*/, const typename T::iterator iter) const
  {
  return &(*iter);
  };
};

template <typename TCollection,template<typename> class TAccess>
void sortCollection(TCollection &collection,const bool &reverse)
{
  std::shared_ptr<MainAccess<TCollection> > access = std::make_shared<TAccess<TCollection> >();

  for (auto i= collection.begin(); i !=collection.end(); i++){
    auto currentItem = i;
    for (auto j = std::next(i); j != collection.end(); j++){
      if (reverse ? *access -> getElement(collection, j) > *access -> getElement(collection, currentItem):
          *access -> getElement(collection, j) < *access -> getElement(collection, currentItem)) {
        currentItem = j;
    }
  }
    if (currentItem != i) {
      std::swap(*access -> getElement(collection, i), *access -> getElement(collection, currentItem));
    }
  }

};

template <typename TIterator>
void printCollection(TIterator begin, TIterator end)
{
  for (auto i = begin; i != end; i++){
    std::cout <<*i<<" ";
  }
  std::cout << "\n";
};

int firstPart(const char *direction);
int secondPart(const char *fileName);
int thirdPart();
int fourthPart(const char *direction, const char *num);

#endif // IMPL_HPP_


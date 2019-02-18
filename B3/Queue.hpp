#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <list>
#include <stdexcept>

typedef enum
{
  low,
  normal,
  high
}ElementPriority;

namespace detail
{
  template<typename T>
  class Queue
  {
  public:
    Queue()
    {
      T Element;
      high_delimiter = m_queue.insert(m_queue.end(), Element);
      normal_delimiter = m_queue.insert(m_queue.end(), Element);
    }

    virtual ~Queue() = default;

    void putElement(const T &elem, ElementPriority priority)
    {
      switch(priority)
      {
      case ElementPriority::high:
        m_queue.insert(high_delimiter, elem);
        break;
      case ElementPriority::normal:
        m_queue.insert(normal_delimiter, elem);
        break;
      case ElementPriority::low:
        m_queue.insert(m_queue.end(), elem);
        break;
      }
    }
    T getElement()
    {
      if(empty())
      {
        throw std::invalid_argument("Queue is empty!");
      }
      if(m_queue.begin() != high_delimiter)
      {
        T obverseElement = m_queue.front();
        m_queue.pop_front();
        return obverseElement;
      }
      else if(std::next(high_delimiter) != normal_delimiter)
      {
        T obverseElement = *std::next(high_delimiter);
        m_queue.erase(std::next(high_delimiter));
        return obverseElement;
      }
      else
      {
        T obverseElement = *std::next(normal_delimiter);
        m_queue.erase(std::next(normal_delimiter));
        return obverseElement;
      }
    }
    void Accelerate()
    {
      auto z = std::next(normal_delimiter);
      while(z != m_queue.end())
      {
        m_queue.insert(high_delimiter, *z);
        z++;
        m_queue.erase(std::prev(z));
      }
    }
    bool empty() const
    {
      if((m_queue.begin() == high_delimiter) && (std::next(high_delimiter) == normal_delimiter)
        && (std::next(normal_delimiter) == m_queue.end()))
      {
        return true;
      }
      else
      {
        return false;
      }
    }

    private:
    std::list<T> m_queue;
    typename std::list<T>::iterator high_delimiter, normal_delimiter;
  };
}

int part1();
int part2();

#endif // QUEUE_HPP


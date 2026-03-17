#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
namespace topit
{
  template <class T>
  struct Vector
  {
    Vector();
    Vector(const Vector< T > v&) = delete;
    ~Vector();
    Vector< T >& operator= (const Vector< T >& v) = delete;

    bool empty() const noexcept;

  private:
    T* data_;
    size_t size_, capacity_;
  }; 
}

template <class T>
topit::Vector< T >::Vector():
  data_(nullptr),
  size_(0),
  capacity_(0)
{}

template <class T>
topit::Vector< T >::~Vector()
{
  delete [] data_;
}

template <class T>
bool topit::Vector< T >::empty()
{
  return data_; 
}
#endif

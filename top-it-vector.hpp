#ifndef TOP_IT_VECTOR_HPP
#define TOP_IT_VECTOR_HPP
namespace topit
{
  template <class T>
  struct Vector
  {
    Vector();
    Vector(const Vector< T >& v) = delete;
    ~Vector();
    Vector< T >& operator=(const Vector< T >& v) = delete;

    bool empty() const noexcept;
    void pushBack(T& a);
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

template <class T>
void topit::Vector< T >::pushBack(T& a)
{
  if (capacity_ > size_)
  {
    data_[size_] = a;
    size_++;
  }
  else
  {
    Vector< T > time = new Vector< T >[capacity_ * 2];
    delete [] data_;
    data_ = time;
    data_[size_] = a;
    size_++;	
  }
}
#endif

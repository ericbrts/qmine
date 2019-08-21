#pragma once

#include <vector>


namespace MathUtils
{
  template<class T>
  class Matrix2d
  {
  public:
    Matrix2d() = delete;
    Matrix2d(unsigned int w, unsigned int h);
    ~Matrix2d() = default;

    T get(unsigned int x, unsigned int y) const;
    void set(unsigned int x, unsigned int y, const T& value);

  protected:
    std::vector<T> mData;
    unsigned int mWidth;
    unsigned int mHeight;
  };

  template <class T>
  Matrix2d<T>::Matrix2d(unsigned int w, unsigned int h)
    : mWidth(w)
    , mHeight(h)
  {
    mData.reserve(w*h);
  }

  template <class T>
  T Matrix2d<T>::get(unsigned int x, unsigned int y) const
  {
    if (x >= mWidth || y >= mHeight)
    {
      throw std::out_of_range("Matrix2d: out of bounds");
    }

    return mData.at(x + y*mWidth);
  }

  template <class T>
  void Matrix2d<T>::set(unsigned int x, unsigned int y, const T& value)
  {
    if (x >= mWidth || y >= mHeight)
    {
      throw std::out_of_range("Matrix2d: out of bounds");
    }

    mData[x + y*mWidth] = value;
  }
}

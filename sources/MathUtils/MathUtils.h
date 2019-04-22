#pragma once


namespace MathUtils
{
  template<typename num_type>
  static num_type lerp(num_type a, num_type b, double x) noexcept {
    return static_cast<num_type>(
      static_cast<double>(a) + ((static_cast<double>(b) - static_cast<double>(a)) * x));
  }

  double Pi();
}

#pragma once

#include <cstdio>
#include <math.h>

  const double e = 1;
  const double w = 2;
  const double m = 1;
  const double q =1;
  const double k = 0.5;

template <typename T>
struct VecR3 {
  T x{0};
  T y{0};
  T z{0};
};

template <typename T>
auto operator+(VecR3<T> a, VecR3<T> b) {
  return VecR3<T>{a.x + b.x, a.y + b.y, a.z + b.z};
}

template <typename T>
auto operator*(VecR3<T> a, T c) {
  return VecR3<T>{c * a.x, c * a.y, c * a.z};
}

template <typename T>
auto operator*(T c, VecR3<T> a) {
  return a * c;
}

template <typename T>
auto operator/(VecR3<T> a, T c) {
  return VecR3<T>{a.x / c, a.y / c, a.z /c};
}

struct TState {
  double t{0};
  VecR3<double> position{-e/(pow(w,2)*sqrt(2)),0,0};
  VecR3<double> velocity{0,e/(w*sqrt(2)),-0.25};
};
//position and velocity at inital point

void print_tstate(TState s) {
  printf("%f %f %f %f %f %f %f\n", s.t, s.position.x, s.position.y, s.position.z, s.velocity.x,
         s.velocity.y, s.velocity.z);
}

int main(){
    TState{0,0,0};
}

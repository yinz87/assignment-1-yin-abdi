#pragma once

#include <cstdio>

struct VecR2 {
  double x{0};
  double y{0};
};

auto operator+(VecR2 a, VecR2 b) { return VecR2{a.x + b.x, a.y + b.y}; }
auto operator*(VecR2 a, double c) { return VecR2{c * a.x, c * a.y}; }
auto operator*(double c, VecR2 a) { return a * c; }
auto operator/(VecR2 a, double c) { return VecR2{a.x / c, a.y / c}; }

struct TState {
  double t{0};
  VecR2 position{0, 0};
  VecR2 velocity{0, 0};
};

void print_tstate(TState s) {
  printf("%f %f %f %f %f\n", s.t, s.position.x, s.position.y, s.velocity.x,
         s.velocity.y);
}

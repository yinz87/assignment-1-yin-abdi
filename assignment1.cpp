#include "projectile.hpp"

const double k = 0.5;
const double q = 1;
const double m = 1;
const double E0 = 1;

auto force(TState s) { return VecR3<double>{0, -m * g}; }

auto euler_step(TState s, VecR3<double> accel) {
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt);
  next.velocity = s.velocity + (accel * dt);
  return next;
}

void n_steps(unsigned n, TState state0) {
  print_tstate(state0);
  if (n == 0)
    return;
  else {
    auto state = state0;
    for (unsigned k = 0; k < n; ++k) {
      state = euler_step(state, force(state) / m);
      print_tstate(state);
    }
  }
}

int main() {
  n_steps(1200, TState{0., {0, 0.1}, {5, 5}});
  return 0;
}

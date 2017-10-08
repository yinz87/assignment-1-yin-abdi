#include "assignment1.hpp"

const double dt = 0.001;

auto force(TState s) { return VecR3<double>{cos(k*s.position.z-w*s.t), sin(k*s.position.z-w*s.t) ,0}; }

auto Verlet_step(TState s, VecR3<double> accel) {
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt) + .5 * accel*pow(dt,2);
  //verlet equation for x
  next.velocity = s.velocity + ((accel + accel + accel*dt)/2.0 * dt);
  //verlet equaiton for v
  return next;

}

void n_steps(unsigned n, TState state0) {
  print_tstate(state0);
  if (n == 0)
    return;
  else {
    auto state = state0;
    for (unsigned k = 0; k < n; ++k) {
      state = Verlet_step(state, force(state) / m);
      print_tstate(state);
    }
  }
}

int main() {
  n_steps(1200, TState{0., {0, 0.1}, {5, 5}});
  return 0;
}

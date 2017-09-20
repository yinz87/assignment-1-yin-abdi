# livecode-projectile

A simple implementation of an Euler integrator for projectile motion. Next week, we will add drag and stopping conditions.

## Compilation

Compile with
```bash
clang++-6.0 -std=c++17 -o projectile projectile.cpp
```
and run as
```bash
./projectile
```
and watch your terminal fill with numbers.

## Output

The output will be six columns of numbers with the following order:
```
time [s], x-position [m], y-position [m], x-speed [m/s], y-speed [m/s]
```
Plot the, you get the familiar parabolic trajectory, which will depend on your constants:  
![](example.jpg)

#include "paddle.hpp"

void Paddle::_bind_methods() {
}

void Paddle::move_up(float dy) {
  translate({0, -dy});
}

void Paddle::move_down(float dy) {
  translate({0, +dy});
}

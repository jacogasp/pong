#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class Paddle : public Node2D {
  GDCLASS(Paddle, Node2D)

 protected:
  static void _bind_methods();

 public:
  void move_up(float dx);
  void move_down(float dy);
};
#endif
#ifndef MAIN_HPP
#define MAIN_HPP

#include <godot_cpp/classes/node2d.hpp>
#include <variant>
#include <memory>

#include "input_controller.hpp"


using namespace godot;

class Paddle;

class Main : public Node2D {
  GDCLASS(Main, Node2D)

  Paddle* m_paddle_left;
  std::unique_ptr<InputController> p1;

 protected:
  static void _bind_methods();

 public:
  Main();
  ~Main() = default;

  void _ready() override;
  void _process(float dt);
};

#endif
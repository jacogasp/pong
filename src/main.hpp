#ifndef MAIN_HPP
#define MAIN_HPP

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <memory>
#include <variant>

#include "input_controller.hpp"

using namespace godot;

class Arena;
class Paddle;

class Main : public Node2D {
  GDCLASS(Main, Node2D)
  Arena* m_arena                      = nullptr;
  Paddle* m_paddle_left               = nullptr;
  std::unique_ptr<InputController> p1 = nullptr;
  Ref<PackedScene> m_ball             = nullptr;

 protected:
  static void _bind_methods();

 public:
  Main();
  ~Main() = default;

  void _ready() override;
  void _process(float dt);

  void set_ball_scene(Ref<PackedScene> scene);
  Ref<PackedScene> get_ball_scene();
};

#endif
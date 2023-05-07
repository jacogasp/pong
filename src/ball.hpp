#ifndef BALL_HPP
#define BALL_HPP
#include <godot_cpp/classes/node2d.hpp>

using namespace godot;

class Ball : public Node2D {
  GDCLASS(Ball, Node2D)

  Vector2 m_velocity{0, 0};
  float m_speed{0};

  static void _bind_methods();
  void _process(float delta);
  void _ready() override;
  auto set_velocity(Vector2 velocity) -> void;
  auto get_velocity() const -> Vector2;
  auto get_speed() const -> float;
  auto set_speed(float speed) -> void;
  auto reset() -> void;
};

#endif
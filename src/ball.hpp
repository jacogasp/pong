#ifndef BALL_HPP
#define BALL_HPP

#include <godot_cpp/classes/area2d.hpp>

using namespace godot;

class Ball : public Area2D {
  GDCLASS(Ball, Area2D)

  Vector2 m_velocity{0, 0};
  float m_speed{0};

  static void _bind_methods();
  void _physics_process(float delta);
  void _ready() override;
  void _on_area_entered(Area2D* area);
  auto set_velocity(Vector2 velocity) -> void;
  auto get_velocity() const -> Vector2;
  auto get_speed() const -> float;
  auto set_speed(float speed) -> void;
  auto reset() -> void;
};

#endif
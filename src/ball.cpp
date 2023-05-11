#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "ball.hpp"

void Ball::_bind_methods() {
  ClassDB::bind_method(D_METHOD("set_velocity"), &Ball::set_velocity);
  ClassDB::bind_method(D_METHOD("get_velocity"), &Ball::get_velocity);
  ClassDB::bind_method(D_METHOD("get_speed"), &Ball::get_speed);
  ClassDB::bind_method(D_METHOD("set_speed"), &Ball::set_speed);
  ClassDB::bind_method(D_METHOD("_on_area_entered"), &Ball::_on_area_entered);
  ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "velocity"), "set_velocity",
               "get_velocity");
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

void Ball::_ready() {
  reset();
}

void Ball::_physics_process(float delta) {
  auto engine = Engine::get_singleton();
  if (!engine->is_editor_hint()) {
    translate(m_velocity * m_speed * delta);
  }
}

void Ball::_on_area_entered(Area2D* area) {
  if (area->is_in_group("Walls")) {
    m_velocity.y *= -1;
  } else if (area->is_in_group("Goals") || area->is_in_group("Paddles")) {
    m_velocity.x *= -1;
  }
}

void Ball::set_velocity(Vector2 velocity) {
  m_velocity = velocity;
}

Vector2 Ball::get_velocity() const {
  return m_velocity;
}

void Ball::set_speed(float speed) {
  m_speed = speed;
}

float Ball::get_speed() const {
  return m_speed;
}

void Ball::reset() {
  auto rnd = RandomNumberGenerator();
  rnd.randomize();
  Vector2 v{static_cast<float>(rnd.randf_range(-1, 1)),
            static_cast<float>(rnd.randf_range(-1, 1))};
  set_velocity(v);
}
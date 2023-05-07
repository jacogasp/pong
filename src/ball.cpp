#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include "ball.hpp"

void Ball::_bind_methods() {
  ClassDB::bind_method(D_METHOD("set_velocity"), &Ball::set_velocity);
  ClassDB::bind_method(D_METHOD("get_velocity"), &Ball::get_velocity);
  ClassDB::bind_method(D_METHOD("get_speed"), &Ball::get_speed);
  ClassDB::bind_method(D_METHOD("set_speed"), &Ball::set_speed);

  ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "velocity"), "set_velocity",
               "get_velocity");
  ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "speed"), "set_speed", "get_speed");
}

void Ball::_ready() {
  reset();
}

void Ball::_process(float delta) {
  translate(m_velocity * m_speed * delta);
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
  auto const center = get_viewport_rect().get_center();
  set("position", center);

  auto rnd = RandomNumberGenerator();
  rnd.randomize();
  Vector2 v{static_cast<float>(rnd.randf_range(-1, 1)),
            static_cast<float>(rnd.randf_range(-1, 1))};
  set_velocity(v);
}
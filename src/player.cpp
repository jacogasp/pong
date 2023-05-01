#include <godot_cpp/classes/input.hpp>
#include "player.hpp"


namespace godot {
void Player::_bind_methods() {

}

Player::Player() {

}

Player::~Player() {

}

void Player::_process(float delta) {
  auto input = Input::get_singleton();
  
  if (input->is_action_pressed("move_up")) {
    translate(Vector2{0, -1} * 10);
  }

  if (input->is_action_pressed("move_down")) {
    translate(Vector2{0, 1} * 10);
  }
}

} // namespace godot

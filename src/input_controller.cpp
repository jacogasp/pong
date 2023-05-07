#include <godot_cpp/classes/input.hpp>

#include "input_controller.hpp"
#include "paddle.hpp"

InputController::InputController(Paddle* paddle)
    : m_paddle{paddle} {
}

Command InputController::handle_input(float dt) {
  auto input = godot::Input::get_singleton();

  if (input->is_action_pressed("move_north")) {
    return MoveUpCommand{5.0f};
  }

  if (input->is_action_pressed("move_south")) {
    return MoveDownCommand{5.0f};
  }
  return NullCommand{};
}
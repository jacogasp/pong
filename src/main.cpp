#include "main.hpp"
#include "input_controller.hpp"
#include "paddle.hpp"
#include <godot_cpp/variant/utility_functions.hpp>

Main::Main() {
}

void Main::_bind_methods() {
}

void Main::_ready() {
  m_paddle_left = get_node<Paddle>("LPaddle");
  p1            = std::make_unique<InputController>(m_paddle_left);
}

void Main::_process(float dt) {
  auto command = p1->handle_input(dt);
  std::visit([&](auto& cmd) { cmd.execute(*m_paddle_left); }, command);
}
#include <godot_cpp/classes/resource_loader.hpp>

#include "input_controller.hpp"
#include "main.hpp"
#include "paddle.hpp"

Main::Main() {
}

void Main::_bind_methods() {
  ClassDB::bind_method(D_METHOD("get_ball_scene"), &Main::get_ball_scene);
  ClassDB::bind_method(D_METHOD("set_ball_scene"), &Main::set_ball_scene);
  PropertyInfo ball_info{Variant::OBJECT, "ball_scene",
                         PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"};
  ADD_PROPERTY(ball_info, "set_ball_scene", "get_ball_scene");
}

void Main::_ready() {
  m_paddle_left = get_node<Paddle>("LPaddle");
  p1            = std::make_unique<InputController>(m_paddle_left);

  auto const ball   = m_ball->instantiate();
  add_child(ball);
}

void Main::_process(float dt) {
  auto command = p1->handle_input(dt);
  std::visit([&](auto& cmd) { cmd.execute(*m_paddle_left); }, command);
}
#ifndef INPUT_CONTROLLER_HPP
#define INPUT_CONTROLLER_HPP

#include <memory>

#include "command.hpp"
#include "paddle_controller.hpp"

class Paddle;

class InputController {
  Paddle* m_paddle;

 public:
  InputController(Paddle* paddle);
  Command handle_input(float dt);
};

#endif
#ifndef PADDLE_CONTROLLER_HPP
#define PADDLE_CONTROLLER_HPP

#include <optional>
#include <variant>

class MoveUpCommand;
class MoveDownCommand;

using move_command_t = std::variant<std::monostate, MoveUpCommand, MoveDownCommand>;

class PaddleController {
 public:
  virtual ~PaddleController()                                  = default;
  virtual std::optional<move_command_t> handle_input(float dt) = 0;
};

#endif
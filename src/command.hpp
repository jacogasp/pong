#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <godot_cpp/classes/node.hpp>
#include <variant>

using namespace godot;
class Paddle;

class NullCommand : public std::monostate {
 public:
  NullCommand() = default;
  void execute(Paddle& paddle){};
};

class MoveUpCommand {
  float m_dY;

 public:
  explicit MoveUpCommand(float deltaY);
  void execute(Paddle& paddle);
};

class MoveDownCommand {
  float m_dY;

 public:
  explicit MoveDownCommand(float deltaY);
  void execute(Paddle& paddle);
};

using Command = std::variant<MoveUpCommand, MoveDownCommand, NullCommand>;

#endif
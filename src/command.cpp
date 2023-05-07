#include "command.hpp"
#include "paddle.hpp"

MoveUpCommand::MoveUpCommand(float deltaY)
    : m_dY{deltaY} {
}

void MoveUpCommand::execute(Paddle& paddle) {
  paddle.move_up(m_dY);
}

MoveDownCommand::MoveDownCommand(float deltaY)
    : m_dY{deltaY} {
}

void MoveDownCommand::execute(Paddle& paddle) {
  paddle.move_down(m_dY);
}
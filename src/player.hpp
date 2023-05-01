#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/node2d.hpp>

namespace godot {
class Player : public Node2D {
  GDCLASS(Player, Node2D)

 protected:
  static void _bind_methods();

 public:
  Player();
  ~Player();
  void _process(float delta);
};
} // namespace godot

#endif // PLAYER_H
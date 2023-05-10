#ifndef ARENA_HPP
#define ARENA_HPP

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/reference_rect.hpp>

using namespace godot;

class Arena : public Node2D {
  GDCLASS(Arena, Node2D)

  ReferenceRect* m_border;
  static void _bind_methods();
  void _ready() override;

 public:
  Vector2 get_arena_center() const;
  Vector2 get_arena_size() const;
};

#endif
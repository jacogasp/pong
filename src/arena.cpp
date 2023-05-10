#include "arena.hpp"

void Arena::_bind_methods() {
}

void Arena::_ready() {
  m_border    = get_node<ReferenceRect>("Border");
  auto center = m_border->get_pivot_offset();
  auto rect   = m_border->get_size();
}

Vector2 Arena::get_arena_center() const {
  return m_border->get_pivot_offset();
}

Vector2 Arena::get_arena_size() const {
  return m_border->get_size();
}
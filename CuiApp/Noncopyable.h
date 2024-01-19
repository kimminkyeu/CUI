//
// Created by minky on 2024-01-19.
//

#ifndef CUI_NONCOPYABLE_H
#define CUI_NONCOPYABLE_H

namespace Cm
{

// NOTE: A copyable class should explicitly declare the copy operations
class Copyable
{
protected:
  Copyable() = default;
  ~Copyable() = default;
  Copyable( const Copyable& other ) = default;
  Copyable& operator=( const Copyable& other ) = default;
  // The implicit move operations are suppressed by the declarations above.
  // You may explicitly declare move operations to support efficient moves.
};

class NonCopyable
{
protected:
  NonCopyable() = default;
  ~NonCopyable() = default;

public:
  NonCopyable( const NonCopyable& ) = delete;
  NonCopyable& operator=( const NonCopyable& ) = delete;
};

// NOTE: move-only class should explicitly declare the move operations
class MoveOnly
{
protected:
  MoveOnly() = default;
  ~MoveOnly() = default;
  MoveOnly( MoveOnly&& ) = default;
  MoveOnly& operator=( MoveOnly&& ) = default;
  // The copy operations are implicitly deleted, but you can spell that out explicitly if you want:
public:
  MoveOnly( const MoveOnly& ) = delete;
  MoveOnly& operator=( const MoveOnly& ) = delete;
};

class NonCopyableOrMovable
{
public:
  NonCopyableOrMovable( const NonCopyableOrMovable& ) = delete;
  NonCopyableOrMovable& operator=( const NonCopyableOrMovable& ) = delete;
  // The move operations are implicitly disabled, but you can spell that out explicitly if you want:
  NonCopyableOrMovable( NonCopyableOrMovable&& ) = delete;
  NonCopyableOrMovable& operator=( NonCopyableOrMovable&& ) = delete;
};

}// namespace Cm

#endif//CUI_NONCOPYABLE_H

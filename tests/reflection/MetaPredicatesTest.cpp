// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest
// cmdlinecompile:-freflection-latest

consteval bool has_identifier(auto)
{
  return true;
}

consteval bool is_public(auto)
{
  return true;
}

consteval bool is_function(auto)
{
  return true;
}

consteval bool is_variable(auto)
{
  return true;
}

consteval bool is_type(auto)
{
  return true;
}

consteval bool is_class_type(auto)
{
  return true;
}

consteval bool is_enum_type(auto)
{
  return true;
}

consteval bool is_complete_type(auto)
{
  return true;
}

consteval bool has_linkage(auto)
{
  return true;
}

namespace Ns {
int fn()
{
  return 42;
}
}

int v = 0;

struct Foo {
};

enum class Color {
  red
};

consteval bool check_entities()
{
  return has_identifier(^^v) &&
         is_public(^^v) &&
         is_function(^^Ns::fn) &&
         is_variable(^^v) &&
         is_type(^^Foo) &&
         is_class_type(^^Foo) &&
         is_enum_type(^^Color) &&
         is_complete_type(^^Foo) &&
         has_linkage(^^v);
}

int main()
{
  return static_cast<int>(check_entities());
}

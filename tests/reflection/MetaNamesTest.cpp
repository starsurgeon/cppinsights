// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest
// cmdlinecompile:-freflection-latest

consteval const char* identifier_of(auto)
{
  return "";
}

consteval const char* display_string_of(auto)
{
  return "";
}

consteval const char8_t* u8identifier_of(auto)
{
  return u8"";
}

consteval const char8_t* u8display_string_of(auto)
{
  return u8"";
}

consteval auto parent_of(auto value)
{
  return value;
}

consteval auto object_of(auto value)
{
  return value;
}

consteval auto constant_of(auto value)
{
  return value;
}

namespace Ns {
struct Foo {
  static int value;
};

int v = 0;
int Foo::value = 1;
}

enum class Color {
  red
};

consteval const char* name_of_v()
{
  return identifier_of(^^Ns::v);
}

consteval const char* display_of_v()
{
  return display_string_of(^^Ns::v);
}

consteval const char8_t* u8_name_of_v()
{
  return u8identifier_of(^^Ns::v);
}

consteval const char8_t* u8_display_of_v()
{
  return u8display_string_of(^^Ns::v);
}

consteval const char* parent_of_member()
{
  return identifier_of(parent_of(^^Ns::Foo::value));
}

consteval const char* object_of_member()
{
  return identifier_of(object_of(^^Ns::Foo::value));
}

consteval const char* constant_of_enum()
{
  return identifier_of(constant_of(^^Color::red));
}

int main()
{
  return 0;
}

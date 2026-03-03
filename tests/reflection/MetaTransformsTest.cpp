// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest
// cmdlinecompile:-freflection-latest

consteval auto remove_const(auto value)
{
  return value;
}

consteval auto add_pointer(auto value)
{
  return value;
}

consteval auto remove_reference(auto value)
{
  return value;
}

consteval auto decay(auto value)
{
  return value;
}

consteval auto underlying_type(auto value)
{
  return value;
}

consteval unsigned long rank(auto)
{
  return 2;
}

consteval unsigned long extent(auto, unsigned)
{
  return 3;
}

consteval unsigned long size_of(auto)
{
  return 4;
}

consteval unsigned long alignment_of(auto)
{
  return 4;
}

enum class Color : unsigned int {
  red
};

consteval int stripped()
{
  static_cast<void>(remove_const(^^const int));
  return 0;
}

consteval int pointed()
{
  static_cast<void>(add_pointer(^^int));
  return 0;
}

consteval int unref()
{
  static_cast<void>(remove_reference(^^int&));
  return 0;
}

consteval int decayed()
{
  static_cast<void>(decay(^^int[3]));
  return 0;
}

consteval int underlying()
{
  static_cast<void>(underlying_type(^^Color));
  return 0;
}

consteval unsigned long array_rank()
{
  return rank(^^int[2][3]);
}

consteval unsigned long first_extent()
{
  return extent(^^int[2][3], 0);
}

consteval unsigned long second_extent()
{
  return extent(^^int[2][3], 1);
}

consteval unsigned long int_size()
{
  return size_of(^^int);
}

consteval unsigned long int_alignment()
{
  return alignment_of(^^int);
}

int main()
{
  return static_cast<int>(stripped() + pointed() + unref() + decayed() + underlying() +
                          array_rank() + first_extent() + second_extent() + int_size() + int_alignment());
}

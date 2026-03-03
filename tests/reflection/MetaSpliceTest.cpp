// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest
// cmdlinecompile:-freflection-latest

namespace Ns {
int v = 7;

enum class Color {
  red,
  blue
};
}

int value()
{
  return [:^^Ns::v:];
}

Ns::Color color()
{
  return [:^^Ns::Color::blue:];
}

int main()
{
  return value() == 7 && color() == Ns::Color::blue;
}

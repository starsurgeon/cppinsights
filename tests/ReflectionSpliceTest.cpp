// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest

namespace Ns {
struct Foo { int x; };
int v = 0;
}

constexpr auto r_type = ^^Ns::Foo;
constexpr auto r_decl = ^^Ns::v;
constexpr auto r_ns = ^^Ns;

[:^^int:] a = 1;

template<typename T>
void splice_dependent() {
  constexpr auto r = ^^T;
  [:r:] value{};
}

int main() {
  splice_dependent<int>();
  return a;
}

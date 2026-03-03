// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest
// cmdlinecompile:-freflection-latest

consteval auto forward(auto r)
{
  return __metafunction(0, r, ^^int);
}

int main()
{
  return 0;
}

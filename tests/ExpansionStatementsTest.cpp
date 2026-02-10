// cmdline:-std=c++26
// cmdlineinsights:--extra-arg=-freflection-latest --extra-arg=-fexpansion-statements

// Iterable expansion
void iterable() {
  constexpr int arr[] = {1,2,3};
  template for (constexpr auto x : arr) {
    int y = x;
  }
}

// Init-list expansion
void init_list() {
  template for (constexpr auto x : {4,5}) {
    int y = x;
  }
}

// Destructurable expansion
struct Pair { int a; int b; };
void destructurable() {
  constexpr Pair p{10, 20};
  template for (constexpr auto x : p) {
    int y = x;
  }
}

// Indeterminate expansion
struct WithValues { static constexpr int values[2] = {7,8}; };

template<typename T>
void indeterminate() {
  template for (constexpr auto x : T::values) {
    int y = x;
  }
}

int main() {
  iterable();
  init_list();
  destructurable();
  indeterminate<WithValues>();
}

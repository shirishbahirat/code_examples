#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T, template <class, class...> class C, class... Args>
std::ostream &operator<<(std::ostream &os, const C<T, Args...> &objs) {
  os << __PRETTY_FUNCTION__ << '\n';
  for (auto const &obj : objs)
    os << obj << ' ';
  return os;
}

int main() {
  std::vector<float> vf{1.1, 2.2, 3.3, 4.4};
  std::cout << vf << '\n';

  std::list<char> lc{'a', 'b', 'c', 'd'};
  std::cout << lc << '\n';

  std::deque<int> di{1, 2, 3, 4};
  std::cout << di << '\n';

  return 0;
}

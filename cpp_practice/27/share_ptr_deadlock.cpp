#include <iostream>
#include <memory>

class A {
  int *data;
  std::shared_ptr<A> other;

 public:
  A() {
    data = new int[100];
    std::cout << "자원을 획득함!" << std::endl;
  }

  ~A() {
    std::cout << "소멸자 호출!" << std::endl;
    delete[] data;
  }

  void set_other(std::shared_ptr<A> o) { other = o; }
};

int main() {
  std::shared_ptr<A> pa = std::make_shared<A>();
  std::shared_ptr<A> pb = std::make_shared<A>();

  pa->set_other(pb);
  pb->set_other(pa);
}
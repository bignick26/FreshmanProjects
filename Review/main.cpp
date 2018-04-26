#include <iostream>
#include <memory>

class Widget {
public:
    void sayHi() {
      std::cout << "Hello!" << std::endl;
    }
    ~Widget() {
      std::cout << "Dead" << std::endl;
    }
};

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
  return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {

  std::unique_ptr<Widget> widget = make_unique<Widget>();

  {
    std::unique_ptr<Widget> anotherPtr = std::move(widget);
  }

  std::cout << "That's all folks" << std::endl;

  return 0;
}
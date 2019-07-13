#include <iostream>

using namespace std;

template <typename Ret, typename Param0> class Callback {
public:
  virtual Ret invoke(Param0 param0) = 0;
};

template <typename Ret, typename Param0>
class StaticFunctionCallback : public Callback<Ret, Param0> {
private:
  Ret (*func_)(Param0);

public:
  StaticFunctionCallback(Ret (*func)(Param0)) : func_(func) {}

  virtual Ret invoke(Param0 param0) { return (*func_)(param0); }
};

template <typename Ret, typename Param0, typename T, typename Method>
class MethodCallback : public Callback<Ret, Param0> {
private:
  void *object_;
  Method method_;

public:
  MethodCallback(void *object, Method method)
      : object_(object), method_(method) {}

  virtual Ret invoke(Param0 param0) {
    T *obj = static_cast<T *>(object_);
    return (obj->*method_)(param0);
  }
};

template <typename Ret, typename Param0> class Delegate {
private:
  Callback<Ret, Param0> *callback_;

public:
  Delegate(Ret (*func)(Param0))
      : callback_(new StaticFunctionCallback<Ret, Param0>(func)) {}

  template <typename T, typename Method>
  Delegate(T *object, Method method)
      : callback_(new MethodCallback<Ret, Param0, T, Method>(object, method)) {}

  ~Delegate(void) {}

  Ret operator()(Param0 param0) { return callback_->invoke(param0); }
};

class A {
public:
  virtual int foo(int p) {
    std::cout << "A::foo(" << p << ")" << std::endl;
    return 0;
  }
};

class B : public A {
public:
  virtual int foo(int p) {
    std::cout << "B::foo(" << p << ")" << std::endl;
    return 0;
  }
};

class C {};

class D : public C, public A {
public:
  virtual int foo(int p) {
    std::cout << "D::foo(" << p << ")" << std::endl;
    return 0;
  }
};

int foo(int x) {
  std::cout << "foo(" << x << ")" << std::endl;
  return 0;
}

int main(void) {
  A *a = new A();
  A *b = new B();
  A *d = new D();

  // static function
  Delegate<int, int> d1(foo);

  // member function
  Delegate<int, int> d2(a, &A::foo);

  // member function + subclass instance
  Delegate<int, int> d3(b, &A::foo);

  // member function + subclass instance + multiple inheritance
  Delegate<int, int> d4(d, &A::foo);

  d1(100); //"foo(100)"
  d2(200); //"A::foo(200)"
  d3(300); //"B::foo(300)"
  d4(400); //"D::foo(400)"

  return 0;
}
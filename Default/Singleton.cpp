
// callOnce.cpp

#include <iostream>
#include <thread>
#include <mutex>
 
std::once_flag onceFlag;
 
void do_once(){
  std::call_once(onceFlag, [](){ std::cout << "Only once." << std::endl; });
}

// Thread safe because of static or std::call_once
class MySingleton
{
public:
    static MySingleton& getInstance()
    {
        static MySingleton instance = MySingleton();
        return instance;
    }
    
private:
    MySingleton() {} // or =default;
    ~MySingleton() {}
    // copy constructor
    MySingleton(const MySingleton&)= delete;
    // copy assignment
    MySingleton& operator=(const MySingleton&) = delete;
};

class MySingletonCallOnce{
public:
  static MySingletonCallOnce& getInstance(){
    std::call_once(initInstanceFlag, &MySingletonCallOnce::initSingleton);
    // volatile int dummy{};
    return *instance;
  }
private:
  MySingletonCallOnce() {} // = default;
  ~MySingletonCallOnce() {} //= default;
  MySingletonCallOnce(const MySingletonCallOnce&)= delete;
  MySingletonCallOnce& operator=(const MySingletonCallOnce&)= delete;

  static MySingletonCallOnce* instance;
  static std::once_flag initInstanceFlag;

  static void initSingleton(){
    instance= new MySingletonCallOnce;
  }
};
MySingletonCallOnce* MySingletonCallOnce::instance= nullptr;
std::once_flag MySingletonCallOnce::initInstanceFlag;

int main(){
  
  std::cout << std::endl;
  
  std::thread t1(do_once);
  std::thread t2(do_once);
  std::thread t3(do_once);
  std::thread t4(do_once);
 
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  
  std::cout << std::endl;
  
  auto &v = MySingleton::getInstance();

  auto &val = MySingletonCallOnce::getInstance();
  

}

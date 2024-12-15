#include <iostream>
#include <utility>  // for std::pair
#include <queue>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <atomic>

using namespace std::chrono_literals;

// thread safe queue
template <typename T>
class tsq
{
public:
    tsq() {
    }
    
    ~tsq() {
    }
    
    tsq(T &&other) {
        std::lock_guard<std::mutex> lock(mtx_);
        q_ = std::move(other.q_);
    }
    
    void push(T val) {
        std::lock_guard<std::mutex> lock(mtx_);
        q_.push(val);
    }
    
    void push(T &&val) {
        std::lock_guard<std::mutex> lock(mtx_);
        q_.push(val);
    }
    
    T front() {
        std::lock_guard<std::mutex> lock(mtx_);
        return q_.front();
    }
    
    bool pop() {
        bool result = false;
        std::lock_guard<std::mutex> lock(mtx_);
        if (!q_.empty()) {
            q_.pop();
            result = true;
        }
        return result;
    }
    
    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return q_.size();
    }
    
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return q_.empty();
    }

private:
    std::queue<T> q_;
    mutable std::mutex mtx_;
    std::condition_variable cv_;
};

template <typename T>
class tsq_w
{
public:
    tsq_w() : data_ready_(0) {
    }
    
    ~tsq_w() {
    }
    
    tsq_w(T &&other) {
        std::lock_guard<std::mutex> lock(mtx_);
        q_ = std::move(other.q_);
    }
    
    void push(T val) {
        std::lock_guard<std::mutex> lock(mtx_);
        q_.push(val);
        data_ready_++;
        cv_.notify_one();
    }
    
    void push(T &&val) {
        std::lock_guard<std::mutex> lock(mtx_);
        q_.push(val);
        data_ready_++;
        cv_.notify_one();
    }
    
    T front() {
        std::lock_guard<std::mutex> lock(mtx_);
        return q_.front();
    }
    
    bool pop() {
        bool result = false;
        std::unique_lock<std::mutex> lock(mtx_);
        if (q_.empty()) {
            cv_.wait(lock, [this]{ return this->data_ready_ > 0; });
        }
        q_.pop();
        return true;
    }
    
    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return q_.size();
    }
    
    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return q_.empty();
    }

private:
    std::queue<T> q_;
    mutable std::mutex mtx_;
    std::condition_variable cv_;
    std::atomic<size_t> data_ready_; 
};


#define ITERS 1000

// template <typename T>
template <template <typename> class Queue, typename T>
void pusher(Queue<T> &q) 
{
    for (int i = 0; i < ITERS; i++) {
        int val = i;
        q.push(val);
        std::this_thread::sleep_for(1ms * (std::rand() % 10));
    }
}

template <class T>
void pusher1(T &q) 
{
    for (int i = 0; i < ITERS; i++) {
        int val = i;
        q.push(val);
        std::this_thread::sleep_for(1ms * (std::rand() % 10));
    }
}

template <template <typename> class Queue, typename T>
void popper(Queue<T> &q) {
    int count_success = 0;
    for (int i=0; i<ITERS; i++) {
        count_success += q.pop();
        std::this_thread::sleep_for(1ms * (std::rand() % 10));
    }
    
    std::cout << __func__ << " successful pops: " << count_success << "\n";
}

int main() {
    {
        std::cout << "Thread safe non waiting queue : " << std::endl;
        tsq<int> myq; 
        
        std::thread t1([&myq]() { pusher<tsq, int>(myq); });
        std::thread t2([&myq]() { popper<tsq, int>(myq); });
        
        t1.join();
        t2.join();
    }
    
    {
        std::cout << "Thread safe queue with wait : " << std::endl;
        tsq_w<int> myq; 
        
        std::thread t1([&myq]() { pusher<tsq_w, int>(std::ref(myq)); });
        std::thread t2([&myq]() { popper<tsq_w, int>(std::ref(myq)); });
        
        t1.join();
        t2.join();
    }
    
    return 0;
}

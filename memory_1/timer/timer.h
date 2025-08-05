#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

class Timer {
public:
    explicit Timer(std::chrono::milliseconds interval)
        : end_time(std::chrono::steady_clock::now() + interval) {}

    bool Expired() const {
        return std::chrono::steady_clock::now() >= end_time;
    }

private:
    std::chrono::steady_clock::time_point end_time;
};

class TimeMeasurer {
public:
    explicit TimeMeasurer(std::ostream& output_stream)
        : start_time(std::chrono::steady_clock::now()), output(output_stream) {}

    ~TimeMeasurer() {
        auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>
                            (std::chrono::steady_clock::now() - start_time).count();
        output << "Elapsed time: " << elapsed_time << std::endl;
    }

private:
    std::chrono::steady_clock::time_point start_time;
    std::ostream& output;
};

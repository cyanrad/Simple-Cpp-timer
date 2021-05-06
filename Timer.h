#pragma once
#include <iostream>
#include <chrono>


class BaseTimer {
protected:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timepoint;

protected:
    //duration is in mSeconds
    void stop() {
        auto end_timepoint = std::chrono::high_resolution_clock::now();

        //you can change the time here
        //auto is long long
        auto start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_start_timepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::milliseconds>(end_timepoint).time_since_epoch().count();

        auto duration = end - start;
        std::cout << duration << " ms" << std::endl;
    }
};

//Scoped Timer
class STimer : private BaseTimer {
public:
    STimer() {
        m_start_timepoint = std::chrono::high_resolution_clock::now();
    }

    ~STimer() {
        stop();
    }
};

//function based timer
class Timer : private BaseTimer {
public:
    void tic() {
        m_start_timepoint = std::chrono::high_resolution_clock::now();
    }

    void toc() {
        stop();
    }
};
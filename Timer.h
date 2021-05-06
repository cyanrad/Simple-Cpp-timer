#pragma once
#include <iostream>
#include <chrono>


class BaseTimer {
protected:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start_timepoint;

protected:
    void stop() {
        //stops timer
        auto end_timepoint = std::chrono::high_resolution_clock::now();

        //you can change the time type by changing microseconds to some other prefix 
        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_timepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_timepoint).time_since_epoch().count();
        
        //calculating measurements
        long durationUS = end - start;
        long durationMS = durationUS / 1000;
        long durationS = durationMS / 1000;
        printf("%ius : %ims : %is\n", durationUS, durationMS, durationS);
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

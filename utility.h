#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>


template <typename Iter>
void fill_from_file(Iter begin, Iter end, const std::string& file_name = "input.txt")
{
    std::fstream fst(file_name, std::ios::in);
    for(auto iter(begin); iter != end && !fst.eof(); ++iter)
        fst >> *iter;
}

template <typename T, typename ... Args>
double execution_time(T func, Args&& ... args)
{
    clock_t begin = clock();
    func(std::forward<Args>(args)...);

    double time = (double)(clock() - begin)/CLOCKS_PER_SEC;
    std::cout << std::setprecision(4) << std::setiosflags(std::ios::fixed) << "Execution time: " << time << " ms.\n";
    return time;
}
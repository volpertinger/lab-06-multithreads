// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru

#include "header.hpp"

// std::thread::hardware_concurrency() == 8;

int main(int const arguments_count, char const* arguments[]) {
  srand(time(0));

  if (arguments_count > 2) {
    std::cerr << "To much arguments" << std::endl;
    return 1;
  }

  size_t threads_count;

  if (arguments_count == 2) {
    threads_count = size_t(arguments[1]);
    BOOST_LOG_TRIVIAL(info) << arguments[1] << " traces";
  }

  if (arguments_count == 1) {
    threads_count = std::thread::hardware_concurrency();
    BOOST_LOG_TRIVIAL(info) << threads_count << " threads";
  }

  std::vector<std::thread> threads;

  for (size_t i = 0; i < threads_count; ++i)
    threads.push_back(std::thread(SHA256::find));

  for (size_t i = 0; i < threads_count; ++i) threads[i].join();

  return 0;
}

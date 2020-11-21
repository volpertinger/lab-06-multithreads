// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <picosha2.h>

#include <atomic>
#include <boost/log/trivial.hpp>
#include <cstddef>
#include <ctime>
#include <header.hpp>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <vector>

class SHA256 {
 public:
  std::string data;
  std::string hash;
  std::string hash_end = "0000";

  bool is_right_hash() {
    return hash.substr(hash.size() - hash_end.size(), hash_end.size()) ==
           hash_end;
  };
  void hash_gen() {
    data = std::to_string(rand());
    hash = picosha2::hash256_hex_string(data);
  }

  static void find() {
    SHA256 ss;
    for (;;) {
      ss.hash_gen();
      if (ss.is_right_hash()) {
        BOOST_LOG_TRIVIAL(info)
            << "Thread id: " << std::this_thread::get_id()
            << "; Data: " << ss.data << "; Hash: " << ss.hash << "; Correct;";
        break;
      }
      BOOST_LOG_TRIVIAL(info)
          << "Thread id: " << std::this_thread::get_id()
          << "; Data: " << ss.data << "; Hash: " << ss.hash << "; Failed;";
    }
  }
};

#include <boost/log/trivial.hpp>

#endif  // INCLUDE_HEADER_HPP_

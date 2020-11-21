// Copyright 2020 Merzlov Nikolay merzlovnik@mail.ru

#include <gtest/gtest.h>

#include "header.hpp"

TEST(Hash, is_right_hash) {
  SHA256 ss;
  ss.hash = "hfskzdlfhdlsagfxckzuyhckcy,jkydfszxv0000";
  EXPECT_EQ(true, ss.is_right_hash());
  ss.hash = "hfskzdlfhdlsagfxckzuyhckcy,jkydfszxv00000";
  EXPECT_EQ(true, ss.is_right_hash());
  ss.hash = "0000";
  EXPECT_EQ(true, ss.is_right_hash());
  ss.hash = "hfskzdlfhdlsagfxckzuyhckcy,jkydfszxv00001";
  EXPECT_EQ(false, ss.is_right_hash());
  ss.hash = "hfskzdlfhdlsagfxckzuyhckcy,jkydfszxv100001";
  EXPECT_EQ(false, ss.is_right_hash());
  ss.hash = "hfskzdlfhdlsagfxckzuyhckcy,jkydfszxv00010";
  EXPECT_EQ(false, ss.is_right_hash());
}

TEST(Hash, hash_gen) {
  SHA256 ss;
  ss.hash_gen();
  EXPECT_EQ(ss.hash, picosha2::hash256_hex_string(ss.data));
  ss.hash_gen();
  EXPECT_EQ(ss.hash, picosha2::hash256_hex_string(ss.data));
  ss.hash_gen();
  EXPECT_EQ(ss.hash, picosha2::hash256_hex_string(ss.data));
  ss.hash_gen();
  EXPECT_EQ(ss.hash, picosha2::hash256_hex_string(ss.data));
  ss.hash_gen();
  EXPECT_EQ(ss.hash, picosha2::hash256_hex_string(ss.data));
}

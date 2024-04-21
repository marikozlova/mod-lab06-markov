// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>

#include "../include/textgen.h"
TEST(Test1, first_test) {
    TextGen textgen;
    textgen.Prefixes("One two three", 2);
    std::map<prefix, std::vector<std::string>> statetab = textgen.get();
    prefix pref = { "One", "two" };
  EXPECT_EQ(pref, statetab.begin()->first);
}

TEST(Test2, second_test) {
    TextGen textgen;
    textgen.Prefixes("One two three", 2);
    prefix prefix = { "One", "two" };
    EXPECT_EQ(textgen.get().at(prefix)[0], "three");
}

TEST(Test3, third_test) {
    TextGen textgen;
    textgen.Prefixes("one two three four five six", 1);
    prefix pref = { "one" };
    std::vector<std::string> suffix = { "three", "five" };
    EXPECT_EQ(suffix, textgen.get().at(pref));
}

TEST(Test4, fourth_test) {
    TextGen textgen;
    textgen.Prefixes("one two three four five six", 1);
    std::string generated_string = textgen.Text(time(0), 5);
    std::cout << generated_string;
    EXPECT_EQ(generated_string, "one two three four five ");
}

/*
** EPITECH PROJECT, 2024
** Project
** File description:
** Created by antoine,
*/

#include <gtest/gtest.h>
#include <exception>

TEST(example, basic)
{
    auto fct = [](int a, int b) { return a < b;};
    EXPECT_EQ(true, fct(1, 4));
}
TEST(example, exception)
{
    auto fct = []() { throw std::runtime_error("broken");};
    EXPECT_THROW(fct(), std::runtime_error);
}
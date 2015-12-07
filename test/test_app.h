#pragma once

#ifndef TEST_APP_H
#define TEST_APP_H

#include <fstream>
#include <iostream>
#include <vector>

#include "test_utils.h"

namespace test
{

class test_app
{
public:
    static void show_help();

    test_app(const test_app &) = delete;
    test_app & operator=(const test_app &) = delete;
    test_app(test_app &&) = delete;
    test_app & operator=(test_app &&) = delete;

    test_app(int argc, char * argv[]);
    ~test_app() = default;

private:
    void on_incorrect_arguments();
    void on_fail();

    void parse_command_line();
    void do_words();
    void do_checksum();
    void do_work();

    std::vector<std::string> command_line_;
    app_mode app_mode_{ app_mode::unknown };

    std::string filename_;
    std::string word_;

    std::ifstream file_{};
};

} // namespace test

#endif // TEST_APP_H

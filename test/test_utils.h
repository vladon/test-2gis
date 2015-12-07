#pragma once

#ifndef TEST_UTILS
#define TEST_UTILS

#include <string>

namespace test
{

enum class app_mode
{
    unknown,
    words,
    checksum
};

std::string to_string(app_mode t_app_mode);

} // namespace test

#endif // TEST_UTILS
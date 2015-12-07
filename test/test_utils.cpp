#include "test_utils.h"

#include <string>

namespace test
{

using namespace std::string_literals;

std::string to_string(app_mode t_app_mode)
{
    std::string result;

    switch (t_app_mode)
    {
        case test::app_mode::words:
            result = "words"s;
            break;

        case test::app_mode::checksum:
            result = "checksum"s;
            break;

        default:
            result = "unknown"s;
            break;
    }

    return result;
}

} // namespace test

#include "test_app.h"

namespace test
{

void test_app::parse_command_line()
{
    using namespace ::std::literals::string_literals;

    auto arg_count = command_line_.size();
    if (arg_count == 2)
    {
        if (command_line_[1] == "-h"s)
        {
            show_help();
        }
    }
    else if (arg_count % 2 == 1) // arg count must be odd
    {
        for (size_t i = 1; i < arg_count; i += 2)
        {
            if (command_line_[i] == "-f")
            {
                if (filename_.empty())
                {
                    filename_ = command_line_[i + 1];
                }
                else
                {
                    on_incorrect_arguments();
                }
            }
            else if (command_line_[i] == "-m")
            {
                if (app_mode_ == app_mode::unknown)
                {
                    if (command_line_[i + 1] == "words")
                    {
                        app_mode_ = app_mode::words;
                    }
                    else if (command_line_[i + 1] == "checksum")
                    {
                        app_mode_ = app_mode::checksum;
                    }
                    else
                    {
                        on_incorrect_arguments();
                    }
                }
                else
                {
                    on_incorrect_arguments();
                }
            }
            else if (command_line_[i] == "-v")
            {
                word_ = command_line_[i + 1];
            }
        }

        if (app_mode_ == app_mode::unknown)
        {
            on_incorrect_arguments();
        }

        if (app_mode_ == app_mode::checksum)
        {
            if (!word_.empty() || filename_.empty())
            {
                on_incorrect_arguments();
            }
        }

        if (app_mode_ == app_mode::words)
        {
            if (word_.empty() || filename_.empty())
            {
                on_incorrect_arguments();
            }
        }
    }
    else
    {
        on_incorrect_arguments();
    }
}

}
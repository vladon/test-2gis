#include "test_app.h"

#include <iterator>
#include <numeric>

namespace test
{

void test_app::show_help()
{
    std::cout <<
            "Usage:\n"
            "\t-f <filename>\t\tfile to process\n"
            "\t-m words -v <word>\tcount given word occurences in the file\n"
            "\t-m checksum\t\tcount checksum of the file\n";
}

test_app::test_app(int argc, char * argv[]): command_line_(argc)
{
    for (int i = 0; i < argc; ++i)
    {
        command_line_[i] = argv[i];
    }

    parse_command_line();

    do_work();
}

void test_app::on_fail()
{
    throw std::exception("Fail on file open");
}

void test_app::on_incorrect_arguments()
{
    throw std::exception("Incorrect arguments");
}

void test_app::do_words()
{
    auto count_words = [](std::ifstream & file, const std::string & word)
    {
        return std::accumulate(std::istream_iterator<std::string>(file),
                               std::istream_iterator<std::string>(),
                               0,
                               [&word](const int & counted, const std::string & value)
        {
            if (value == word)
            {
                return counted + 1;
            }
            else
            {
                return counted;
            }
        });
    };

    std::cout << "Word count: " << count_words(file_, word_) << std::endl;
}

void test_app::do_checksum()
{
    auto checksum_f = [](std::ifstream & file)
    {
        uint32_t checksum{ 0L };

        // file is Little Endian, checksum is of any endianness
        unsigned int shift{ 0 };
        for (uint32_t word = file.get(); file; word = file.get())
        {
            checksum += (word << shift);
            shift += 8;
            if (shift == 32)
            {
                shift = 0;
            }
        }

        return checksum;
    };

    std::cout << "checksum: " << std::hex << checksum_f(file_) << std::endl;
}

void test_app::do_work()
{
    file_.open(filename_, std::ios::in);
    if (file_.fail())
    {
        on_fail();
    }

    if (app_mode_ == app_mode::words)
    {
        do_words();
    }
    else if (app_mode_ == app_mode::checksum)
    {
        do_checksum();
    }
}

}

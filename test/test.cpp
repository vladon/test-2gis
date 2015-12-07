#include <iostream>

#include "test_app.h"

int main(int argc, char * argv[])
{
    try
    {
        test::test_app app(argc, argv);
    }
    catch (const std::exception & ex)
    {
        std::cerr << "Exception occured: " << ex.what() << std::endl;
        test::test_app::show_help();
    }

    return 0;
}

#include <iostream>
#include <boost/optional.hpp>

int main()
{
    boost::optional<int> hello = 1;

    std::cout << "Hello World" << std::endl;
    std::cout << "Hello optional: " << *hello << std::endl;
}
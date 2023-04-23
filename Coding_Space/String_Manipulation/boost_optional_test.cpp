#include <boost/optional/optional.hpp>
#include <boost/none_t.hpp>
#include <iostream>

int main()
{
    boost::optional<bool> _lava_enabled;

    if (_lava_enabled == false)
    {
        std::cout << "1.1 _lava_enabled evaluated to false" << std::endl;
    }

    _lava_enabled = false;
    if (_lava_enabled == false)
    {
        std::cout << "1.2 _lava_enabled evaluated to false" << std::endl;
    }
}
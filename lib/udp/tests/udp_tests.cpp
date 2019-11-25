#include <criterion/criterion.h>
#include "UDP.hpp"


Test(stringToMap, simpleString)
{
    std::string string = "toto=tata:titi=salut";
    std::unordered_map<std::string, std::string> res;

    boost::asio::io_context io_context;

    UDP udp(io_context, 765);
    res = udp.stringToMap(string);
    cr_assert_str_eq(res["toto"].c_str(), "tata");
    cr_assert_str_eq(res["titi"].c_str(), "salut");
}
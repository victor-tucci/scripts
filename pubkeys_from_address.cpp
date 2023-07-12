#include <iostream>
#include "cryptonote_basic/cryptonote_basic_impl.h"

int main()
{
    cryptonote::address_parse_info info;
    bool r = false;
    std::string address = "";
    std::cout << "enter the mainnet address : ";
    std::cin >> address;
    r = cryptonote::get_account_address_from_str(info, cryptonote::MAINNET, address);

    if (r)
    {
        if (info.is_subaddress)
        {
            std::cout << "This is sub address\n";
        }
        else if (info.has_payment_id)
        {
            std::cout << "This is integrated address\n";
        }
        else
        {
            std::cout << "This is primary address\n";
        }

        std::cout << "view_public_key : " << info.address.m_view_public_key << "\n";
        std::cout << "spend_public_key : " << info.address.m_spend_public_key << "\n";
    }
    return 0;
}

//in the cmake src/simplewallet/CMakeLists.txt
//     add_executable(keyFetch sample.cpp)

// target_link_libraries(keyFetch PRIVATE wallet
// daemonizer
// rpc_commands
// cryptonote_core
// mnemonics
// Boost::program_options
// filesystem
// icu
// Boost::thread
// extra)

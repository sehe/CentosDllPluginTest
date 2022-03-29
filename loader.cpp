#include <boost/dll.hpp>
#include <iostream>

int main() {
    boost::dll::library_info inf("libplugin.so");
    std::vector<std::string> s = inf.sections();

    auto found = (std::find(s.begin(), s.end(), "MySect") != s.end());
    std::cout << "Found: " << std::boolalpha << found << "\n";
}
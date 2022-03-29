#include <boost/dll.hpp>
#include <boost/dll/alias.hpp>

namespace MyPlugin {
    struct X{};
    static std::shared_ptr<X> create() {
        return std::make_shared<X>();
    }
}

BOOST_DLL_ALIAS_SECTIONED(
        MyPlugin::create, 
        Factory, 
        MySect)

#include "BaseApplication.hpp"

// this a kind of platform to application
namespace My
{
    BaseApplication g_App;
    IApplication* g_pApp = &g_App;
} // namespace My

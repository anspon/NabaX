#ifndef TkPchHeaders_H
#define TkPchHeaders_H

#ifndef TKPCH_ACTIVE
#define GTEST_HAS_TR1_TUPLE 0
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
#include <string>
#include <sstream>
#include <memory>
#include <list>
#include <map>
#include <set>
#include <filesystem>
#include <functional>

#define filesystem std::experimental::filesystem::v1


#endif

#endif
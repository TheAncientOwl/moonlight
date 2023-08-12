#pragma once

#include <string>
#include <sstream>

#define IDENTIFIER "[a-zA-Z0-9_]+"
#define PATH_IDENTIFIER R"("[a-zA-Z0-9_]+")"
#define VARIANT_OR ")|("
#define BOOLEAN "(true|false)"

#define EXPAND_ARGS(out) \
    out << std::forward<Arg>(arg) << "[ ]*"; \
    ((out << std::forward<Args>(args) << "[ ]*"), ...);

namespace Moonlight::QueryParser::Helpers {

namespace Regex {

template<typename Arg, typename ...Args>
std::string regex(Arg&& arg, Args&&... args)
{
    std::ostringstream out;

    EXPAND_ARGS(out);

    return out.str();
}

template<typename Arg, typename ...Args>
std::string functionArgs(Arg&& arg, Args&&... args)
{
    std::ostringstream out;

    out << "\\([ ]*";
    EXPAND_ARGS(out);
    out << "\\)[ ]*";

    return out.str();
}

template<typename Arg, typename ...Args>
std::string listOf(Arg&& arg, Args&&... args)
{
    std::ostringstream out;

    out << "(";
    EXPAND_ARGS(out);
    out << "(,| )*" << ")+" << "[ ]*";

    return out.str();
}

template<typename Arg, typename ...Args>
std::string optional(Arg&& arg, Args&&... args)
{
    std::ostringstream out;

    out << "(";
    EXPAND_ARGS(out);
    out << ")?" << "[ ]*";

    return out.str();
}

template<typename Arg, typename ...Args>
std::string variant(Arg&& arg, Args&&... args)
{
    std::ostringstream out;

    out << "((";
    EXPAND_ARGS(out);
    out << "))" << "[ ]*";

    return out.str();
}

} // namespace Regex

} // namespace Moonlight::QueryParser::Helpers

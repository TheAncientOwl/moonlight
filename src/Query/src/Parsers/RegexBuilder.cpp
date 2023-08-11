#include "../QueryParser.hpp"

namespace Moonlight::QueryParser::Helpers {

std::string RegexBuilder::build() const
{
    return m_ss.str();
}

RegexBuilder& RegexBuilder::blank()
{
    m_ss << "[ ]*";

    return *this;
}

RegexBuilder& RegexBuilder::add(std::string_view str)
{
    m_ss << str;
    blank();

    return *this;
}

RegexBuilder& RegexBuilder::paranthesis(std::string_view str, std::string_view begin, std::string_view end)
{
    add("\\(").blank();

    if (begin.length() > 0)
    {
        add(begin).blank();
    }

    add(str).blank();

    if (end.length() > 0)
    {
        add(end).blank();
    }

    add("\\)").blank();

    return *this;
}

RegexBuilder& RegexBuilder::beginCase()
{
    m_ss << "((";

    return *this;
}

RegexBuilder& RegexBuilder::orCase()
{
    m_ss << ")|(";

    return *this;
}

RegexBuilder& RegexBuilder::endCase()
{
    m_ss << "))";

    return *this;
}

RegexBuilder& RegexBuilder::beginOptional()
{
    m_ss << "(";

    return *this;
}

RegexBuilder& RegexBuilder::endOptional()
{
    m_ss << ")?";

    return *this;
}


} // namespace Moonlight::QueryParser::Helpers

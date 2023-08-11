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

RegexBuilder& RegexBuilder::paranthesis(std::string_view str)
{
    add("\\(").blank().add(str).blank().add("\\)");
    blank();

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


} // namespace Moonlight::QueryParser::Helpers

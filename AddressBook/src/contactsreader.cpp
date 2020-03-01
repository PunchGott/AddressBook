#include "include/contactsreader.h"

namespace  {
    const std::vector<Contact> mockData
    {
        {"Max", "Panch", "79153537283"},
        {"Max", "Panch", "79153537283"},
        {"Max", "Panch", "79153537283"},
        {"Max", "Panch", "79153537283"}
    };
}
std::pair<bool, std::vector<Contact> > ContactsReader::requestContactBrowse()
{
    return std::make_pair(true, mockData);
}

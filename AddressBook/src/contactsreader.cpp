#include "include/contactsreader.h"

namespace  {
    const std::vector<Contact> mockData
    {
        {"Max", "Panch", "79153537283"},
        {"Nikita", "Tot", "1234567890"},
        {"Kirill", "Serov", "0987654321"},
        {"Alex", "Dunch", "68423454772"}
    };
}
std::pair<bool, std::vector<Contact> > ContactsReader::requestContactBrowse()
{
    return std::make_pair(true, mockData);
}

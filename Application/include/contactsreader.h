#pragma once
#include <utility>
#include <memory>
#include <vector>
#include "contact.h"

namespace db {
    class Processor;
}

class ContactsReader
{
public:
    ContactsReader();
    ~ContactsReader();
    std::pair<bool,
                    std::vector<Contact>> requestContactBrowse();
private:
    std::unique_ptr<db::Processor> m_processor;
};


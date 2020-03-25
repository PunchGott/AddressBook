#pragma once
#include "dbtypes.h"
#include <QString>

namespace db {
static const std::map<DBTables, QString> TableMapper {
    {DBTables::Contacts, "Contacts"}
};
static  const std::map<QString, QString> TablesMapping {
    {"Contacts", "Name, Surname, PhoneNumber"}
};
}

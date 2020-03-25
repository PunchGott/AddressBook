#include "Processor.h"
#include "Selector.h"
#include "dbmapper.h"
#include "Manipulator.h"
#include <mutex>

namespace db {

struct Processor::ProcessorPrivate {
    Selector selector;
    Manipulator manipulator;
#ifdef BUILD_TESTS
    std::once_flag initialized;
    void insertMockData();
#endif
};

Processor::Processor()
    : m_d{new ProcessorPrivate{}}
{

}

Processor::~Processor()
{

}
#ifdef BUILD_TESTS
void Processor::ProcessorPrivate::insertMockData()
{
    manipulator.inserRow("Contacts", {{"Wylie", "Johns", "3800123131"}});
    manipulator.inserRow("Contacts", {{"Max", "Panchenko", "79153537283"}});
    manipulator.inserRow("Contacts", {{"Nikita", "Totmyanin", "79091231311"}});
    manipulator.inserRow("Contacts", {{"Alexandr", "Dunch", "791612312312"}});
}
#endif
std::pair<DBResult, std::vector<DBEntry> > Processor::requestTabledata(DBTables table)
{
#ifdef BUILD_TESTS
    auto inserter = [this] {
        m_d->insertMockData();
    };
    std::call_once(m_d->initialized, inserter);
#endif
    const auto& result {m_d->selector.selectAll(TableMapper.at(table))};
    return result;
}

}

#pragma once
#include <memory>

namespace db {

class ConnectionManager
{
public:
    ConnectionManager();
    ~ConnectionManager();
    ConnectionManager(const ConnectionManager&) = delete;
    ConnectionManager& operator=(const ConnectionManager&) = delete;

    static ConnectionManager& instance();
    bool isValid() const;
private:
    struct ConnectionManagerPrivate;
    std::unique_ptr<ConnectionManagerPrivate> m_d;
};
}

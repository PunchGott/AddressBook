#pragma once
#include <QAbstractListModel>
#include <vector>

#include "contact.h"
#include "contactsreader.h"

class ContactsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ContactsModel();
    Q_INVOKABLE void addContact(const QString& name, const QString& surname,
                                const QString& phoneNumber, const QString& homePhoneNumber);

    static void registerMe(const std::string& moduleName);

    QHash<int, QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent = {}) const override;

    QVariant data(const QModelIndex& index = {}, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

private:
    ContactsReader m_contactsReader;
    std::vector<Contact> m_contacts;
    enum ContactRoles {
        NameRole = Qt::UserRole + 1,
        SurnameRole,
        PhoneNameRole
    };

    bool updateContacts();
};

#include "include/contactsmodel.h"
#include <QQmlEngine>
#include <QDebug>

ContactsModel::ContactsModel()
{
    m_contacts = {
        {"Max", "Panch", "79153537283"},
        {"Nikita", "Tot", "1234567890"},
        {"Kirill", "Serov", "0987654321"},
        {"Alex", "Dunch", "68423454772"}
    };
    //    const bool updateResult {updateContacts()};
    //    if (!updateResult)
    //        qWarning() << "Update contacts failed!";
}

void ContactsModel::addContact(const QString& name, const QString& surname,
                               const QString& phoneNumber, const QString& homePhoneNumber)
{

    Contact contact {};
    contact.setFirstName(name);
    contact.setSurname(surname);
    contact.setPhone(phoneNumber);

    beginInsertRows(QModelIndex(), rowCount() - 1, rowCount() - 1);
    m_contacts.push_back(contact);
    endInsertRows();

    emit dataChanged(createIndex(0, 0), createIndex(m_contacts.size(), 0));
}

void ContactsModel::registerMe(const std::string &moduleName)
{
    qmlRegisterType<ContactsModel>(moduleName.c_str(), 1, 0, "ContactsModel");
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContactRoles::NameRole] = "name";
    roles[ContactRoles::SurnameRole] = "surname";
    roles[ContactRoles::PhoneNameRole] = "phoneNumber";

    return roles;
}

int ContactsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return static_cast<int>(m_contacts.size());
}

QVariant ContactsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index))
        return QVariant{};

    const Contact& contact {m_contacts.at(index.row())};

    switch (role) {
    case ContactRoles::NameRole:
        return QVariant::fromValue(contact.firstName());

    case ContactRoles::SurnameRole:
        return QVariant::fromValue(contact.surname());

    case ContactRoles::PhoneNameRole:
        return QVariant::fromValue(contact.phone());

    default:
        return QVariant{};
    }

}

bool ContactsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || index.row() > rowCount(index))
        return false;

    Contact& contact {m_contacts.at(index.row())};

    switch (role) {
    case ContactRoles::NameRole: {
        contact.setFirstName(value.toString());
        return true;
    }

    case ContactRoles::SurnameRole: {
        contact.setSurname(value.toString());
        return true;
    }

    case ContactRoles::PhoneNameRole: {
        contact.setPhone(value.toString());
        return true;
    }

    default:
        return false;
    }

    emit dataChanged(createIndex(0, 0), createIndex(m_contacts.size(), 0));
}

//bool ContactsModel::updateContacts()
//{
//    bool requestResult {false};

//    std::vector<Contact> contactsResult;
//    std::tie(requestResult, contactsResult) = m_contactsReader.requestContactBrowse();

//    if(requestResult) {
//        m_contacts.swap(contactsResult);
//        emit dataChanged(createIndex(0, 0), createIndex(m_contacts.size(), 0));
//    }

//    return requestResult;
//}

#include "include/contact.h"
#include <QDebug>

Contact::Contact(const QString &firstName, const QString &surname, const QString &phone)
    : m_firstName{firstName},
      m_surname{surname},
      m_phone{phone}
{
    qDebug() << m_firstName << '\n' << m_surname << '\n' << m_phone << '\n';
}

QString Contact::phone() const
{
    return m_phone;
}

void Contact::setFirstName(const QString &firstName)
{
    m_firstName = firstName;
}

void Contact::setSurname(const QString &surname)
{
    m_surname = surname;
}

void Contact::setPhone(const QString &phone)
{
    m_phone = phone;
}

QString Contact::firstName() const
{
    return m_firstName;
}

QString Contact::surname() const
{
    return m_surname;
}

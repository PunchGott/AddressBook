#pragma once
#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(const QString& firstName, const QString &surname, const QString& phone);

    QString firstName() const;
    void setFirstName(const QString &firstName);

    QString surname() const;
    void setSurname(const QString &surname);

    QString phone() const;
    void setPhone(const QString &phone);

private:
    QString m_firstName;
    QString m_surname;
    QString m_phone;
};

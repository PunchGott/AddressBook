#pragma once
#include <QString>

class Contact
{
public:
    Contact() = default;
    Contact(const QString& firstName, const QString &surname, const QString& phone);

    QString firstName() const;

    QString surname() const;

    QString phone() const;

private:
    QString m_firstName;
    QString m_surname;
    QString m_phone;
};

pragma Singleton
import QtQuick 2.4

Item {
    property alias contacts: _contacts
    QtObject {
        id: _contacts
        readonly property string defaultContactIcon: "qrc:/qml/resources/default_contact_icon.svg"
    }
}

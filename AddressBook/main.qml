import QtQuick 2.12
import QtQuick.Window 2.12
import Contacts 1.0
import ContactsModule.Impl 1.0
import Style 1.0

Window {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("AddressBook")

    property var contactsModel: ContactsModel {
        id: contactsModel
    }

    ContactsView {
        id: contactsView
        anchors.fill: parent
        model: contactsModel

    }

    Rectangle {
        id: _background
        z: -1
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }

    NewContact {
        id: newContact

        acceptButton.onClicked: {
            contactsModel.addContact(nameInput.text, surnameInput.text, phoneNumberInput.text, "");
            newContact.close();
        }
    }

    NewContactButton {
        id: newContactButton
    }
}

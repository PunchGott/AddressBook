import QtQuick 2.0
import ContactsModule.Base 1.0
import Contacts 1.0

BaseListView {
    id: root
    model: ContactsModel {

    }

    delegate: ContactsDelegate {
        width: root.width
        height: 80
    }
}

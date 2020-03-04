import QtQuick 2.0
import ContactsModule.Base 1.0

ListView {
    id: root
    spacing: 1
    section.criteria: ViewSection.FirstCharacter
    section.property: "name"

    delegate: ContactsDelegate {
        id: _delegate
        width: root.width
        height: 80
    }

}

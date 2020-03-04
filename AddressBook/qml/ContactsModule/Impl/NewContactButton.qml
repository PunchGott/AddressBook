import QtQuick 2.0
import ContactsModule.Base 1.0
import Style 1.0

Rectangle {
    id: root
    anchors.bottom: _background.bottom
    anchors.right: _background.right
    anchors.margins: 10
    width: 40
    height: 40
    radius: 10
    color: Style.primaryColor
    opacity: newContactIconArea.pressed ? Style.secondaryOpacity : Style.emphasisOpacity

    Text {
        anchors.centerIn: parent
        color: Style.textColor
        font.pointSize: 16
        font.bold: true
        text: "+"
    }

    MouseArea{
        id: newContactIconArea
        anchors.fill: root
        onClicked: {
            newContact.visible = true;
        }
    }
}

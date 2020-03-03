import QtQuick 2.0
import Style 1.0

Rectangle {
    id: root
    color: Style.backgroundColor
    opacity: _delegateArea.pressed ? Style.secondaryOpacity : Style.emphasisOpacity

    AboutContact {
        id: contactInfo
        nameText: name
        surnameText: surname
        phoneNumberText: "+" + phoneNumber
    }

    MouseArea {
        id: _delegateArea
        anchors.fill: root
        onClicked:
            contactInfo.visible = true;
    }
}

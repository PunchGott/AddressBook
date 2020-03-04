import QtQuick 2.0
import Style 1.0
import ContactsModule.Base 1.0
import ContactsModule.Impl 1.0
import ResourceProvider 1.0

Rectangle {
    id: root
    color: Style.backgroundColor
    opacity: _delegateArea.pressed ? Style.secondaryOpacity : Style.emphasisOpacity

    property alias textName: nameText.text
    property alias textSurname: surnameText.text
    property alias textPhoneNumber: phoneNumberText.text

    AboutContact {
        id: contactInfo
        onSaveChanges: {
            nameText.text = name
            surnameText.text =  surname
            phoneNumberText.text = phoneNumber
        }
    }

    MouseArea {
        id: _delegateArea
        anchors.fill: root
        onClicked:
            contactInfo.visible = true;
    }

    ImageBubble {
        id: _contactBubble
        anchors.left: root.left
        anchors.leftMargin: Style.defaultOffset
        anchors.verticalCenter: root.verticalCenter
        width: root.height - 15
        height: root.height - 15
        image.source: Resources.contacts.defaultContactIcon
    }

    Column {
        anchors.verticalCenter: root.verticalCenter
        anchors.left: _contactBubble.right
        anchors.leftMargin: Style.defaultOffset
        spacing: Style.smallSpacing
        Row {
            spacing: Style.smallSpacing
            BaseText {
                id: nameText
                text: name
            }
            BaseText {
                id: surnameText
                text: surname
            }
        }
        BaseText {
            id: phoneNumberText
            text: "+" + phoneNumber
            color: Style.primaryColor
        }
    }
}

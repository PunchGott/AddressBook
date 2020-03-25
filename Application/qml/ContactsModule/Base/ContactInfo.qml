import QtQuick 2.0
import QtQuick.Dialogs 1.2
import ResourceProvider 1.0
import ContactsModule.Base 1.0
import Style 1.0

Dialog {
    id: root
    visible: false;
    width: 400
    height: 500

    signal saveChanges();

    property alias nameInput: nameInput
    property alias surnameInput: surnameInput
    property alias phoneNumberInput: phoneNumberInput
    property alias homePhoneNumberInput: homePhoneNumberInput

    property alias acceptButton: acceptButton

    contentItem: Rectangle {
        id: content
        anchors.fill: parent
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity


        ImageBubble {
            id: contactImage
            width: content.height / 4
            height: content.height / 4
            anchors.horizontalCenter: content.horizontalCenter
            anchors.top: content.top
            anchors.topMargin: 10
            anchors.bottomMargin: 10
            image.source: Resources.contacts.defaultContactIcon
        }

        Column {
            id: infoColumn
            anchors.top: contactImage.bottom
            anchors.horizontalCenter: content.horizontalCenter
            spacing: 5

            BaseText {
                text: "Name:"
                color: Style.primaryColor
            }

            InputArea {
                id: nameInput
                width: contactImage.height * 2 - 70
                text: ""
            }

            BaseText {
                text: "Surname:"
                color: Style.primaryColor
            }

            InputArea {
                id: surnameInput
                width: contactImage.height * 2 - 70
                text: ""
            }

            BaseText {
                text: "Mobile phone number:"
                color: Style.primaryColor
            }

            InputArea {
                id: phoneNumberInput
                text: ""
                width: contactImage.height * 2 - 70
                validator: RegExpValidator {
                    regExp: /^(\+|0)\d{7,12}$/
                }
            }

            BaseText {
                text: "Home phone number:"
                color: Style.primaryColor
            }

            InputArea {
                id: homePhoneNumberInput
                width: contactImage.height * 2 - 70
                text: ""
            }

        }
            Row {
                anchors.horizontalCenter: content.horizontalCenter
                anchors.top: infoColumn.bottom
                anchors.topMargin: 10
                spacing: 10
                BaseButton {
                    id: cancelButton
                    buttonText: qsTr("Cancel")
                    onClicked: {
                        root.close();
                    }
                }

                BaseButton {
                    id: acceptButton
                    buttonText: qsTr("Accept")
                }
            }
    }
}

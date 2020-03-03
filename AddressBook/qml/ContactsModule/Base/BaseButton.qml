import QtQuick 2.0
import QtQuick.Controls 2.5
import Style 1.0

Button {
    id: root
    width: 70
    height: 40

    property string buttonText: qsTr("")
    text: buttonText

    background: Rectangle {
        id: buttonBackground
        anchors.fill: root
        color: Style.primaryColor
        opacity: root.pressed ? Style.secondaryOpacity : Style.emphasisOpacity
    }

    contentItem: Text {
        id: buttonContent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: root.text
        color: Style.textColor
        font.pointSize: 13
    }

    onClicked: {
        console.log(buttonText + " button clicked")
    }
}

import QtQuick 2.0
import QtQuick.Controls 2.5
import Style 1.0

TextField {
    id: inputArea

    property string defaultText: "Enter info"
    property string inputText: ""

    background: Rectangle {
        color: Style.backgroundColor
        opacity: Style.emphasisOpacity
    }

    height: 30
    color: Style.textColor
    font.pointSize: 13
    font.underline: focus ? true : false
    placeholderText: defaultText
    text: inputText
}

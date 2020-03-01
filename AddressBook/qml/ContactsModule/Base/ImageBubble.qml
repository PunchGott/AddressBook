import QtQuick 2.0
import Style 1.0
import QtGraphicalEffects 1.0

Rectangle {
    id: root

    property alias image: _internalImage

    color: "transparent"
    radius: width / 2
    border.width: 2
    border.color: Style.primaryColor

    RoundImage {
        id: _internalImage
        anchors.fill: root
        anchors.margins: Style.mediumOffset
        sourceSize.width: width
        sourceSize.height: height
    }

    ColorOverlay {
        anchors.fill: root.image
        source: image
        color: Style.themeInvertedColor
        antialiasing: true
    }
}

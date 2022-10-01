import QtQuick 2.15
import tesajah 1.0

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor

    property alias title: textItem.text

    Text {
        id: textItem
        text: qsTr("Hello tesajah") + " 02"
        anchors.centerIn: parent
        font.family: Constants.largeFont.family
        font.pixelSize: Constants.largeFont.pixelSize
    }
}

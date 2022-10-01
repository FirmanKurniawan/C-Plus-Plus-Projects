pragma Singleton
import QtQuick 2.15

QtObject {
    readonly property int width: 414
    readonly property int height: 896

    readonly property FontLoader mySystemFont: FontLoader { name: "Arial" }

    property alias fontDirectory: directoryFontLoader.fontDirectory
    property alias relativeFontDirectory: directoryFontLoader.relativeFontDirectory

    /* Edit this comment to add your custom font */
    readonly property font font: Qt.font({
                                             family: mySystemFont.name,
                                             pixelSize: Qt.application.font.pixelSize
                                         })
    readonly property font largeFont: Qt.font({
                                                  family: mySystemFont.name,
                                                  pixelSize: Qt.application.font.pixelSize * 1.6
                                              })
    readonly property color backgroundColor: "#c2c2c2"
    readonly property color bgMainolor: "#242728"

    property DirectoryFontLoader directoryFontLoader: DirectoryFontLoader {
        id: directoryFontLoader
    }
}

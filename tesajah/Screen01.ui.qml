import QtQuick 2.15
import QtGraphicalEffects 1.12
import tesajah 1.0

Rectangle {
    width: Constants.width
    height: Constants.height

    color: Constants.bgMainolor

    Image {
        id: grp_radar_03
        x: 0
        y: 0
        source: "images/grp_radar_03.png"
        fillMode: Image.PreserveAspectFit

        Image {
            id: phoenix_logo_colored
            x: 40
            y: 86
            source: "images/phoenix_logo_colored.svg"
            fillMode: Image.PreserveAspectFit

            Image {
                id: kX809
                x: 73
                y: 458
                source: "images/KX-809.svg"
                fillMode: Image.PreserveAspectFit
            }
        }
    }
}

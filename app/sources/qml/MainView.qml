import QtQuick 2.6
import Industrial.Controls 1.0 as Controls

Controls.ApplicationWindow {
    id: main

    visible: true

    header: Rectangle {
        id: topbar
        anchors.left: parent.left
        anchors.right: parent.right
        color: customPalette.backgroundColor
        height: sizings.controlBaseSize

        Controls.RoundButton {
            id: burger
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: y
            iconSource: "qrc:/icons/burger.svg"
            tipText: qsTr("Open drawer")
        }
    }
}

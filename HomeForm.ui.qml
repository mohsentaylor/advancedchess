import QtQuick 2.12
import QtQuick.Controls 2.5

Page {
    width: 600
    height: 400

    title: qsTr("Home")

    Label {
        text: qsTr("You are on the home page.")
        anchors.centerIn: parent
    }

    DelayButton {
        id: delayButton
        x: 265
        y: 144
        text: qsTr("Delay Button")
    }

    CheckBox {
        id: checkBox
        x: 90
        y: 97
        text: qsTr("Check Box")
    }
}

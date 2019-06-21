
import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.0
import QtQuick.Controls 2.4

Rectangle{
    visible: true
    width: 300
    height: 200

    GridLayout {
        columns: 2

        Text {
            id: label1
            text: qsTr("Input Text:")
        }

        TextField {
            id: input
            text: qsTr("1")
            inputMask: mask.text
        }

        Text {
            id: label2
            text: qsTr("Input Mask:")
        }

        TextField {
            id: mask
            text: qsTr("999999")
        }

        Button {
            text: qsTr("&amp;Clear")
            onClicked: {
                input.clear()
                mask.clear()
            }
        }
        Button {
            text: qsTr("&amp;Quit")
            onClicked: {
                Qt.quit()
            }
        }
    }
}

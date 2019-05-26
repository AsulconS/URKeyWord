import QtQuick 2.0
import com.qt.name 1.0
Rectangle {
    id: page
    width: 500; height: 200
    color: "lightgray"

    Text {
        id: helloText
        text: name.leerNombre()
        y: 30
        anchors.horizontalCenter: page.horizontalCenter
        font.pointSize: 24; font.bold: true
    }
    MainWindow
    {
        id: name;
    }
}

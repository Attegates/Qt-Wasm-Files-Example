import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Qt for WebAssembly files example")


    // Signal to c++ to load a file
    signal loadFile();
    // Signal to c++ to save file with content from the text edit
    signal saveFile(string contents);

    Connections {
        target: fileTest
        onToTextEdit: {
            toTextEdit(contents);
        }
    }


    Button {
        id: open
        text: "Open a file"
        anchors.top: parent.top
        anchors.topMargin: 20
        onClicked: {
            loadFile();
        }
    }

    Button {
        id: save
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: open.right
        anchors.leftMargin: 10
        text: "Save a file"
        onClicked: {
            saveFile(textEdit.text);
        }
    }

    Rectangle {
        id: textEditRect
        anchors.top: open.bottom
        anchors.topMargin: 20
        width: parent.width
        height: parent.height - open.height - open.anchors.topMargin - textEditRect.anchors.topMargin
        color:"pink"

        TextEdit {
            id: textEdit
            anchors.fill: parent
        }
    }

    function toTextEdit(text) {
        textEdit.clear();
        textEdit.text = text;
    }

}

import QtQuick 2.0
import Ubuntu.Components 0.1
import Ubuntu.Components.ListItems 0.1 as ListItem
import UQQ 1.0 as QQ

Item {
    id: root

    property alias model: memberView.model
    property alias rotation: arrow.rotation
    property bool newMsg: false
    property string title
    property string subtitle
    property int minHeight: units.gu(6.5)
    property int maxHeight
    property string iconSource
    property alias iconPageSource: loader.source
    property bool isGroup: false
    property int messageCount: 0
    property int onlineCount: 0



    signal clicked
    signal iconClicked

    height: titleItem.height

    Item {
        id: titleItem
        width: parent.width
        height: minHeight

        Row {
            anchors {
                fill: parent
                leftMargin: units.gu(1)
                rightMargin: units.gu(1)
            }
            spacing: units.gu(0.5)

            Image {
                id: faceImg
                anchors.verticalCenter: parent.verticalCenter
                height: parent.height - units.gu(2)
                width: height
                visible: source != ""
                source: iconSource

                UbuntuShape {
                    width: newMsgCount.width + units.gu(0.5)
                    height: newMsgCount.height
                    anchors {
                        right: parent.right
                        bottom: parent.bottom
                    }
                    antialiasing: true
                    color: "orangered"
                    visible: messageCount > 0

                    Label {
                        id: newMsgCount
                        anchors.centerIn: parent
                        text: messageCount
                        font.bold: true
                        color: "white"
                        fontSize: "small"
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    anchors.margins: -units.gu(2)
                    onClicked: {
                        if (root.state != "IconExpand") {
                            root.state = "IconExpand";
                            root.newMsg = false;
                        } else {
                            root.state = "";
                        }

                        root.iconClicked();
                    }
                }
            }
            Label {
                anchors.verticalCenter: parent.verticalCenter
                clip: true
                text: title
            }
            Label {
                id: subtitleLabel
                anchors.verticalCenter: parent.verticalCenter
                text: subtitle
                opacity: root.state != "" ? 1 : 0
                visible: opacity > 0
                Behavior on opacity {
                    NumberAnimation {}
                }
            }

            Rectangle {
                id: newMsgTip
                width: units.gu(1.5)
                height: width
                radius: width
                color: "darkorange"
                opacity: newMsg ? 1 : 0
                antialiasing: true
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Image {
            id: arrow
            anchors {
                right: parent.right
                rightMargin: units.gu(1)
                verticalCenter: parent.verticalCenter
            }

            source: "../arrow.png"
        }

        MouseArea {
            anchors.fill: parent
            anchors.leftMargin: faceImg.source == "" ? 0 : faceImg.width + units.gu(2)
            onClicked: {
                if (root.state != "Expand") {
                    root.state = "Expand";
                    root.newMsg = false;
                } else {
                    root.state = "";
                }
                root.clicked();
            }
        }
        ListItem.ThinDivider { anchors.bottom: parent.bottom }
    }

    ListView {
        id: memberView
        anchors {
            fill: parent
            topMargin: root.minHeight
        }
        opacity: 0
        visible: opacity > 0
        clip: true
        interactive: false
        delegate: Member {
            width: parent.width
            isGroupMember: root.isGroup
        }
    }

    Loader {
        id: loader
        anchors {
            fill: parent
            topMargin: root.minHeight + units.gu(1)
            leftMargin: units.gu(1)
            rightMargin: units.gu(1)
        }
        active: false
        opacity: 0
        visible: opacity > 0
    }

    states: [
        State {
            name: "Expand"

            PropertyChanges {
                target: root
                height: maxHeight
                rotation: 90
            }
            PropertyChanges {
                target: flick
                explicit: true
                contentY: root.y
                interactive: false
            }
            PropertyChanges {
                target: memberView
                opacity: 1
                interactive: true
            }
            PropertyChanges {
                target: loader
                active: true
            }
        },
        State {
            name: "IconExpand"

            PropertyChanges {
                target: root
                height: maxHeight
                rotation: 90
            }
            PropertyChanges {
                target: flick
                explicit: true
                contentY: root.y
                interactive: false
            }
            PropertyChanges {
                target: loader
                active: true
                opacity: 1
            }
        }

    ]

    transitions: [
        Transition {
            NumberAnimation { properties: "height,contentY,rotation,opacity" }
        }
    ]
}

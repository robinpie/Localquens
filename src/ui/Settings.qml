// SPDX-FileCopyrightText: 2022 Felipe Kinoshita <kinofhek@gmail.com>
// SPDX-FileCopyrightText: 2026 robinpie <robin413@protonmail.com>
// SPDX-License-Identifier: GPL-3.0-or-later

import QtQuick
import QtQuick.Controls as QQC2
import QtQuick.Layouts
import org.kde.kirigami as Kirigami

import io.github.robinpie.localquens

Kirigami.Page {
    id: settingsPage

    title: i18n("Settings")

    Kirigami.FormLayout {
        anchors.fill: parent

        RowLayout {
            QQC2.Label {
                text: i18n("Paragraphs:")
            }
            QQC2.SpinBox {
                from: 1
                to: 100
                value: Config.paragraphs

                onValueModified: {
                    Config.paragraphs = value
                    Config.save()
                    Controller.fetch()
                }
            }
        }

        RowLayout {
            QQC2.Label {
                text: i18n("Paragraph Length:")
            }
            QQC2.ComboBox {
                model: ["short", "medium", "long"]

                currentIndex: {
                    if (Config.paragraphLength == "small") {
                        return 0;
                    } else if (Config.paragraphLength == "medium") {
                        return 1;
                    } else if (Config.paragraphLength == "long") {
                        return 2;
                    }
                }
                onActivated: {
                    if (currentIndex == 0) {
                        Config.paragraphLength = "small"
                    } else if (currentIndex == 1) {
                        Config.paragraphLength = "medium"
                    } else if (currentIndex == 2) {
                        Config.paragraphLength = "long"
                    }

                    Config.save()
                    Controller.fetch()
                }
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Bold and Italic text")
            checked: Config.boldAndItalic
            onClicked: {
                Config.boldAndItalic = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Links")
            checked: Config.links
            onClicked: {
                Config.links = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Code blocks")
            checked: Config.code
            onClicked: {
                Config.code = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Unordered Lists")
            checked: Config.unorderedLists
            onClicked: {
                Config.unorderedLists = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Ordered Lists")
            checked: Config.orderedLists
            onClicked: {
                Config.orderedLists = checked
                Config.save()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Description Lists")
            checked: Config.descriptionLists
            onClicked: {
                Config.descriptionLists = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show Blockquotes")
            checked: Config.blockquotes
            onClicked: {
                Config.blockquotes = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("Show headings")
            checked: Config.headings
            onClicked: {
                Config.headings = checked
                Config.save()
                Controller.fetch()
            }
        }

        QQC2.CheckBox {
            text: i18n("All Caps")
            checked: Config.allCaps
            onClicked: {
                Config.allCaps = checked
                Config.save()
                Controller.fetch()
            }
        }
    }
}

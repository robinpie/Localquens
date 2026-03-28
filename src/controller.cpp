// SPDX-FileCopyrightText: 2022 Felipe Kinoshita <kinofhek@gmail.com>
// SPDX-FileCopyrightText: 2026 robinpie <robin413@protonmail.com>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "controller.h"
#include "config.h"
#include "loremipsum.h"

Controller::Controller(QObject* parent)
    : QObject(parent)
{
}

void Controller::fetch()
{
    Q_EMIT response(LoremIpsum::generate(
        Config::self()->paragraphs(),
        Config::self()->paragraphLength(),
        Config::self()->boldAndItalic(),
        Config::self()->links(),
        Config::self()->code(),
        Config::self()->unorderedLists(),
        Config::self()->orderedLists(),
        Config::self()->descriptionLists(),
        Config::self()->blockquotes(),
        Config::self()->headings(),
        Config::self()->allCaps()
    ));
}

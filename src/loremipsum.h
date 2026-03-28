// SPDX-FileCopyrightText: 2026 robinpie <robin413@protonmail.com>
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include <QString>

class LoremIpsum
{
public:
    static QString generate(int paragraphs,
                            const QString &length,
                            bool boldAndItalic,
                            bool links,
                            bool code,
                            bool unorderedLists,
                            bool orderedLists,
                            bool descriptionLists,
                            bool blockquotes,
                            bool headings,
                            bool allCaps);
};

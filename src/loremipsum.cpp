// SPDX-FileCopyrightText: 2026 robinpie <robin413@protonmail.com>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "loremipsum.h"

#include <QRandomGenerator>
#include <QStringList>

namespace {

const QStringList corpus = {
    QStringLiteral("Lorem ipsum dolor sit amet, consectetur adipiscing elit."),
    QStringLiteral("Ut labore et dolore magna aliqua, ut enim ad minim veniam."),
    QStringLiteral("Quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."),
    QStringLiteral("Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur."),
    QStringLiteral("Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."),
    QStringLiteral("Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium."),
    QStringLiteral("Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit."),
    QStringLiteral("Neque porro quisquam est qui dolorem ipsum quia dolor sit amet consectetur adipisci velit."),
    QStringLiteral("Ut enim ad minima veniam quis nostrum exercitationem ullam corporis suscipit laboriosam."),
    QStringLiteral("Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur."),
    QStringLiteral("At vero eos et accusamus et iusto odio dignissimos ducimus qui blanditiis praesentium."),
    QStringLiteral("Nam libero tempore cum soluta nobis est eligendi optio cumque nihil impedit quo minus."),
    QStringLiteral("Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet."),
    QStringLiteral("Itaque earum rerum hic tenetur a sapiente delectus ut aut reiciendis voluptatibus maiores."),
    QStringLiteral("Totam rem aperiam eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt."),
    QStringLiteral("Nisi ut aliquid ex ea commodi consequatur quis autem vel eum iure reprehenderit."),
    QStringLiteral("Illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo."),
    QStringLiteral("Nam libero tempore soluta nobis est eligendi optio cumque nihil impedit."),
    QStringLiteral("Similique sunt in culpa qui officia deserunt mollitia animi id est laborum et dolorum fuga."),
    QStringLiteral("Et harum quidem rerum facilis est et expedita distinctio nam libero tempore."),
    QStringLiteral("Ut et voluptates repudiandae sint et molestiae non recusandae itaque earum rerum."),
    QStringLiteral("Hic tenetur a sapiente delectus ut aut reiciendis voluptatibus maiores alias."),
    QStringLiteral("Consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt neque porro."),
    QStringLiteral("Quisquam est qui dolorem ipsum quia dolor sit amet consectetur adipisci velit."),
    QStringLiteral("Sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat."),
    QStringLiteral("Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat."),
    QStringLiteral("Vel illum dolore eu feugiat nulla facilisis at vero eros et accumsan et iusto odio."),
    QStringLiteral("Dignissim qui blandit praesent luptatum zzril delenit augue duis dolore te feugait nulla facilisi."),
    QStringLiteral("Nam liber tempor cum soluta nobis eleifend option congue nihil imperdiet doming id quod mazim."),
    QStringLiteral("Placerat facer possim assum typi non habent claritatem insitam est usus legentis."),
    QStringLiteral("In iis qui ratione voluptatem sequi nesciunt neque porro quisquam est qui dolorem ipsum."),
    QStringLiteral("Quia voluptas sit aspernatur aut odit aut fugit sed quia consequuntur magni dolores eos."),
    QStringLiteral("Ratione voluptatem sequi nesciunt neque porro quisquam est qui dolorem ipsum quia dolor."),
    QStringLiteral("Sit amet consectetur adipisci velit sed quia non numquam eius modi tempora incidunt."),
    QStringLiteral("Ut labore et dolore magnam aliquam quaerat voluptatem ut enim ad minima veniam."),
    QStringLiteral("Quis nostrum exercitationem ullam corporis suscipit laboriosam nisi ut aliquid ex ea."),
    QStringLiteral("Commodi consequatur quis autem vel eum iure reprehenderit qui in ea voluptate velit."),
    QStringLiteral("Esse quam nihil molestiae consequatur vel illum dolore eu feugiat nulla pariatur."),
    QStringLiteral("At vero eos et accusam et justo duo dolores et ea rebum stet clita kasd gubergren."),
    QStringLiteral("No sea takimata sanctus est lorem ipsum dolor sit amet lorem ipsum dolor sit amet."),
    QStringLiteral("Consetetur sadipscing elitr sed diam nonumy eirmod tempor invidunt ut labore et dolore."),
    QStringLiteral("Magna aliquyam erat sed diam voluptua at vero eos et accusam et justo duo dolores."),
    QStringLiteral("Et ea rebum stet clita kasd gubergren no sea takimata sanctus est lorem ipsum dolor sit amet."),
    QStringLiteral("Stet clita kasd gubergren no sea takimata sanctus est lorem ipsum dolor sit amet consetetur."),
    QStringLiteral("Rebum stet clita kasd gubergren no sea takimata sanctus est lorem ipsum dolor sit amet."),
};

static QString randomSentence()
{
    return corpus.at(static_cast<int>(QRandomGenerator::global()->bounded(static_cast<quint32>(corpus.size()))));
}

static QStringList pickSentences(int count)
{
    QStringList result;
    result.reserve(count);
    for (int i = 0; i < count; ++i)
        result << randomSentence();
    return result;
}

static QString decorateBoldItalic(const QString &sentence)
{
    QStringList words = sentence.split(QLatin1Char(' '));
    if (words.size() < 4)
        return sentence;
    const int lo = words.size() / 3;
    const int hi = (2 * words.size()) / 3;
    const int pos = lo + static_cast<int>(QRandomGenerator::global()->bounded(static_cast<quint32>(hi - lo)));
    const bool useBold = QRandomGenerator::global()->bounded(2) == 0;
    const QString tag = useBold ? QStringLiteral("strong") : QStringLiteral("em");
    words[pos] = QStringLiteral("<%1>%2</%1>").arg(tag, words[pos]);
    return words.join(QLatin1Char(' '));
}

static QString decorateLink(const QString &sentence)
{
    QStringList words = sentence.split(QLatin1Char(' '));
    if (words.size() < 4)
        return sentence;
    const int lo = words.size() / 3;
    const int hi = (2 * words.size()) / 3;
    const int pos = lo + static_cast<int>(QRandomGenerator::global()->bounded(static_cast<quint32>(hi - lo)));
    QString word = words[pos];
    QString trail;
    if (!word.isEmpty() && (word.back() == QLatin1Char(',') || word.back() == QLatin1Char('.'))) {
        trail = word.back();
        word.chop(1);
    }
    words[pos] = QStringLiteral("<a href=\"https://example.com\">%1</a>%2").arg(word, trail);
    return words.join(QLatin1Char(' '));
}

static QString buildParagraph(const QString &length, bool boldAndItalic, bool links)
{
    int count;
    if (length == QStringLiteral("short"))
        count = 2 + static_cast<int>(QRandomGenerator::global()->bounded(3u));
    else if (length == QStringLiteral("long"))
        count = 8 + static_cast<int>(QRandomGenerator::global()->bounded(5u));
    else
        count = 5 + static_cast<int>(QRandomGenerator::global()->bounded(3u));

    QStringList sentences = pickSentences(count);
    for (QString &s : sentences) {
        if (boldAndItalic && QRandomGenerator::global()->bounded(3u) == 0)
            s = decorateBoldItalic(s);
        if (links && QRandomGenerator::global()->bounded(3u) == 0)
            s = decorateLink(s);
    }
    return QStringLiteral("<p>%1</p>").arg(sentences.join(QLatin1Char(' ')));
}

static QString buildHeading()
{
    const int level = 2 + static_cast<int>(QRandomGenerator::global()->bounded(3u));
    QStringList words = randomSentence().split(QLatin1Char(' '));
    int take = qMin(3 + static_cast<int>(QRandomGenerator::global()->bounded(3u)), words.size());
    QString last = words.at(take - 1);
    if (!last.isEmpty() && (last.back() == QLatin1Char('.') || last.back() == QLatin1Char(',')))
        last.chop(1);
    words[take - 1] = last;
    return QStringLiteral("<h%1>%2</h%1>").arg(level).arg(words.mid(0, take).join(QLatin1Char(' ')));
}

static QString buildUnorderedList()
{
    const int items = 3 + static_cast<int>(QRandomGenerator::global()->bounded(3u));
    QString html = QStringLiteral("<ul>\n");
    for (int i = 0; i < items; ++i)
        html += QStringLiteral("  <li>%1</li>\n").arg(randomSentence());
    html += QStringLiteral("</ul>");
    return html;
}

static QString buildOrderedList()
{
    const int items = 3 + static_cast<int>(QRandomGenerator::global()->bounded(3u));
    QString html = QStringLiteral("<ol>\n");
    for (int i = 0; i < items; ++i)
        html += QStringLiteral("  <li>%1</li>\n").arg(randomSentence());
    html += QStringLiteral("</ol>");
    return html;
}

static QString buildDescriptionList()
{
    const int items = 2 + static_cast<int>(QRandomGenerator::global()->bounded(3u));
    QString html = QStringLiteral("<dl>\n");
    for (int i = 0; i < items; ++i) {
        QStringList termWords = randomSentence().split(QLatin1Char(' '));
        int take = qMin(2 + static_cast<int>(QRandomGenerator::global()->bounded(2u)), termWords.size());
        QString term = termWords.mid(0, take).join(QLatin1Char(' '));
        if (!term.isEmpty() && (term.back() == QLatin1Char('.') || term.back() == QLatin1Char(',')))
            term.chop(1);
        html += QStringLiteral("  <dt>%1</dt>\n  <dd>%2</dd>\n").arg(term, randomSentence());
    }
    html += QStringLiteral("</dl>");
    return html;
}

static QString buildBlockquote()
{
    return QStringLiteral("<blockquote><p>%1</p></blockquote>").arg(randomSentence());
}

static QString buildCode()
{
    QStringList words = randomSentence().split(QLatin1Char(' '));
    int take = qMin(4 + static_cast<int>(QRandomGenerator::global()->bounded(4u)), words.size());
    QString snippet = words.mid(0, take).join(QLatin1Char(' '));
    if (!snippet.isEmpty() && (snippet.back() == QLatin1Char('.') || snippet.back() == QLatin1Char(',')))
        snippet.chop(1);
    return QStringLiteral("<pre><code>%1</code></pre>").arg(snippet);
}

} // namespace

QString LoremIpsum::generate(int paragraphs,
                              const QString &length,
                              bool boldAndItalic,
                              bool links,
                              bool code,
                              bool unorderedLists,
                              bool orderedLists,
                              bool descriptionLists,
                              bool blockquotes,
                              bool headings,
                              bool allCaps)
{
    using BuildFn = QString(*)();
    QList<BuildFn> extras;
    if (unorderedLists)  extras << buildUnorderedList;
    if (orderedLists)    extras << buildOrderedList;
    if (descriptionLists) extras << buildDescriptionList;
    if (blockquotes)     extras << buildBlockquote;
    if (code)            extras << buildCode;

    QStringList blocks;
    for (int i = 0; i < paragraphs; ++i) {
        if (headings && QRandomGenerator::global()->bounded(2u) == 0)
            blocks << buildHeading();

        blocks << buildParagraph(length, boldAndItalic, links);

        if (!extras.isEmpty() && QRandomGenerator::global()->bounded(2u) == 0) {
            const int pick = static_cast<int>(QRandomGenerator::global()->bounded(static_cast<quint32>(extras.size())));
            blocks << extras[pick]();
        }
    }

    QString result = blocks.join(QStringLiteral("\n\n"));

    if (allCaps)
        result = result.toUpper();

    return result;
}

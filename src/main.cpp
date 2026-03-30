// SPDX-FileCopyrightText: 2022 Felipe Kinoshita <kinofhek@gmail.com>
// SPDX-FileCopyrightText: 2026 robinpie <robin413@protonmail.com>
// SPDX-License-Identifier: LGPL-2.1-or-later

#include <QApplication>
#include <QCommandLineParser>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQuickWindow>
#include <QQmlContext>

#include "version-localquens.h"
#include <KAboutData>
#include <KLocalizedContext>
#include <KLocalizedString>
#include <KDBusService>


Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName(QStringLiteral("robinpie"));

    KLocalizedString::setApplicationDomain("localquens");

    KAboutData aboutData(
                         // The program name used internally.
                         QStringLiteral("localquens"),
                         // A displayable program name string.
                         i18nc("@title", "Localquens"),
                         // The program version string.
                         QStringLiteral(LOCALQUENS_VERSION_STRING),
                         // Short description of what the app does.
                         i18n("Generate lorem ipsum text"),
                         // The license this code is released under.
                         KAboutLicense::GPL,
                         // Copyright Statement.
                         i18n("© 2022–2026"));
    aboutData.addAuthor(i18nc("@info:credit", "robinpie"), i18nc("@info:credit", "Fork maintainer"), QStringLiteral("robin413@protonmail.com"), QStringLiteral(""));
    aboutData.addAuthor(i18nc("@info:credit", "Felipe Kinoshita"), i18nc("@info:credit", "Original author"), QStringLiteral("kinofhek@gmail.com"), QStringLiteral("https://fhek.gitlab.io"));
    aboutData.setBugAddress("");
    aboutData.setDesktopFileName(QStringLiteral("io.github.robinpie.localquens"));
    KAboutData::setApplicationData(aboutData);
    QGuiApplication::setWindowIcon(QIcon::fromTheme(QStringLiteral("io.github.robinpie.localquens")));

    QQmlApplicationEngine engine;

    QCommandLineParser parser;

    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);

    engine.rootContext()->setContextObject(new KLocalizedContext(&engine));
    engine.loadFromModule(QStringLiteral("io.github.robinpie.localquens"), QStringLiteral("Main"));

    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    KDBusService service(KDBusService::Unique);

    return app.exec();
}

#include "smoothysearch/qt_url_opener.h"

#include <QDesktopServices>
#include <QUrl>

bool open_url_with_activation(const QString& url)
{
    const QUrl parsed_url = QUrl::fromUserInput(url.trimmed());

    if (!parsed_url.isValid() || parsed_url.isEmpty()) {
        return false;
    }

    return QDesktopServices::openUrl(parsed_url);
}

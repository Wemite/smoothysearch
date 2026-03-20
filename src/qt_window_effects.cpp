#include "smoothysearch/qt_window_effects.h"

#include <QCursor>
#include <QGuiApplication>
#include <QPainterPath>
#include <QRegion>
#include <QWindow>

#if SMOOTHYSEARCH_HAS_KWINDOWSYSTEM
#include <KWindowEffects>
#endif

namespace {

QRegion rounded_region_for_window(QWindow* window, int radius)
{
    if (!window) {
        return {};
    }

    const QRect rect(QPoint(0, 0), window->size());
    if (!rect.isValid()) {
        return {};
    }

    const int clamped_radius = std::clamp(radius, 0, std::min(rect.width(), rect.height()) / 2);
    if (clamped_radius <= 0) {
        return QRegion(rect);
    }

    QPainterPath path;
    path.addRoundedRect(QRectF(rect), clamped_radius, clamped_radius);
    return QRegion(path.toFillPolygon().toPolygon());
}

QWindow* resolve_target_window()
{
    if (QWindow* window = QGuiApplication::focusWindow(); window && window->isVisible()) {
        return window;
    }

    if (QWindow* window = QGuiApplication::topLevelAt(QCursor::pos()); window && window->isVisible()) {
        return window;
    }

    for (QWindow* window : QGuiApplication::topLevelWindows()) {
        if (!window || !window->isVisible()) {
            continue;
        }

        if (window->flags().testFlag(Qt::Tool)) {
            return window;
        }
    }

    return QGuiApplication::topLevelWindows().value(0, nullptr);
}

} // namespace

bool sync_plasma_blur_for_visible_windows(int radius)
{
#if SMOOTHYSEARCH_HAS_KWINDOWSYSTEM
    if (!KWindowEffects::isEffectAvailable(KWindowEffects::BlurBehind)) {
        return false;
    }

    QWindow* window = resolve_target_window();
    if (!window || !window->isVisible()) {
        return false;
    }

    const QRegion region = rounded_region_for_window(window, radius);
    window->setMask(region);
    KWindowEffects::enableBlurBehind(window, true, region);
    return true;
#else
    Q_UNUSED(radius);
    return false;
#endif
}

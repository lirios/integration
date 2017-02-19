/****************************************************************************
 * This file is part of Liri.
 *
 * Copyright (C) 2010-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:GPL3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#pragma once

#include <QtCore/QObject>

#include "liritheme.h"

namespace Vibe {
class QGSettings;
}

class HintsSettings : public QObject
{
    Q_OBJECT
public:
    HintsSettings(Vibe::QGSettings *settings, QObject *parent = 0);

    inline QVariant themeHint(QPlatformTheme::ThemeHint hint) const {
        if (m_hints.contains(hint))
            return m_hints[hint];
        return QVariant();
    }

    void collectHints();

private:
    Vibe::QGSettings *m_settings;
    QHash<QPlatformTheme::ThemeHint, QVariant> m_hints;

    Qt::ToolButtonStyle toolButtonStyle(const QVariant &value);
    int toolBarIconSize(const QVariant &value);

    void qtSettingsChanged();
    void toolButtonStyleChanged();
    void iconChanged();
    void styleChanged();
};
/**************************************************************************
**
** This file is part of Qt Creator
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** Contact: Nokia Corporation (qt-info@nokia.com)
**
**
** GNU Lesser General Public License Usage
**
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this file.
** Please review the following information to ensure the GNU Lesser General
** Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** Other Usage
**
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**************************************************************************/

#ifndef DETAILSBUTTON_H
#define DETAILSBUTTON_H

#include "qtcreatorutilities_global.h"

#include <QtGui/QAbstractButton>
#include <QtGui/QPixmap>

QT_FORWARD_DECLARE_CLASS(QGraphicsOpacityEffect)

namespace QtCreatorUtilities {

class QT_CREATOR_UTILITIES_EXPORT FadingPanel : public QWidget
{
public:
    FadingPanel(QWidget *parent = 0);
    void setOpacity(qreal value);
    void fadeTo(float value);
protected:
    QGraphicsOpacityEffect *m_opacityEffect;
};

class QT_CREATOR_UTILITIES_EXPORT DetailsButton : public QAbstractButton
{
    Q_OBJECT
    Q_PROPERTY(float fader READ fader WRITE setFader)

public:
    DetailsButton(QWidget *parent = 0);

    QSize sizeHint() const;
    float fader() { return m_fader; }
    void setFader(float value) { m_fader = value; update(); }

protected:
    void paintEvent(QPaintEvent *e);
    bool event(QEvent *e);

private:
    QPixmap cacheRendering(const QSize &size, bool checked);
    QPixmap m_checkedPixmap;
    QPixmap m_uncheckedPixmap;
    float m_fader;
};
} // namespace QtCreatorUtilities
#endif // DETAILSBUTTON_H

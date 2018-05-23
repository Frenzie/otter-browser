/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2018 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#include "FeedPropertiesDialog.h"
#include "../core/FeedsManager.h"
#include "../core/ThemesManager.h"

#include "ui_FeedPropertiesDialog.h"

namespace Otter
{

FeedPropertiesDialog::FeedPropertiesDialog(Feed *feed, QWidget *parent) : Dialog(parent),
	m_feed(feed),
	m_ui(new Ui::FeedPropertiesDialog)
{
	m_ui->setupUi(this);

	if (feed)
	{
		m_ui->titleLineEditWidget->setText(feed->getTitle());
		m_ui->iconButton->setIcon(feed->getIcon());
		m_ui->urlLineEditWidget->setText(feed->getUrl().toString());
		m_ui->updateIntervalSpinBox->setValue(feed->getUpdateInterval());
	}

	m_ui->iconButton->setDefaultIcon(ThemesManager::createIcon(QLatin1String("application-rss+xml")));
}

FeedPropertiesDialog::~FeedPropertiesDialog()
{
	delete m_ui;
}

void FeedPropertiesDialog::changeEvent(QEvent *event)
{
	QDialog::changeEvent(event);

	if (event->type() == QEvent::LanguageChange)
	{
		m_ui->retranslateUi(this);
	}
}

}

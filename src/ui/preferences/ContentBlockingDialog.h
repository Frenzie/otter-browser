/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2013 - 2020 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
* Copyright (C) 2014 - 2017 Jan Bajer aka bajasoft <jbajer@gmail.com>
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

#ifndef OTTER_CONTENTBLOCKINGDIALOG_H
#define OTTER_CONTENTBLOCKINGDIALOG_H

#include "../Dialog.h"
#include "../ItemDelegate.h"

namespace Otter
{

namespace Ui
{
	class ContentBlockingDialog;
}

class ContentBlockingDialog final : public Dialog
{
	Q_OBJECT

public:
	explicit ContentBlockingDialog(QWidget *parent = nullptr);
	~ContentBlockingDialog();

protected:
	void changeEvent(QEvent *event) override;

protected slots:
	void updateProfilesActions();
	void addRule();
	void editRule();
	void removeRule();
	void updateRulesActions();
	void save();

private:
	Ui::ContentBlockingDialog *m_ui;
};

}

#endif

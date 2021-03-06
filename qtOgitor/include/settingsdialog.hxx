/*/////////////////////////////////////////////////////////////////////////////////
/// An
///    ___   ____ ___ _____ ___  ____
///   / _ \ / ___|_ _|_   _/ _ \|  _ \
///  | | | | |  _ | |  | || | | | |_) |
///  | |_| | |_| || |  | || |_| |  _ <
///   \___/ \____|___| |_| \___/|_| \_\
///                              File
///
/// Copyright (c) 2008-2015 Ismail TARIM <ismail@royalspor.com> and the Ogitor Team
///
/// The MIT License
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
////////////////////////////////////////////////////////////////////////////////*/

#ifndef SETTINGSDIALOG_HXX
#define SETTINGSDIALOG_HXX

#include <QtWidgets/QDialog>
#include <QtWidgets/QWidget>

#include "OgitorsPrerequisites.h"
#include "ui_settingsdialog.h"
#include "colourpicker.hxx"

//----------------------------------------------------------------------------------

class SettingsDialog : public QDialog, public Ui::settingsdialog 
{
    Q_OBJECT

public:
    SettingsDialog(QWidget *parent, Ogitors::PROJECTOPTIONS *options);
    virtual ~SettingsDialog();
    void addResourceLocation(int loctype, QString path);

private:
    Ogitors::PROJECTOPTIONS *mOptions;
    std::vector<int>         mResourceFileTypes;
    ColourPickerWidget      *mSelRectColourWidget;
    ColourPickerWidget      *mSelColourWidget;
    ColourPickerWidget      *mHighlightColourWidget;
    ColourPickerWidget      *mSelectHighlightColourWidget;
    ColourPickerWidget      *mGridColourWidget;

    bool eventFilter(QObject* watched, QEvent* e);

private Q_SLOTS:
    void onAccept();
    void browse();
    void onAddDirectory();
    void onRemoveEntry();
    void setDirty();
    void autoBackupStateChanged(int state);
    void onAutoBackupValueChanged();
    void onSelectPathForBackup();
};

//----------------------------------------------------------------------------------

#endif // SETTINGSDIALOG_HXX

//----------------------------------------------------------------------------------


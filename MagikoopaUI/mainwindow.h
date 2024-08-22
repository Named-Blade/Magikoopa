#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "patchmaker.h"

#include <QMainWindow>
#include <QSettings>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

    void loadLastWorkingDirectory();
    void setWorkingDirectory(const QString &path, bool updateSettings = false);
    void build();

signals:
    void on_finished();

private slots:
    void appendOutput(const QString& catergory, const QString& text, bool showCategory);

    void setActionsDisabled(bool disabled);

    void on_actionSet_Working_Directory_triggered();

    void on_makeInsertButton_clicked();

    void on_makeCleanButton_clicked();

    void on_actionQuit_triggered();

    void on_issues_doubleClicked(const QModelIndex &index);

    void on_actionSetEditor_triggered();

private:
    Ui::MainWindow* ui;

    PatchMaker* patchMaker;

    enum IssueType
    {
        Warning,
        Error
    };

    void addIssue(QString text, IssueType type, bool removeLabel = true);
    int m_issueCount;

    void clearIssues();

    QSettings* settings;
    void loadSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H

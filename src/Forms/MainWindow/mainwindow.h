#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLayout>
#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QFrame>
#include <QToolBar>
#include <QAction>
#include <QMenu>

namespace Luna {

    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

        QLabel *labelUser() const;
        QLabel *labelLevel() const;

        QAction *aboutAction() const;

    signals:

    public slots:

    private:
        // Private Methods
        void initilizeWidgets();
        void configWidgets();
        void createLayout();
        void createMenus();
        void createActions();
        void createToolBars();

        // Private Variables
        QGroupBox *m_centralWidget;
        QLabel *m_labelLogo, *m_labelUser, *m_labelUserTab,
               *m_labelLevel, *m_labelLevelTab;
        QFrame *m_frame;
        QHBoxLayout *m_frameLayout;

        QToolBar *m_toolBar;
        QMenu *m_fileMenu, *m_helpMenu;
        QAction *m_customerManagerAction, *m_carManagerAction,
                *m_orderManagerAction, *m_quitAction, *m_aboutAction;
    };

}

#endif // MAINWINDOW_H

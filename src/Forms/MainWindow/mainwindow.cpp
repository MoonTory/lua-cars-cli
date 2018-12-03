#include "mainwindow.h"
#include <QMenuBar>

namespace Luna {

    MainWindow::MainWindow(QWidget *parent)
        :QMainWindow(parent)
    {
        this->setWindowTitle("Luna Cars");
        this->setWindowIcon(QIcon(":/images/resources/icons/Moon-icon.png"));

        this->initilizeWidgets();

        // Setting Central Widget for the main Menu
        this->setFixedSize(300,500);
        this->setCentralWidget(this->m_central);

        this->configWidgets();
        this->createLayout();
        this->createActions();
        this->createMenus();
        this->createToolBars();
    }

    void MainWindow::initilizeWidgets()
    {
        this->m_central = new QWidget();
        this->m_mainBox = new QGroupBox();
        this->m_labelLogo = new QLabel();
        this->m_labelUser = new QLabel();
        this->m_labelUserTab = new QLabel();
        this->m_labelLevel = new QLabel();
        this->m_labelLevelTab = new QLabel();
        this->m_frame = new QFrame();
    }

    void MainWindow::configWidgets()
    {
        this->m_mainBox->setTitle(tr("Main Menu"));

        this->m_labelLogo->setPixmap(QPixmap(":/images/resources/logo/Luna_Cars_Client_Logo.png"));
        this->m_labelLogo->setGeometry(27,30,241,30);

        this->m_labelUserTab->setText("User:");
        this->m_labelUserTab->setStyleSheet("font-weight: bold; color: red; font-size: 13pt;");
        this->m_labelUser->setText("default");
        this->m_labelUser->setStyleSheet("font-size: 11pt;");

        this->m_labelLevelTab->setText("Level:");
        this->m_labelLevelTab->setStyleSheet("font-weight: bold; color: red; font-size: 13pt;");
        this->m_labelLevel->setText("default");
        this->m_labelLevel->setStyleSheet("font-size: 11pt;");

        this->m_frame->setGeometry(12,68,271,39);
    }

    void MainWindow::createLayout()
    {

        QHBoxLayout *logoLayout = new QHBoxLayout();
        logoLayout->addStretch(1);
        logoLayout->addWidget(this->m_labelLogo);
        logoLayout->addStretch(1);

        this->m_frameLayout = new QHBoxLayout();
        this->m_frameLayout->addWidget(this->m_labelUserTab);
        this->m_frameLayout->addWidget(this->m_labelUser);
        this->m_frameLayout->addWidget(this->m_labelLevelTab);
        this->m_frameLayout->addWidget(this->m_labelLevel);

        this->m_frame->setLayout(this->m_frameLayout);

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addLayout(logoLayout);
        layout->addWidget(this->m_frame);
        layout->addStretch(1);
        this->m_mainBox->setLayout(layout);

        QVBoxLayout *centralLayout = new QVBoxLayout();
        centralLayout->addWidget(m_mainBox);
        this->m_central->setLayout(centralLayout);
    }

    void MainWindow::createMenus()
    {
        this->m_fileMenu = menuBar()->addMenu(tr("File"));
        this->m_fileMenu->addAction(this->m_customerManagerAction);
        this->m_fileMenu->addAction(this->m_carManagerAction);
        this->m_fileMenu->addAction(this->m_orderManagerAction);
        this->m_fileMenu->addSeparator();
        this->m_fileMenu->addAction(this->m_quitAction);

        this->m_helpMenu = menuBar()->addMenu(tr("Help"));
        this->m_helpMenu->addAction(this->m_aboutAction);

    }

    void MainWindow::createActions()
    {
        this->m_customerManagerAction = new QAction(tr("Customer Manager"), this);
        this->m_customerManagerAction->setIcon(QIcon(":/images/resources/icons/address-card.png"));

        this->m_carManagerAction = new QAction(tr("Car Manager"), this);
        this->m_carManagerAction->setIcon(QIcon(":/images/resources/icons/car.png"));

        this->m_orderManagerAction = new QAction(tr("Order Manager"), this);
        this->m_orderManagerAction->setIcon(QIcon(":/images/resources/icons/dashboard.png"));

        this->m_quitAction = new QAction(tr("Quit"), this);
        this->m_quitAction->setIcon(QIcon(":/images/resources/icons/close.png"));
        connect(this->m_quitAction, SIGNAL(triggered(bool)), this, SLOT(close()));

        this->m_aboutAction = new QAction(tr("About"), this);
        this->m_aboutAction->setIcon(QIcon(":/images/resources/icons/question-circle.png"));
    }

    void MainWindow::createToolBars()
    {
        this->m_toolBar = addToolBar(tr("File"));
        this->m_toolBar->addAction(this->m_customerManagerAction);
        this->m_toolBar->addAction(this->m_carManagerAction);
        this->m_toolBar->addAction(this->m_orderManagerAction);
    }

    QAction *MainWindow::aboutAction() const
    {
        return m_aboutAction;
    }

    QLabel *MainWindow::labelLevel() const
    {
        return m_labelLevel;
    }

    QLabel *MainWindow::labelUser() const
    {
        return m_labelUser;
    }

} // namespace Luna

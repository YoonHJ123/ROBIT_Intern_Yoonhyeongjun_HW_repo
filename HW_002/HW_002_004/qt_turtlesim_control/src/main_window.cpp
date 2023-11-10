/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/qt_turtlesim_control/main_window.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_turtlesim_control
{
  using namespace Qt;

  /*****************************************************************************
  ** Implementation [MainWindow]
  *****************************************************************************/

  MainWindow::MainWindow(int argc, char** argv, QWidget* parent) : QMainWindow(parent), qnode(argc, argv)
  {
    ui.setupUi(this);  // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.

    setWindowIcon(QIcon(":/images/icon.png"));

    qnode.init();

    qnode.X = 0;
    qnode.Z = 0;

    connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(pushButton_1()));
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(pushButton_2()));
    connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(pushButton_3()));
    connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(pushButton_4()));
    connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(pushButton_5()));

    QObject::connect(&qnode, SIGNAL(rosShutdown()),this,SLOT(close()));
  }

  MainWindow::~MainWindow()
  {
  }

  /*****************************************************************************
  ** Functions
  *****************************************************************************/

  void MainWindow::pushButton_1()
  {
      qnode.X = 2;
      qnode.Z = 0;
  }
  void MainWindow::pushButton_2()
  {
      qnode.Z = +2;
  }
  void MainWindow::pushButton_3()
  {
      qnode.Z = -2;
  }
  void MainWindow::pushButton_4()
  {
      qnode.X = -2;
      qnode.Z = 0;
  }
  void MainWindow::pushButton_5()
  {
      qnode.X = 0;
      qnode.Z = 0;
  }
  void MainWindow::keyPressEvent(QKeyEvent *event)
  {
      switch (event->key()) {
      case Qt::Key_W:
          qnode.X = 2;
          qnode.Z = 0;
          break;
      case Qt::Key_S:
          qnode.X = -2;
          qnode.Z = 0;
          break;
      case Qt::Key_A:
          qnode.Z = 2;
          break;
      case Qt::Key_D:
          qnode.Z = -2;
          break;
      }
      // 이벤트 처리 후 메시지를 발행하거나 다른 작업을 수행할 수 있습니다.
  }

}  // namespace s

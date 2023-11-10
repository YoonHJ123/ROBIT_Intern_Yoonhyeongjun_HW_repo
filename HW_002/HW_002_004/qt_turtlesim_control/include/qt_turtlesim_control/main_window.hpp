/**
 * @file /include/qt_turtlesim_control/main_window.hpp
 *
 * @brief Qt based gui for %(package)s.
 *
 * @date November 2010
 **/
#ifndef qt_turtlesim_control_MAIN_WINDOW_H
#define qt_turtlesim_control_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qt_turtlesim_control
{
  /*****************************************************************************
  ** Interface [MainWindow]
  *****************************************************************************/
  /**
   * @brief Qt central, all operations relating to the view part here.
   */
  class MainWindow : public QMainWindow
  {
    Q_OBJECT

  public:
    MainWindow(int argc, char** argv, QWidget* parent = 0);
    ~MainWindow();

  public Q_SLOTS:
    void pushButton_1();
    void pushButton_2();
    void pushButton_3();
    void pushButton_4();
    void pushButton_5();
    void keyPressEvent(QKeyEvent *event);

  private:
    Ui::MainWindowDesign ui;
    QNode qnode;
  };

}  // namespace s

#endif  // qt_turtlesim_control_MAIN_WINDOW_H

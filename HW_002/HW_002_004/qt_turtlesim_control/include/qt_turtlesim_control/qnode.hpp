/**
 * @file /include/qt_turtlesim_control/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef qt_turtlesim_control_QNODE_HPP_
#define qt_turtlesim_control_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <QKeyEvent>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace qt_turtlesim_control
{
  /*****************************************************************************
  ** Class
  *****************************************************************************/

  class QNode : public QThread
  {
    Q_OBJECT
  public:
    QNode(int argc, char** argv);
    virtual ~QNode();
    bool init();
    void run();
    int X, Z;

  Q_SIGNALS:
    void rosShutdown();

  private:
    int init_argc;
    char** init_argv;
  };

}  // namespace s

#endif /* qt_turtlesim_control_QNODE_HPP_ */

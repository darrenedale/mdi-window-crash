#include "subwindow.h"
#include "ui_subwindow.h"


SubWindow::SubWindow(QWidget * parent)
: QMainWindow(parent),
  m_ui(new Ui::SubWindow) {
	m_ui->setupUi(this);
}


SubWindow::~SubWindow(void) = default;

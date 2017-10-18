#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMdiSubWindow>

#include "subwindow.h"


MainWindow::MainWindow(QWidget * parent)
: QMainWindow(parent),
  m_ui(new Ui::MainWindow) {
	m_ui->setupUi(this);

	connect(m_ui->actionAddMdiWindow, &QAction::triggered, [this]() {
		QMdiSubWindow * subWindow = m_ui->workspace->addSubWindow(new SubWindow);
		subWindow->show();
		m_ui->workspace->setActiveSubWindow(subWindow);
	});
}


MainWindow::~MainWindow(void) = default;

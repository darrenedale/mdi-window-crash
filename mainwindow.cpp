#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

#include <QMdiSubWindow>

#include "subwindow.h"


MainWindow::MainWindow(QWidget * parent)
: QMainWindow(parent), m_ui(new Ui::MainWindow) {
	m_ui->setupUi(this);

	connect(m_ui->actionAddMdiWindow, &QAction::triggered, [this]() {
		std::cout << "adding sub window" << std::endl;
		QMdiSubWindow * subWindow = m_ui->workspace->addSubWindow(new SubWindow);
		subWindow->show();
		subWindow->activateWindow();
	});
}


MainWindow::~MainWindow() = default;

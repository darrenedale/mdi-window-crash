#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <memory>

#include <QMainWindow>

namespace Ui {
	class SubWindow;
}

class SubWindow
: public QMainWindow {
	Q_OBJECT

public:
	explicit SubWindow(QWidget * parent = nullptr);
	~SubWindow(void);

private:
	std::unique_ptr<Ui::SubWindow> m_ui;
};

#endif  // SUBWINDOW_H

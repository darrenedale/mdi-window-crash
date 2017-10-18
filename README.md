# mdi-window-crash
A sample program that triggers a crash in Qt5.9.1 installed from the Kubuntu Artful repositories.

In the default install of Qt5.9.1 from the Kubuntu-Artful repositories, adding a designer-based
(i.e. a .ui file) QMainWindow subclass as a sub-window of a QMdiArea causes a segfault in
QWindow::winId() when the subwindow is shown. This behaviour is not exhibited on the same system
when the QMainWindow subclass that is added to the MDI area is hand-coded (i.e. does not use a
designer-based .ui file) or when using Qt5.9.2 installed using the Qt installation tool.

The simple example program in this repository triggers this crash.

To reproduce the problem:

1. Make sure you are using Qt development tools from Qt 5.9.1 in Kubuntu
2. clone this repository and cd into the directory where you cloned it
3. mkdir build && cd build
4. qmake ../QMdiMainWindowCrash.pro
5. make
6. You should have built an executable QMdiMainWindowCrash. Run it.
7. Click the toolbar button to add a QMainWindow sub-window to the MDI area.
8. Observe the segfault.

Unless this program is doing something wrong, I think a bug report needs to be filed but I'm unclear
if that bug report needs to go to Qt or to the Kubuntu Qt5 package maintainers. Advice appreciated.

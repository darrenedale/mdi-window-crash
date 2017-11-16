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
2. make sure that you are using KDE Plasma desktop
3. make sure you have the **Global Menu** widget visible somewhere
3. make sure that you have **System Settings > Widget Style > Fine Tuning > Menubar style** set to
   **Application Menu widget**
2. clone this repository and `cd` into the directory where you cloned it
3. `mkdir build && cd build`
4. `qmake ../QMdiMainWindowCrash.pro`
   or
   `cmake ../`
5. `make`
6. You should have built an executable **QMdiMainWindowCrash**. Run it.
7. Click the toolbar button to add a QMainWindow sub-window to the MDI area.
8. Observe the segfault.

I think the issue is in KDEPlasmaPlatformTheme.so when Plasma desktop is configured to use the global
menu widget. Adding the MDI sub-window, which has a menu bar, makes some calls into
KDEPlasmaPlatformTheme.so via QMenu. My guess is that the presence of both an application menu and a
MDI sub-window menu is causing some kind of clash that the Global Menu widget can't resolve. That's
just a guess, though.

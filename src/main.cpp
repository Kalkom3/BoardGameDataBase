#include <QApplication>

#include <mainwindow.h>

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);
	MainWindow* window = new MainWindow();
    window->setWindowState(Qt::WindowMaximized);
	window->show();

	return app.exec();
}

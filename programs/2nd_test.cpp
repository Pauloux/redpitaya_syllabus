// http://doc.qt.io/qt-4.8/gettingstartedqt.html

#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>

int main(int argv, char **args)
{
 QApplication app(argv, args);

 QTextEdit *textEdit = new QTextEdit;
 textEdit->setText("Hello, world!");
 textEdit->append("Appending some text...");

 QPushButton *quitButton = new QPushButton("&Quit");
 QObject::connect(quitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

 QVBoxLayout *layout = new QVBoxLayout;
 layout->addWidget(textEdit);
 layout->addWidget(quitButton);
 
 QWidget window;
 window.setLayout(layout);
 window.show();

 return app.exec();
}

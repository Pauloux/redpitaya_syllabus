// https://wiki.qt.io/How_to_Use_QTextEdit

#include <QApplication>
#include <QTextEdit>

int main(int argc, char **argv)
{
 QApplication app(argc, argv);

QTextEdit *txt = new QTextEdit();
 txt->setText("Hello, world!");
 txt->append("Appending some text...");

txt->show();
 return app.exec();
}

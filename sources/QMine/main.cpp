#include <iostream>

#include <QGuiApplication>

#include "MathUtils/Matrix/Matrix2d.h"


int main(int argc, char* argv[])
{
  std::cout << "Hello world" << std::endl;

  MathUtils::Matrix2d<double> mat(4, 4);

  QGuiApplication app(argc, argv);

  return app.exec();
}

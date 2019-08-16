#pragma once

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class HomePage : public APage
  {
  public:
    HomePage();

    void load(QQmlContext * qmlContext) override;
    void unload() override;
  };
}

#pragma once

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class HomePage : public APage
  {
  public:
    HomePage();

    void Load(QQmlContext * qmlContext) override;
    void Unload() override;
  };
}

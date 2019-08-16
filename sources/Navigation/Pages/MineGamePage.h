#pragma once

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class MineGamePage : public APage
  {
  public:
    MineGamePage();

    void load(QQmlContext * qmlContext) override;
    void unload() override;
  };
}

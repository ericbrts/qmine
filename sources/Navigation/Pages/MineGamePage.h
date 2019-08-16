#pragma once

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class MineGamePage : public APage
  {
  public:
    MineGamePage();

    void Load(QQmlContext * qmlContext) override;
    void Unload() override;
  };
}

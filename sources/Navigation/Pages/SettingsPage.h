#pragma once

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class SettingsPage : public APage
  {
  public:
    SettingsPage();

    void Load(QQmlContext * qmlContext) override;
    void Unload() override;
  };
}

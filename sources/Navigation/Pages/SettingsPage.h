#pragma once

#include "Navigation/Pages/APage.h"


namespace Navigation
{
  class SettingsPage : public APage
  {
  public:
    SettingsPage();

    void load(QQmlContext * qmlContext) override;
    void unload() override;
  };
}

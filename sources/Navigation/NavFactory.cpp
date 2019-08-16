#include "Navigation/NavFactory.h"

#include "Navigation/Pages/HomePage.h"
#include "Navigation/Pages/MineGamePage.h"
#include "Navigation/Pages/SettingsPage.h"


namespace Navigation
{
  namespace NavFactory
  {
    void BuildPages(NavPresenter & navPresenter)
    {
      navPresenter.AddPage("home", std::make_unique<HomePage>());
      navPresenter.AddPage("mineGame", std::make_unique<MineGamePage>());
      navPresenter.AddPage("settings", std::make_unique<SettingsPage>());
    }
  }
}

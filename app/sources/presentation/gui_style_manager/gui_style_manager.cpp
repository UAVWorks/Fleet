#include "gui_style_manager.h"

// Qt
#include <QQmlContext>
#include <QVariant>

// Internal
//#include "settings_provider.h"

#include "sizings.h"
#include "day_palette_factory.h"
#include "night_palette_factory.h"

using namespace presentation;

GuiStyleManager::GuiStyleManager(QQmlContext* context, QObject* parent):
    QObject(parent),
    m_context(context)
{}

void GuiStyleManager::setPaletteStyle(PaletteStyle paletteStyle)
{
    QScopedPointer<AbstractPaletteFactory> factory;

    switch (paletteStyle) {
    case Day:
        factory.reset(new DayPaletteFactory());
        break;
    case Night:
        factory.reset(new NightPaletteFactory());
        break;
    default:
        break;
    }

    if (factory) m_context->setContextProperty("customPalette", QVariant::fromValue(factory->create()));
}

void GuiStyleManager::loadSettingsPalette()
{
//    this->setPaletteStyle(PaletteStyle(settings::Provider::value(settings::gui::paletteStyle).toInt()));
}

void GuiStyleManager::setSizings(const Sizings& sizings)
{
    m_context->setContextProperty("sizings", QVariant::fromValue(sizings));
}

void GuiStyleManager::setSizings(int controlBaseSize)
{
    Sizings sizings;

    sizings.setControlBaseSize(controlBaseSize);
    sizings.setInputControlHeight(controlBaseSize * 1.25);
    sizings.setFontSize(controlBaseSize / 2);
    sizings.setSecondaryFontSize(sizings.fontSize() * 0.75);
    sizings.setSpacing(controlBaseSize / 4);
    sizings.setMargins(controlBaseSize / 4);
    sizings.setPadding(controlBaseSize / 6);
    sizings.setShadowSize(3);

    this->setSizings(sizings);
}

void GuiStyleManager::loadSettingsSizings()
{
//    this->setSizings(settings::Provider::value(settings::gui::uiSize).toInt());
}

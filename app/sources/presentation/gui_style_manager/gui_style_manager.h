#ifndef GUI_STYLE_MANAGER_H
#define GUI_STYLE_MANAGER_H

// Qt
#include <QObject>

class QQmlContext;

namespace presentation
{
    class Sizings;

    class GuiStyleManager: public QObject // TODO: rename
    {
        Q_OBJECT

    public:
        enum PaletteStyle
        {
            Night,
            Day
        };

        explicit GuiStyleManager(QQmlContext* context, QObject* parent = nullptr);

    public slots:
        void setPaletteStyle(PaletteStyle paletteStyle);
        void loadSettingsPalette();

        void setSizings(const Sizings& sizings);
        void setSizings(int controlBaseSize);
        void loadSettingsSizings();

    private:
        QQmlContext* const m_context;

        Q_ENUM(PaletteStyle)
    };
}

#endif // GUI_STYLE_MANAGER_H

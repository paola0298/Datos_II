#include "Gui.cpp"
#include <gtkmm-3.0/gtkmm/application.h>

int main (int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    GUI gui;
    gui.set_default_size(600, 400);
    gui.set_position(Gtk::WIN_POS_CENTER_ALWAYS);
    //Shows the window and returns when it is closed.
    return app->run(gui);
}
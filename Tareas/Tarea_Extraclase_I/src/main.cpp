//#include <gtkmm.h>
//
//int main(int argc, char *argv[])
//{
//    auto app =
//            Gtk::Application::create(argc, argv,
//                                     "org.gtkmm.examples.base");
//
//    Gtk::Window window;
//    window.set_default_size(600, 500);
//
//    return app->run(window);
//}

#include "GUI.cpp"
#include <gtkmm-3.0/gtkmm/application.h>

int main (int argc, char *argv[])
{
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.example");

    GUI gui;
    gui.set_default_size(300, 180);

    //Shows the window and returns when it is closed.
    return app->run(gui);
}
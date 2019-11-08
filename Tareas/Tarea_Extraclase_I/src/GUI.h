//
// Created by paola on 31/7/19.
//

#ifndef TAREA_GUI_H
#define TAREA_GUI_H

#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/label.h>
#include <gtkmm-3.0/gtkmm/entry.h>

class GUI : public Gtk::Window {
public:
    GUI();
    virtual ~GUI();

protected:

    // Signal handlers:
    // Our new improved on_button_clicked(). (see below)
    void on_button_clicked(Glib::ustring data);

    // Child widgets:
    Gtk::Box m_box1;
    Gtk::Button sendMessage;
    Gtk::Label labelWelcome;
    Gtk::Label labelMessage;
    Gtk::Entry inputFromUser;

};

#endif //TAREA_GUI_H

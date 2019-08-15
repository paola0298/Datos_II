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
#include <gtkmm.h>

class GUI : public Gtk::Window {
public:
    GUI();
    virtual ~GUI();

protected:

    // Signal handlers:
    void onListSelected();
    void onTreeSelected();

    // Child widgets:
    Gtk::Box vContainer;
    Gtk::Label labelWelcome;
    Gtk::Label labelStructure;
    Gtk::RadioButton linkedListButton, binaryTreeButton;
    Gtk::Separator separator;
    Gtk::Label labelOption;

    Gtk::Box listContainer;
    Gtk::Box buttonsListContainer;
    Gtk::Button addStart;
    Gtk::Button removeStart;
    Gtk::Button modifyByPos;
    Gtk::Button getByPos;
    Gtk::Label elementsOfList; //etiqueta mostrara los elementos de la listas

    Gtk::Box treeContainer;
    Gtk::Box buttonsTreeContainer;
    Gtk::Button addB;
    Gtk::Button remove;
    Gtk::Label elementsOfTree; //etiqueta mostrara los elementos del arbol
};

#endif //TAREA_GUI_H

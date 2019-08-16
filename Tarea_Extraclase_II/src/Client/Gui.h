#ifndef TAREA_GUI_H
#define TAREA_GUI_H

#include <gtkmm-3.0/gtkmm/box.h>
#include <gtkmm-3.0/gtkmm/button.h>
#include <gtkmm-3.0/gtkmm/window.h>
#include <gtkmm-3.0/gtkmm/label.h>
#include <gtkmm-3.0/gtkmm/entry.h>
#include <gtkmm-3.0/gtkmm/adjustment.h>
#include <gtkmm.h>
#include <string>

class GUI : public Gtk::Window {
public:
    GUI();
    virtual ~GUI();

protected:

    // Signal handlers:
    void onListSelected();
    void onTreeSelected();
    void addToList();
    void removeFromList();
    void modifyListEle();
    void getListEle();
    
    void addToTree();
    void removeFromTree();

    void doActionOf();

    std::string action;



    // Child widgets:
    Gtk::Box vContainer;
    Gtk::Label labelWelcome;
    Gtk::Label labelStructure;
    Gtk::Box radioButContainer;
    Gtk::RadioButton linkedListButton, binaryTreeButton;
    Gtk::Separator separator;
    Gtk::Label labelOption;


    //Contenedor de las opciones para la lista enlazada
    Gtk::Box listContainer;
    Gtk::Box buttonsListContainer;
    Gtk::Button addStart;
    Gtk::Button removeStart;
    Gtk::Button modifyByPos;
    Gtk::Button getByPos;
    Gtk::Label elementsOfList; //etiqueta mostrara los elementos de la listas


    //Contenedor de las opciones del arbol de busqueda binaria
    Gtk::Box treeContainer;
    Gtk::Box buttonsTreeContainer;
    Gtk::Button addB;
    Gtk::Button remove;
    Gtk::Label elementsOfTree; //etiqueta mostrara los elementos del arbol
    //Widgets especificos para cada accion

    //Widgets especificos para cada accion LinkedList y Binary Tree
    Gtk::Box entryContainer;
    Gtk::Label lblOption;
    Gtk::Entry entryOption;
    Gtk::Entry entryIndex;

    Gtk::Button doAction;

};


#endif //TAREA_GUI_H

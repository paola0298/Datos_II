//
// Created by paola on 31/7/19.
//

#include "Gui.h"
#include "client.cpp"
#include <iostream>

GUI::GUI() : 
    vContainer(Gtk::ORIENTATION_VERTICAL, 0),
    labelWelcome("¡Bienvenido!"),
    labelStructure("Seleccione la estructura que desea utilizar"),
    radioButContainer(Gtk::ORIENTATION_HORIZONTAL, 0),
    linkedListButton("Lista enlazada simple"),
    binaryTreeButton("Arbol Binario de Busqueda"),
    labelOption("Seleccione la accion a realizar"),
    listContainer(Gtk::ORIENTATION_VERTICAL, 0),
    buttonsListContainer(Gtk::ORIENTATION_HORIZONTAL),
    addStart("Agregar"),
    removeStart("Eliminar"),
    modifyByPos("Modificar"),
    getByPos("Buscar por posicion"),
    treeContainer(Gtk::ORIENTATION_VERTICAL, 0),
    buttonsTreeContainer(Gtk::ORIENTATION_HORIZONTAL, 0),
    addB("Agregar"),
    remove("Eiminar"),
    entryContainer(Gtk::ORIENTATION_HORIZONTAL, 0) {
    // This just sets the title of our new window.
    set_title("Estructuras de Datos!");

    // sets the border width of the window.
    set_border_width(10);

    // put the box into the main window.
    add(vContainer);
    vContainer.set_halign(Gtk::ALIGN_CENTER);
    radioButContainer.set_halign(Gtk::ALIGN_CENTER);
    binaryTreeButton.join_group(linkedListButton);

    //Connect Radio Button
    linkedListButton.signal_clicked().connect(sigc::mem_fun(*this,
              &GUI::onListSelected));

    binaryTreeButton.signal_clicked().connect(sigc::mem_fun(*this,
              &GUI::onTreeSelected));


    vContainer.pack_start(labelWelcome, false, false, 10);
    vContainer.pack_start(labelStructure, false, false, 10);
    vContainer.pack_start(radioButContainer, false, false, 10);
    vContainer.pack_start(separator,false, false, 0);
    vContainer.pack_start(labelOption, false, false, 10);

    radioButContainer.pack_start(linkedListButton, false, false, 10);
    radioButContainer.pack_start(binaryTreeButton, false, false, 10);

    // Show the widgets.
    // They will not really be shown until this Window is shown.
    vContainer.show();
    radioButContainer.show();
    labelWelcome.show();
    labelStructure.show();
    linkedListButton.show();
    binaryTreeButton.show();
    separator.show();

    //Container when linkedlist option is clicked
    listContainer.set_halign(Gtk::ALIGN_CENTER);
    vContainer.pack_start(listContainer, false, false, 0);
    listContainer.pack_start(buttonsListContainer);
    buttonsListContainer.pack_start(addStart, false, false, 10);
    buttonsListContainer.pack_start(removeStart, false, false, 10);
    buttonsListContainer.pack_start(modifyByPos, false, false, 10);
    buttonsListContainer.pack_start(getByPos, false, false, 10);

    //Connect buttons to function 
    addStart.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &GUI::addToList), "Agregar a Lista"));
    removeStart.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &GUI::removeFromList), "Eliminar de la lista"));
    modifyByPos.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &GUI::modifyListEle), "Modificar elemento por posicion"));
    getByPos.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &GUI::getListEle), "Obtener elemento por posicion"));
    
    addB.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &GUI::addToTree), "Agregar al Arbol"));
    remove.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &GUI::removeFromTree), "Eliminar del arbol"));

    //Show widgets
    addStart.show();
    removeStart.show();
    modifyByPos.show();
    getByPos.show();
    buttonsListContainer.show();


    //Container when binary tree option is clicked
    treeContainer.set_halign(Gtk::ALIGN_CENTER);
    vContainer.pack_start(treeContainer, false, false, 0);
    treeContainer.pack_start(buttonsTreeContainer, false, false, 10);
    buttonsTreeContainer.pack_start(addB, false, false, 10);
    buttonsTreeContainer.pack_start(remove, false, false, 10);

    addB.show();
    remove.show();
    buttonsTreeContainer.show();

    //Container of specific option
    vContainer.pack_start(entryContainer, false, false, 0);
    entryContainer.pack_start(lblOption, false, false, 10);
    entryContainer.pack_start(entryOption, false, false, 10);
    
    lblOption.show();
    entryOption.show();
}

GUI::~GUI() { }

void GUI::onListSelected() {
    labelOption.show();
    treeContainer.hide();
    listContainer.show();
}

void GUI::onTreeSelected(){
    labelOption.show();
    listContainer.hide();
    treeContainer.show();
}

void addToList(Glib::ustring data) { 

}
    
void removeFromList(Glib::ustring data) {

}
    
void modifyListEle(Glib::ustring data) {

}

void getListEle(Glib::ustring data) {

}
    
void addToTree(Glib::ustring data) {

}

void removeFromTree(Glib::ustring data) {
    
}

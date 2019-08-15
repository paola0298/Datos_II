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
    remove("Eiminar") {
    // This just sets the title of our new window.
    set_title("Estructuras de Datos!");

    // sets the border width of the window.
    set_border_width(10);

    // put the box into the main window.
    add(vContainer);
    binaryTreeButton.join_group(linkedListButton);

    //Connect Radio Button
    linkedListButton.signal_clicked().connect(sigc::mem_fun(*this,
              &GUI::onListSelected));

    binaryTreeButton.signal_clicked().connect(sigc::mem_fun(*this,
              &GUI::onTreeSelected));


    vContainer.pack_start(labelWelcome, false, false, 10);
    vContainer.pack_start(labelStructure, false, false, 10);
    vContainer.pack_start(linkedListButton, false, false, 10);
    vContainer.pack_start(binaryTreeButton, false, false, 10);
    vContainer.pack_start(separator,false, false, 0);
    vContainer.pack_start(labelOption, false, false, 10);

    // Show the widgets.
    // They will not really be shown until this Window is shown.
    vContainer.show();
    labelWelcome.show();
    labelStructure.show();
    linkedListButton.show();
    binaryTreeButton.show();
    separator.show();
    
}

GUI::~GUI() { }

void GUI::onListSelected() {
    std::cout << "LinkedList Selected \n";
    labelOption.show();
}

void GUI::onTreeSelected(){
    std::cout << "Binary Tree Selected \n";
    labelOption.show();
}

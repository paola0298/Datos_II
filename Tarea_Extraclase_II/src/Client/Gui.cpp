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
    entryContainer(Gtk::ORIENTATION_HORIZONTAL, 0),
    doAction("Do it!") {
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
    addStart.signal_clicked().connect(sigc::mem_fun(*this, &GUI::addToList));
    removeStart.signal_clicked().connect(sigc::mem_fun(*this, &GUI::removeFromList));
    modifyByPos.signal_clicked().connect(sigc::mem_fun(*this, &GUI::modifyListEle));
    getByPos.signal_clicked().connect(sigc::mem_fun(*this, &GUI::getListEle));
    
    addB.signal_clicked().connect(sigc::mem_fun(*this, &GUI::addToTree));
    remove.signal_clicked().connect(sigc::mem_fun(*this, &GUI::removeFromTree));

    doAction.signal_clicked().connect(sigc::mem_fun(*this, &GUI::doActionOf));

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
    vContainer.pack_start(entryContainer, false, false, 10);
    entryContainer.pack_start(lblOption, false, false, 10);
    entryContainer.pack_start(entryOption, false, false, 10);
    entryContainer.pack_start(entryIndex, false, false, 10);
    
    lblOption.show();
    entryOption.show();

    //Initial
    labelOption.show();
    treeContainer.hide();
    entryContainer.hide();
    listContainer.show();
    vContainer.pack_start(doAction, false, false, 10);


}

GUI::~GUI() { }

void GUI::onListSelected() {
    labelOption.show();
    treeContainer.hide();
    entryContainer.hide();
    listContainer.show();
    doAction.hide();
}

void GUI::onTreeSelected(){
    labelOption.show();
    listContainer.hide();
    entryContainer.hide();
    treeContainer.show();
    doAction.hide();
}

void GUI::addToList() { 
    entryContainer.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    lblOption.set_text("Ingrese el número que desea agregar");
    entryIndex.hide();
    doAction.show();
    GUI::action = "agregarL";
}
    
void GUI::removeFromList() {
    entryContainer.show();
    lblOption.set_text("Se ha eliminado el numero ");
    entryOption.set_text("#");
    entryOption.set_editable(false);
    entryIndex.hide();
    doAction.hide();
    GUI::action = "eliminarL";

}
    
void GUI::modifyListEle() {
    entryContainer.show();
    lblOption.set_text("Indique el nuevo numero y la\nposicion a modificar");
    entryOption.set_text("");
    entryOption.set_editable(true);
    entryIndex.show();
    doAction.show();
    GUI::action = "modificar";

}

void GUI::getListEle() {
    entryContainer.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    lblOption.set_text("Ingrese el indice del numero a buscar");
    entryIndex.hide();
    doAction.show();
    GUI::action = "obtener";

}
    
void GUI::addToTree() {
    entryContainer.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    lblOption.set_text("Ingrese el número que desea agregar");
    entryIndex.hide();
    doAction.show();
    GUI::action = "agregarT";
}

void GUI::removeFromTree() {
    entryContainer.show();
    lblOption.set_text("Ingrese el numero a eliminar ");
    entryOption.set_text("");
    entryOption.set_editable(false);
    entryIndex.hide();
    doAction.show();
    GUI::action = "eliminarT";
}


void GUI::doActionOf(){
    if (GUI::action == "agregarL"){
        std::cout << "Agregando en lista\n";
    } else if (GUI::action == "eliminarL"){
        std::cout << "Eliminando en lista\n";
    } else if (GUI::action == "modificar"){
        std::cout << "Modificando en lista\n";
    } else if (GUI::action == "obtener"){
        std::cout << "Recuperando elemento en lista\n";
    } else if (GUI::action == "agregarT"){
        std::cout << "Agregando en arbol\n";
    } else {
        std::cout << "Eliminando en arbol\n";
    } 

}


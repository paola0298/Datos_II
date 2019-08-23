//
// Created by paola on 31/7/19.
//

#include "Gui.h"
#include "controller.cpp"
#include <iostream>

Controller *controller = new Controller();

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
    listContainer.pack_start(labelElements);
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
    labelElements.show();

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
    entryOption.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    lblOption.set_text("Ingrese el número que desea agregar");
    entryIndex.hide();
    doAction.show();
    GUI::action = "agregarL";
}
    
void GUI::removeFromList() {
    entryContainer.show();
    lblOption.set_text("Eliminar el primer numero de la lista");
    // entryOption.set_text("#");
    entryOption.set_editable(false);
    entryIndex.hide();
    doAction.show();
    GUI::action = "eliminarL";

}
    
void GUI::modifyListEle() {
    entryContainer.show();
    lblOption.set_text("Indique el nuevo numero y la\nposicion a modificar");
    entryOption.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    entryIndex.show();
    doAction.show();
    GUI::action = "modificar";

}

void GUI::getListEle() {
    entryContainer.show();
    entryOption.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    lblOption.set_text("Ingrese el indice del numero a buscar");
    entryIndex.hide();
    doAction.show();
    GUI::action = "obtenerL";

}
    
void GUI::addToTree() {
    entryContainer.show();
    entryOption.show();
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
    entryOption.show();
    entryOption.set_text("");
    entryOption.set_editable(true);
    entryIndex.hide();
    doAction.show();
    GUI::action = "eliminarT";
}


void GUI::doActionOf(){
    std::string entry = entryOption.get_text();
    char *entryChar = &entry[0];
    int response;
    if (GUI::action == "agregarL"){
        std::cout << "Agregando en lista: " << entry << "\n";
        int value = std::stol(entry);
    
        response = controller->addToList(value);

        // std::cout << response << "\n";
        if (response == 1) {
            lblOption.set_text("Valor agregado correctamente");
        } else {
            lblOption.set_text("Valor no agregado");
        }

        labelElements.set_text(controller->listofElements);
        
    } else if (GUI::action == "eliminarL"){
        std::cout << "Eliminando en lista> \n";
        int valueDe = controller->removeFromList();

        if (valueDe != -1) {
            lblOption.set_text("Valor " + std::to_string(valueDe) + " eliminado correctamente");
        } else {
            lblOption.set_text("Valor no eliminado");
        }
        labelElements.set_text(controller->listofElements);


    } else if (GUI::action == "modificar"){
        std::string entryI = entryIndex.get_text();
        char *entryCharI = &entryI[0];
        std::cout << "Modificando en lista" << entryI << ", nuevo valor:  \n" << entry << "\n";
        
        int value = std::stol(entry);
        int index = std::stol(entryI);
    
        response = controller->modifyList(value, index);

        std::cout << response << "\n";
        if (response == 1) {
            lblOption.set_text("Valor modificado correctamente");
        } else {
            lblOption.set_text("Valor no modificado");
        }

        labelElements.set_text(controller->listofElements);

    } else if (GUI::action == "obtenerL"){
        std::cout << "Recuperando elemento en lista (indice) "  << entry << "\n";
        int value = std::stol(entry);
        response = controller->get(value);
        std::cout << response << "\n";
        if (response != -1) {
        lblOption.set_text("El valor es " + std::to_string(response));
        } else {
            lblOption.set_text("Valor no obtenido");
        }

        labelElements.set_text(controller->listofElements);

    } else if (GUI::action == "agregarT"){
        std::cout << "Agregando en arbol: "  << entry << "\n";

        int value = std::stol(entry);
    
        response = controller->addToTree(value);

        std::cout << response << "\n";
        if (response == 1) {
            lblOption.set_text("Valor agregado correctamente");
        } else {
            lblOption.set_text("Valor no agregado");
        }
    } else {
        std::cout << "Eliminando en arbol: "  << entry << "\n";
        int value = std::stol(entry);
    
        response = controller->removeFromTree(value);

        std::cout << response << "\n";
        if (response == 1) {
            lblOption.set_text("Valor eliminado correctamente");
        } else {
            lblOption.set_text("Valor no eliminado");
        }
    } 

    
    doAction.hide();
    entryOption.hide();
    entryIndex.hide();


}


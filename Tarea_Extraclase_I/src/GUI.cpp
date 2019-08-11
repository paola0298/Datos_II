//
// Created by paola on 31/7/19.
//

#include "GUI.h"
#include "client.cpp"
#include <iostream>

GUI::GUI() :sendMessage("Enviar mensaje"), labelWelcome("¡Bienvenido!"),
labelMessage("Escribe un mensaje"), m_box1(Gtk::ORIENTATION_VERTICAL, 0) {
    // This just sets the title of our new window.
    set_title("Chat bot!");

    // sets the border width of the window.
    set_border_width(10);

    // put the box into the main window.
    add(m_box1);



    m_box1.pack_start(labelWelcome, false, false, 10);
    m_box1.pack_start(labelMessage, false, false, 10);
    m_box1.pack_start(inputFromUser, false, false, 10);
    // Now when the button is clicked, we call the "on_button_clicked" function
    // with a pointer to "button 1" as it's argument
    sendMessage.signal_clicked().connect(sigc::bind<Glib::ustring>(
            sigc::mem_fun(*this, &GUI::on_button_clicked), "button 1"));

    // instead of gtk_container_add, we pack this button into the invisible
    // box, which has been packed into the window.
    // note that the pack_start default arguments are Gtk::EXPAND | Gtk::FILL, 0
    m_box1.pack_start(sendMessage, false, false, 10);


    // always remember this step, this tells GTK that our preparation
    // for this button is complete, and it can be displayed now.
    sendMessage.show();



    // Show the widgets.
    // They will not really be shown until this Window is shown.
    inputFromUser.show();
    labelWelcome.show();
    labelMessage.show();
    m_box1.show();
}

GUI::~GUI() { }

// Our new improved signal handler.  The data passed to this method is
// printed to stdout.
void GUI::on_button_clicked(Glib::ustring data) {
    std::cout << "User input " << inputFromUser.get_text() << std::endl;
    std::cout << "Hello World - " << data << " was pressed" << std::endl;
    if (connect()) {

        std::string s = inputFromUser.get_text();
        char *message[s.size() + 1];
        strcpy(reinterpret_cast<char *>(message), s.c_str());

        sendMessageToServer(reinterpret_cast<char *>(message));
        labelMessage.set_text(receiveMessageFromServer());
    } else {
        labelMessage.set_text("Error al conectar con el servidor, intente de nuevo");
    }
}

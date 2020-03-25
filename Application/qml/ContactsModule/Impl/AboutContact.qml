import QtQuick 2.0
import ContactsModule.Base 1.0
import Style 1.0

ContactInfo {
    id: root
    title: "About Contact"

    nameInput.text: name
    surnameInput.text: surname
    phoneNumberInput.text: phoneNumber
    homePhoneNumberInput.text: ""

    acceptButton.onClicked: {
        name = nameInput.text;
        surname = surnameInput.text;
        phoneNumber = phoneNumberInput.text;
        saveChanges();
        root.close();
    }
}

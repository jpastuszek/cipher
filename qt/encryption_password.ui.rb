=begin
** Form generated from reading ui file 'encryption_password.ui'
**
** Created: sob. sty 5 02:47:39 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
=end

require 'Qt4'

class Ui_EncryptionPassword
    attr_reader :verticalLayout
    attr_reader :gridLayout
    attr_reader :label_2
    attr_reader :label
    attr_reader :password_retype
    attr_reader :password
    attr_reader :horizontalLayout_2
    attr_reader :show_password_checkbox
    attr_reader :generate_password_button
    attr_reader :verticalSpacer
    attr_reader :buttonBox

    def setupUi(encryptionPassword)
    if encryptionPassword.objectName.nil?
        encryptionPassword.objectName = "encryptionPassword"
    end
    encryptionPassword.windowModality = Qt::ApplicationModal
    encryptionPassword.resize(349, 172)
    @verticalLayout = Qt::VBoxLayout.new(encryptionPassword)
    @verticalLayout.objectName = "verticalLayout"
    @gridLayout = Qt::GridLayout.new()
    @gridLayout.objectName = "gridLayout"
    @label_2 = Qt::Label.new(encryptionPassword)
    @label_2.objectName = "label_2"

    @gridLayout.addWidget(@label_2, 1, 0, 1, 1)

    @label = Qt::Label.new(encryptionPassword)
    @label.objectName = "label"

    @gridLayout.addWidget(@label, 0, 0, 1, 1)

    @password_retype = Qt::LineEdit.new(encryptionPassword)
    @password_retype.objectName = "password_retype"
    @password_retype.echoMode = Qt::LineEdit::Password

    @gridLayout.addWidget(@password_retype, 1, 1, 1, 1)

    @password = Qt::LineEdit.new(encryptionPassword)
    @password.objectName = "password"
    @password.echoMode = Qt::LineEdit::Password

    @gridLayout.addWidget(@password, 0, 1, 1, 1)


    @verticalLayout.addLayout(@gridLayout)

    @horizontalLayout_2 = Qt::HBoxLayout.new()
    @horizontalLayout_2.objectName = "horizontalLayout_2"
    @show_password_checkbox = Qt::CheckBox.new(encryptionPassword)
    @show_password_checkbox.objectName = "show_password_checkbox"

    @horizontalLayout_2.addWidget(@show_password_checkbox)

    @generate_password_button = Qt::PushButton.new(encryptionPassword)
    @generate_password_button.objectName = "generate_password_button"

    @horizontalLayout_2.addWidget(@generate_password_button)


    @verticalLayout.addLayout(@horizontalLayout_2)

    @verticalSpacer = Qt::SpacerItem.new(20, 40, Qt::SizePolicy::Minimum, Qt::SizePolicy::Expanding)

    @verticalLayout.addItem(@verticalSpacer)

    @buttonBox = Qt::DialogButtonBox.new(encryptionPassword)
    @buttonBox.objectName = "buttonBox"
    @buttonBox.orientation = Qt::Horizontal
    @buttonBox.standardButtons = Qt::DialogButtonBox::Cancel|Qt::DialogButtonBox::Ok

    @verticalLayout.addWidget(@buttonBox)

    Qt::Widget.setTabOrder(@password, @password_retype)
    Qt::Widget.setTabOrder(@password_retype, @buttonBox)
    Qt::Widget.setTabOrder(@buttonBox, @show_password_checkbox)
    Qt::Widget.setTabOrder(@show_password_checkbox, @generate_password_button)

    retranslateUi(encryptionPassword)
    Qt::Object.connect(@buttonBox, SIGNAL('accepted()'), encryptionPassword, SLOT('accept()'))
    Qt::Object.connect(@buttonBox, SIGNAL('rejected()'), encryptionPassword, SLOT('reject()'))
    Qt::Object.connect(@generate_password_button, SIGNAL('clicked()'), encryptionPassword, SLOT('generate_password()'))
    Qt::Object.connect(@show_password_checkbox, SIGNAL('stateChanged(int)'), encryptionPassword, SLOT('show_password(int)'))

    Qt::MetaObject.connectSlotsByName(encryptionPassword)
    end # setupUi

    def setup_ui(encryptionPassword)
        setupUi(encryptionPassword)
    end

    def retranslateUi(encryptionPassword)
    encryptionPassword.windowTitle = Qt::Application.translate("EncryptionPassword", "Encryption password", nil, Qt::Application::UnicodeUTF8)
    @label_2.text = Qt::Application.translate("EncryptionPassword", "Password retype", nil, Qt::Application::UnicodeUTF8)
    @label.text = Qt::Application.translate("EncryptionPassword", "Password", nil, Qt::Application::UnicodeUTF8)
    @show_password_checkbox.text = Qt::Application.translate("EncryptionPassword", "Show password", nil, Qt::Application::UnicodeUTF8)
    @generate_password_button.text = Qt::Application.translate("EncryptionPassword", "Generate password", nil, Qt::Application::UnicodeUTF8)
    end # retranslateUi

    def retranslate_ui(encryptionPassword)
        retranslateUi(encryptionPassword)
    end

end

module Ui
    class EncryptionPassword < Ui_EncryptionPassword
    end
end  # module Ui

if $0 == __FILE__
    a = Qt::Application.new(ARGV)
    u = Ui_EncryptionPassword.new
    w = Qt::Dialog.new
    u.setupUi(w)
    w.show
    a.exec
end

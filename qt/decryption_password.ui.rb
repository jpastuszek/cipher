=begin
** Form generated from reading ui file 'decryption_password.ui'
**
** Created: sob. sty 5 02:47:34 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
=end

require 'Qt4'

class Ui_DecryptionPassword
    attr_reader :verticalLayout
    attr_reader :horizontalLayout
    attr_reader :label
    attr_reader :password
    attr_reader :verticalSpacer
    attr_reader :buttonBox

    def setupUi(decryptionPassword)
    if decryptionPassword.objectName.nil?
        decryptionPassword.objectName = "decryptionPassword"
    end
    decryptionPassword.resize(306, 98)
    @verticalLayout = Qt::VBoxLayout.new(decryptionPassword)
    @verticalLayout.objectName = "verticalLayout"
    @horizontalLayout = Qt::HBoxLayout.new()
    @horizontalLayout.objectName = "horizontalLayout"
    @label = Qt::Label.new(decryptionPassword)
    @label.objectName = "label"

    @horizontalLayout.addWidget(@label)

    @password = Qt::LineEdit.new(decryptionPassword)
    @password.objectName = "password"
    @password.echoMode = Qt::LineEdit::Password

    @horizontalLayout.addWidget(@password)


    @verticalLayout.addLayout(@horizontalLayout)

    @verticalSpacer = Qt::SpacerItem.new(20, 40, Qt::SizePolicy::Minimum, Qt::SizePolicy::Expanding)

    @verticalLayout.addItem(@verticalSpacer)

    @buttonBox = Qt::DialogButtonBox.new(decryptionPassword)
    @buttonBox.objectName = "buttonBox"
    @buttonBox.orientation = Qt::Horizontal
    @buttonBox.standardButtons = Qt::DialogButtonBox::Cancel|Qt::DialogButtonBox::Ok

    @verticalLayout.addWidget(@buttonBox)


    retranslateUi(decryptionPassword)
    Qt::Object.connect(@buttonBox, SIGNAL('accepted()'), decryptionPassword, SLOT('accept()'))
    Qt::Object.connect(@buttonBox, SIGNAL('rejected()'), decryptionPassword, SLOT('reject()'))

    Qt::MetaObject.connectSlotsByName(decryptionPassword)
    end # setupUi

    def setup_ui(decryptionPassword)
        setupUi(decryptionPassword)
    end

    def retranslateUi(decryptionPassword)
    decryptionPassword.windowTitle = Qt::Application.translate("DecryptionPassword", "Enter password", nil, Qt::Application::UnicodeUTF8)
    @label.text = Qt::Application.translate("DecryptionPassword", "Password", nil, Qt::Application::UnicodeUTF8)
    end # retranslateUi

    def retranslate_ui(decryptionPassword)
        retranslateUi(decryptionPassword)
    end

end

module Ui
    class DecryptionPassword < Ui_DecryptionPassword
    end
end  # module Ui

if $0 == __FILE__
    a = Qt::Application.new(ARGV)
    u = Ui_DecryptionPassword.new
    w = Qt::Dialog.new
    u.setupUi(w)
    w.show
    a.exec
end

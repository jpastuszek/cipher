=begin
** Form generated from reading ui file 'main.ui'
**
** Created: pt. sty 4 23:34:02 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
=end

require 'Qt4'

class Ui_MainWindow
    attr_reader :centralwidget
    attr_reader :horizontalLayout_9
    attr_reader :tabWidget
    attr_reader :encryptionTab
    attr_reader :verticalLayout_2
    attr_reader :verticalLayout_3
    attr_reader :groupBox_2
    attr_reader :horizontalLayout_3
    attr_reader :output_file_line
    attr_reader :output_file_button
    attr_reader :groupBox
    attr_reader :horizontalLayout_2
    attr_reader :label
    attr_reader :cipher_selector
    attr_reader :label_2
    attr_reader :mode_selector
    attr_reader :label_3
    attr_reader :sub_block_size_selector
    attr_reader :label_4
    attr_reader :key_size_selector
    attr_reader :horizontalSpacer
    attr_reader :verticalSpacer
    attr_reader :horizontalLayout_8
    attr_reader :encryption_progress_bar
    attr_reader :encrypt_button
    attr_reader :decryptionTab
    attr_reader :verticalLayout
    attr_reader :verticalLayout_4
    attr_reader :groupBox_3
    attr_reader :horizontalLayout_4
    attr_reader :input_file_line
    attr_reader :input_file_button
    attr_reader :verticalSpacer_2
    attr_reader :horizontalLayout_6
    attr_reader :decryption_progress_bar
    attr_reader :decryption_button
    attr_reader :statusbar

    def setupUi(mainWindow)
    if mainWindow.objectName.nil?
        mainWindow.objectName = "mainWindow"
    end
    mainWindow.resize(721, 293)
    @centralwidget = Qt::Widget.new(mainWindow)
    @centralwidget.objectName = "centralwidget"
    @horizontalLayout_9 = Qt::HBoxLayout.new(@centralwidget)
    @horizontalLayout_9.objectName = "horizontalLayout_9"
    @horizontalLayout_9.setContentsMargins(-1, -1, -1, 0)
    @tabWidget = Qt::TabWidget.new(@centralwidget)
    @tabWidget.objectName = "tabWidget"
    @encryptionTab = Qt::Widget.new()
    @encryptionTab.objectName = "encryptionTab"
    @verticalLayout_2 = Qt::VBoxLayout.new(@encryptionTab)
    @verticalLayout_2.objectName = "verticalLayout_2"
    @verticalLayout_3 = Qt::VBoxLayout.new()
    @verticalLayout_3.objectName = "verticalLayout_3"
    @groupBox_2 = Qt::GroupBox.new(@encryptionTab)
    @groupBox_2.objectName = "groupBox_2"
    @horizontalLayout_3 = Qt::HBoxLayout.new(@groupBox_2)
    @horizontalLayout_3.objectName = "horizontalLayout_3"
    @output_file_line = Qt::LineEdit.new(@groupBox_2)
    @output_file_line.objectName = "output_file_line"
    @output_file_line.readOnly = true

    @horizontalLayout_3.addWidget(@output_file_line)

    @output_file_button = Qt::PushButton.new(@groupBox_2)
    @output_file_button.objectName = "output_file_button"

    @horizontalLayout_3.addWidget(@output_file_button)


    @verticalLayout_3.addWidget(@groupBox_2)


    @verticalLayout_2.addLayout(@verticalLayout_3)

    @groupBox = Qt::GroupBox.new(@encryptionTab)
    @groupBox.objectName = "groupBox"
    @horizontalLayout_2 = Qt::HBoxLayout.new(@groupBox)
    @horizontalLayout_2.objectName = "horizontalLayout_2"
    @label = Qt::Label.new(@groupBox)
    @label.objectName = "label"

    @horizontalLayout_2.addWidget(@label)

    @cipher_selector = Qt::ComboBox.new(@groupBox)
    @cipher_selector.objectName = "cipher_selector"

    @horizontalLayout_2.addWidget(@cipher_selector)

    @label_2 = Qt::Label.new(@groupBox)
    @label_2.objectName = "label_2"

    @horizontalLayout_2.addWidget(@label_2)

    @mode_selector = Qt::ComboBox.new(@groupBox)
    @mode_selector.objectName = "mode_selector"

    @horizontalLayout_2.addWidget(@mode_selector)

    @label_3 = Qt::Label.new(@groupBox)
    @label_3.objectName = "label_3"

    @horizontalLayout_2.addWidget(@label_3)

    @sub_block_size_selector = Qt::SpinBox.new(@groupBox)
    @sub_block_size_selector.objectName = "sub_block_size_selector"
    @sub_block_size_selector.enabled = true
    @sub_block_size_selector.maximum = 128
    @sub_block_size_selector.singleStep = 8
    @sub_block_size_selector.value = 64

    @horizontalLayout_2.addWidget(@sub_block_size_selector)

    @label_4 = Qt::Label.new(@groupBox)
    @label_4.objectName = "label_4"

    @horizontalLayout_2.addWidget(@label_4)

    @key_size_selector = Qt::SpinBox.new(@groupBox)
    @key_size_selector.objectName = "key_size_selector"
    @key_size_selector.enabled = true
    @key_size_selector.readOnly = false
    @key_size_selector.maximum = 2048
    @key_size_selector.singleStep = 8
    @key_size_selector.value = 256

    @horizontalLayout_2.addWidget(@key_size_selector)

    @horizontalSpacer = Qt::SpacerItem.new(197, 20, Qt::SizePolicy::Expanding, Qt::SizePolicy::Minimum)

    @horizontalLayout_2.addItem(@horizontalSpacer)


    @verticalLayout_2.addWidget(@groupBox)

    @verticalSpacer = Qt::SpacerItem.new(20, 40, Qt::SizePolicy::Minimum, Qt::SizePolicy::Expanding)

    @verticalLayout_2.addItem(@verticalSpacer)

    @horizontalLayout_8 = Qt::HBoxLayout.new()
    @horizontalLayout_8.objectName = "horizontalLayout_8"
    @encryption_progress_bar = Qt::ProgressBar.new(@encryptionTab)
    @encryption_progress_bar.objectName = "encryption_progress_bar"
    @encryption_progress_bar.value = 24

    @horizontalLayout_8.addWidget(@encryption_progress_bar)

    @encrypt_button = Qt::PushButton.new(@encryptionTab)
    @encrypt_button.objectName = "encrypt_button"

    @horizontalLayout_8.addWidget(@encrypt_button)


    @verticalLayout_2.addLayout(@horizontalLayout_8)

    @tabWidget.addTab(@encryptionTab, Qt::Application.translate("MainWindow", "Encryption", nil, Qt::Application::UnicodeUTF8))
    @decryptionTab = Qt::Widget.new()
    @decryptionTab.objectName = "decryptionTab"
    @verticalLayout = Qt::VBoxLayout.new(@decryptionTab)
    @verticalLayout.objectName = "verticalLayout"
    @verticalLayout_4 = Qt::VBoxLayout.new()
    @verticalLayout_4.objectName = "verticalLayout_4"
    @groupBox_3 = Qt::GroupBox.new(@decryptionTab)
    @groupBox_3.objectName = "groupBox_3"
    @horizontalLayout_4 = Qt::HBoxLayout.new(@groupBox_3)
    @horizontalLayout_4.objectName = "horizontalLayout_4"
    @input_file_line = Qt::LineEdit.new(@groupBox_3)
    @input_file_line.objectName = "input_file_line"
    @input_file_line.readOnly = true

    @horizontalLayout_4.addWidget(@input_file_line)

    @input_file_button = Qt::PushButton.new(@groupBox_3)
    @input_file_button.objectName = "input_file_button"

    @horizontalLayout_4.addWidget(@input_file_button)


    @verticalLayout_4.addWidget(@groupBox_3)


    @verticalLayout.addLayout(@verticalLayout_4)

    @verticalSpacer_2 = Qt::SpacerItem.new(20, 40, Qt::SizePolicy::Minimum, Qt::SizePolicy::Expanding)

    @verticalLayout.addItem(@verticalSpacer_2)

    @horizontalLayout_6 = Qt::HBoxLayout.new()
    @horizontalLayout_6.objectName = "horizontalLayout_6"
    @decryption_progress_bar = Qt::ProgressBar.new(@decryptionTab)
    @decryption_progress_bar.objectName = "decryption_progress_bar"
    @decryption_progress_bar.value = 24

    @horizontalLayout_6.addWidget(@decryption_progress_bar)

    @decryption_button = Qt::PushButton.new(@decryptionTab)
    @decryption_button.objectName = "decryption_button"

    @horizontalLayout_6.addWidget(@decryption_button)


    @verticalLayout.addLayout(@horizontalLayout_6)

    @tabWidget.addTab(@decryptionTab, Qt::Application.translate("MainWindow", "Decryption", nil, Qt::Application::UnicodeUTF8))

    @horizontalLayout_9.addWidget(@tabWidget)

    mainWindow.centralWidget = @centralwidget
    @statusbar = Qt::StatusBar.new(mainWindow)
    @statusbar.objectName = "statusbar"
    mainWindow.statusBar = @statusbar

    retranslateUi(mainWindow)
    Qt::Object.connect(@cipher_selector, SIGNAL('currentIndexChanged(QString)'), mainWindow, SLOT('cipher_selected(QString)'))
    Qt::Object.connect(@mode_selector, SIGNAL('currentIndexChanged(QString)'), mainWindow, SLOT('mode_selected(QString)'))
    Qt::Object.connect(@sub_block_size_selector, SIGNAL('valueChanged(int)'), mainWindow, SLOT('sub_block_size_selected(int)'))
    Qt::Object.connect(@key_size_selector, SIGNAL('valueChanged(int)'), mainWindow, SLOT('key_size_selected(int)'))
    Qt::Object.connect(@encrypt_button, SIGNAL('clicked()'), mainWindow, SLOT('encrypt()'))

    @tabWidget.setCurrentIndex(0)


    Qt::MetaObject.connectSlotsByName(mainWindow)
    end # setupUi

    def setup_ui(mainWindow)
        setupUi(mainWindow)
    end

    def retranslateUi(mainWindow)
    mainWindow.windowTitle = Qt::Application.translate("MainWindow", "MainWindow", nil, Qt::Application::UnicodeUTF8)
    @groupBox_2.title = Qt::Application.translate("MainWindow", "Input File", nil, Qt::Application::UnicodeUTF8)
    @output_file_button.text = Qt::Application.translate("MainWindow", "Input File...", nil, Qt::Application::UnicodeUTF8)
    @groupBox.title = Qt::Application.translate("MainWindow", "Cipher Settings", nil, Qt::Application::UnicodeUTF8)
    @label.text = Qt::Application.translate("MainWindow", "Cipher", nil, Qt::Application::UnicodeUTF8)
    @label_2.text = Qt::Application.translate("MainWindow", "Mode", nil, Qt::Application::UnicodeUTF8)
    @label_3.text = Qt::Application.translate("MainWindow", "Sub Bolck Size", nil, Qt::Application::UnicodeUTF8)
    @label_4.text = Qt::Application.translate("MainWindow", "Key Size", nil, Qt::Application::UnicodeUTF8)
    @encrypt_button.text = Qt::Application.translate("MainWindow", "Encrypt...", nil, Qt::Application::UnicodeUTF8)
    @tabWidget.setTabText(@tabWidget.indexOf(@encryptionTab), Qt::Application.translate("MainWindow", "Encryption", nil, Qt::Application::UnicodeUTF8))
    @groupBox_3.title = Qt::Application.translate("MainWindow", "Input File", nil, Qt::Application::UnicodeUTF8)
    @input_file_button.text = Qt::Application.translate("MainWindow", "Input File...", nil, Qt::Application::UnicodeUTF8)
    @decryption_button.text = Qt::Application.translate("MainWindow", "Decrypt...", nil, Qt::Application::UnicodeUTF8)
    @tabWidget.setTabText(@tabWidget.indexOf(@decryptionTab), Qt::Application.translate("MainWindow", "Decryption", nil, Qt::Application::UnicodeUTF8))
    end # retranslateUi

    def retranslate_ui(mainWindow)
        retranslateUi(mainWindow)
    end

end

module Ui
    class MainWindow < Ui_MainWindow
    end
end  # module Ui

if $0 == __FILE__
    a = Qt::Application.new(ARGV)
    u = Ui_MainWindow.new
    w = Qt::MainWindow.new
    u.setupUi(w)
    w.show
    a.exec
end

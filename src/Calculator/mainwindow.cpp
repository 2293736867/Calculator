#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

    fadeIn();
    initButtonShadow();
    setButtonShadow();
    installButtonEventFilter();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initButtonShadow(void)
{
    num0_shadow = new QGraphicsDropShadowEffect();
    num1_shadow = new QGraphicsDropShadowEffect();
    num2_shadow = new QGraphicsDropShadowEffect();
    num3_shadow = new QGraphicsDropShadowEffect();
    num4_shadow = new QGraphicsDropShadowEffect();
    num5_shadow = new QGraphicsDropShadowEffect();
    num6_shadow = new QGraphicsDropShadowEffect();
    num7_shadow = new QGraphicsDropShadowEffect();
    num8_shadow = new QGraphicsDropShadowEffect();
    num9_shadow = new QGraphicsDropShadowEffect();

    plus_shadow = new QGraphicsDropShadowEffect();
    minus_shadow = new QGraphicsDropShadowEffect();
    mutiply_shadow = new QGraphicsDropShadowEffect();
    divide_shadow = new QGraphicsDropShadowEffect();
    percent_shadow = new QGraphicsDropShadowEffect();
    pow_shadow = new QGraphicsDropShadowEffect();
    dot_shadow = new QGraphicsDropShadowEffect();
    equal_shadow = new QGraphicsDropShadowEffect();

    c_shadow = new QGraphicsDropShadowEffect();
    ce_shadow = new QGraphicsDropShadowEffect();
    brace_shadow = new QGraphicsDropShadowEffect();
    bracket_shadow = new QGraphicsDropShadowEffect();
    parentheses_shadow = new QGraphicsDropShadowEffect();
    space_shadow = new QGraphicsDropShadowEffect();
    backspace_shadow = new QGraphicsDropShadowEffect();

    QGraphicsDropShadowEffect * allShadow[] = {
        num0_shadow,num1_shadow,num2_shadow,num3_shadow,num4_shadow,num5_shadow,num6_shadow,
        num7_shadow,num8_shadow,num9_shadow,plus_shadow,minus_shadow,mutiply_shadow,divide_shadow,
        percent_shadow,pow_shadow,dot_shadow,equal_shadow,c_shadow,ce_shadow,brace_shadow,bracket_shadow,
        parentheses_shadow,space_shadow,backspace_shadow};
    for(int i=0;i<25;++i)
    {
        allShadow[i]->setBlurRadius(14);
        allShadow[i]->setOffset(-1,1);
        allShadow[i]->setColor(Qt::gray);
        allShadow[i]->setEnabled(false);
    }
}

void MainWindow::installButtonEventFilter(void)
{
    ui->num0->installEventFilter(this);
    ui->num1->installEventFilter(this);
    ui->num2->installEventFilter(this);
    ui->num3->installEventFilter(this);
    ui->num4->installEventFilter(this);
    ui->num5->installEventFilter(this);
    ui->num6->installEventFilter(this);
    ui->num7->installEventFilter(this);
    ui->num8->installEventFilter(this);
    ui->num9->installEventFilter(this);
    ui->plus->installEventFilter(this);
    ui->minus->installEventFilter(this);
    ui->mutiply->installEventFilter(this);
    ui->divide->installEventFilter(this);
    ui->percent->installEventFilter(this);
    ui->pow->installEventFilter(this);
    ui->dot->installEventFilter(this);
    ui->equal->installEventFilter(this);
    ui->C->installEventFilter(this);
    ui->CE->installEventFilter(this);

    ui->brace->installEventFilter(this);
    ui->bracket->installEventFilter(this);
    ui->parentheses->installEventFilter(this);
    ui->blank->installEventFilter(this);
    ui->backspace->installEventFilter(this);
}

void MainWindow::setButtonShadow(void)
{
    ui->num0->setGraphicsEffect(num0_shadow);
    ui->num1->setGraphicsEffect(num1_shadow);
    ui->num2->setGraphicsEffect(num2_shadow);
    ui->num3->setGraphicsEffect(num3_shadow);
    ui->num4->setGraphicsEffect(num4_shadow);
    ui->num5->setGraphicsEffect(num5_shadow);
    ui->num6->setGraphicsEffect(num6_shadow);
    ui->num7->setGraphicsEffect(num7_shadow);
    ui->num8->setGraphicsEffect(num8_shadow);
    ui->num9->setGraphicsEffect(num9_shadow);

    ui->plus->setGraphicsEffect(plus_shadow);
    ui->minus->setGraphicsEffect(minus_shadow);
    ui->mutiply->setGraphicsEffect(mutiply_shadow);
    ui->divide->setGraphicsEffect(divide_shadow);
    ui->percent->setGraphicsEffect(percent_shadow);
    ui->pow->setGraphicsEffect(pow_shadow);
    ui->dot->setGraphicsEffect(dot_shadow);
    ui->equal->setGraphicsEffect(equal_shadow);
    ui->C->setGraphicsEffect(c_shadow);
    ui->CE->setGraphicsEffect(ce_shadow);

    ui->brace->setGraphicsEffect(brace_shadow);
    ui->bracket->setGraphicsEffect(bracket_shadow);
    ui->parentheses->setGraphicsEffect(parentheses_shadow);
    ui->blank->setGraphicsEffect(space_shadow);
    ui->backspace->setGraphicsEffect(backspace_shadow);
}

void MainWindow::fadeIn(void)
{
    QPropertyAnimation * changeOpacity = new QPropertyAnimation(this,"windowOpacity");
    changeOpacity->setStartValue(0);
    changeOpacity->setEndValue(0.87);
    changeOpacity->setDuration(1200);
    changeOpacity->start();
}

void MainWindow::fadeOut(void)
{
    QPropertyAnimation * changeOpacity = new QPropertyAnimation(this,"windowOpacity");
    changeOpacity->setStartValue(0.87);
    changeOpacity->setEndValue(0);
    changeOpacity->setDuration(850);
    changeOpacity->start();

    QTime start = QTime::currentTime().addMSecs(850);
    while(QTime::currentTime() < start)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void MainWindow::setText(const QString &s)
{
    ui->box->setText(s);
}

void MainWindow::appendText(const QString &s)
{
    ui->box->setText(ui->box->text()+s);
}

void MainWindow::setTextIf0ElseAppend(const QString &s)
{
    ui->box->text() == "0" ? setText(s) : appendText(s);
}

void MainWindow::setTextAndClearFocus(QPushButton *button, const QString &s)
{
    setText(s);
    button->clearFocus();
}

void MainWindow::appendTextAndClearFocus(QPushButton *button, const QString &s)
{
    appendText(s);
    button->clearFocus();
}

void MainWindow::setTextIf0ElseAppendAndClearFocus(QPushButton *button, const QString &s)
{
    setTextIf0ElseAppend(s);
    button->clearFocus();
}

void MainWindow::setResult(void)
{
    setText(ui->box->text().contains(QRegExp("[\\x4e00-\\x9fa5]+")) ?
        "请清除后重试." : result());
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_0:
        addNumButtonEffect(ui->num0,num0_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("0");
        break;
    case Qt::Key_1:
        addNumButtonEffect(ui->num1,num1_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("1");
        break;

    case Qt::Key_2:
        addNumButtonEffect(ui->num2,num2_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("2");
        break;

    case Qt::Key_3:
        addNumButtonEffect(ui->num3,num3_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("3");
        break;

    case Qt::Key_4:
        addNumButtonEffect(ui->num4,num4_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("4");
        break;

    case Qt::Key_5:
        addNumButtonEffect(ui->num5,num5_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("5");
        break;

    case Qt::Key_6:
        addNumButtonEffect(ui->num6,num6_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("6");
        break;

    case Qt::Key_7:
        addNumButtonEffect(ui->num7,num7_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("7");
        break;

    case Qt::Key_8:
        addNumButtonEffect(ui->num8,num8_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("8");
        break;

    case Qt::Key_9:
        addNumButtonEffect(ui->num9,num9_shadow);
        if(previousIsNotRightBrace())
            setTextIf0ElseAppend("9");
        break;

    case Qt::Key_Plus:
        addSignButtonEffect(ui->plus,plus_shadow);
        if(previousIsNotDot() && previousIsNotSign())
            appendText("+");
        break;

    case Qt::Key_Minus:
        addSignButtonEffect(ui->minus,minus_shadow);
        if(previousIsNotDot() && previousIsNotSign())
            appendText("-");
        break;

    case Qt::Key_Asterisk:
        addSignButtonEffect(ui->mutiply,mutiply_shadow);
        if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
            appendText("*");
        break;

    case Qt::Key_Slash:
        addSignButtonEffect(ui->divide,divide_shadow);
        if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
            appendText("/");
        break;

    case Qt::Key_AsciiCircum:
        addSignButtonEffect(ui->pow,pow_shadow);
        if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
            appendText("^");
        break;

    case Qt::Key_Percent:
        addSignButtonEffect(ui->percent,percent_shadow);
        if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
            appendText("%");
        break;

    case Qt::Key_ParenLeft:
        addSignButtonEffect(ui->parentheses,parentheses_shadow);
        if(previousIsNotNum() && previousIsNotDot() && previousIsNotRightBrace())
            setTextIf0ElseAppend("(");
        break;

    case Qt::Key_ParenRight:
        addSignButtonEffect(ui->parentheses,parentheses_shadow);
        if(previousIsNotDot() && previousIsNotLeftBrace() && previousIsNotSign())
            setTextIf0ElseAppend(")");
        break;

    case Qt::Key_BraceLeft:
        addSignButtonEffect(ui->brace,brace_shadow);
        if(previousIsNotNum() && previousIsNotDot() && previousIsNotRightBrace())
            setTextIf0ElseAppend("{");
        break;

    case Qt::Key_BraceRight:
        addSignButtonEffect(ui->brace,brace_shadow);
        if(previousIsNotDot() && previousIsNotLeftBrace() && previousIsNotSign())
            setTextIf0ElseAppend("}");
        break;

    case Qt::Key_BracketLeft:
        addSignButtonEffect(ui->bracket,bracket_shadow);
        if(previousIsNotNum() && previousIsNotDot() && previousIsNotRightBrace())
            setTextIf0ElseAppend("[");
        break;

    case Qt::Key_BracketRight:
        addSignButtonEffect(ui->bracket,bracket_shadow);
        if(previousIsNotDot() && previousIsNotLeftBrace() && previousIsNotSign())
            setTextIf0ElseAppend("]");
        break;

    case Qt::Key_Backspace:
        addSignButtonEffect(ui->backspace,backspace_shadow);
        if(ui->box->text() != "0")
        {
            ui->box->setReadOnly(false);
            if(ui->box->text().size() == 1)
                setText("0");
            else
                setText(ui->box->text().mid(0,ui->box->text().size()-1));
            ui->box->setReadOnly(true);
        }
        break;

    case Qt::Key_Space:
        addSignButtonEffect(ui->blank,space_shadow);
        if(ui->box->text() != "0")
            appendText(" ");
        break;

    case Qt::Key_Period:
        addSignButtonEffect(ui->dot,dot_shadow);
        if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace() && previousIsNotRightBrace())
            appendText(".");
        break;

    case Qt::Key_Escape:
        addSignButtonEffect(ui->C,c_shadow);
        setText("0");
        break;

    case Qt::Key_Equal:
    case Qt::Key_Return:
        addSignButtonEffect(ui->equal,equal_shadow);
        setResult();
        break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_0:
        case Qt::Key_1:
        case Qt::Key_2:
        case Qt::Key_3:
        case Qt::Key_4:
        case Qt::Key_5:
        case Qt::Key_6:
        case Qt::Key_7:
        case Qt::Key_8:
        case Qt::Key_9:
        case Qt::Key_Plus:
        case Qt::Key_Minus:
        case Qt::Key_Asterisk:
        case Qt::Key_Slash:
        case Qt::Key_AsciiCircum:
        case Qt::Key_Percent:
        case Qt::Key_ParenLeft:
        case Qt::Key_ParenRight:
        case Qt::Key_BraceLeft:
        case Qt::Key_BraceRight:
        case Qt::Key_BracketLeft:
        case Qt::Key_BracketRight:
        case Qt::Key_Backspace:
        case Qt::Key_Space:
        case Qt::Key_Period:
        case Qt::Key_Escape:
        case Qt::Key_Equal:
        case Qt::Key_Return:
            removeNumButtonEffect(ui->num0,num0_shadow);
            removeNumButtonEffect(ui->num1,num1_shadow);
            removeNumButtonEffect(ui->num2,num2_shadow);
            removeNumButtonEffect(ui->num3,num3_shadow);
            removeNumButtonEffect(ui->num4,num4_shadow);
            removeNumButtonEffect(ui->num5,num5_shadow);
            removeNumButtonEffect(ui->num6,num6_shadow);
            removeNumButtonEffect(ui->num7,num7_shadow);
            removeNumButtonEffect(ui->num8,num8_shadow);
            removeNumButtonEffect(ui->num9,num9_shadow);
            removeSignButtonEffect(ui->plus,plus_shadow);
            removeSignButtonEffect(ui->minus,minus_shadow);
            removeSignButtonEffect(ui->mutiply,mutiply_shadow);
            removeSignButtonEffect(ui->divide,divide_shadow);
            removeSignButtonEffect(ui->pow,pow_shadow);
            removeSignButtonEffect(ui->percent,percent_shadow);
            removeSignButtonEffect(ui->parentheses,parentheses_shadow);
            removeSignButtonEffect(ui->parentheses,parentheses_shadow);
            removeSignButtonEffect(ui->brace,brace_shadow);
            removeSignButtonEffect(ui->brace,brace_shadow);
            removeSignButtonEffect(ui->bracket,bracket_shadow);
            removeSignButtonEffect(ui->bracket,bracket_shadow);
            removeSignButtonEffect(ui->backspace,backspace_shadow);
            removeSignButtonEffect(ui->blank,space_shadow);
            removeSignButtonEffect(ui->dot,dot_shadow);
            removeSignButtonEffect(ui->C,c_shadow);
            removeSignButtonEffect(ui->equal,equal_shadow);
            break;
    }
}

void MainWindow::on_num7_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("7");
    clearButtonFocus(ui->num7);
}

void MainWindow::on_num8_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("8");
    clearButtonFocus(ui->num8);
}

void MainWindow::on_num9_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("9");
    clearButtonFocus(ui->num9);
}


void MainWindow::on_num4_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("4");
    clearButtonFocus(ui->num4);
}

void MainWindow::on_num5_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("5");
    clearButtonFocus(ui->num5);
}

void MainWindow::on_num6_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("6");
    clearButtonFocus(ui->num6);
}

void MainWindow::on_num1_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("1");
    clearButtonFocus(ui->num1);
}

void MainWindow::on_num2_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("2");
    clearButtonFocus(ui->num2);
}

void MainWindow::on_num3_clicked()
{
    if(previousIsNotRightBrace())
        setTextIf0ElseAppend("3");
    clearButtonFocus(ui->num3);
}

void MainWindow::on_num0_clicked()
{
    if(previousIsNotRightBrace())
       setTextIf0ElseAppend("0");
    clearButtonFocus(ui->num0);
}

void MainWindow::on_percent_clicked()
{
    if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
        appendText("%");
    clearButtonFocus(ui->percent);
}

void MainWindow::on_dot_clicked()
{
    if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace() && previousIsNotRightBrace())
        appendText(".");
    clearButtonFocus(ui->dot);
}

void MainWindow::on_brace_clicked()
{
    if(previousIsNotDot() && previousIsNotNum() && previousIsNotRightBrace())
        setTextIf0ElseAppend("{}");
    clearButtonFocus(ui->brace);
}

void MainWindow::on_bracket_clicked()
{
    if(previousIsNotDot() && previousIsNotNum() && previousIsNotRightBrace())
        setTextIf0ElseAppend("[]");
    clearButtonFocus(ui->bracket);
}

void MainWindow::on_parentheses_clicked()
{
    if(previousIsNotDot() && previousIsNotNum() && previousIsNotRightBrace())
        setTextIf0ElseAppend("()");
    clearButtonFocus(ui->parentheses);
}

void MainWindow::on_blank_clicked()
{
    if(ui->box->text() != "0")
        appendText(" ");
}

void MainWindow::on_mutiply_clicked()
{
    if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
        appendText("*");
    clearButtonFocus(ui->mutiply);
}

void MainWindow::on_plus_clicked()
{
    if(previousIsNotDot() && previousIsNotSign())
        appendText("+");
    clearButtonFocus(ui->plus);
}

void MainWindow::on_minus_clicked()
{
    if(previousIsNotDot() && previousIsNotSign())
        appendText("-");
    clearButtonFocus(ui->minus);
}

void MainWindow::on_equal_clicked()
{
    setResult();
    clearButtonFocus(ui->equal);
}

void MainWindow::on_divide_clicked()
{
    if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
        appendText("/");
    clearButtonFocus(ui->divide);
}

void MainWindow::on_pow_clicked()
{
    if(previousIsNotDot() && previousIsNotSign() && previousIsNotLeftBrace())
        appendText("^");
    clearButtonFocus(ui->pow);
}

void MainWindow::on_backspace_clicked()
{
    if(ui->box->text() != "0")
    {
        ui->box->setReadOnly(false);
        setText(ui->box->text().size() != 1 ? ui->box->text().mid(0,ui->box->text().size()-1) : "0");
        ui->box->setReadOnly(true);
        ui->backspace->clearFocus();
    }
}

void MainWindow::on_CE_clicked()
{
    ui->box->setText("0");
}

void MainWindow::on_C_clicked()
{
    ui->box->setText("0");
}

void MainWindow::on_minimize_clicked()
{
    MainWindow::showMinimized();
}


void MainWindow::on_close_clicked()
{
    fadeOut();
    exit(0);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mousePoint = event->globalPos();
        windowPoint = frameGeometry().topLeft();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(windowPoint + event->globalPos() - mousePoint);
    }
}
bool MainWindow::eventFilter(QObject *object,QEvent *event)
{
    if(event->type() == QEvent::HoverEnter)
    {
        if(object == ui->num0)
            addNumButtonEffect(ui->num0,num0_shadow);
        else if(object == ui->num1)
            addNumButtonEffect(ui->num1,num1_shadow);
        else if(object == ui->num2)
            addNumButtonEffect(ui->num2,num2_shadow);
        else if(object == ui->num3)
            addNumButtonEffect(ui->num3,num3_shadow);
        else if(object == ui->num4)
            addNumButtonEffect(ui->num4,num4_shadow);
        else if(object == ui->num5)
            addNumButtonEffect(ui->num5,num5_shadow);
        else if(object == ui->num6)
            addNumButtonEffect(ui->num6,num6_shadow);
        else if(object == ui->num7)
            addNumButtonEffect(ui->num7,num7_shadow);
        else if(object == ui->num8)
            addNumButtonEffect(ui->num8,num8_shadow);
        else if(object == ui->num9)
            addNumButtonEffect(ui->num9,num9_shadow);
        else if(object == ui->plus)
            addSignButtonEffect(ui->plus,plus_shadow);
        else if(object == ui->minus)
            addSignButtonEffect(ui->minus,minus_shadow);
        else if(object == ui->mutiply)
            addSignButtonEffect(ui->mutiply,mutiply_shadow);
        else if(object == ui->divide)
            addSignButtonEffect(ui->divide,divide_shadow);
        else if(object == ui->percent)
            addSignButtonEffect(ui->percent,percent_shadow);
        else if(object == ui->pow)
            addSignButtonEffect(ui->pow,pow_shadow);
        else if(object == ui->dot)
            addSignButtonEffect(ui->dot,dot_shadow);
        else if(object == ui->equal)
            addSignButtonEffect(ui->equal,equal_shadow);
        else if(object == ui->C)
            addSignButtonEffect(ui->C,c_shadow);
        else if(object == ui->CE)
            addSignButtonEffect(ui->CE,ce_shadow);
        else if(object == ui->brace)
            addSignButtonEffect(ui->brace,brace_shadow);
        else if(object == ui->bracket)
            addSignButtonEffect(ui->bracket,bracket_shadow);
        else if(object == ui->parentheses)
            addSignButtonEffect(ui->parentheses,parentheses_shadow);
        else if(object == ui->blank)
            addSignButtonEffect(ui->blank,space_shadow);
        else if(object == ui->backspace)
            addSignButtonEffect(ui->backspace,backspace_shadow);
    }
    else if(event->type() == QEvent::HoverLeave)
    {
        if(object == ui->num0)
            removeNumButtonEffect(ui->num0,num0_shadow);
        else if(object == ui->num1)
            removeNumButtonEffect(ui->num1,num1_shadow);
        else if(object == ui->num2)
            removeNumButtonEffect(ui->num2,num2_shadow);
        else if(object == ui->num3)
            removeNumButtonEffect(ui->num3,num3_shadow);
        else if(object == ui->num4)
            removeNumButtonEffect(ui->num4,num4_shadow);
        else if(object == ui->num5)
            removeNumButtonEffect(ui->num5,num5_shadow);
        else if(object == ui->num6)
            removeNumButtonEffect(ui->num6,num6_shadow);
        else if(object == ui->num7)
            removeNumButtonEffect(ui->num7,num7_shadow);
        else if(object == ui->num8)
            removeNumButtonEffect(ui->num8,num8_shadow);
        else if(object == ui->num9)
            removeNumButtonEffect(ui->num9,num9_shadow);
        else if(object == ui->plus)
            removeSignButtonEffect(ui->plus,plus_shadow);
        else if(object == ui->minus)
            removeSignButtonEffect(ui->minus,minus_shadow);
        else if(object == ui->mutiply)
            removeSignButtonEffect(ui->mutiply,mutiply_shadow);
        else if(object == ui->divide)
            removeSignButtonEffect(ui->divide,divide_shadow);
        else if(object == ui->percent)
            removeSignButtonEffect(ui->percent,percent_shadow);
        else if(object == ui->pow)
            removeSignButtonEffect(ui->pow,pow_shadow);
        else if(object == ui->dot)
            removeSignButtonEffect(ui->dot,dot_shadow);
        else if(object == ui->equal)
            removeSignButtonEffect(ui->equal,equal_shadow);
        else if(object == ui->C)
            removeSignButtonEffect(ui->C,c_shadow);
        else if(object == ui->CE)
            removeSignButtonEffect(ui->CE,ce_shadow);
        else if(object == ui->brace)
            removeSignButtonEffect(ui->brace,brace_shadow);
        else if(object == ui->bracket)
            removeSignButtonEffect(ui->bracket,bracket_shadow);
        else if(object == ui->parentheses)
            removeSignButtonEffect(ui->parentheses,parentheses_shadow);
        else if(object == ui->blank)
            removeSignButtonEffect(ui->blank,space_shadow);
        else if(object == ui->backspace)
            removeSignButtonEffect(ui->backspace,backspace_shadow);
    }
}

void MainWindow::addNumButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(true);
    button->setStyleSheet(
        "border:1px groove rgb(220,220,220);"
        "background-color:rgb(193,193,193);"
    );
}

void MainWindow::removeNumButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(false);
    button->setStyleSheet("border:1px groove rgb(220,220,220);background-color:rgb(243,243,243);");
}
void MainWindow::addSignButtonEffect(QPushButton *button, QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(true);
    button->setStyleSheet(
        "border:1px groove rgb(220,220,220);"
        "background-color:rgb(170,170,170);"
    );
}

void MainWindow::removeSignButtonEffect(QPushButton *button,QGraphicsDropShadowEffect *shadow)
{
    shadow->setEnabled(false);
    button->setStyleSheet("border:1px groove rgb(220,220,220);background-color:rgb(222,222,222);");
}


void MainWindow::on_num7_pressed()
{

}

void MainWindow::on_num8_pressed()
{

}

QString MainWindow::result(void)
{
    QProcess * caller = new QProcess;
    caller->execute("MyCalc.exe",QStringList()<<(ui->box->text().remove(QRegExp("\\s"))));
    caller->waitForFinished();
    caller->close();
    QFile resultFile("result.txt");
    resultFile.open(QIODevice::ReadOnly);
    QString result = resultFile.readAll();
    resultFile.remove();
    resultFile.close();
    if(result == "#")
        result = "表达式错误,请重新输入.";
    else if(result == "#1")
        result = "除数为0";
    else
    {
        if(result.indexOf('e') == -1 && result.indexOf('E') == -1)
        {
            for(int len = result.size()-1;len>=0 && result[len] != '.';--len)
            {
                if(result[len] == '0')
                    result.remove(len,1);
                else
                    break;
            }
            if(result[result.size()-1] == '.')
                result.remove(result.size()-1,1);
        }
        if(result.size() > 17)
            result = result.mid(0,17);
        if(result == "-0")
            result = "0";
    }
    return result;
}

void MainWindow::clearButtonFocus(QPushButton *button)
{
    button->clearFocus();
}

bool MainWindow::previousIsNotDot(void)
{
    return ui->box->text()[ui->box->text().size()-1] != '.';
}

bool MainWindow::previousIsNotNum(void)
{
    QCharRef c = ui->box->text()[ui->box->text().size()-1];
    return c < '0' || c > '9';
}

bool MainWindow::previousIsNotSign(void)
{
    QCharRef c = ui->box->text()[ui->box->text().size()-1];
    return c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && c != '%';
}

bool MainWindow::previousIsNotLeftBrace(void)
{
    QCharRef c = ui->box->text()[ui->box->text().size()-1];
    return c != '(' && c != '[' && c != '{';
}

bool MainWindow::previousIsNotRightBrace(void)
{
    QCharRef c = ui->box->text()[ui->box->text().size()-1];
    return c != ')' && c != ']' && c != '}';
}

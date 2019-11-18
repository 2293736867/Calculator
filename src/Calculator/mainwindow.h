#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QTime>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_num7_clicked();

    void on_num8_clicked();

    void on_num9_clicked();

    void on_num7_pressed();

    void on_num4_clicked();

    void on_num3_clicked();

    void on_num5_clicked();

    void on_num6_clicked();

    void on_num1_clicked();

    void on_num2_clicked();

    void on_num0_clicked();

    void on_percent_clicked();

    void on_dot_clicked();

    void on_brace_clicked();

    void on_bracket_clicked();

    void on_parentheses_clicked();

    void on_blank_clicked();

    void on_mutiply_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_equal_clicked();

    void on_divide_clicked();

    void on_pow_clicked();

    void on_backspace_clicked();

    void on_CE_clicked();

    void on_C_clicked();

    void on_minimize_clicked();

    void on_close_clicked();

    void on_num8_pressed();


protected:
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    bool eventFilter(QObject *,QEvent *);

private:
    Ui::MainWindow *ui;
    QPoint mousePoint;
    QPoint windowPoint;

    QGraphicsDropShadowEffect *num0_shadow;
    QGraphicsDropShadowEffect *num1_shadow;
    QGraphicsDropShadowEffect *num2_shadow;
    QGraphicsDropShadowEffect *num3_shadow;
    QGraphicsDropShadowEffect *num4_shadow;
    QGraphicsDropShadowEffect *num5_shadow;
    QGraphicsDropShadowEffect *num6_shadow;
    QGraphicsDropShadowEffect *num7_shadow;
    QGraphicsDropShadowEffect *num8_shadow;
    QGraphicsDropShadowEffect *num9_shadow;

    QGraphicsDropShadowEffect *plus_shadow;
    QGraphicsDropShadowEffect *minus_shadow;
    QGraphicsDropShadowEffect *mutiply_shadow;
    QGraphicsDropShadowEffect *divide_shadow;
    QGraphicsDropShadowEffect *percent_shadow;
    QGraphicsDropShadowEffect *pow_shadow;
    QGraphicsDropShadowEffect *dot_shadow;
    QGraphicsDropShadowEffect *equal_shadow;

    QGraphicsDropShadowEffect *c_shadow;
    QGraphicsDropShadowEffect *ce_shadow;
    QGraphicsDropShadowEffect *brace_shadow;
    QGraphicsDropShadowEffect *bracket_shadow;
    QGraphicsDropShadowEffect *parentheses_shadow;
    QGraphicsDropShadowEffect *space_shadow;
    QGraphicsDropShadowEffect *backspace_shadow;


    void fadeIn(void);
    void fadeOut(void);

    void setText(const QString &);
    void appendText(const QString &);
    void setTextIf0ElseAppend(const QString &);

    void setTextAndClearFocus(QPushButton *,const QString &);
    void appendTextAndClearFocus(QPushButton *,const QString &);
    void setTextIf0ElseAppendAndClearFocus(QPushButton *,const QString &);

    void setResult(void);
    void clearButtonFocus(QPushButton *);

    bool previousIsNotDot(void);
    bool previousIsNotSign(void);
    bool previousIsNotLeftBrace(void);
    bool previousIsNotRightBrace(void);
    bool previousIsNotNum(void);

    void addNumButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void removeNumButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void addSignButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);
    void removeSignButtonEffect(QPushButton *,QGraphicsDropShadowEffect *);

    void initButtonShadow(void);
    void setButtonShadow(void);
    void installButtonEventFilter(void);

    QString result(void);
};

#endif // MAINWINDOW_H

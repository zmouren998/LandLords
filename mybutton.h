#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

    ///
    /// \brief setImage
    /// \param normal 默认鼠标图片
    /// \param hover  点击时的图片
    /// \param press  鼠标释放
    ///
    void setImage(QString normal,QString hover,QString press);

protected:
    // 鼠标按下
    void mousePressEvent(QMouseEvent* event)override;
    // 鼠标进入
    void enterEvent(QEvent* event)override;
    // 鼠标释放
    void mouseReleaseEvent(QMouseEvent* event)override;
    // 绘图事件
    void paintEvent(QPaintEvent *event) override;

    // 鼠标离开
    void leaveEvent(QEvent *event)override;
signals:

private:
    QString m_normal;
    QString m_press;
    QString m_hover;
    QPixmap m_pixmap;
};

#endif // MYBUTTON_H

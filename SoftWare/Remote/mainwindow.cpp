#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTcpSocket>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 在构造函数中连接到 AP
    connectToAP();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connectToAP()
{
    // 创建 QTcpSocket 对象
    socket = new QTcpSocket(this);

    // 连接到 AP
    socket->connectToHost("192.168.4.1", 80); // 替换为 AP 的 IP 地址和端口

    // 等待连接完成
    if(socket->waitForConnected())
    {
        qDebug() << "Connected to AP";
    }
    else
    {
        qDebug() << "Failed to connect to AP";
    }
}


void MainWindow::sendDataToAP(const QString &data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
    {
        // 向 AP 发送数据
        socket->write(data.toUtf8());
        qDebug() << "Sent data to AP: " << data;
    }
    else
    {
        qDebug() << "Not connected to AP";
        // 使用弹窗显示消息提醒
        QMessageBox::warning(this, "Warning", "Not connected to AP.");
    }
}


void MainWindow::on_up_clicked()
{
     sendDataToAP("F");
}

void MainWindow::on_down_clicked()
{
     sendDataToAP("B");
}

void MainWindow::on_left_clicked()
{
     sendDataToAP("L");
}

void MainWindow::on_right_clicked()
{
     sendDataToAP("R");
}

void MainWindow::on_off_clicked()
{
     sendDataToAP("S");
}

/**************************************
Author:��������?���ַ�ת�뺯�����Ժ�����
Date:2017/12/23
Update:2018/1/6
Description:������
***************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QtGui>
#include <QMainWindow>
#include <QMessageBox>
#include "CSSSpatialIndex.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /* ����������ť��ִ�����Ե�ͼ�Ĳ�ѯ���� */
    void on_pushButton_clicked();

protected:
    /* ����ͼ�ϵ㣬ִ��ͼ�����ԵĲ�ѯ���� */
    void mousePressEvent(QMouseEvent *);

private:
    Ui::MainWindow *ui;
    CSSNameIndex* nidx;
    CSSSpatialIndex* sidx;

    /* �ַ�ת�룬���Ժ��� */
    string GB2312ToUTF_8(const char *pText, int pLen);
    void Gb2312ToUnicode(wchar_t* pOut, const char *gbBuffer);
    void UnicodeToUTF_8(char* pOut, wchar_t* pText);
};

#endif // MAINWINDOW_H

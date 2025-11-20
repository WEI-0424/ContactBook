#include "mywidget.h"
#include "ui_mywidget.h"
#include<QTableWidgetItem>
#include<QFile>
#include<QDebug>
#include <QFileDialog>
QString mFilename="c:/Desktop/EX/ContactBook/Contact.txt";

void write_str(QString filename, QString str){
    QFile mFile(filename);
    if(!mFile.open(QFile::WriteOnly|QFile::Text)){
        qDebug()<<"Could not open file for writing";
        return;
    }
    QTextStream out(&mFile);
    out<<str;
    mFile.flush();
    mFile.close();
}

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    QStringList colTitles;
    ui->tableWidget->setColumnCount(4);
    colTitles<<"學號"<<"班級"<<"姓名"<<"電話";
    ui->tableWidget->setHorizontalHeaderLabels(colTitles);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    QTableWidgetItem *InputRow1 = new QTableWidgetItem(ui->lineEdit->text());
    QTableWidgetItem *InputRow2 = new QTableWidgetItem(ui->lineEdit_2->text());
    QTableWidgetItem *InputRow3 = new QTableWidgetItem(ui->lineEdit_3->text());
    QTableWidgetItem *InputRow4 = new QTableWidgetItem(ui->lineEdit_4->text());

    int newRow = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(newRow);

    ui->tableWidget->setItem(newRow, 0, InputRow1);
    ui->tableWidget->setItem(newRow, 1, InputRow2);
    ui->tableWidget->setItem(newRow, 2, InputRow3);
    ui->tableWidget->setItem(newRow, 3, InputRow4);
}


void MyWidget::on_pushButton_2_clicked()
{
    QString saveFile="";
    int rc,cc;
    rc=ui->tableWidget->rowCount();
    cc=ui->tableWidget->columnCount();
    mFilename=QFileDialog::getSaveFileName(this, "匯出存檔", ".");
    for(int i=0; i<rc; i++){
        for(int j=0;j<cc;j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";
            saveFile+="\n";
        }
        write_str(mFilename,saveFile);
    }
}


void MyWidget::on_pushButton_4_clicked()
{
    close();
}


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QList>
#include <QMessageBox>
#include <QStandardItem>
#include <QDateTime>
#include <QDir>
#include <QTextStream>
#include <QVector>
#include <QPen>
#include <QTimer>
#include <QMessageBox>
#include <command.h>
#include "common/CRC16.h"
#include "Signalprocess/qrcode.h"
#include "Signalprocess/Signalprocess.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();  
   // void SearchPort();
    void DataListShow();
    void DataCurveShowInit();
    int CommandSend(int cmdDataNum, quint8 cmdType, quint8 cmdCode, int bypass);
    void QR_Date_SignalProcess_Alg_data (void);
    void stringToHtml(QString &str,QColor crl);
    void stringToHtmlFilter(QString &str);

    void Config_File_Init();
    /*获取组好的初始化*/
    void Get_SetSn_Init();
    /*输入限制初始化*/
    void Input_Limit_Init();
private slots:
    void on_Connect_Btn_clicked();
    void ReadData();
    void SearchPort();
    void on_SaveBtn_clicked();

    void on_ClearBtn2_clicked();

    void on_TypeSelctcomboBox_2_activated(int index);

    void Rrrorhandle(QSerialPort::SerialPortError a);

    void on_SetTime_Btn_clicked();

    void on_DebugMode_Btn_clicked();

    void on_NormalMode_Btn_clicked();

    void on_ChineseSet_Btn_clicked();

    void on_LaunchPrinter_Btn_clicked();

    void on_ClosePrinter_Btn_clicked();

    void on_ReadIDCard_Btn_clicked();

    void on_WriteRES_Btn_clicked();

    void on_SetSNandFW_Btn_clicked();

    void on_WriteIDCard_Btn_clicked();

    void on_ReadRES_Btn_clicked();

    void on_EnglishSet_Btn_clicked();

    void on_ClearBtn_clicked();

    void on_APPSystemInfo_Btn_clicked();

    void on_Set_BorderLine_Btn_clicked();

    void on_APPSystemInfo_Btn_4_clicked();

    void on_Read_BorderLine_Btn_clicked();

    void on_Set_Cal_Btn_clicked();

    void on_Get_Status_Btn_clicked();

    void on_Clear_Btn_clicked();

    void on_RecoverySet_Btn_clicked();

    void on_JieKe_Btn_clicked();

    void on_Chanl_Scan_Btn_clicked();

private:
    Ui::MainWindow *ui;

    QStandardItemModel* dataModel;          //绑定表格Tableview
    QStandardItemModel* C_TModelLocal;      //绑定本地计算的CT TableView
    QStandardItemModel* C_TModelRecev;      //绑定下位机计算的 CT Tableview

    QList<float> Showdata;                  //原始表格数据临时存储
    QList<float> SaveShowdata[300];              //保存表格数据
    int SaveShowdataIndex = 0;

    int index=0;

    QList<float> C_LocalDate;               //本地C
    QList<float> T_LocalDate;               //本地T
    QList<float> C_TLocalDate;              //本地C/T
    
    QList<float> C_RecevDate;               //设备C
    QList<float> T_RecevDate[100];               //设备T
    int CandTRecevIndex = 0;
    QList<float> C_T_RecevDate;              //设备C/T

    QTimer *SearchPortT;                    //刷新端口定时器

    QVector<double>  TempX[8];              //八条曲线的X轴临时值
    QVector<double> Curve[8];               //八条曲线Y轴的临时值

    QSerialPort *SerialPort;                //传输绑定的端口
    QSerialPort *SerialPort2;               //刷新端口绑定的端口

    uint8 commandType;
    uint8 commandCode;

    uint8 dataBuffer[1024*50];
    uint8 cmdBuffer[1025];
    uint8 respBuffer[2 * 1024];

    int Sn;         //批号
    int Number;   //编号

    int contReceive = 0;
    int respLength = 0;
    int bytesReceived = 0;
    int getResponse = 0;

    QRCODE_STRUCT QR_Date;

    int OFFSET_HEADER = 0;
    int OFFSET_LEN_LO = 1;
    int OFFSET_LEN_HI = 2;
    int OFFSET_CMD_TYPE = 3;
    int OFFSET_CMD_CODE = 4;
    int OFFSET_CMD_DATA = 5;

    int LEN_HEAD_LENGTH = 3;
    int LEN_HEAD_TAIL = 2;

    /*曲线数据处理*/
    void Get_Curver_Data_Handle(quint8 *,quint16);
    /*边界线处理*/
    void Get_Border_Line(quint8 *,quint16);
    /*原始数据处理*/
    void Get_RawData_Handle(quint8 *,quint16);
    /*C和T线处理*/
    void Get_C_and_T_Value(quint8 *,quint16);
    /*电位器值处理*/
    void Get_Res_Value(quint8 *,quint16);
    /*二维码数据处理*/
    void Get_QRcode_Data(quint8 *,quint16);
    /*校准结果返回处理*/
    void Get_Cal_Result(quint8 *,quint16);
    /*获取设备模式*/
    void Get_Device_Status(quint8 *,quint16);
};

#endif // MAINWINDOW_H

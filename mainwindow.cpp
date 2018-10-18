#include "mainwindow.h"
#include "ui_mainwindow.h"

ALG_DATA SignalProcess_Alg_data;
//extern "C" void test();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SerialPort = new QSerialPort(this);
    SerialPort2 = new QSerialPort(this);

    dataModel = new QStandardItemModel();
    C_TModelLocal = new QStandardItemModel();
    C_TModelRecev = new QStandardItemModel();

    SerialPort->setDataBits(QSerialPort::Data8);
    SerialPort->setParity(QSerialPort::NoParity);
    SerialPort->setStopBits(QSerialPort::OneStop);
    SerialPort->setBaudRate(115200);
    connect(SerialPort,SIGNAL(readyRead()),this,SLOT(ReadData()));

    SearchPortT = new QTimer;
    SearchPortT->setInterval(200);
    connect(SearchPortT, SIGNAL(timeout()), this, SLOT(SearchPort()));
    SearchPortT->start();

    DataCurveShowInit();
    connect(SerialPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this,SLOT(Rrrorhandle(QSerialPort::SerialPortError)));
   // ui->groupBox_2->setEnabled(false);
    ui->groupBox_3->setEnabled(false);
    ui->groupBox_4->setEnabled(false);
    ui->Get_Status_Btn->setEnabled(true);
    Config_File_Init();
    /*输入框输入控制*/
    Input_Limit_Init();
//    QString qssFile = ":/darkblue.css";
//    QFile file(qssFile);
//    if (file.open(QFile::ReadOnly)) {
//        QString qss = QLatin1String(file.readAll());
//        QString paletteColor = qss.mid(20, 7);
//        qApp->setPalette(QPalette(QColor(paletteColor)));
//        qApp->setStyleSheet(qss);
//        file.close();
//    }

}
void MainWindow::Input_Limit_Init()
{
    ui->textBrowser->moveCursor(QTextCursor::End);//接收框始终定为在末尾一行
    QRegExp regExp("[2][0][0-9]{6,6}");//正则表达式，第一位数字为a-z的数字，第二位为1-9的数字，后边是0-2位0-9的数字
    ui->SNDate_lineEdit->setValidator(new QRegExpValidator(regExp,this));
}
void MainWindow::Rrrorhandle(QSerialPort::SerialPortError ror)
{
    qDebug()<<ror;
//    if(a == QSerialPort::ResourceError)
//    {
//        QMessageBox::warning(this,tr("警告"),tr("串口已拔出！"));
//        ui->Connect_Btn->setText("连接");
//        ui->groupBox_2->setEnabled(false);
//        ui->groupBox_3->setEnabled(false);
//        ui->groupBox_4->setEnabled(false);
//        ui->COMSelectcomboBox->setEnabled(true);
   //     SerialPort->clear();
//        SerialPort->close();

//    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
/*连接*/
void MainWindow::on_Connect_Btn_clicked()
{
    if(ui->Connect_Btn->text()==tr("连接"))
    {

        SerialPort->setPortName(ui->COMSelectcomboBox->currentText());
        SerialPort->setFlowControl(QSerialPort::NoFlowControl);
        if(SerialPort->open(QIODevice::ReadWrite))
        {
            ui->Connect_Btn->setText("断开");
            ui->COMSelectcomboBox->setEnabled(false);
        }
        else
        {
            QMessageBox::warning(this,tr("警告"),tr("打开串口失败\r\n该串口被占用或者未选择正确的串口"));
        }

    }
    else
    {
        ui->Connect_Btn->setText("连接");
        ui->groupBox_2->setEnabled(false);
        ui->groupBox_3->setEnabled(false);
        ui->groupBox_4->setEnabled(false);
        ui->COMSelectcomboBox->setEnabled(true);
        SerialPort->clear();
        SerialPort->close();
    }

}
/*串口插入添加，拔出清除*/
void MainWindow::SearchPort()
{
    QStringList ComList;
    QList<int> Index;
    int index;
   // ComList.append(ui->comboBox->currentText());
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {

        SerialPort2->setPort(info);
//        if(SerialPort2->open(QIODevice::ReadWrite))
//        {
//           ComList += SerialPort2->portName();
//           SerialPort2->close();
//        }
                SerialPort2->open(QIODevice::ReadWrite);
                   ComList += SerialPort2->portName();
                   SerialPort2->close();


    }
  //  ui->comboBox->addItems(ComList);
  //新插入添加
//    if(ui->comboBox->currentText().isEmpty())
//    {}
//    else
//    {
//    if(SerialPort->portName().isEmpty())
//    {}
//    else
//    {
//           ComList.append(SerialPort->portName());
//    }
       // ComList.append(ui->comboBox->currentText());
//    }
    for(int i=0;i< ComList.length();i++)
    {
       for(int j=0;j< ui->COMSelectcomboBox->count();j++)
       {
           if(ComList.at(i) == ui->COMSelectcomboBox->itemText(j))
           {
               Index.append(i);
               break;
           }
           else
           {
           }
        }
    }
    for(int i=0;i< ComList.length();i++)
    {
        if(Index.contains(i))
        {
        }
        else
        {
          ui->COMSelectcomboBox->addItem(ComList.at(i));
         qDebug("add");
        }
    }
   //拔出清除
    for(int i=0;i<ui->COMSelectcomboBox->count();i++)
    {
        if(ComList.contains(ui->COMSelectcomboBox->itemText(i)))
        {

        }
        else
        {
            ui->COMSelectcomboBox->removeItem(i);
            qDebug("rm ");
        }
    }
}
/***********************************************************************************************
*函数名: CommandSend
*函数功能描述:串口发送函数
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
int MainWindow::CommandSend(int cmdDataNum, byte cmdType, byte cmdCode, int bypass)
{
    int SIZE_LEN_HEAD_CMD_CRC = 6;
    uint16 totalPackageLength = SIZE_LEN_HEAD_CMD_CRC + cmdDataNum + 2;
    uint16 packageLength = SIZE_LEN_HEAD_CMD_CRC + cmdDataNum;
    uint16 crcCal = 0;
    QString str;

    /* Head */
    cmdBuffer[OFFSET_HEADER] = (char)'$';

    /* Package length */
    cmdBuffer[OFFSET_LEN_LO] = (uint8)(packageLength & 0x00FF);
    cmdBuffer[OFFSET_LEN_HI] = (uint8)((packageLength & 0xFF00)>>8);

    /* Command type and code */
    cmdBuffer[OFFSET_CMD_TYPE] = cmdType;
    cmdBuffer[OFFSET_CMD_CODE] = cmdCode;

    /* Calculate CRC, exclude 2-bytes crc value */

    crcCal = CRC16_Calculate(cmdBuffer, (uint32)(packageLength - 2), 0xFFFF, 0);

    /* CRC */
    cmdBuffer[OFFSET_CMD_DATA + cmdDataNum] = crcCal& 0x00FF;
    cmdBuffer[OFFSET_CMD_DATA + cmdDataNum + 1] = (crcCal & 0xFF00)>>8;

    /* Tail */
    cmdBuffer[OFFSET_CMD_DATA + cmdDataNum + 2] = (char)'#';
    QByteArray data = QByteArray((const char*)cmdBuffer,totalPackageLength);
    if(ui->Connect_Btn->text() == tr("断开"))
    {
        SerialPort->write(data);
        str.append(tr("发送数据:"));
        for(int i = 0;i < data.length();i++)
        {
            str += (QString("%1").arg(data[i]&0xFF,2,16,QLatin1Char('0')).toUpper() + QString(" "));   //2 字符宽度
        }
        QColor  clrR(85,0,255);
        stringToHtmlFilter(str);
        stringToHtml(str,clrR);
        ui->textBrowser->moveCursor(QTextCursor::End);//接收框始终定为在末尾一行
        ui->textBrowser->insertHtml(str);
        ui->textBrowser->append("\n");
       // ui->textBrowser->append(Str);
       // ui->textBrowser->append(str);
    }
    else
    {
        QMessageBox::warning(this,tr("串口问题"),tr("串口未连接，请先连接串口。"));
    }
}
void MainWindow::stringToHtmlFilter(QString &str)
{
    //注意这几行代码的顺序不能乱，否则会造成多次替换
    str.replace("&","&amp;");
    str.replace(">","&gt;");
    str.replace("<","&lt;");
    str.replace("\"","&quot;");
    str.replace("\'","&#39;");
    str.replace(" ","&nbsp;");
    str.replace("\n","<br>");
    str.replace("\r","<br>");
}
void MainWindow::stringToHtml(QString &str,QColor crl)
{
     QByteArray array;
     array.append(crl.red());
     array.append(crl.green());
     array.append(crl.blue());
     QString strC(array.toHex());
     str = QString("<span style=\" color:#%1;\">%2</span>").arg(strC).arg(str);
 }

void MainWindow::ReadData()
{
    static int i=0;
    i++;
    static QByteArray ReadBuff;
    quint8  stdid,RecvBuff[2048];
    quint16 Datalength,Total_Length;
    QString Str;
    ReadBuff.append(SerialPort->readAll());
    memset(RecvBuff,0,2048);
    memcpy(&RecvBuff[0],ReadBuff,ReadBuff.length());
    Total_Length = ReadBuff.length();
    for(int i = 0; i < Total_Length; i++)
    {
       Str.append(tr("%1").arg(RecvBuff[i]&0xFF,2, 16, QLatin1Char('0')).toUpper() + QString(" "));
    }
    qDebug()<<Str;
    Str.clear();
    memcpy(&Datalength,&RecvBuff[1],2);
    if(Datalength <= Total_Length-2)
    {
        if((ReadBuff[0] == '$') && (ReadBuff[Datalength+1] == '#'))
        {
           Str.append(tr("接受数据:"));
           for(int i = 0; i < Total_Length; i++)
           {
              Str.append(tr("%1").arg(RecvBuff[i]&0xFF,2, 16, QLatin1Char('0')).toUpper() + QString(" "));
           }
           QColor  clrR(255,0,0);
           stringToHtmlFilter(Str);
           stringToHtml(Str,clrR);
           ui->textBrowser->moveCursor(QTextCursor::End);//接收框始终定为在末尾一行
           ui->textBrowser->insertHtml(Str);
           ui->textBrowser->append("\n");
            stdid = RecvBuff[4];
            switch(stdid)
            {
                case APP_SYSINFO:
                    break;
                case APP_RECEIVE_CURVERDATA:
                    Get_Curver_Data_Handle(RecvBuff,Total_Length);
                    break;
                case APP_READ_BORDER_LINE:
                    Get_Border_Line(RecvBuff,Total_Length);
                    break;
                case APP_RECEIVE_RAWDATA:
                    Get_RawData_Handle(RecvBuff,Total_Length);
                    break;
                case APP_RECEIVE_CT:
                    Get_C_and_T_Value(RecvBuff,Total_Length);
                case APP_READ_RES:
                    Get_Res_Value(RecvBuff,Total_Length);
                    break;
                case APP_RECEIVE_QRCODE_DATA:
                    Get_QRcode_Data(RecvBuff,Total_Length);
                    break;
                case APP_SET_CAL:
                    Get_Cal_Result(RecvBuff,Total_Length);
                    break;
                case GET_STATUS:
                    Get_Device_Status(RecvBuff,Total_Length);
                    break;
                case APP_READ_IDCARD:
                    /*读取ID卡*/
                    break;
                case APP_SET_MFG:
                    Get_SetSn_Init();
                    break;
                default:
                    break;
            }
            if(index == 8)
            {
                index =0;
            }
            if(ui->Curver_checkBox->isChecked())
            {
                ui->CurveShow->graph(0)->setData(TempX[0], Curve[0]);
                ui->CurveShow->graph(1)->setData(TempX[1], Curve[1]);
                ui->CurveShow->graph(2)->setData(TempX[2], Curve[2]);
                ui->CurveShow->graph(3)->setData(TempX[3], Curve[3]);
                ui->CurveShow->graph(4)->setData(TempX[4], Curve[4]);
                ui->CurveShow->graph(5)->setData(TempX[5], Curve[5]);
                ui->CurveShow->graph(6)->setData(TempX[6], Curve[6]);
                ui->CurveShow->graph(7)->setData(TempX[7], Curve[7]);
                ui->CurveShow->replot();
            }
            ReadBuff.clear();
            DataListShow();
        }
    }
}
void MainWindow::Get_Curver_Data_Handle(quint8 *Data,quint16 length)
{
    quint8 temp;
    for(int i=0;i<(length-8)/2;i++)
    {
        memcpy(&temp,&Data[5+i*2],2);
        Showdata.append(temp);
    }
}
void MainWindow::Get_Border_Line(quint8 *Data,quint16 length)
{
    quint16 temp;
    memcpy(&temp,&Data[5],2);
    ui->Read_BorderLine_lineEdit->setText(tr("%1").arg(temp));
}
void MainWindow::Get_RawData_Handle(quint8 *Data,quint16 length)
{
    quint16 temp;
    for(int i=0;i<(length-8)/2;i++)
    {
        memcpy(&temp,&Data[5+i*2],2);
        Curve[index].append(temp);
        TempX[index].append(TempX[index].back()+1);
        Showdata.append(temp);
    }
    qDebug()<<index<<SaveShowdataIndex;
    QR_Date_SignalProcess_Alg_data();
    memcpy(&SignalProcess_Alg_data.sampleBuffer[0],&Data[5] , length-8);
    SignalProcess_Alg_data.sampleNumber = (length-8)/2;
    SignalProcess_Run();
    C_LocalDate.append(SignalProcess_Alg_data.calcInfo.areaC);
    T_LocalDate.append(SignalProcess_Alg_data.calcInfo.areaT);
    qDebug("end");
    index++;
    SaveShowdataIndex++;
}
/*获取CT数据值，单一C数据，多个T数据*/
void MainWindow::Get_C_and_T_Value (quint8 *Data,quint16 length)
{
    quint16 temp;
    memcpy(&temp,&Data[5],2);
    C_RecevDate.append(temp);
    for(int i=0;i<(length-10)/2;i++)
    {
       memcpy(&temp,&Data[7+i*2],2);
       T_RecevDate[CandTRecevIndex].append(temp);
    }
    CandTRecevIndex++;
}
/* 获取下位机电位器值*/
void MainWindow::Get_Res_Value (quint8 *Data,quint16 length)
{
    quint8 resvalue;
    resvalue = Data[OFFSET_CMD_DATA];
    ui->ReadRES_lineEdit->setText(tr("%1").arg(resvalue));
}
/*获取二维码数据*/
void MainWindow::Get_QRcode_Data(quint8 *Data,quint16 length)
{
    quint8 singleLineSize,headLineSize;
    singleLineSize = sizeof(QRCODE_SINGLE_LINE);
    headLineSize = sizeof(QRCODE_HEAD_STRUCT);
    memset(&QR_Date, 0, sizeof(QRCODE_STRUCT));
    memcpy(&QR_Date.head.name[0], &Data[OFFSET_CMD_DATA + 3], sizeof(QRCODE_HEAD_STRUCT) - 2);
    memcpy(&QR_Date.ch_data[9], &Data[OFFSET_CMD_DATA+headLineSize + 9 * singleLineSize], sizeof(QRCODE_SINGLE_LINE));
}
/*获取设备状态App模式 Boot模式*/
void MainWindow::Get_Device_Status(quint8 *Data,quint16 length)
{
    quint8 Status;
    Status = Data[OFFSET_CMD_DATA];
    if(Status == 1)
    {
        ui->Status_Label->setText(tr("%1").arg("APP"));
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
        ui->groupBox_4->setEnabled(true);
     }
    else
    {
        ui->Status_Label->setText(tr("%1").arg("BOOT"));
    }
}
/*获取校准结果，成功或失败*/
void MainWindow::Get_Cal_Result(quint8 *Data,quint16 length)
{
    quint8 Result;
    Result = Data[OFFSET_CMD_DATA];
    if(Result == 0)
    {
        QMessageBox::information(this, tr("校准信息"), tr("校准失败"));
        //ui->Set_Cal_label->setText(tr("%1").arg("校准失败"));
     }
    else
    {
        QMessageBox::information(this, tr("校准信息"), tr("校准成功"));
       // ui->Set_Cal_label->setText(tr("%1").arg("校准成功"));
    }
}
/*算法添加二维码数据初始化*/
void MainWindow::QR_Date_SignalProcess_Alg_data (void)
{
    /* @TODO */
    SignalProcess_Alg_data.posInfo.C_center = QR_Date.head.midC;
    SignalProcess_Alg_data.posInfo.searchHalfRadius_C = QR_Date.head.searchHalfRadius_C;
    SignalProcess_Alg_data.posInfo.dist_C_T1 = QR_Date.head.distC_T;
    SignalProcess_Alg_data.posInfo.searchHalfRadius_T = QR_Date.head.searchHalfRadius_T;
    SignalProcess_Alg_data.posInfo.dist_peak1 = QR_Date.head.distC_Base1;
    SignalProcess_Alg_data.posInfo.dist_peak2 = QR_Date.head.distC_Base2;
    SignalProcess_Alg_data.posInfo.dist_peak3 = QR_Date.head.distC_Base3;
    SignalProcess_Alg_data.posInfo.dist_peak4 = QR_Date.head.distC_Base4;
    SignalProcess_Alg_data.posInfo.areaC_HalfRadius = QR_Date.head.areaC_HalfRadius;
    SignalProcess_Alg_data.posInfo.areaT_HalfRadius = QR_Date.head.areaT_HalfRadius;
    SignalProcess_Alg_data.posInfo.winSize = QR_Date.head.winSize;
    SignalProcess_Alg_data.limitEnabled = QR_Date.head.limitEnabled;
    SignalProcess_Alg_data.limitInfo.C_stepSize = QR_Date.head.C_stepSize;
    SignalProcess_Alg_data.limitInfo.C_magnitude = QR_Date.head.C_magnitude;
    SignalProcess_Alg_data.limitInfo.C_MIN = QR_Date.head.C_MIN;
}
void MainWindow::on_SaveBtn_clicked()
{
    QFile file;
    QString timePoint = QDateTime::currentDateTime().toString("yyyy-MM-dd HH-mm-ss");
    QString path = QString("Data/TestData-%1-%2").arg(ui->TypeSelctcomboBox->currentText()).arg(timePoint);
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save File"),
            path,
            tr("Config Files (*.csv)"));
    QDir dir;
    dir.cd(QDir::currentPath());
    if(!dir.exists("Data"))
    {
        dir.mkdir("Data");
    }
    file.setFileName(fileName);
    if (file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        QTextStream out(&file);
//        int columnCount=dataModel->columnCount();
//        int rowCount = dataModel->rowCount();
//        int i,j;
//        for(i=0;i<rowCount;i++)
//        {
//            for(j=0;j<columnCount;j++)
//            {
//                QModelIndex index = dataModel->index(i,j);
//                QString Datatemp = dataModel->data(index).toString();
//                qDebug()<<Datatemp;
//                if(!Datatemp.isEmpty())
//                {
//                    Datatemp.append(',');
//                    out <<Datatemp;
//                   // Datatemp.clear();
//                }
//            }
//            out << endl;
//        }
        for(int i=0;i<20;i++)
        {
            if(!SaveShowdata[i].isEmpty())
            {
                for(int j=0;j<SaveShowdata[i].length();j++)
                    {
                        QString Datatemp = QString(tr("%1").arg(SaveShowdata[i].at(j)));
                        Datatemp.append(',');
                        out <<Datatemp;
                    }
                out << endl;
            }else
                {
               // break;
            }
        }
        for(int i = 0;i<C_LocalDate.length();i++)
        {
            QString Datatemp = QString(tr("%1").arg(C_LocalDate.at(i)));
            Datatemp.append(',');
            out <<Datatemp;
        }
        out << endl;
        for(int i = 0;i<T_LocalDate.length();i++)
        {
            QString Datatemp = QString(tr("%1").arg(T_LocalDate.at(i)));
            Datatemp.append(',');
            out <<Datatemp;
        }
        out << endl;

        for(int i = 0;i<C_TLocalDate.length();i++)
        {
            QString Datatemp = QString(tr("%1").arg(C_TLocalDate.at(i)));
            Datatemp.append(',');
            out <<Datatemp;
        }
        out << endl;
        for(int i = 0;i<C_RecevDate.length();i++)
        {
            QString Datatemp = QString(tr("%1").arg(C_RecevDate.at(i)));
            Datatemp.append(',');
            for(int j = 0;j<T_RecevDate[i].length();j++)
            {
                Datatemp.append(QString(tr("%1").arg(T_RecevDate[i].at(j))));
                Datatemp.append(',');
            }
            out <<Datatemp;
            out << endl;
        }
        file.close();
    }
}
void MainWindow::DataListShow()
{
    ui->tableView->setModel(dataModel);  //绑定数据模型 
    /*本地C、T、C除以T数据模块处理*/
    C_TModelRecev->removeRows(0,C_TModelRecev->rowCount());
    C_TModelLocal->removeRows(0,C_TModelLocal->rowCount());
    ui->C_TLocal_tableView->setModel(C_TModelLocal);
    QList<QStandardItem *> C_Trow;
    QList<QStandardItem *> C_T;
    QList<QString> C_Tstr;
    QList<float> C_TData;
    for(int i=0; i<C_LocalDate.length();i++)
    {
        QStandardItem* C_T_item = new QStandardItem;
        C_Tstr.append(tr("%1,%2").arg(C_LocalDate.at(i)).arg(T_LocalDate.at(i)));
        C_T_item->setData(C_Tstr.at(i),0);
        C_Trow.append(C_T_item);

        QStandardItem* C_T_D = new QStandardItem;
        if(T_LocalDate.at(i) > 0)
        {
            C_TData.append(C_LocalDate.at(i)/T_LocalDate.at(i));
        }
        else
        {
            C_TData.append(0);
        }
        C_T_D->setData(C_TData.at(i),0);
        C_T.append(C_T_D);
    }
    for(int i=0;i<C_TData.length();i++)
    {
        C_TLocalDate.append(C_TData.at(i));
    }
    if(ui->CandTDatecheckBox->isChecked())
    {
        C_TModelLocal->appendRow(C_Trow);
        C_TModelLocal->appendRow(C_T);
    }
    /*得到的下位机C、T数据模块处理*/
    ui->C_TRecev_tableView->setModel(C_TModelRecev);
    QList<QString> C_T_RecevDateitemStr;
    QList<QStandardItem *> C_T_Recerow;
    for(int i=0; i<C_RecevDate.length();i++)
    {
        QStandardItem* C_T_RecevDateitem = new QStandardItem;
        QString str;
        str.append(tr("%1").arg(C_RecevDate.at(i)));
        for(int j=0;j<T_RecevDate[i].length();j++)
        {
            str.append(",");
            str.append(tr("%1").arg(T_RecevDate[i].at(j)));

        }
        C_T_RecevDateitemStr.append(str);
        C_T_RecevDateitem->setData(C_T_RecevDateitemStr.at(i),0);
        C_T_Recerow.append(C_T_RecevDateitem);
    }
    if(ui->CandTDatecheckBox->isChecked())
    {
        for(int a =0; a<C_T_Recerow.length();a++)
        {
            C_TModelRecev->appendRow(C_T_Recerow.at(a));
        }
    }

    QList<QStandardItem *> row;
    for(int i=0; i<Showdata.length(); i++)
    {
        QStandardItem* item = new QStandardItem;
        item->setData(Showdata.at(i), 0);
        SaveShowdata[SaveShowdataIndex].append(Showdata.at(i));              //保存表格数据
        row.append(item);
    }
    if(ui->RowDatacheckBox->isChecked())
    {
        if(!row.isEmpty())
        {
            dataModel->appendRow(row);
        }
    }
    Showdata.clear();
}
void MainWindow::DataCurveShowInit()
{

        QPen pen;
        pen.setWidth(2);
        ui->CurveShow->addGraph();
        pen.setColor(Qt::red);
        ui->CurveShow->graph(0)->setPen(pen);
        ui->CurveShow->graph(0)->setName("数据1");

        ui->CurveShow->addGraph();
        pen.setColor(Qt::black);
        ui->CurveShow->graph(1)->setPen(pen);
        ui->CurveShow->graph(1)->setName("数据2");

        ui->CurveShow->addGraph();
        pen.setColor(Qt::green);
        ui->CurveShow->graph(2)->setPen(pen);
        ui->CurveShow->graph(2)->setName("数据3");

        ui->CurveShow->addGraph();
        pen.setColor(Qt::blue);
        ui->CurveShow->graph(3)->setPen(pen);
        ui->CurveShow->graph(3)->setName("数据4");

        ui->CurveShow->addGraph();
        pen.setColor(Qt::yellow);
        ui->CurveShow->graph(4)->setPen(pen);
        ui->CurveShow->graph(4)->setName("数据5");

        ui->CurveShow->addGraph();
        pen.setColor(Qt::gray);
        ui->CurveShow->graph(5)->setPen(pen);
        ui->CurveShow->graph(5)->setName("数据6");

        ui->CurveShow->addGraph();
        pen.setColor(Qt::lightGray);
        ui->CurveShow->graph(6)->setPen(pen);
        ui->CurveShow->graph(6)->setName("数据7");

        ui->CurveShow->addGraph();
        pen.setColor(tr("#B8860B"));
        ui->CurveShow->graph(7)->setPen(pen);
        ui->CurveShow->graph(7)->setName("数据8");


       ui->CurveShow->legend->setVisible(true);
        ui->CurveShow->xAxis->setLabel("x");
        ui->CurveShow->yAxis->setLabel("y");

//        ui->TempPlot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
//        ui->TempPlot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
       //设置customPlot可进行拽托或伸缩
        ui->CurveShow->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
//        ui->TempPlot->graph(0)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(1)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(2)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(3)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(4)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(5)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(6)->rescaleValueAxis(true, true);
//        ui->TempPlot->graph(7)->rescaleValueAxis(true, true);

//        //自适应轴
//        ui->TempPlot->graph(0)->rescaleAxes(true);
         ui->CurveShow->yAxis->setRange(0, 2000);
         ui->CurveShow->xAxis->setRange(0, 500);

        ui->CurveShow->graph(0)->setData(TempX[0], Curve[0]);
        ui->CurveShow->graph(1)->setData(TempX[1], Curve[1]);
        ui->CurveShow->graph(2)->setData(TempX[2], Curve[2]);
        ui->CurveShow->graph(3)->setData(TempX[3], Curve[3]);
        ui->CurveShow->graph(4)->setData(TempX[4], Curve[4]);
        ui->CurveShow->graph(5)->setData(TempX[5], Curve[5]);
        ui->CurveShow->graph(6)->setData(TempX[6], Curve[6]);
        ui->CurveShow->graph(7)->setData(TempX[7], Curve[7]);

        connect(ui->CurveShow->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->CurveShow->xAxis2, SLOT(setRange(QCPRange)), Qt::DirectConnection);
        connect(ui->CurveShow->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->CurveShow->yAxis2, SLOT(setRange(QCPRange)), Qt::DirectConnection);
        //界面背景设置

        QBrush backRole;
        backRole.setColor("lightGray");
        backRole.setStyle(Qt::SolidPattern);
        ui->CurveShow->setBackground(backRole);
}

void MainWindow::on_ClearBtn2_clicked()
{
    for(int i=0; i<8; i++)
    {
        Curve[i].clear();
        TempX[i].clear();
        ui->CurveShow->graph(i)->data().data()->clear();
    }

    ui->CurveShow->clearMask();
    ui->CurveShow->replot();
}
void MainWindow::on_TypeSelctcomboBox_2_activated(int index)
{
    if(index == 1)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
         ui->stackedWidget->setCurrentIndex(0);
    }
}
/***********************************************************************************************
*函数名: on_ClearBtn_clicked
*函数功能描述:清空
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_ClearBtn_clicked()
{

    SaveShowdataIndex = 0;
    for(int i=0;i<20;i++)
    {
        SaveShowdata[i].clear();
    }
    dataModel->clear();
    C_TModelLocal->clear();
    C_TModelRecev->clear();
    C_LocalDate.clear();
    T_LocalDate.clear();
    C_TLocalDate.clear();

    C_RecevDate.clear();//设备C
    for(int i=0;i<100;i++)
    {
          T_RecevDate[i].clear();               //设备T
    }
    CandTRecevIndex = 0;
    C_T_RecevDate.clear();

    for(int i=0; i<8; i++)
    {
        Curve[i].clear();
        TempX[i].clear();
        ui->CurveShow->graph(i)->data().data()->clear();
    }
    ui->CurveShow->clearMask();
    ui->CurveShow->replot();
}
/***********************************************************************************************
*函数名: on_SetTime_Btn_clicked
*函数功能描述:设置时间
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_SetTime_Btn_clicked()
{
    int cmdDataLength = 11;
    commandType = (uint8)cmdType::APP;
    commandCode = (uint8)cmdCode::APP_SET_TIME;
    QString TimeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss");
    QStringList sections = TimeStr.split(QRegExp("[-]"));
    /*年月日时分秒*/
    cmdBuffer[OFFSET_CMD_DATA] = (quint16)(QString(sections.at(0)).toUInt() & 0x00FF);
    cmdBuffer[OFFSET_CMD_DATA+1] = (quint16)((QString(sections.at(0)).toUInt()& 0xFF00)>>8);

    cmdBuffer[OFFSET_CMD_DATA + 2] = QString(sections.at(1)).toInt();
    cmdBuffer[OFFSET_CMD_DATA + 3] = QString(sections.at(2)).toInt();
    cmdBuffer[OFFSET_CMD_DATA + 4] = QString(sections.at(3)).toInt();
    cmdBuffer[OFFSET_CMD_DATA + 5] = QString(sections.at(4)).toInt();
    cmdBuffer[OFFSET_CMD_DATA + 6] = QString(sections.at(5)).toInt();
    cmdBuffer[OFFSET_CMD_DATA + 7] = 0;
    cmdBuffer[OFFSET_CMD_DATA + 8] = 0;
    cmdBuffer[OFFSET_CMD_DATA + 9] = 0;
    cmdBuffer[OFFSET_CMD_DATA + 10] =0;
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_DebugMode_Btn_clicked
*函数功能描述:设置调试模式
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_DebugMode_Btn_clicked()
{
    int cmdDataLength = 1;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_MODE;
    cmdBuffer[OFFSET_CMD_DATA] = 1;
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_NormalMode_Btn_clicked
*函数功能描述:设置正常模式
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_NormalMode_Btn_clicked()
{
    int cmdDataLength = 1;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_MODE;
    cmdBuffer[OFFSET_CMD_DATA] = 0;
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_ChineseSet_Btn_clicked
*函数功能描述:设置中文模式
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_ChineseSet_Btn_clicked()
{
    int cmdDataLength = 2;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_LANGUAGE;

    cmdBuffer[OFFSET_CMD_DATA] = 0; /* English */
    cmdBuffer[OFFSET_CMD_DATA + 1] = 0;
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_ChineseSet_Btn_clicked
*函数功能描述:设置英文模式
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_EnglishSet_Btn_clicked()
{
    int cmdDataLength = 2;

    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_LANGUAGE;

    cmdBuffer[OFFSET_CMD_DATA] = 1; /* English */
    cmdBuffer[OFFSET_CMD_DATA + 1] = 0;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_LaunchPrinter_Btn_clicked
*函数功能描述:运行打印机
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_LaunchPrinter_Btn_clicked()
{
    int cmdDataLength = 2;

    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_PRINTER;

    cmdBuffer[OFFSET_CMD_DATA] = 1; /*  */
    cmdBuffer[OFFSET_CMD_DATA + 1] = 0;

    cmdDataLength = 2;
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_ClosePrinter_Btn_clicked
*函数功能描述:关闭打印机
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_ClosePrinter_Btn_clicked()
{
     int cmdDataLength = 2;

     commandType = (quint8)cmdType::APP;
     commandCode = (quint8)cmdCode::APP_SET_PRINTER;

     cmdBuffer[OFFSET_CMD_DATA] = 0;
     cmdBuffer[OFFSET_CMD_DATA + 1] = 0;

     cmdDataLength = 2;
     CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_WriteIDCard_Btn_clicked
*函数功能描述:写ID卡
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_WriteIDCard_Btn_clicked()
{
}
/***********************************************************************************************
*函数名: on_ReadIDCard_Btn_clicked
*函数功能描述:读ID卡
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_ReadIDCard_Btn_clicked()
{
    int cmdDataLength = 0;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_READ_IDCARD;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_ReadRES_Btn_clicked
*函数功能描述:读RES
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_ReadRES_Btn_clicked()
{
    int cmdDataLength = 0;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_READ_RES;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_ReadRES_Btn_clicked
*函数功能描述:读RES
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_WriteRES_Btn_clicked()
{
    int cmdDataLength = 1;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_WRITE_RES;

    cmdBuffer[OFFSET_CMD_DATA] = ui->ReadRES_lineEdit->text().toInt();
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_SetSNandFW_Btn_clicked
*函数功能描述:设置产品批号和固件版本号
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_SetSNandFW_Btn_clicked()
{
    if(!(ui->SNDate_lineEdit->text().length() == 8))
    {
        QMessageBox::information(this, "Title", "请输入八位批号", QMessageBox::Yes, QMessageBox::Yes);
        return;
    }
    int cmdDataLength = 0;

    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_MFG;

//    QString TimeStr = QDateTime::currentDateTime().toString("yyyy-MM-dd-HH-mm-ss");
//    QStringList sections = TimeStr.split(QRegExp("[-]"));
//    int year = QString(sections.at(0)).toInt();
//    int month = QString(sections.at(1)).toInt();
//    int day = QString(sections.at(2)).toInt();
//    int SN;

//    if (ui->SNDate_lineEdit->text().isEmpty())
//        SN = (int)((year - 2000) * 1e7 + month * 1e5 + day * 1e3 + ui->SNNumber_lineEdit->text().toInt());
//    else
//        SN = (int)((ui->SNDate_lineEdit->text().toInt() - 20000000) * 1e3 + ui->SNNumber_lineEdit->text().toInt());

//    cmdBuffer[OFFSET_CMD_DATA + 0] = SN& 0x00FF;
//    cmdBuffer[OFFSET_CMD_DATA + 1] = (SN& 0xFF00) >> 8;
//    cmdBuffer[OFFSET_CMD_DATA + 2] = (SN& 0xFF0000) >> 16;
//    cmdBuffer[OFFSET_CMD_DATA + 3] = (SN& 0xFF000000) >> 24;

//    uint16 revision = 0;

//    cmdBuffer[OFFSET_CMD_DATA + 4] = 0;
//    cmdBuffer[OFFSET_CMD_DATA + 5] = 0;
//    cmdBuffer[OFFSET_CMD_DATA + 6] = revision& 0x00FF;
//    cmdBuffer[OFFSET_CMD_DATA + 7] = (revision& 0xFF00) >> 8;

    int data = (ui->SNDate_lineEdit->text().toInt()-20000000)* 1e3 + ui->SNNumber_spinBox->value();

    cmdBuffer[OFFSET_CMD_DATA + 0] = data& 0x00FF;
    cmdBuffer[OFFSET_CMD_DATA + 1] = (data& 0xFF00) >> 8;
    cmdBuffer[OFFSET_CMD_DATA + 2] = (data& 0xFF0000) >> 16;
    cmdBuffer[OFFSET_CMD_DATA + 3] = (data& 0xFF000000) >> 24;

    cmdDataLength = 4;
    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
void MainWindow::on_APPSystemInfo_Btn_clicked()
{
     int cmdDataLength = 0;
     commandType = (quint8)cmdType::APP;
     commandCode = (quint8)cmdCode::APP_SYSINFO;
     CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_Set_BorderLine_Btn_clicked
*函数功能描述:设置边界线
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_Set_BorderLine_Btn_clicked()
{
    int cmdDataLength = 2;
    quint16 borderdata= ui->Set_BorderLine_lineEdit->text().toInt();
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_BORDER_LINE;

    cmdBuffer[OFFSET_CMD_DATA] = borderdata& 0x00FF;
    cmdBuffer[OFFSET_CMD_DATA + 1] = (borderdata& 0xFF00) >> 8;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_APPSystemInfo_Btn_4_clicked 已去除
*函数功能描述:
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_APPSystemInfo_Btn_4_clicked()
{
//    APP_SET_BORDER_LINE,
//    APP_READ_BORDER_LINE,

//    int cmdDataLength = 0;
//    commandType = (quint8)cmdType::APP;
//    commandCode = (quint8)cmdCode::APP_READ_BORDER_LINE;

//    CommandSend(cmdDataLength, commandType, commandCode, 0);

}
/***********************************************************************************************
*函数名: on_Read_BorderLine_Btn_clicked 已去除
*函数功能描述:读取边界线
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_Read_BorderLine_Btn_clicked()
{
    int cmdDataLength = 0;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_READ_BORDER_LINE;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_Set_Cal_Btn_clicked
*函数功能描述:校准参数
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_Set_Cal_Btn_clicked()
{
    int cmdDataLength = 0;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_CAL;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_Get_Status_Btn_clicked
*函数功能描述:下位机状态
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_Get_Status_Btn_clicked()
{
    int cmdDataLength = 0;
    commandType = (quint8)cmdType::NONE;
    commandCode = (quint8)cmdCode::GET_STATUS;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名: on_Clear_Btn_clicked
*函数功能描述:
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_Clear_Btn_clicked()
{
    ui->textBrowser->clear();
}
/***********************************************************************************************
*函数名:  on_RecoverySet_Btn_clicked
*函数功能描述:出厂设置
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_RecoverySet_Btn_clicked()
{
    int cmdDataLength = 2;
    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_OUTFAB;

    cmdBuffer[OFFSET_CMD_DATA] = 0;
    cmdBuffer[OFFSET_CMD_DATA + 1] = 0;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名:  on_JieKe_Btn_clicked
*函数功能描述:捷克语
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_JieKe_Btn_clicked()
{
    int cmdDataLength = 2;

    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_LANGUAGE;

    cmdBuffer[OFFSET_CMD_DATA] = 2; /* English */
    cmdBuffer[OFFSET_CMD_DATA + 1] = 0;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名:  on_Chanl_Scan_Btn_clicked
*函数功能描述:通道Scan
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::on_Chanl_Scan_Btn_clicked()
{
    quint8 chanl = ui->Chanl_Scan_comboBox->currentIndex()+1;
    int cmdDataLength = 1;

    commandType = (quint8)cmdType::APP;
    commandCode = (quint8)cmdCode::APP_SET_LANGUAGE;

    cmdBuffer[OFFSET_CMD_DATA] = chanl;

    CommandSend(cmdDataLength, commandType, commandCode, 0);
}
/***********************************************************************************************
*函数名:  Get_SetSn_Init
*函数功能描述:设置sn
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::Get_SetSn_Init()
{
    quint8 SNsize = 0;
    quint8 index = 0;
    int TempSn = 0;
    QSettings ReadConfig(tr("Setting.ini"),QSettings::IniFormat);
    if(!ReadConfig.contains(tr("Manage/CurrentType")))
    {
        ReadConfig.beginGroup(tr("Manage"));
        ReadConfig.setValue(tr("CurrentType"), ui->TypeSelctcomboBox->currentText());
        ReadConfig.endGroup();
    }
    else
    {
        ReadConfig.beginGroup(tr("Manage"));
        ReadConfig.setValue(tr("CurrentType"), ui->TypeSelctcomboBox->currentText());
        ReadConfig.endGroup();
    }

    if(!ReadConfig.contains(tr("%1/CurrentGroup").arg(ui->TypeSelctcomboBox->currentText())))
    {
        ReadConfig.beginGroup(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
        ReadConfig.setValue(tr("CurrentGroup"), 0);
        ReadConfig.endGroup();

        ReadConfig.beginWriteArray(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
        ReadConfig.setArrayIndex(0);
        ReadConfig.setValue("SN",ui->SNDate_lineEdit->text().toInt());
        ReadConfig.setValue("Number",ui->SNNumber_spinBox->value());
        ui->SNNumber_spinBox->setValue(ui->SNNumber_spinBox->value()+1);
        ReadConfig.endArray();
    }
    else{
        ReadConfig.beginGroup(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
        SNsize = ReadConfig.value("size").toInt();
        ReadConfig.endGroup();
        for(int i=0;i<SNsize;i++)
        {
            ReadConfig.beginReadArray(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
            ReadConfig.setArrayIndex(i);
            TempSn = ReadConfig.value(tr("SN")).toInt();
            ReadConfig.endArray();
            if(TempSn == ui->SNDate_lineEdit->text().toInt())
            {
                break;
            }
            index++;
        }
        if(TempSn ==  ui->SNDate_lineEdit->text().toInt())
        {
            ReadConfig.beginWriteArray(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
            ReadConfig.setArrayIndex(index);
            ReadConfig.setValue("SN", ui->SNDate_lineEdit->text().toInt());
            ReadConfig.setValue("Number", ui->SNNumber_spinBox->value());
            ui->SNNumber_spinBox->setValue(ui->SNNumber_spinBox->value()+1);
            ReadConfig.endArray();

            ReadConfig.beginGroup(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
            ReadConfig.setValue(tr("CurrentGroup"), index);
            ReadConfig.endGroup();
        }
        else
        {
            ReadConfig.beginWriteArray(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
            ReadConfig.setArrayIndex(SNsize);
            ReadConfig.setValue(tr("SN"), ui->SNDate_lineEdit->text().toInt());
            ReadConfig.setValue(tr("Number"), ui->SNNumber_spinBox->value());
            ui->SNNumber_spinBox->setValue(ui->SNNumber_spinBox->value()+1);
            ReadConfig.endArray();

            ReadConfig.beginGroup(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
            ReadConfig.setValue(tr("CurrentGroup"), SNsize);
            ReadConfig.endGroup();
        }
    }
}
/***********************************************************************************************
*函数名:  Config_File_Init
*函数功能描述:初始化SN
*函数参数:无
*函数返回值: 无
***********************************************************************************************/
void MainWindow::Config_File_Init()
{
    int a,b,c;
    QSettings ReadConfig(tr("Setting.ini"),QSettings::IniFormat);
    if(ReadConfig.contains(tr("Manage/CurrentType")))
    {
        ReadConfig.beginGroup(tr("Manage"));
        QString CurrentTypeStr = ReadConfig.value("CurrentType").toString();
        ReadConfig.endGroup();
        ui->TypeSelctcomboBox->setCurrentText(CurrentTypeStr);

        ReadConfig.beginGroup(tr("%1").arg(CurrentTypeStr));
         c = ReadConfig.value("CurrentGroup").toInt();
        ReadConfig.endGroup();

        ReadConfig.beginReadArray(tr("%1").arg(ui->TypeSelctcomboBox->currentText()));
        ReadConfig.setArrayIndex(c);
        a = ReadConfig.value("SN").toInt();
        b = ReadConfig.value("Number").toInt();
        ReadConfig.endArray();

        ui->SNDate_lineEdit->setText(tr("%1").arg(a));
        ui->SNNumber_spinBox->setValue(b+1);
    }
    else
    {
        return;
    }
}

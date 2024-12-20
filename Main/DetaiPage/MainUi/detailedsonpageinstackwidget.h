#ifndef DETAILEDSONPAGEINSTACKWIDGET_H
#define DETAILEDSONPAGEINSTACKWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QSqlDatabase>
#include <QStandardItemModel>
#include "Main/DetaiPage/MainUi/SubCtrls/calendarkit.h"
#include "Main/DetaiPage/MainUi/SubCtrls/inandoutkit.h"
#include "Main/DetaiPage/SubPage/Bill/SubCtrls/billdataitem.h"
#include "BaseClass/detialtableview.h"
#include "Controler/DataStruct/PublicDataStruct.h"
#include "BaseClass/basecustomwidget.h"

///****************************************************************************
/// @author  : MichaelFeng
/// @date    : 2022/12/16
/// @file    : DetailedSonPageInStackwidget.h
/// @brief   : 明细主界面在stackwidget中
///----------------------------------------------------------------------------
///                           Change History
///----------------------------------------------------------------------------
///
///****************************************************************************
namespace Ui {
class DetailedSonPageInStackwidget;
}

class DetailedSonPageInStackwidget : public BaseCustomWidget
{
    Q_OBJECT

public:
    explicit DetailedSonPageInStackwidget(QWidget *parent = nullptr);
    ~DetailedSonPageInStackwidget();

public:
    void UpdateBillContent();                           //刷新账单界面

    void UpdateBillDetailPage();                        //刷新账单详情界面

public slots:
    void receiveSetDateInfo(int year,int month);         //收到设置日期信息槽函数

    void receiveCallGetInAndOutInfo(int type,double num=0); //收到获取账单详情信息

    void receiveUpdateBillInfoSignal(bool status); //收到刷新账单信息的信号

    void onBillSubButtonClicked();                 //打开账单子界面槽函数

    void onBudgetButtonClicked();                  //打开预算子界面槽函数

    void onAssetManagerButtonClicked();            //打开资产管理子界面槽函数

    void onShopPageButtonClicked();                //打开购物返现界面槽函数

    void onMoreButtonClicked();                    //打开更多功能子界面槽函数



protected:
    void buildUiLayout();     //构建UI布局

    void buildConnect();      //建立槽函数连接

    void initMenuSettingIni(); //初始化菜单配置文件

    void getBilldata();       //获取账单数据

    void initTableview();     //初始化表格内容

    void initInAndOutKitContent();  //初始化收入支出控件内容

    bool eventFilter(QObject *obj, QEvent *event);   //事件过滤器


signals:



private:
    QGridLayout outterlayout;

    //QGridLayout titlelayout;
    QGridLayout inAndoutlayout;
    //QGridLayout toollayout;
    QGridLayout tableviewlayout;

    DetialTableview * tableview;
    QStandardItemModel * model;

    CalendarKit * calendarkit;
    InAndOutKit * inkit;
    InAndOutKit * outkit;
    QPointF m_TempPoint;

    QDate m_CurrentDate;                            //当前日期
    QSqlDatabase coon;
    bool hasConnected;
private:
    QVector<BillTableStruct> m_BillList;             //账单列表
    QVector<BillTableStruct> m_BillListOfYear;       //近一年的账单列表
    QVector<BillDataItem *> m_BillDateItemList;       //itemlist;
    double m_Current_InNumber = 0.00;                //当前收入数据
    double m_Current_OutNumber = 0.00;               //当前支出数据
    InAndOutType m_currentOpenType;


private:
    Ui::DetailedSonPageInStackwidget *ui;
};

#endif // DETAILEDSONPAGEINSTACKWIDGET_H
